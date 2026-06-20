#!/bin/bash
# Find builds here:
# https://ci.android.com/builds/branches/aosp_kernel-common-android15-6.6/grid
set -e

files=(
  "ffa-module.ko"
  "system_heap.ko"
  "trusty-core.ko"
  "trusty-ipc.ko"
  "trusty-log.ko"
  "trusty-test.ko"
  "trusty-virtio.ko"
)

# Change directory to the script patj
cd "$(dirname "$(realpath $0)")"

if [ $# == 1 ]
then
build=$1
else
	echo "Usage: $0 <build>"
	exit 1
fi

download_trusty_file()
{
  local target=$1
  local ko_file=$2

  local ci_url="https://ci.android.com/builds/submitted/${build}/${target}/latest/raw"
  echo "Downloading $ko_file..."
  curl -fL "$ci_url/$ko_file" -o $ko_file

  echo "Adding $ko_file to current branch"
  git add $ko_file
}

for file in "${files[@]}"; do
  download_trusty_file "trusty_aarch64" "$file"
done

echo "Committing build $build..."
git commit -m "Update Trusty prebuilts to $build

Bug: None
Test: Presubmit"

topic="trusty_module_prebuilts_$build"
echo "Uploading topic $topic"
repo upload -c . --topic=$topic
