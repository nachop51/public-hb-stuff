integration-tests: ## 
	@go test -v -coverprofile=coverage-integrations.out

unit-tests: ## Runs unit tests in order to test the code
	@go test -v -short -coverprofile=coverage-units.out

lint: ## Runs a lint tool
	@golangci-lint run *.go

build: lint check ## Generate the website from markdown
	@hugo
	@go build -o awesome-api ./*.go

run: ## Run the application
	./awesome-api >./awesome.log 2>&1 &

stop: ## Stop the app
	@pkill awesome-api || true

clean: stop ## Cleanup the content of the 'dist/' folder
	@rm -rf dist/
	@rm -f awesome-api awesome.log
	@rm -f coverage-units.out coverage-integrations.out

test: unit-tests integration-tests ## Tests the application
	@echo "Test"

post: ## Create a new blog post using POST_TITLE and POST_NAME env variables
	hugo new posts/$(POST_NAME).md
	sed -i '/title:/c\title: "$(POST_TITLE)"' content/posts/$(POST_NAME).md

check: ## Runs a lint for the md and an analysis of the links
	markdownlint 'content/**/*.md'
	find ./content -name \*.md -print0 | xargs -0 -n1 markdown-link-check

validate: ## Validates the syntax of the index.html in the dist directory
	./w3c_validator.py ./dist/index.html || true

help: ## Show this help.
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

