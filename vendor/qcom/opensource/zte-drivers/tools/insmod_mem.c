/*
 * insmod_mem.c - Memory-based kernel module loader
 *
 * Loads a kernel module by reading the .ko file into userspace memory
 * and calling the init_module() syscall directly. This bypasses the
 * noexec mount restriction that blocks finit_module() on /data partitions
 * in Android.
 *
 * Usage: insmod_mem <module.ko> [param=value ...]
 *
 * Copyright (c) 2026 - Antigravity Senior Systems Engineer
 * License: GPL v2
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/syscall.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int fd;
	struct stat st;
	void *image;
	ssize_t bytes_read;
	long ret;
	char params[4096] = "";

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <module.ko> [param=value ...]\n", argv[0]);
		return 1;
	}

	/* Open the .ko file */
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf(stderr, "ERROR: Cannot open '%s': %s\n", argv[1], strerror(errno));
		return 1;
	}

	/* Get file size */
	if (fstat(fd, &st) < 0) {
		fprintf(stderr, "ERROR: Cannot stat '%s': %s\n", argv[1], strerror(errno));
		close(fd);
		return 1;
	}

	if (st.st_size == 0) {
		fprintf(stderr, "ERROR: File '%s' is empty\n", argv[1]);
		close(fd);
		return 1;
	}

	/* Allocate memory and read the entire module image */
	image = malloc(st.st_size);
	if (!image) {
		fprintf(stderr, "ERROR: Cannot allocate %ld bytes: %s\n",
			(long)st.st_size, strerror(errno));
		close(fd);
		return 1;
	}

	bytes_read = read(fd, image, st.st_size);
	close(fd);

	if (bytes_read != st.st_size) {
		fprintf(stderr, "ERROR: Short read: got %zd of %ld bytes\n",
			bytes_read, (long)st.st_size);
		free(image);
		return 1;
	}

	/* Build parameter string from remaining args */
	if (argc > 2) {
		int i;
		size_t offset = 0;

		for (i = 2; i < argc; i++) {
			size_t len = strlen(argv[i]);

			if (offset + len + 2 > sizeof(params)) {
				fprintf(stderr, "ERROR: Parameter string too long\n");
				free(image);
				return 1;
			}
			if (offset > 0)
				params[offset++] = ' ';
			memcpy(params + offset, argv[i], len);
			offset += len;
		}
		params[offset] = '\0';
	}

	/* Call init_module syscall directly (bypasses noexec VFS check) */
	fprintf(stderr, "Loading module '%s' (%ld bytes) via init_module()...\n",
		argv[1], (long)st.st_size);

	ret = syscall(SYS_init_module, image, (unsigned long)st.st_size, params);
	free(image);

	if (ret != 0) {
		fprintf(stderr, "ERROR: init_module failed: %s (errno=%d)\n",
			strerror(errno), errno);
		return 1;
	}

	fprintf(stderr, "Module '%s' loaded successfully!\n", argv[1]);
	return 0;
}
