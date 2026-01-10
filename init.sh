#!/bin/bash
set -e

# Get the directory of the script
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

echo "Running docker-compose for the main project..."
docker-compose -f "$SCRIPT_DIR/docker-compose.yml" up -d

echo "Running docker-compose for the challenges..."
docker-compose -f "$SCRIPT_DIR/challenges/docker-compose.yml" up -d

echo "Docker containers started."