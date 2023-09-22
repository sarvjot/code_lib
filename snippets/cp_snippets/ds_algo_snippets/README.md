# My Data Structures and Algorithms Snippets (for Competitive Programming)

## Snippet Format

- These snippets are in c++ format, there is a [python script](https://github.com/sarvjot/code_lib/tree/main/scripts/save_snippets_to_json.py) which converts these into json format, consumable by popular snippet engines like VSCode and LuaSnip (Neovim).
- The script expects all the snippets to follow the following format:

```cpp
// prefix: <snippet-prefix>
// description: <snippet-description> (optional)

C++ Snippet code goes here...
```
- The two snippet meta-data comments must be placed at the top of the file
- The name of the snippet file, will be given the name of the snippet
