build: ## Generate the website from markdown
	@hugo
	@go build -o awesome-api ./*.go

run: ## Run the application
	./awesome-api >./awesome.log 2>&1 &

stop: ## Stop the app
	@pkill awesome-api

clean: stop ## Cleanup the content of the 'dist/' folder
	@rm -rf dist/
	@rm -f awesome-api awesome.log

test: ## Tests the application
	@echo "Test"
	@if curl http://localhost:9999; then echo "\nTESTOK"; else echo "TESTFAILED"; fi
	@if curl http://localhost:9999/health; then echo "\nTESTOK"; else echo "TESTFAILED"; fi

post: ## Create a new blog post using POST_TITLE and POST_NAME env variables
	hugo new posts/$(POST_NAME).md
	sed -i '/title:/c\title: "$(POST_TITLE)"' content/posts/$(POST_NAME).md

lint: ## Runs a lint tool
	@golangci-lint run ./*.go

help: ## Show this help.
	@fgrep -h "##" $(MAKEFILE_LIST) | fgrep -v fgrep | sed -e 's/\\$$//' | sed -e 's/##//'

