npm install --save-dev eslint-plugin-prettier eslint-config-prettier
npx install-peerdeps --dev eslint-config-airbnb

path="$lib_path/snippets/non_cp_snippets"

touch .prettierrc && cat < $path"/boilerplate_prettierrc" > .prettierrc 
touch .eslintrc && cat < $path"/boilerplate_eslintrc" > .eslintrc
