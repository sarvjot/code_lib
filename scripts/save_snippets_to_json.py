import os
import json

def text_after(pattern, string):
    return string.partition(pattern)[2]

def parse_snippet_file(snippet_file):
    snippet = []
    with open(snippet_file, 'r') as f:
        for line in f:
            snippet.append(line[:-1]) # remove the newline character

    first_line = snippet[0]
    second_line = snippet[1]

    if(not first_line.startswith("// prefix: ")):
        exit("No prefix found for file " + os.path.basename(snippet_file))
    elif(not second_line.startswith("// description: ")):
        body = snippet[1:]
        prefix = description = text_after("// prefix: ", first_line)
    else:
        body = snippet[2:]
        prefix = text_after("// prefix: ", first_line)
        description = text_after("// description: ", second_line)

    return {
        "prefix": prefix,
        "body": body,
        "description": description
    }

# get the snippet directory's path from env variable
lib_path = os.environ.get('lib_path')
if(lib_path is None):
    exit("env variable lib_path not set")
snippet_directory = os.path.join(lib_path, 'snippets', 'cp_snippets', 'ds_algo_snippets')

if(not os.path.isdir(snippet_directory)):
    exit("snippet directory does not exist " + snippet_directory)

# parse all the cpp snippets
json_snippets = {}
for snippet in os.listdir(snippet_directory):
    if(snippet.endswith(".cpp")):
        snippet_file_path = os.path.join(snippet_directory, snippet)
        snippet_name = os.path.basename(snippet_file_path).split('.')[0]

        json_snippets[snippet_name] = parse_snippet_file(snippet_file_path)

# write the json to file
dotfiles_path = os.environ.get('dotfiles_path')
if(dotfiles_path is None):
    exit("env variable dotfiles_path not set, no place to save the snippets")
target_file = os.path.join(dotfiles_path, '.config', 'nvim', 'my_snippets', 'snippets', 'cpp.json')

if(not os.path.isdir(os.path.dirname(target_file))):
    exit("target file does not exist " + target_file)

with open(target_file, 'w') as f:
    json.dump(json_snippets, f, indent='\t')
