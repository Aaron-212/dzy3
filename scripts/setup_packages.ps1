# PowerShell Script to install packages on Windows
$ErrorActionPreference = "Stop"

# Check for vcpkg
if (-Not (Test-Path "C:\vcpkg")) {
    Write-Host "vcpkg not found. Installing vcpkg..."
    git clone https://github.com/microsoft/vcpkg.git C:\vcpkg
    & C:\vcpkg\bootstrap-vcpkg.bat
}

# Install required packages
& C:\vcpkg\vcpkg install packagename1:x64-windows packagename2:x64-windows

# Setting up the environment variable for vcpkg
$env:VCPKG_ROOT="C:\vcpkg"

Write-Host "Required packages installed successfully."
