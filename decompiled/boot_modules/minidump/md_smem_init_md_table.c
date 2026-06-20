__int64 md_smem_init_md_table()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x1
  int v2; // w10
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 result; // x0
  unsigned __int64 v6; // x12
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v0 = qcom_smem_get(0xFFFFFFFFLL, 602, v10);
  md_global_toc = v0;
  if ( v0 && v0 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( v10[0] >= 0x150u && *(_DWORD *)v0 )
    {
      qword_1100F0 = v0;
      v2 = *(_DWORD *)(v0 + 4);
      md_ss_toc = v0 + 16;
      *(_QWORD *)(v0 + 24) = 0x4E52444F4E45LL;
      minidump_table = v2;
      qword_1100E8 = v0 + 16;
      v3 = _kmalloc_cache_noprof(_tracepoint_android_vh_ftrace_oops_enter, 3520, 8040);
      qword_1100F8 = v3;
      if ( v3 )
      {
        v4 = v3 << 8 >> 8;
        result = 0;
        v6 = (unsigned __int64)(v4 + 0x8000000000LL) >> 38;
        v7 = memstart_addr + v4 + 0x8000000000LL;
        v8 = md_ss_toc;
        v9 = v4 - kimage_voffset;
        if ( !v6 )
          v9 = v7;
        *(_QWORD *)(md_ss_toc + 24) = v9;
        *(_DWORD *)(v8 + 16) = 1;
      }
      else
      {
        result = 4294967284LL;
      }
    }
    else
    {
      printk(&unk_11383C, v1);
      result = 4294967277LL;
    }
  }
  else
  {
    printk(&unk_113563, v1);
    result = (unsigned int)md_global_toc;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
