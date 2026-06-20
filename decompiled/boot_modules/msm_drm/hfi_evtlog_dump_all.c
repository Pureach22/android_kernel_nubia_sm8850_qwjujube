_QWORD *__fastcall hfi_evtlog_dump_all(_QWORD *result)
{
  char *v1; // x21
  __int64 v2; // x22
  int v3; // w19
  unsigned int v4; // w8
  int v5; // w24
  unsigned int i; // w25
  unsigned int v7; // w8
  size_t v8; // x2
  unsigned int v9; // w8
  int v10; // w24
  unsigned int j; // w25
  unsigned int v12; // w8
  size_t v13; // x2
  char s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v15; // [xsp+208h] [xbp-8h]

  v1 = (char *)(result + 98304);
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = result[98308];
  if ( v2 )
  {
    if ( *((_DWORD *)result + 196618) )
    {
      v3 = *((_DWORD *)result + 196614);
      if ( (v3 & 0xF) != 0 )
      {
        result = memset(s, 0, sizeof(s));
        if ( (v3 & 8) != 0 )
        {
          drm_printf(*(_QWORD *)(hfi_dbg + 32), "===================evtlog================\n");
          mutex_lock(hfi_dbg + 272);
          v4 = *((_DWORD *)v1 + 10);
          if ( v4 )
          {
            v5 = 0;
            for ( i = 0; i < v4; i += 512 )
            {
              v7 = v4 + v5;
              if ( v7 >= 0x200 )
                v8 = 512;
              else
                v8 = v7;
              memcpy(s, (const void *)(v2 + (int)i), v8);
              drm_printf(*(_QWORD *)(hfi_dbg + 32), "%s", s);
              v4 = *((_DWORD *)v1 + 10);
              v5 -= 512;
            }
          }
          mutex_unlock(hfi_dbg + 272);
          result = (_QWORD *)drm_printf(*(_QWORD *)(hfi_dbg + 32), "\n");
        }
        if ( (v3 & 5) != 0 )
        {
          printk(&unk_237F02, "hfi_evtlog_dump_all");
          mutex_lock(hfi_dbg + 272);
          v9 = *((_DWORD *)v1 + 10);
          if ( v9 )
          {
            v10 = 0;
            for ( j = 0; j < v9; j += 512 )
            {
              v12 = v9 + v10;
              if ( v12 >= 0x200 )
                v13 = 512;
              else
                v13 = v12;
              memcpy(s, (const void *)(v2 + (int)j), v13);
              printk(&unk_276989, "hfi_evtlog_dump_all");
              v9 = *((_DWORD *)v1 + 10);
              v10 -= 512;
            }
          }
          mutex_unlock(hfi_dbg + 272);
          result = (_QWORD *)printk(&unk_26C28E, "hfi_evtlog_dump_all");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
