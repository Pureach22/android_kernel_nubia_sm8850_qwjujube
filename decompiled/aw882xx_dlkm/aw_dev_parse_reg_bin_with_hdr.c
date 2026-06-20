__int64 __fastcall aw_dev_parse_reg_bin_with_hdr(__int64 a1, char *a2, unsigned int a3, __int64 a4)
{
  __int64 *v4; // x9
  __int64 v9; // x8
  unsigned __int64 v10; // x24
  _DWORD *v11; // x20
  unsigned int v12; // w0
  char *v13; // x8
  __int64 *v15; // x8
  unsigned int v16; // w19
  __int64 v17; // x1
  void *v18; // x0
  __int64 *v19; // x8
  __int64 *v20; // x8
  __int64 v21; // x1
  unsigned __int64 StatusReg; // x25
  __int64 v23; // x26

  v4 = *(__int64 **)(a1 + 112);
  v9 = v4[14];
  if ( !v9 )
    v9 = *v4;
  printk(&unk_2880A, v9, "aw_dev_parse_reg_bin_with_hdr");
  v10 = a3;
  v11 = (_DWORD *)_kmalloc_noprof(a3 + 7224LL, 3520);
  if ( !v11 )
    return 4294967284LL;
  while ( 1 )
  {
    v11[1805] = a3;
    if ( v10 >= a3 )
      break;
    _fortify_panic(17);
    StatusReg = _ReadStatusReg(SP_EL0);
    v23 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &aw_dev_parse_reg_bin_with_hdr__alloc_tag;
    v10 = a3;
    v11 = (_DWORD *)_kmalloc_noprof(a3 + 7224LL, 3520);
    *(_QWORD *)(StatusReg + 80) = v23;
    if ( !v11 )
      return 4294967284LL;
  }
  memcpy(v11 + 1806, a2, a3);
  v12 = ((__int64 (__fastcall *)(_DWORD *))aw_parsing_bin_file)(v11);
  if ( (v12 & 0x80000000) != 0 )
  {
    v19 = *(__int64 **)(a1 + 112);
    v16 = v12;
    v17 = v19[14];
    if ( !v17 )
      v17 = *v19;
    v18 = &unk_28830;
    goto LABEL_16;
  }
  if ( v11[2] != 1 || v11[8] )
  {
    v15 = *(__int64 **)(a1 + 112);
    v16 = v12;
    v17 = v15[14];
    if ( !v17 )
      v17 = *v15;
    v18 = &unk_2518A;
LABEL_16:
    printk(v18, v17, "aw_dev_parse_reg_bin_with_hdr");
    kfree(v11);
    return v16;
  }
  if ( (v11[17] & 3) != 0 )
  {
    v20 = *(__int64 **)(a1 + 112);
    v21 = v20[14];
    if ( !v21 )
      v21 = *v20;
    printk(&unk_26FE8, v21, "aw_dev_parse_reg_bin_with_hdr");
    return 4294967274LL;
  }
  else
  {
    v13 = &a2[v11[18]];
    *(_DWORD *)(a4 + 16) = v11[17];
    *(_QWORD *)(a4 + 24) = v13;
    *(_DWORD *)a4 = 1;
    kfree(v11);
    return 0;
  }
}
