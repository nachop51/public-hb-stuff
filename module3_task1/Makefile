build: ## Make build
	hugo --cleanDestinationDir -D
clean: ## Make clean
	rm -rf dist/
post:  ## Make post
	hugo new posts/$(POST_NAME).md
	sed -i '/title:/c\title: "$(POST_TITLE)"' content/posts/$(POST_NAME).md
help:  ## Make help
	@sed -ne '/@sed/!s/## //p' Makefile
