__int64 __fastcall md_smem_remove_region(char *a1)
{
  __int64 v2; // x23
  unsigned __int64 v3; // x1
  size_t v4; // x2
  _DWORD *v5; // x19
  int v6; // w24
  unsigned __int64 v7; // x25
  int v8; // w27
  __int64 v9; // x22
  __int64 v10; // x21
  unsigned int v11; // w21
  int v12; // w28
  unsigned int v13; // w24
  const char *v14; // x23
  unsigned int v15; // w22
  int v16; // w0
  __int64 v17; // x8
  unsigned __int64 v18; // x1
  int *v19; // x8
  void *v20; // x0
  const void *v21; // x1
  __int64 v22; // x8
  __int64 v23; // x8
  int v24; // w10
  int v25; // w9
  __int64 v27; // x0
  unsigned int v28; // [xsp+0h] [xbp-10h]
  __int64 v29; // [xsp+8h] [xbp-8h]

  if ( !qword_1100E8 || *(_DWORD *)(qword_1100E8 + 4) != 1162756684 )
    return (unsigned int)-22;
  v2 = raw_spin_lock_irqsave(&mdt_lock);
  raw_write_lock(&mdt_remove_lock);
  v5 = (_DWORD *)qword_1100E8;
  if ( !qword_1100E8 || *(_DWORD *)(qword_1100E8 + 4) != 1162756684 )
  {
LABEL_32:
    v11 = -22;
LABEL_33:
    raw_write_unlock(&mdt_remove_lock);
    raw_spin_unlock_irqrestore(&mdt_lock, v2);
    return v11;
  }
  v6 = md_num_regions;
  if ( md_num_regions < 1 )
  {
LABEL_10:
    v11 = -2;
LABEL_29:
    printk_deferred("Not able to find the entry %s in table\n", a1);
    goto LABEL_33;
  }
  v7 = 0;
  v8 = 1;
  v9 = 202;
  v10 = 48LL * (unsigned int)md_num_regions;
  while ( 1 )
  {
    if ( !v9 )
      goto LABEL_35;
    if ( !strcmp((const char *)&minidump_table[v7 / 4 + 8], a1) )
      break;
    v7 += 48LL;
    ++v8;
    --v9;
    if ( v10 == v7 )
      goto LABEL_10;
  }
  v11 = v8 - 1;
  if ( v8 - 1 < 0 )
    goto LABEL_29;
  v12 = v5[4];
  if ( v12 < 1 )
  {
    v15 = -22;
LABEL_31:
    printk_deferred("Not able to find the region %s (%d,%d) in table\n", a1, v11, v15);
    goto LABEL_32;
  }
  v28 = v6;
  v29 = v2;
  v13 = 0;
  v14 = (const char *)qword_1100F8;
  v15 = -22;
  do
  {
    v16 = strcmp(v14, a1);
    v14 += 40;
    if ( !v16 )
      v15 = v13;
    ++v13;
  }
  while ( v12 != v13 );
  v2 = v29;
  if ( (v15 & 0x80000000) != 0 )
    goto LABEL_31;
  if ( first_removed_entry > (int)v11 )
    first_removed_entry = v8 - 1;
  *v5 = 0;
  if ( v11 >= 0xCA || v8 == 202 )
    goto LABEL_35;
  v4 = 48LL * (int)(v28 - v8);
  v3 = 9648 - v7;
  if ( 9648 - v7 < v4 )
  {
LABEL_36:
    _fortify_panic(19, v3, v4);
    goto LABEL_37;
  }
  if ( 9600 - v7 < v4 )
  {
LABEL_37:
    _fortify_panic(18, v3, v4);
    goto LABEL_38;
  }
  memmove(&minidump_table[v7 / 4 + 8], &minidump_table[v7 / 4 + 20], v4);
  if ( v28 > 0xCA )
  {
LABEL_35:
    __break(0x5512u);
    goto LABEL_36;
  }
  v17 = v28 - 1;
  v18 = -48 * v17 + 9648;
  if ( v18 > 0x2F )
  {
    v19 = &minidump_table[12 * (unsigned int)v17];
    v20 = (void *)(qword_1100F8 + 40LL * v15);
    v21 = (const void *)(qword_1100F8 + 40LL * (int)(v15 + 1));
    *((_QWORD *)v19 + 8) = 0;
    *((_QWORD *)v19 + 9) = 0;
    *((_QWORD *)v19 + 6) = 0;
    *((_QWORD *)v19 + 7) = 0;
    *((_QWORD *)v19 + 4) = 0;
    *((_QWORD *)v19 + 5) = 0;
    memmove(v20, v21, 40LL * (int)(v12 + ~v15));
    v22 = qword_1100F8 + 40LL * (unsigned int)v12;
    *(_QWORD *)(v22 - 40) = 0;
    *(_QWORD *)(v22 - 32) = 0;
    *(_QWORD *)(v22 - 24) = 0;
    *(_QWORD *)(v22 - 16) = 0;
    *(_QWORD *)(v22 - 8) = 0;
    v11 = msm_minidump_clear_headers(a1);
    if ( !v11 )
    {
      v23 = qword_1100E8;
      v24 = *(_DWORD *)(qword_1100E8 + 16);
      *(_DWORD *)qword_1100E8 = 1;
      v25 = md_num_regions;
      *(_DWORD *)(v23 + 16) = v24 - 1;
      md_num_regions = v25 - 1;
    }
    goto LABEL_33;
  }
LABEL_38:
  v27 = _fortify_panic(15, v18, 48);
  return md_smem_add_region(v27);
}
