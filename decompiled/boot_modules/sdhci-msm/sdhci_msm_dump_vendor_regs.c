__int64 __fastcall sdhci_msm_dump_vendor_regs(__int64 a1)
{
  __int64 v2; // x8
  unsigned int *v3; // x24
  __int64 v4; // x1
  __int64 v5; // x20
  unsigned __int8 (__fastcall *v6)(__int64, __int64); // x9
  __int64 v7; // x1
  __int64 v8; // x1
  int v9; // w8
  unsigned __int64 v10; // x22
  __int64 v11; // x1
  __int64 (__fastcall *v12)(__int64, __int64); // x8
  unsigned int v13; // w0
  unsigned int v14; // w21
  __int64 v15; // x1
  void (__fastcall *v16)(__int64, __int64); // x8
  __int64 v17; // x21
  __int64 v18; // x22
  _DWORD *v19; // x8
  __int64 v20; // x1
  __int64 v21; // x8
  __int64 v22; // x20
  __int64 v23; // x8
  __int64 v24; // x20
  __int64 v25; // x8
  __int64 v26; // x20
  __int64 v27; // x8
  __int64 v28; // x20
  __int64 v29; // x8
  __int64 v30; // x20
  __int64 v31; // x8
  unsigned int *v32; // x22
  __int64 v33; // x20
  __int64 v34; // x1
  void (__fastcall *v35)(__int64, __int64); // x8
  __int64 v36; // x1
  void (__fastcall *v37)(__int64, __int64); // x8
  __int64 v38; // x1
  void (__fastcall *v39)(__int64, __int64); // x8
  int v40; // w21
  int v41; // w27
  int v42; // w28
  int v43; // w8
  int v44; // w23
  int v45; // w0
  unsigned __int64 v46; // x20
  _QWORD *v47; // x22
  __int64 v48; // x8
  __int64 v49; // x1
  __int64 result; // x0
  bool v51; // cf
  __int64 v52; // [xsp+0h] [xbp-100h]
  _QWORD v53[31]; // [xsp+8h] [xbp-F8h] BYREF

  v53[29] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 72);
  v3 = *(unsigned int **)(a1 + 1624);
  v4 = *(_QWORD *)(v2 + 120);
  v52 = 0;
  memset(v53, 0, 232);
  if ( !v4 )
    v4 = *(_QWORD *)(v2 + 8);
  printk(&unk_FEA6, v4);
  v5 = *(_QWORD *)(a1 + 1552);
  if ( v5 )
  {
    v6 = **(unsigned __int8 (__fastcall ***)(__int64, __int64))(a1 + 1616);
    v7 = *(unsigned int *)(*(_QWORD *)(a1 + 1624) + 16LL);
    if ( *((_DWORD *)v6 - 1) != -1793813973 )
      __break(0x8229u);
    if ( v6(a1, v7) <= 0x48u )
      v9 = 72;
    else
      v9 = 0;
    if ( *(_BYTE *)(v5 + 62) )
      LODWORD(v10) = v9 | 0x900;
    else
      LODWORD(v10) = v9;
    printk(&unk_10212, v8);
    v11 = (unsigned int)(v10 + 336);
    v12 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v5 + 16LL);
    if ( v12 )
    {
LABEL_64:
      if ( *((_DWORD *)v12 - 1) != 1427797680 )
        __break(0x8228u);
      v13 = v12(v5, v11);
    }
    else
    {
      v13 = readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 8) + (unsigned int)v11));
    }
    v14 = v13;
    v15 = (unsigned int)(v10 + 340);
    v16 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v5 + 16LL);
    if ( v16 )
    {
      if ( *((_DWORD *)v16 - 1) != 1427797680 )
        __break(0x8228u);
      v16(v5, v15);
    }
    else
    {
      readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 8) + (unsigned int)v15));
    }
    printk(&unk_FCEB, v14);
    v17 = 0;
    v18 = (unsigned int)(v10 + 272);
    do
    {
      v19 = *(_DWORD **)(*(_QWORD *)v5 + 16LL);
      if ( v19 )
      {
        if ( *(v19 - 1) != 1427797680 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v19)(v5, (unsigned int)v18);
      }
      else
      {
        readl_relaxed((unsigned int *)(*(_QWORD *)(v5 + 8) + v18));
      }
      printk(&unk_FAD8, (unsigned int)v17++);
      v18 += 4;
    }
    while ( v17 != 16 );
    printk(&unk_FEE5, v20);
  }
  v21 = *(_QWORD *)(a1 + 72);
  v22 = *(_QWORD *)(v21 + 120);
  if ( !v22 )
    v22 = *(_QWORD *)(v21 + 8);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[1]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[3]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[2]));
  printk(&unk_10E92, v22);
  v23 = *(_QWORD *)(a1 + 72);
  v24 = *(_QWORD *)(v23 + 120);
  if ( !v24 )
    v24 = *(_QWORD *)(v23 + 8);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[16]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[15]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[25]));
  printk(&unk_10EDA, v24);
  v25 = *(_QWORD *)(a1 + 72);
  v26 = *(_QWORD *)(v25 + 120);
  if ( !v26 )
    v26 = *(_QWORD *)(v25 + 8);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[26]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[29]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[28]));
  printk(&unk_FBA4, v26);
  v27 = *(_QWORD *)(a1 + 72);
  v28 = *(_QWORD *)(v27 + 120);
  if ( !v28 )
    v28 = *(_QWORD *)(v27 + 8);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[4]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[18]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[19]));
  printk(&unk_1034E, v28);
  v29 = *(_QWORD *)(a1 + 72);
  v30 = *(_QWORD *)(v29 + 120);
  if ( !v30 )
    v30 = *(_QWORD *)(v29 + 8);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[17]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[20]));
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[24]));
  printk(&unk_10A03, v30);
  v31 = *(_QWORD *)(a1 + 72);
  v32 = *(unsigned int **)(a1 + 1624);
  v33 = *(_QWORD *)(v31 + 120);
  if ( !v33 )
    v33 = *(_QWORD *)(v31 + 8);
  v34 = v32[10];
  v35 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v35 - 1) != -1793813973 )
    __break(0x8228u);
  v35(a1, v34);
  v36 = v32[11];
  v37 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v37 - 1) != -1793813973 )
    __break(0x8228u);
  v37(a1, v36);
  v38 = v32[13];
  v39 = **(void (__fastcall ***)(__int64, __int64))(a1 + 1616);
  if ( *((_DWORD *)v39 - 1) != -1793813973 )
    __break(0x8228u);
  v39(a1, v38);
  printk(&unk_FB5C, v33);
  v5 = 0;
  v40 = 0;
  do
  {
    if ( v40 <= 59 )
    {
      v10 = 4LL * (unsigned int)v40;
      v41 = 0;
      if ( (unsigned int)v40 <= 0x3C )
        v42 = 60 - v40;
      else
        v42 = 0;
      if ( (unsigned int)(59 - v40) >= 7 )
        v43 = 7;
      else
        v43 = 59 - v40;
      v44 = v43 + 1;
      while ( 1 )
      {
        writel_relaxed(v3[8] | v41 | ((_DWORD)v5 << v3[7]), (unsigned int *)(*(_QWORD *)(a1 + 24) + v3[6]));
        v45 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + v3[14]));
        if ( v42 == v41 )
          break;
        if ( v10 > 0xEF )
        {
          __break(1u);
          break;
        }
        ++v41;
        *(_DWORD *)((char *)&v53[-1] + v10) = v45;
        v10 += 4LL;
        if ( v44 == v41 )
        {
          v40 += v41;
          goto LABEL_43;
        }
      }
      __break(0x5512u);
      goto LABEL_64;
    }
LABEL_43:
    v5 = (unsigned int)(v5 + 1);
  }
  while ( (_DWORD)v5 != 7 );
  v46 = 0;
  v47 = v53;
  do
  {
    v48 = *(_QWORD *)(a1 + 72);
    v49 = *(_QWORD *)(v48 + 120);
    if ( !v49 )
      v49 = *(_QWORD *)(v48 + 8);
    v47 += 2;
    result = printk(&unk_10D98, v49);
    v51 = v46 >= 0x38;
    v46 += 4LL;
  }
  while ( !v51 );
  *(_BYTE *)(a1 + 2168) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
