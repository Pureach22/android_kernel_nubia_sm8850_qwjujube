__int64 __fastcall hfi_dbg_reg_base_reg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x28
  __int64 result; // x0
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x21
  unsigned __int64 v11; // x22
  _QWORD *v12; // x23
  _QWORD *cmd_buf; // x0
  __int64 v14; // x19
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x9
  int property; // w0
  int v19; // w19
  __int64 v20; // x8
  void *v21; // x0
  unsigned __int64 v22; // x20
  __int64 v23; // x19
  int v24; // w21
  _DWORD *v25; // x24
  unsigned int v26; // w23
  unsigned __int64 v27; // x20
  __int64 v28; // x21
  __int64 v29; // x19
  int v30; // w20
  char v31; // [xsp+0h] [xbp-20h]
  unsigned __int64 v32; // [xsp+8h] [xbp-18h]
  _QWORD *v33; // [xsp+10h] [xbp-10h]
  unsigned __int64 v34; // [xsp+18h] [xbp-8h]

  if ( !a1 )
    return -22;
  v4 = hfi_dbg;
  if ( !hfi_dbg )
  {
    v21 = &unk_26C2D0;
    goto LABEL_20;
  }
  v5 = *(_QWORD *)(*(_QWORD *)hfi_dbg + 152LL);
  if ( !v5 || (v6 = *(_QWORD *)(v5 + 56)) == 0 )
  {
    v21 = &unk_26C29E;
LABEL_20:
    printk(v21, "hfi_dbg_reg_base_reg_read");
    return -22;
  }
  v7 = *(_QWORD *)(a1 + 32);
  if ( v7 )
  {
    result = -22;
    if ( a2 && a4 )
    {
      v9 = *(unsigned int *)(hfi_dbg + 360);
      if ( *(_QWORD *)v7 <= v9 )
        return 0;
      if ( !(_DWORD)v9 )
      {
        v10 = a3;
        v11 = a2;
        v12 = a4;
        cmd_buf = hfi_adapter_get_cmd_buf(*(_QWORD *)(*(_QWORD *)(v6 + 8) + 6440LL) + 8LL);
        if ( !cmd_buf )
        {
          v21 = &unk_237EB0;
          goto LABEL_20;
        }
        v14 = (__int64)cmd_buf;
        v15 = _kmalloc_cache_noprof(wake_up_process, 3264, 32);
        *(_DWORD *)(v15 + 4) = *(_QWORD *)v7;
        v16 = hfi_dbg;
        *(_DWORD *)(v15 + 8) = 4 * *(_DWORD *)(v7 + 8);
        v17 = *(_QWORD *)(v16 + 40);
        if ( !v17 )
        {
          v21 = &unk_261DA7;
          goto LABEL_20;
        }
        *(_QWORD *)(v15 + 12) = v17;
        *(_DWORD *)(v15 + 20) = *(_DWORD *)(v16 + 56);
        *(_QWORD *)(v16 + 344) = hfi_dbg_reg_read_handler;
        property = hfi_adapter_add_get_property(v14, -16777203, 0, 2u, v15, 0x20u, v16 + 344, 2);
        if ( property )
        {
          v30 = property;
          printk(&unk_2314A6, "hfi_dbg_reg_base_reg_read");
          return v30;
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "hfi_dbg_reg_base_reg_read", 833, -1, 0, -16777203, 13107, -1059143953, v31);
        v19 = hfi_adapter_set_cmd_buf_blocking(v14);
        sde_evtlog_log(sde_dbg_base_evtlog, "hfi_dbg_reg_base_reg_read", 835, -1, 0, -16777203, v19, 17476, 239);
        if ( v19 )
        {
          printk(&unk_276A12, "hfi_dbg_reg_base_reg_read");
          return v19;
        }
        v4 = hfi_dbg;
        a4 = v12;
        a2 = v11;
        a3 = v10;
      }
      v20 = *(_QWORD *)(v4 + 48);
      if ( !v20 )
        return 0;
      v22 = 0;
      v34 = a3;
      v32 = a2;
      v33 = a4;
      v23 = *(_QWORD *)(v7 + 8) >> 2;
      if ( (v23 & 0x80000000) == 0 )
      {
        v24 = 0;
        v25 = (_DWORD *)(v20 + 8);
        do
        {
          v26 = *(_DWORD *)(v7 + 8) & 3;
          printk(&unk_26C34A, "hfi_dbg_reg_base_reg_read");
          if ( v24 < (int)v23 || v26 )
          {
            v27 = v22 + (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v22, 4096 - v22, "0x%08zx:", *(_QWORD *)v7);
            v22 = v27 + (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v27, 4096 - v27, " %08x", *(v25 - 2));
          }
          if ( v24 < (int)v23 || v26 >= 2 )
            v22 += (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v22, 4096 - v22, " %08x", *(v25 - 1));
          if ( v24 < (int)v23 || v26 == 3 )
            v22 += (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v22, 4096 - v22, " %08x", *v25);
          if ( v24 < (int)v23 )
            v22 += (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v22, 4096 - v22, " %08x", v25[1]);
          ++v24;
          v22 += (int)scnprintf(*(_QWORD *)(hfi_dbg + 368) + v22, 4096 - v22, "\n");
          v25 += 4;
        }
        while ( v24 <= (int)v23 );
        if ( v22 > v34 )
        {
          v21 = &unk_211FD5;
          goto LABEL_20;
        }
      }
      printk(&unk_22A889, "hfi_dbg_reg_base_reg_read");
      mutex_lock(hfi_dbg + 272);
      if ( v22 >> 31 )
      {
        __break(0x800u);
        v29 = -14;
      }
      else
      {
        v28 = *(_QWORD *)(hfi_dbg + 368);
        _check_object_size(v28, v22, 1);
        if ( inline_copy_to_user_0(v32, v28, v22) )
          v29 = -14;
        else
          v29 = v22;
      }
      mutex_unlock(hfi_dbg + 272);
      *v33 += v29;
      *(_DWORD *)(hfi_dbg + 360) = *(_QWORD *)v7;
      return v29;
    }
  }
  else
  {
    printk(&unk_21D21A, "hfi_dbg_reg_base_reg_read");
    return -19;
  }
  return result;
}
