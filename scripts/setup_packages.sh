#!/bin/sh

# Determine OS
OS_NAME=$(uname -s)

if [ "$OS_NAME" = "Darwin" ]; then
    # macOS
    which -s brew
    if [[ $? != 0 ]]; then
        echo "Homebrew not found. Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    echo "Installing required packages with Homebrew..."
    brew install cmake PackageName1 PackageName2
elif [ "$OS_NAME" = "Linux" ]; then
    # Linux (example for Debian-based distros)
    if [ -x "$(command -v apt-get)" ]; then
        echo "Installing required packages with apt-get..."
        sudo apt-get update
        sudo apt-get install -y cmake libpackagename1-dev libpackagename2-dev
    elif [ -x "$(command -v yum)" ]; then
        echo "Installing required packages with yum..."
        sudo yum install -y cmake packagename1-devel packagename2-devel
    # Add other potential package managers here (e.g., pacman for Arch Linux, zypper for openSUSE)
    else
        echo "Unsupported package manager. Please install the required packages manually."
        exit 1
    fi
else
    echo "Unsupported OS: $OS_NAME"
    exit 1
fi

echo "Required packages installed successfully."
