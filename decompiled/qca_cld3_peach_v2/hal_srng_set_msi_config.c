__int64 __fastcall hal_srng_set_msi_config(__int64 a1, __int64 a2)
{
  int v3; // w10
  __int64 v4; // x8
  __int64 v5; // x2
  __int64 v6; // x0
  int v7; // w11
  __int64 v8; // x1
  int v9; // w8
  __int64 v10; // x2
  __int64 v11; // x1
  double v12; // d0
  __int64 v13; // x1
  double v14; // d0
  __int64 v15; // x0
  __int64 v16; // x0
  int v17; // w8
  __int64 v18; // x1
  double v19; // d0
  __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x1
  int v23; // w8
  __int64 v24; // x9
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x0
  int v28; // w8
  __int64 v29; // x1
  double v30; // d0
  __int64 v31; // x0
  __int64 v32; // x2
  __int64 v33; // x1
  int v34; // w8

  v3 = *(_DWORD *)(a1 + 116);
  *(_DWORD *)(a1 + 48) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a1 + 52) = *(_DWORD *)(a2 + 40);
  v4 = *(_QWORD *)(a1 + 96);
  v5 = *(_QWORD *)(a2 + 24);
  *(_QWORD *)(a1 + 64) = v5;
  v6 = *(_QWORD *)(a1 + 160);
  v7 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a1 + 72) = v7;
  if ( v5 || v7 )
  {
    if ( v3 )
    {
      v11 = v4 + *(int *)(v6 + 74288);
      if ( (*(_BYTE *)(v6 + 74224) & 1) != 0 )
        v12 = hal_write32_mb_1(v6, (const char *)(unsigned int)(v11 - *(_DWORD *)(v6 + 16)));
      else
        writel_7((unsigned int)v5, v11);
      v16 = *(_QWORD *)(a1 + 160);
      v17 = *(unsigned __int8 *)(a1 + 68);
      v18 = *(_QWORD *)(a1 + 96) + *(int *)(v16 + 74292);
      if ( (*(_BYTE *)(v16 + 74224) & 1) != 0 )
        v19 = hal_write32_mb_1(v16, (const char *)(unsigned int)(v18 - *(_DWORD *)(v16 + 16)), v17 | 0x100u, v12);
      else
        writel_7(v17 | 0x100u, v18);
      v20 = *(_QWORD *)(a1 + 160);
      v21 = *(unsigned int *)(a1 + 72);
      v22 = *(_QWORD *)(a1 + 96) + *(int *)(v20 + 74296);
      if ( (*(_BYTE *)(v20 + 74224) & 1) != 0 )
        hal_write32_mb_1(v20, (const char *)(unsigned int)(v22 - *(_DWORD *)(v20 + 16)), v21, v19);
      else
        writel_7((unsigned int)v21, v22);
      v23 = *(_DWORD *)(a1 + 52);
      v10 = (*(_DWORD *)(a1 + 48) << 13) & 0xFFFF0000;
      if ( v23 )
        v10 = ((unsigned __int16)*(_DWORD *)(a1 + 44) * (_WORD)v23) & 0x7FFF | (unsigned int)v10;
      v6 = *(_QWORD *)(a1 + 160);
      v24 = *(_QWORD *)(a1 + 96);
      v25 = v6 + 73728;
      v26 = *(int *)(v6 + 74324);
    }
    else
    {
      v13 = v4 + *(int *)(v6 + 74360);
      if ( (*(_BYTE *)(v6 + 74224) & 1) != 0 )
        v14 = hal_write32_mb_1(v6, (const char *)(unsigned int)(v13 - *(_DWORD *)(v6 + 16)));
      else
        writel_7((unsigned int)v5, v13);
      v27 = *(_QWORD *)(a1 + 160);
      v28 = *(unsigned __int8 *)(a1 + 68);
      v29 = *(_QWORD *)(a1 + 96) + *(int *)(v27 + 74364);
      if ( (*(_BYTE *)(v27 + 74224) & 1) != 0 )
        v30 = hal_write32_mb_1(v27, (const char *)(unsigned int)(v29 - *(_DWORD *)(v27 + 16)), v28 | 0x100u, v14);
      else
        writel_7(v28 | 0x100u, v29);
      v31 = *(_QWORD *)(a1 + 160);
      v32 = *(unsigned int *)(a1 + 72);
      v33 = *(_QWORD *)(a1 + 96) + *(int *)(v31 + 74368);
      if ( (*(_BYTE *)(v31 + 74224) & 1) != 0 )
        hal_write32_mb_1(v31, (const char *)(unsigned int)(v33 - *(_DWORD *)(v31 + 16)), v32, v30);
      else
        writel_7((unsigned int)v32, v33);
      v34 = *(_DWORD *)(a1 + 52);
      v10 = (unsigned int)(*(_DWORD *)(a1 + 48) << 16);
      if ( v34 )
        v10 = ((unsigned __int16)*(_DWORD *)(a1 + 44) * (_WORD)v34) & 0x7FFF | (unsigned int)v10;
      v6 = *(_QWORD *)(a1 + 160);
      v24 = *(_QWORD *)(a1 + 96);
      v25 = v6 + 73728;
      v26 = *(int *)(v6 + 74380);
    }
    v8 = v24 + v26;
    if ( (*(_BYTE *)(v25 + 496) & 1) != 0 )
    {
      v9 = *(_DWORD *)(v6 + 16);
      goto LABEL_35;
    }
    v15 = (unsigned int)v10;
LABEL_37:
    writel_7(v15, v8);
    return 0;
  }
  if ( !v3 )
  {
    v8 = v4 + *(int *)(v6 + 74364);
    if ( (*(_BYTE *)(v6 + 74224) & 1) != 0 )
      goto LABEL_5;
    goto LABEL_12;
  }
  v8 = v4 + *(int *)(v6 + 74292);
  if ( (*(_BYTE *)(v6 + 74224) & 1) == 0 )
  {
LABEL_12:
    v15 = 0;
    goto LABEL_37;
  }
LABEL_5:
  v9 = *(_DWORD *)(v6 + 16);
  v10 = 0;
LABEL_35:
  hal_write32_mb_1(v6, (const char *)(unsigned int)(v8 - v9), v10);
  return 0;
}
