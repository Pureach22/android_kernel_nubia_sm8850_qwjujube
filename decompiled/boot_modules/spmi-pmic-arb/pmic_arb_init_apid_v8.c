__int64 __fastcall pmic_arb_init_apid_v8(__int64 *a1, unsigned int a2)
{
  __int64 v4; // x21
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x2
  __int64 v8; // x22
  unsigned __int16 v9; // w23
  __int64 result; // x0
  char *v11; // x24
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w0
  int v14; // w0
  int v15; // w21
  _DWORD *v16; // x8
  unsigned int *v17; // x0
  int v18; // w8
  __int64 v19; // x12
  char v20; // w9
  __int64 v21; // x10
  int v22; // w9
  int v23; // w11
  __int64 v24; // x9
  __int64 v25; // x0
  const char *v26; // x1

  if ( a2 >= 4 )
  {
    v25 = a1[5];
    v26 = "Unsupported bus index %d detected\n";
LABEL_29:
    v7 = a2;
LABEL_31:
    dev_err(v25, v26, v7);
    return 4294967274LL;
  }
  v4 = *a1;
  *((_WORD *)a1 + 26) = 0;
  *((_DWORD *)a1 + 14) = 0;
  v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24) + 4LL)) & 0x1FFF;
  *((_DWORD *)a1 + 14) = v5;
  if ( a2 )
  {
    *((_WORD *)a1 + 26) += v5;
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24) + 8LL)) & 0x1FFF;
    *((_DWORD *)a1 + 14) = v5;
    if ( a2 != 1 )
    {
      *((_WORD *)a1 + 26) += v5;
      v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24) + 12LL)) & 0x1FFF;
      *((_DWORD *)a1 + 14) = v5;
      if ( a2 != 2 )
      {
        *((_WORD *)a1 + 26) += v5;
        v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(v4 + 24) + 16LL)) & 0x1FFF;
        *((_DWORD *)a1 + 14) = v5;
      }
    }
  }
  if ( !(_DWORD)v5 )
  {
    v25 = a1[5];
    v26 = "Bus %d not implemented\n";
    goto LABEL_29;
  }
  v6 = *((unsigned __int16 *)a1 + 26);
  v7 = (unsigned int)(v5 + v6);
  if ( (int)v7 > *(_DWORD *)(v4 + 64) )
  {
    v25 = a1[5];
    v26 = "Unsupported max APID %d detected\n";
    goto LABEL_31;
  }
  v8 = *a1;
  *((_WORD *)a1 + 81) = 0;
  v9 = v6 + v5;
  result = 0;
  *((_WORD *)a1 + 80) = *(_WORD *)(v8 + 64) - 1;
  if ( (unsigned int)v6 < (unsigned __int16)(v6 + v5) )
  {
    v11 = (char *)(a1[19] + 4 * v6 + 3);
    do
    {
      v12 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v8 + 56) + 96LL);
      if ( *((_DWORD *)v12 - 1) != 932471953 )
        __break(0x8228u);
      v13 = v12((unsigned int)v6);
      v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(v8 + 40) + v13));
      if ( v14 )
      {
        v15 = v14;
        v16 = *(_DWORD **)(*(_QWORD *)(v8 + 56) + 104LL);
        if ( *(v16 - 1) != -395291818 )
          __break(0x8228u);
        v17 = (unsigned int *)((__int64 (__fastcall *)(__int64 *, _QWORD))v16)(a1, (unsigned int)v6);
        v18 = readl_relaxed(v17) & 7;
        v19 = v15 & 0x1FFF;
        if ( v15 >= 0 )
          v20 = -1;
        else
          v20 = v18;
        *(v11 - 1) = v18;
        *v11 = v20;
        v21 = a1[17];
        v22 = *(__int16 *)(v21 + 2 * v19);
        if ( (v22 & 0x80000000) == 0 || (v23 = *(unsigned __int8 *)(v8 + 49), v18 == v23) )
        {
          *(_WORD *)(v21 + 2 * v19) = v6 | 0x8000;
        }
        else if ( v15 < 0 )
        {
          v24 = a1[19] + 4LL * (v22 & 0x7FFF);
          if ( *(unsigned __int8 *)(v24 + 2) == v23 )
            *(_BYTE *)(v24 + 3) = v18;
        }
        *(_WORD *)(v11 - 3) = v15 & 0x1FFF;
        *((_WORD *)a1 + 72) = v6;
      }
      LODWORD(v6) = v6 + 1;
      v11 += 4;
    }
    while ( (unsigned __int16)v6 < (unsigned int)v9 );
    return 0;
  }
  return result;
}
