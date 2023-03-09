integration-tests: ## Runs integreation tests in order to test the code
	@go test -v -coverprofile=coverage-integrations.out

unit-tests: ## Runs unit tests in order to test the code
	@go test -v -short -coverprofile=coverage-units.out

validate: ## Validates the syntax of the index.html in the dist directory
	@./w3c_validator.py ./dist/index.html || true

lint: ## update files README.md and DEPLOY.md to markdownlint
	markdownlint --fix DEPLOY.md README.md

package: ## produces a file awesome-website.zip
	zip -r awesome-website.zip dist/ awesome-api

build: ## Generate the website from markdown
	@hugo

run: ## Run the application
	@./awesome-api >./awesome.log 2>&1 &

stop: ## Stop the app
	@pkill awesome-api || true

clean: stop ## Cleanup the content of the 'dist/' folder
	@rm -rf dist/
	@rm -f awesome-api awesome.log awesome-website.zip
	@rm -f coverage-units.out coverage-integrations.out

test: unit-tests integration-tests ## Tests the application
	@echo "Test"

post: ## Create a new blog post using POST_TITLE and POST_NAME env variables
	hugo new posts/$(POST_NAME).md
	sed -i '/title:/c\title: "$(POST_TITLE)"' content/posts/$(POST_NAME).md

help: ## Show this help.
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

