FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

# Install dependencies
RUN apt-get update && \
    apt-get install -y \
    libxml2-dev \
    libcurl4-openssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Create the exact directory structure we need
RUN mkdir -p /workspace/crawler && \
    chown -R vscode:vscode /workspace

USER vscode
WORKDIR /workspace/crawler