NS = cmehay
VERSION ?= latest

REPO = libftasm
NAME = libftasm
INSTANCE = default

.PHONY: all build shell run rm

all: build run

build:
	docker build -t $(NS)/$(REPO):$(VERSION) .

shell:
	docker run --rm --name $(NAME)-$(INSTANCE) -i -t $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) /bin/bash

verbose:
	docker run --rm --name $(NAME)-$(INSTANCE) $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION) ./libft_asm -v

run:
	docker run --rm --name $(NAME)-$(INSTANCE) -i -t $(PORTS) $(VOLUMES) $(ENV) $(NS)/$(REPO):$(VERSION)

rm:
	docker rm $(NAME)-$(INSTANCE)
