__int64 __fastcall sps_debugfs_record(const char *a1)
{
  unsigned int v2; // w8
  unsigned int v3; // w8

  mutex_lock(&sps_debugfs_lock);
  if ( debugfs_record_enabled )
  {
    v2 = debugfs_buf_used;
    if ( debugfs_buf_used + 80 >= (unsigned int)debugfs_buf_size )
    {
      v2 = 0;
      debugfs_buf_used = 0;
      wraparound = 1;
    }
    v3 = debugfs_buf_used + scnprintf(debugfs_buf + v2, debugfs_buf_size - v2, a1);
    debugfs_buf_used = v3;
    if ( wraparound == 1 )
      scnprintf(debugfs_buf + v3, debugfs_buf_size - v3, "\n**** end line of sps log ****\n\n");
  }
  return mutex_unlock(&sps_debugfs_lock);
}
