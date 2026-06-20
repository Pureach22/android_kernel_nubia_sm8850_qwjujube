void *hfi_dump_reg_all()
{
  void *result; // x0
  __int64 v1; // x22
  int v2; // w23
  int v3; // w20
  int v4; // w24
  int v5; // w8
  int v6; // w26
  size_t v7; // x2
  int v8; // w24
  int v9; // w8
  int v10; // w26
  char s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v12; // [xsp+208h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = memset(s, 0, sizeof(s));
  v1 = *(_QWORD *)(hfi_dbg + 48);
  if ( v1 )
  {
    v2 = *(_DWORD *)(hfi_dbg + 56);
    if ( v2 )
    {
      v3 = *(_DWORD *)(hfi_dbg + 324);
      if ( (v3 & 0xF) != 0 )
      {
        if ( (v3 & 8) != 0 )
        {
          drm_printf(*(_QWORD *)(hfi_dbg + 32), "===================reg_dump================\n");
          mutex_lock(hfi_dbg + 272);
          if ( v2 >= 1 )
          {
            v4 = 0;
            v5 = v2;
            while ( 1 )
            {
              v6 = v5 - 512;
              v7 = v5 >= 512 ? 512LL : (unsigned int)v5;
              if ( (unsigned int)v7 >= 0x201 )
                break;
              memcpy(s, (const void *)(v1 + 4LL * v4), v7);
              drm_printf(*(_QWORD *)(hfi_dbg + 32), "%s", s);
              v4 += 512;
              v5 = v6;
              if ( v4 >= v2 )
                goto LABEL_12;
            }
LABEL_23:
            _fortify_panic(17, 512, v7);
          }
LABEL_12:
          mutex_unlock(hfi_dbg + 272);
          result = (void *)drm_printf(*(_QWORD *)(hfi_dbg + 32), "\n");
        }
        if ( (v3 & 5) != 0 )
        {
          printk(&unk_256ACB, "_hfi_dump_reg_all");
          mutex_lock(hfi_dbg + 272);
          if ( v2 >= 1 )
          {
            v8 = 0;
            v9 = v2;
            do
            {
              v10 = v9 - 512;
              v7 = v9 >= 512 ? 512LL : (unsigned int)v9;
              if ( (unsigned int)v7 >= 0x201 )
                goto LABEL_23;
              memcpy(s, (const void *)(v1 + 4LL * v8), v7);
              printk(&unk_276989, "_hfi_dump_reg_all");
              v8 += 512;
              v9 = v10;
            }
            while ( v8 < v2 );
          }
          mutex_unlock(hfi_dbg + 272);
          result = (void *)printk(&unk_26C28E, "_hfi_dump_reg_all");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
