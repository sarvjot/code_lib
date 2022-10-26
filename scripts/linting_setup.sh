npm install --save-dev eslint-plugin-prettier eslint-config-prettier
npx install-peerdeps --dev eslint-config-airbnb

path="$lib_path/templates/non_cp_templates"

touch .prettierrc && cat < $path"/boilerplate_prettierrc" > .prettierrc 
touch .eslintrc && cat < $path"/boilerplate_eslintrc" > .eslintrc