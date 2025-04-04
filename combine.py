import os
import re
import sys
from typing import Set

def read_file(file_path):
    with open(file_path, "r", encoding="utf-8", errors="replace") as f:
        return f.read()

def expand_includes(file_path, included_files: Set[str], project_root: str) -> str:
    file_path = os.path.normpath(file_path)
    if file_path in included_files:
        return ""

    included_files.add(file_path)

    base_dir = os.path.dirname(file_path)
    content = read_file(file_path)
    lines = content.splitlines()

    result = [f"// begin {os.path.relpath(file_path, project_root)}"]
    for line in lines:
        match = re.match(r'^\s*#include\s+"(.*)"\s*$', line)
        if match:
            relative_include = match.group(1)
            include_target = os.path.normpath(os.path.join(project_root, relative_include))
            expanded = expand_includes(include_target, included_files, project_root)
            result.append(expanded)
        else:
            result.append(line)
    result.append(f"// end {os.path.relpath(file_path, project_root)}\n")
    return "\n".join(result)

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 combine.py <source_file> <output_file>")
        sys.exit(1)

    source_file = os.path.normpath(sys.argv[1])
    output_file = sys.argv[2]
    included_files = set()
    project_root = os.path.dirname(source_file)

    with open(source_file, "r", encoding="utf-8") as f:
        lines = f.readlines()

    output_lines = []
    for line in lines:
        match = re.match(r'^\s*#include\s+"(.+\.cpp)"\s*$', line)
        if match:
            include_path = os.path.normpath(os.path.join(project_root, match.group(1)))
            expanded = expand_includes(include_path, included_files, project_root)
            output_lines.append(expanded)
        else:
            output_lines.append(line.rstrip())

    with open(output_file, "w", encoding="utf-8") as f:
        f.write("\n".join(output_lines))

if __name__ == "__main__":
    main()
