void hdd_debugfs_thread_decrement()
{
  unsigned int v6; // w10

  _X9 = &debugfs_thread_count;
  __asm { PRFM            #0x11, [X9] }
  do
    v6 = __ldxr((unsigned int *)&debugfs_thread_count);
  while ( __stxr(v6 - 1, (unsigned int *)&debugfs_thread_count) );
}
