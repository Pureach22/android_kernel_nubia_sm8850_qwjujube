__int64 __fastcall populate_l3_table(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  unsigned int matched; // w8
  unsigned int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x21
  _DWORD *v10; // x22
  unsigned int v11; // w0
  __int64 v12; // x26
  __int64 v13; // x27
  unsigned int v14; // w0
  __int64 v15; // x8
  unsigned int v16; // w23
  __int64 v17; // x0
  __int64 v18; // x9
  const char *v19; // x1
  __int64 v20; // x0
  __int64 v21; // x2
  int v23; // [xsp+4h] [xbp-6Ch] BYREF
  _QWORD v24[13]; // [xsp+8h] [xbp-68h] BYREF

  v24[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 744);
  memset(v24, 0, 96);
  v23 = 0;
  matched = of_property_match_string(v4, "reg-names", "l3tbl-base");
  if ( (matched & 0x80000000) != 0 )
  {
    v19 = "Unable to find l3tbl-base: %d\n";
    v20 = a1;
    v21 = matched;
LABEL_23:
    dev_err(v20, v19, v21);
    v16 = -22;
    goto LABEL_27;
  }
  v6 = of_address_to_resource(*(_QWORD *)(a1 + 744), matched, v24);
  if ( (v6 & 0x80000000) != 0 )
  {
    v21 = v6;
    v19 = "Unable to get resource from address: %d\n";
    v20 = a1;
    goto LABEL_23;
  }
  v7 = ioremap_prot();
  if ( !v7 )
  {
    dev_err(a1, "Unable to map l3tbl-base!\n", v8);
LABEL_26:
    v16 = -12;
    goto LABEL_27;
  }
  v9 = v7;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,ftbl-row-size", &v23, 1, 0) & 0x80000000) != 0 )
    v23 = 4;
  v10 = (_DWORD *)_kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 160);
  if ( !v10 )
    goto LABEL_25;
  v11 = readl_relaxed(v9);
  v12 = 1;
  v13 = v11 >> 30 ? 19200000LL * (unsigned __int8)v11 : 300000000LL;
  *v10 = ((unsigned __int64)v13 * (unsigned __int128)0x4189374BC6A7F0uLL) >> 64;
  while ( 1 )
  {
    v14 = readl_relaxed(v9 + (unsigned int)(v23 * v12));
    v15 = 19200000LL * (unsigned __int8)v14;
    if ( !(v14 >> 30) )
      v15 = 300000000;
    if ( v13 == v15 )
      break;
    v13 = v15;
    v10[v12++] = ((unsigned __int64)v15 * (unsigned __int128)0x4189374BC6A7F0uLL) >> 64;
    if ( v12 == 40 )
    {
      v16 = 40;
      goto LABEL_17;
    }
  }
  v16 = v12;
LABEL_17:
  v17 = devm_kmalloc(a1, 4LL * v16, 3520);
  *a2 = v17;
  if ( !v17 )
  {
LABEL_25:
    iounmap(v9);
    goto LABEL_26;
  }
  v18 = 0;
  do
  {
    *(_DWORD *)(*a2 + v18 * 4) = v10[v18];
    ++v18;
  }
  while ( v16 != v18 );
  iounmap(v9);
  kfree(v10);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v16;
}
