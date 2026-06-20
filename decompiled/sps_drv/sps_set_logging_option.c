__int64 __fastcall sps_set_logging_option(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x2
  __int64 v7; // x2
  char v8; // w8
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v4 = kstrtouint_from_user(a2, a3, 10, &v9);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    printk(&unk_2675E, v9, v5);
    if ( v9 >= 4 )
    {
      printk(&unk_29AAD, v9, v7);
    }
    else
    {
      mutex_lock(&sps_debugfs_lock);
      v8 = v9;
      if ( (v9 & 0xFFFFFFFD) == 0 && (logging_option & 0xFD) == 1 )
      {
        debugfs_record_enabled = 0;
        kfree(debugfs_buf);
        debugfs_buf = 0;
        debugfs_buf_used = 0;
        v8 = v9;
        debugfs_buf_size = 0;
        wraparound = 0;
      }
      logging_option = v8;
      mutex_unlock(&sps_debugfs_lock);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
