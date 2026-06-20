void *hfi_dump_dbg_bus()
{
  void *result; // x0
  __int64 v1; // x22
  unsigned int v2; // w23
  int v3; // w9
  int v4; // w20
  unsigned int v5; // w24
  unsigned int v6; // w8
  unsigned int v7; // w26
  size_t v8; // x2
  unsigned int v9; // w24
  unsigned int v10; // w8
  unsigned int v11; // w26
  size_t v12; // x2
  char s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v14; // [xsp+208h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  v1 = *(_QWORD *)(hfi_dbg + 160);
  if ( v1 )
  {
    v2 = *(_DWORD *)(hfi_dbg + 168);
    if ( v2 )
    {
      v3 = *(_DWORD *)(hfi_dbg + 324);
      if ( (v3 & 0xF) != 0 )
      {
        v4 = *(_DWORD *)(hfi_dbg + 324) & 5;
        if ( (v3 & 8) != 0 )
        {
          drm_printf(*(_QWORD *)(hfi_dbg + 32), "===================dgb_bus================\n");
          mutex_lock(hfi_dbg + 272);
          v5 = 0;
          v6 = v2;
          do
          {
            v7 = v6 - 512;
            if ( v6 >= 0x200 )
              v8 = 512;
            else
              v8 = v6;
            memcpy(s, (const void *)(v1 + (int)v5), v8);
            drm_printf(*(_QWORD *)(hfi_dbg + 32), "%s", s);
            v5 += 512;
            v6 = v7;
          }
          while ( v5 < v2 );
          mutex_unlock(hfi_dbg + 272);
          result = (void *)drm_printf(*(_QWORD *)(hfi_dbg + 32), "\n");
        }
        if ( v4 )
        {
          printk(&unk_234996, "_hfi_dump_dbg_bus");
          mutex_lock(hfi_dbg + 272);
          v9 = 0;
          v10 = v2;
          do
          {
            v11 = v10 - 512;
            if ( v10 >= 0x200 )
              v12 = 512;
            else
              v12 = v10;
            memcpy(s, (const void *)(v1 + (int)v9), v12);
            printk(&unk_276989, "_hfi_dump_dbg_bus");
            v9 += 512;
            v10 = v11;
          }
          while ( v9 < v2 );
          mutex_unlock(hfi_dbg + 272);
          result = (void *)printk(&unk_26C28E, "_hfi_dump_dbg_bus");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
