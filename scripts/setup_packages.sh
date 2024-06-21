#!/bin/sh

# Determine OS
OS_NAME=$(uname -s)

if [ "$OS_NAME" = "Darwin" ]; then
    which -s brew
    if [[ $? != 0 ]]; then
        echo "Homebrew not found. Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    echo "Installing required packages with Homebrew..."
    brew install cmake googletest
elif [ "$OS_NAME" = "Linux" ]; then
    if [ -x "$(command -v apt-get)" ]; then
        echo "Installing required packages with apt-get..."
        sudo apt-get update
        sudo apt-get install -y cmake libgtest-dev
    else
        echo "Unsupported package manager. Please install the required packages manually."
        exit 1
    fi
else
    echo "Unsupported OS: $OS_NAME"
    exit 1
fi

echo "Required packages installed successfully."
