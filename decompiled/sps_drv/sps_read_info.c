__int64 __fastcall sps_read_info(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v7; // w8
  __int64 v8; // x19

  mutex_lock(&sps_debugfs_lock);
  if ( debugfs_record_enabled )
  {
    if ( wraparound )
      v7 = debugfs_buf_size - 80;
    else
      v7 = debugfs_buf_used;
    v8 = (int)simple_read_from_buffer(a2, a3, a4, debugfs_buf, v7);
  }
  else
  {
    v8 = 0;
  }
  mutex_unlock(&sps_debugfs_lock);
  return v8;
}
