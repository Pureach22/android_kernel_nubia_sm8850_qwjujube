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
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w8
  __int64 v16; // x1
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x1
  int v20; // w8
  __int64 v21; // x9
  __int64 v22; // x8
  __int64 v23; // x10
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x1
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x1
  int v30; // w8

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
        hal_write32_mb_1(v6, (unsigned int)(v11 - *(_DWORD *)(v6 + 16)), v5);
      else
        writel_7((unsigned int)v5, v11);
      v14 = *(_QWORD *)(a1 + 160);
      v15 = *(unsigned __int8 *)(a1 + 68);
      v16 = *(_QWORD *)(a1 + 96) + *(int *)(v14 + 74292);
      if ( (*(_BYTE *)(v14 + 74224) & 1) != 0 )
        hal_write32_mb_1(v14, (unsigned int)(v16 - *(_DWORD *)(v14 + 16)), v15 | 0x100u);
      else
        writel_7(v15 | 0x100u, v16);
      v17 = *(_QWORD *)(a1 + 160);
      v18 = *(unsigned int *)(a1 + 72);
      v19 = *(_QWORD *)(a1 + 96) + *(int *)(v17 + 74296);
      if ( (*(_BYTE *)(v17 + 74224) & 1) != 0 )
        hal_write32_mb_1(v17, (unsigned int)(v19 - *(_DWORD *)(v17 + 16)), v18);
      else
        writel_7((unsigned int)v18, v19);
      v20 = *(_DWORD *)(a1 + 52);
      v10 = (*(_DWORD *)(a1 + 48) << 13) & 0xFFFF0000;
      if ( v20 )
        v10 = ((unsigned __int16)*(_DWORD *)(a1 + 44) * (_WORD)v20) & 0x7FFF | (unsigned int)v10;
      v6 = *(_QWORD *)(a1 + 160);
      v21 = *(_QWORD *)(a1 + 96);
      v22 = v6 + 73728;
      v23 = *(int *)(v6 + 74324);
    }
    else
    {
      v12 = v4 + *(int *)(v6 + 74360);
      if ( (*(_BYTE *)(v6 + 74224) & 1) != 0 )
        hal_write32_mb_1(v6, (unsigned int)(v12 - *(_DWORD *)(v6 + 16)), v5);
      else
        writel_7((unsigned int)v5, v12);
      v24 = *(_QWORD *)(a1 + 160);
      v25 = *(unsigned __int8 *)(a1 + 68);
      v26 = *(_QWORD *)(a1 + 96) + *(int *)(v24 + 74364);
      if ( (*(_BYTE *)(v24 + 74224) & 1) != 0 )
        hal_write32_mb_1(v24, (unsigned int)(v26 - *(_DWORD *)(v24 + 16)), v25 | 0x100u);
      else
        writel_7(v25 | 0x100u, v26);
      v27 = *(_QWORD *)(a1 + 160);
      v28 = *(unsigned int *)(a1 + 72);
      v29 = *(_QWORD *)(a1 + 96) + *(int *)(v27 + 74368);
      if ( (*(_BYTE *)(v27 + 74224) & 1) != 0 )
        hal_write32_mb_1(v27, (unsigned int)(v29 - *(_DWORD *)(v27 + 16)), v28);
      else
        writel_7((unsigned int)v28, v29);
      v30 = *(_DWORD *)(a1 + 52);
      v10 = (unsigned int)(*(_DWORD *)(a1 + 48) << 16);
      if ( v30 )
        v10 = ((unsigned __int16)*(_DWORD *)(a1 + 44) * (_WORD)v30) & 0x7FFF | (unsigned int)v10;
      v6 = *(_QWORD *)(a1 + 160);
      v21 = *(_QWORD *)(a1 + 96);
      v22 = v6 + 73728;
      v23 = *(int *)(v6 + 74380);
    }
    v8 = v21 + v23;
    if ( (*(_BYTE *)(v22 + 496) & 1) != 0 )
    {
      v9 = *(_DWORD *)(v6 + 16);
      goto LABEL_35;
    }
    v13 = (unsigned int)v10;
LABEL_37:
    writel_7(v13, v8);
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
    v13 = 0;
    goto LABEL_37;
  }
LABEL_5:
  v9 = *(_DWORD *)(v6 + 16);
  v10 = 0;
LABEL_35:
  hal_write32_mb_1(v6, (unsigned int)(v8 - v9), v10);
  return 0;
}
