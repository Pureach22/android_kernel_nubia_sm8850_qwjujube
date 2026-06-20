__int64 __fastcall hfi_core_dbg_lb_cmd_buf_wr(__int64 a1, int *a2, size_t a3)
{
  __int64 v3; // x30
  __int64 v4; // x22
  __int64 v5; // x8
  _QWORD *v6; // x23
  size_t v7; // x20
  size_t v9; // x24
  char *v10; // x19
  char *v11; // x0
  int v12; // w0
  char *v13; // x25
  unsigned __int64 v14; // x24
  char *v15; // x0
  unsigned __int64 v16; // x26
  __int64 v17; // x27
  int v18; // w0
  unsigned int v19; // w25
  int v20; // w25
  int v21; // w26
  int v22; // w8
  unsigned __int64 v23; // x1
  __int64 v24; // x3
  _QWORD *v25; // x27
  _QWORD *v26; // t1
  char v27; // w8
  __int64 v28; // x0
  void *v29; // x0
  __int64 v30; // x2
  __int64 v31; // x0
  _QWORD *v32; // x8
  _QWORD *v33; // x2
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v36; // x26
  unsigned __int64 v37; // x27
  __int64 (__fastcall *v38)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v39; // [xsp+8h] [xbp-28h]
  int v40; // [xsp+14h] [xbp-1Ch]
  int v41; // [xsp+18h] [xbp-18h] BYREF
  int v42; // [xsp+1Ch] [xbp-14h] BYREF
  char *stringp[2]; // [xsp+20h] [xbp-10h] BYREF

  v4 = v3;
  stringp[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  stringp[0] = nullptr;
  v42 = 0;
  v41 = 0;
  if ( !a1 || (v5 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    printk(&unk_1F30A, "hfi_core_dbg_lb_cmd_buf_wr", 1660, v3);
    result = -22;
    goto LABEL_68;
  }
  v6 = *(_QWORD **)(v5 + 792);
  if ( !v6 )
  {
    printk(&unk_1A52F, "hfi_core_dbg_lb_cmd_buf_wr", 1667, v3);
    result = -22;
    goto LABEL_68;
  }
  v7 = a3;
  v9 = a3 + 1;
  v10 = (char *)_kmalloc_noprof(a3 + 1, 3520);
  if ( !v10 )
  {
LABEL_59:
    result = -12;
    goto LABEL_68;
  }
  while ( 1 )
  {
    if ( v7 >> 31 )
    {
      __break(0x800u);
LABEL_56:
      printk(&unk_1EDD0, "hfi_core_dbg_lb_cmd_buf_wr", 1676, v4);
      LODWORD(v7) = -14;
      goto LABEL_67;
    }
    _check_object_size(v10, v7, 0);
    if ( inline_copy_from_user((__int64)v10, (unsigned __int64)a2, v7) )
      goto LABEL_56;
    if ( v9 >= v7 )
    {
      v10[v7] = 0;
      stringp[0] = v10;
      v11 = strsep(stringp, " ");
      v12 = kstrtouint(v11, 16, &v41);
      if ( v12 )
      {
        LODWORD(v7) = v12;
        printk(&unk_1A226, "hfi_core_dbg_lb_cmd_buf_wr", 1688, v4);
        goto LABEL_67;
      }
      v13 = strsep(stringp, " ");
      v14 = 4LL * (unsigned int)(v41 + 2);
      a2 = (int *)_kmalloc_noprof(v14, 3520);
      if ( !a2 )
      {
        printk(&unk_1F384, "hfi_core_dbg_lb_cmd_buf_wr", 1698, v4);
        LODWORD(v7) = -12;
        goto LABEL_67;
      }
      v15 = v13;
      if ( v13 )
      {
        v16 = 0;
        v17 = -4095;
        while ( 1 )
        {
          v18 = kstrtouint(v15, 16, &v42);
          if ( v18 )
          {
            LODWORD(v7) = v18;
            printk(&unk_1949C, "hfi_core_dbg_lb_cmd_buf_wr", 1706, v4);
            goto LABEL_66;
          }
          if ( v14 <= v16 )
            goto LABEL_58;
          a2[v16 / 4] = v42;
          if ( !v17 )
            break;
          v15 = strsep(stringp, " ");
          v16 += 4LL;
          ++v17;
          if ( !v15 )
          {
            v19 = v17 + 4095;
            goto LABEL_18;
          }
        }
        printk(&unk_1D009, "hfi_core_dbg_lb_cmd_buf_wr", 1713, v4);
        LODWORD(v7) = -14;
        goto LABEL_66;
      }
      v19 = 0;
LABEL_18:
      if ( (~msm_hfi_core_debug_level & 0x10004) != 0 )
      {
        if ( !v19 )
          goto LABEL_52;
      }
      else
      {
        printk(&unk_1BE2A, "hfi_core_dbg_lb_cmd_buf_wr", 1720, v19);
        if ( !v19 )
        {
LABEL_52:
          LODWORD(v7) = -14;
          goto LABEL_66;
        }
      }
      v20 = v41;
      if ( !v41 )
        goto LABEL_50;
      if ( v14 && v14 != 4 )
        break;
    }
LABEL_58:
    __break(1u);
    v9 = v7 + 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v36 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &hfi_core_dbg_lb_cmd_buf_wr__alloc_tag;
    v10 = (char *)_kmalloc_noprof(v7 + 1, 3520);
    *(_QWORD *)(StatusReg + 80) = v36;
    if ( !v10 )
      goto LABEL_59;
  }
  if ( a2 == (int *)-8LL )
  {
LABEL_50:
    printk(&unk_1905C, "hfi_core_create_lb_cmd_packets", 1603, v4);
    LODWORD(v7) = -22;
LABEL_65:
    printk(&unk_1DF18, "hfi_core_dbg_lb_cmd_buf_wr", 1733, v4);
    goto LABEL_66;
  }
  v21 = *a2;
  v40 = a2[1];
  v22 = 4 * v41;
  if ( v14 >= 8 )
    v23 = v14 - 8;
  else
    v23 = 0;
  if ( v23 < v22 )
  {
    _fortify_panic(28, v23, v22);
    v37 = _ReadStatusReg(SP_EL0);
    v38 = devm_free_irq;
    v39 = *(_QWORD *)(v37 + 80);
    *(_QWORD *)(v37 + 80) = &hfi_core_create_lb_cmd_packets__alloc_tag_162;
    v31 = _kmalloc_cache_noprof(v38, 3520, 40);
    *(_QWORD *)(v37 + 80) = v39;
    if ( v31 )
      goto LABEL_40;
LABEL_63:
    printk(&unk_1EA67, "hfi_core_create_lb_cmd_packets", 1626, v4);
    kfree(v14);
    goto LABEL_64;
  }
  v14 = kmemdup_noprof(a2 + 2, v22, 3264);
  if ( !v14 )
  {
    printk(&unk_1EE05, "hfi_core_create_lb_cmd_packets", 1612, v4);
LABEL_64:
    LODWORD(v7) = -12;
    goto LABEL_65;
  }
  v26 = (_QWORD *)v6[15];
  v6 += 15;
  v25 = v26;
  if ( v26 == v6 )
  {
LABEL_39:
    v31 = _kmalloc_cache_noprof(devm_free_irq, 3520, 40);
    if ( v31 )
    {
LABEL_40:
      *(_DWORD *)v31 = v21;
      *(_QWORD *)(v31 + 8) = v14;
      *(_DWORD *)(v31 + 16) = v20;
      *(_DWORD *)(v31 + 20) = v40;
      v32 = (_QWORD *)(v31 + 24);
      *(_QWORD *)(v31 + 24) = v31 + 24;
      *(_QWORD *)(v31 + 32) = v31 + 24;
      v33 = (_QWORD *)*v6;
      if ( *(_QWORD **)(*v6 + 8LL) != v6 || v32 == v6 || v33 == v32 )
      {
        _list_add_valid_or_report(v31 + 24, v6, v33);
      }
      else
      {
        v33[1] = v32;
        *(_QWORD *)(v31 + 24) = v33;
        *(_QWORD *)(v31 + 32) = v6;
        *v6 = v32;
      }
      if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
      {
        v29 = &unk_1D56A;
        v30 = 1637;
        goto LABEL_46;
      }
      goto LABEL_66;
    }
    goto LABEL_63;
  }
  v27 = 0;
  do
  {
    while ( v25 != &_ksymtab_hfi_core_cmds_rx_buf_get && *((_DWORD *)v25 - 6) == v21 )
    {
      v28 = *(v25 - 2);
      *(v25 - 2) = v14;
      *((_DWORD *)v25 - 2) = v20;
      *((_DWORD *)v25 - 1) = v40;
      kfree(v28);
      v25 = (_QWORD *)*v25;
      v27 = 1;
      if ( v25 == v6 )
        goto LABEL_37;
    }
    v25 = (_QWORD *)*v25;
  }
  while ( v25 != v6 );
  if ( (v27 & 1) == 0 )
    goto LABEL_39;
LABEL_37:
  if ( (~msm_hfi_core_debug_level & 0x10004) == 0 )
  {
    v29 = &unk_1BE63;
    v30 = 1620;
LABEL_46:
    printk(v29, "hfi_core_create_lb_cmd_packets", v30, v24);
  }
LABEL_66:
  kfree(a2);
LABEL_67:
  kfree(v10);
  result = (int)v7;
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
