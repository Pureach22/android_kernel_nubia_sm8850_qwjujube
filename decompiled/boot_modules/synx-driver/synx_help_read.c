__int64 __fastcall synx_help_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x19
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = _kmalloc_cache_noprof(jiffies, 3520, 4096);
  if ( v7 )
  {
    v8 = v7;
    v11 = v7 + 4096;
    v12[0] = v7;
    synx_debugfs_util_load_help_content(v12, &v11);
    v9 = simple_read_from_buffer(a2, a3, a4, v8, v12[0] - v8);
    kfree(v8);
  }
  else
  {
    v9 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
