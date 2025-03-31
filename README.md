# Crawler

## Overview
This is a simple web crawler written in C++ that fetches and parses HTML content from web pages. It extracts links from the retrieved pages and continues crawling in a breadth-first manner. The project utilizes `libcurl` for HTTP requests and `libxml2` for HTML parsing.

## Features
- Fetches HTML content using `libcurl`
- Parses and extracts links using `libxml2`
- Resolves relative URLs to absolute URLs
- Avoids duplicate crawling with a set-based tracking system
- Uses a queue-based breadth-first crawling approach

## Installation & Setup
### Prerequisites
Make sure you have the following dependencies installed:
- `g++` (C++ compiler)
- `libcurl` (for HTTP requests)
- `libxml2` (for HTML parsing)

### Build & Run
Clone the repository and build the project:
```sh
git clone https://github.com/itsNavinSingh/crawler.git
cd crawler
make
./build/bin/crawler [starting_url]
```
If no starting URL is provided, it defaults to Wikipedia's Web Crawler page.

## Usage for LLM Data Collection
This crawler can be used to gather textual data from the web for training a Large Language Model (LLM). The extracted web pages can be processed and stored for further use in natural language processing tasks.

### Steps to Gather Data:
1. **Crawl Websites**: Provide a list of seed URLs and run the crawler to fetch web pages.
2. **Extract Text**: Use `libxml2` or another text-processing tool to extract meaningful content while filtering out scripts, navigation elements, and advertisements.
3. **Store Data**: Save the processed text in a structured format like JSON, CSV, or a database.
4. **Preprocess for LLM Training**:
   - Tokenization
   - Cleaning and normalization
   - Removing duplicates and unwanted content
5. **Train the Model**: Use frameworks like TensorFlow, PyTorch, or Hugging Face's `transformers` to train an LLM on the gathered data.

## Development Setup
For development, you can use VS Code with Dev Containers. The project includes a `.devcontainer` setup for ease of development.
```sh
docker build -t crawler-dev .
docker run --rm -it -v $(pwd):/workspace crawler-dev
```

## Contributing
Feel free to contribute by submitting issues or pull requests to enhance the crawler.