void hdd_debugfs_thread_increment()
{
  unsigned int v6; // w9

  _X8 = &debugfs_thread_count;
  __asm { PRFM            #0x11, [X8] }
  do
    v6 = __ldxr((unsigned int *)&debugfs_thread_count);
  while ( __stxr(v6 + 1, (unsigned int *)&debugfs_thread_count) );
}
