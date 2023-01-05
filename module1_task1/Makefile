build:
	hugo --cleanDestinationDir -D
clean:
	rm -rf dist/
post:
	hugo new posts/$(POST_NAME).md
	sed '/title:/c\title: $(POST_TITLE)' content/posts/$(POST_NAME).md
