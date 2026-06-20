__int64 __fastcall _flush_debug_queue(__int64 a1, unsigned int *a2, unsigned int a3)
{
  unsigned int v3; // w21
  int v4; // w23
  bool v5; // zf
  unsigned int *v6; // x20
  int v8; // w28
  __int64 v9; // x3
  __int64 v10; // x4
  unsigned int v11; // w22
  __int64 v12; // x5

  v3 = a3;
  v4 = msm_fw_debug;
  if ( a2 )
    v5 = a3 == 0;
  else
    v5 = 1;
  v6 = a2;
  v8 = v5;
  if ( !v5 )
    goto LABEL_11;
  v6 = (unsigned int *)vzalloc_noprof(4096);
  if ( v6 )
  {
    v4 |= 0x10000000u;
    v3 = 4096;
LABEL_11:
    v11 = 0;
    if ( !(unsigned int)venus_hfi_queue_dbg_read(a1, v6) )
    {
      _ReadStatusReg(SP_EL0);
      do
      {
        v12 = *v6;
        if ( (unsigned int)v12 <= 0xF )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8EAFE, "err ", 0xFFFFFFFFLL, "codec", "__flush_debug_queue");
        }
        else if ( (unsigned int)v12 >= v3 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_96783, "err ", 0xFFFFFFFFLL, "codec", "__flush_debug_queue");
        }
        else
        {
          *((_BYTE *)v6 + v12) = 0;
          if ( (v4 & 0x10000000 & msm_fw_debug) != 0 )
            printk(&unk_8A180, &unk_91004, (char *)v6 + 17, v9, v10);
        }
        ++v11;
      }
      while ( !(unsigned int)venus_hfi_queue_dbg_read(a1, v6) );
    }
    if ( v8 )
      vfree(v6);
    return v11;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "__flush_debug_queue");
  return 0;
}
