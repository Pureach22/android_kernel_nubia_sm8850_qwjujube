__int64 __fastcall mmrm_sw_update_curr(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x11
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x11
  _DWORD *v7; // x12
  __int64 v8; // x11
  __int64 v9; // x10
  __int64 v10; // x9
  unsigned __int64 v11; // x13
  unsigned __int64 v12; // x14
  unsigned __int64 v13; // x15
  __int64 v14; // x2
  __int64 v15; // x7
  int v16; // w19
  unsigned __int64 v17; // x7
  unsigned __int64 v18; // x6
  unsigned __int64 v19; // x20
  bool v20; // cc
  unsigned __int64 v21; // x6
  unsigned __int64 v22; // x6
  int v23; // w7
  __int64 v24; // x19
  __int64 v25; // x7
  int v26; // w20
  unsigned __int64 v27; // x20
  int v28; // w20

  v2 = *(unsigned int *)(a1 + 16);
  if ( !(_DWORD)v2 )
    goto LABEL_20;
  v3 = 5 * v2;
  v4 = *(_QWORD *)a1;
  v5 = 0;
  v6 = 4 * v3;
  v7 = (_DWORD *)(*(_QWORD *)(a1 + 8) + 160LL);
  while ( *(_DWORD *)(a2 + 160) != *v7 )
  {
    v5 += 20;
    v7 += 180;
    if ( v6 == v5 )
      goto LABEL_20;
  }
  v8 = *(_QWORD *)(v4 + 72);
  if ( v8 + v5 )
  {
    v9 = v8 + v5;
    v10 = 0;
    v11 = *(_QWORD *)(a2 + 216);
    v12 = (*(_DWORD *)(v9 + 8) & 0xFFFF0000)
        + ((42949673 * (unsigned __int64)((100 * (unsigned __int16)*(_DWORD *)(v9 + 8)) & 0x7F0000)) >> 32);
    v13 = (*(_DWORD *)(v9 + 12) & 0xFFFF0000)
        + ((42949673 * (unsigned __int64)((100 * (unsigned __int16)*(_DWORD *)(v9 + 12)) & 0x7F0000)) >> 32);
    v14 = 328;
    do
    {
      v15 = *(_QWORD *)(v4 + 56) + 24 * v10;
      v16 = *(_DWORD *)(v15 + 12);
      v17 = ((*(_DWORD *)(v15 + 16) & 0xFFFF0000)
           + ((42949673 * (unsigned __int64)((100 * (unsigned __int16)*(_DWORD *)(v15 + 16)) & 0x7F0000)) >> 32))
          * v13;
      v18 = ((v16 & 0xFFFF0000) + ((42949673 * (unsigned __int64)((100 * (unsigned __int16)v16) & 0x7F0000)) >> 32))
          * (((*(_QWORD *)(a2 + 184 + 8 * v10) * v12) & 0xFFFFFFFFFFFF0000LL)
           / v11);
      v19 = HIDWORD(v18);
      v20 = (v18 & 0xFFFF0000) > 0x7FFE0000;
      v21 = (v18 & 0xFFFFFFFFFFFF0000LL) + v17;
      if ( v20 )
        LODWORD(v19) = v19 + 1;
      v22 = v21 & 0xFFFFFFFFFFFF0000LL;
      if ( (v17 & 0xFFFF0000) <= 0x7FFE0000 )
        v23 = HIDWORD(v17);
      else
        v23 = HIDWORD(v17) + 1;
      *(_DWORD *)(a2 + 292 + 4 * v10) = v23;
      v24 = 8;
      v25 = v14;
      *(_DWORD *)(a2 + 256 + 4 * v10) = v19;
      do
      {
        v26 = *(_DWORD *)(*(_QWORD *)(v4 + 56) + v24);
        v24 += 24;
        v27 = v22
            / ((v26 & 0xFFFF0000) + ((42949673 * (unsigned __int64)((100 * (unsigned __int16)v26) & 0x7F0000)) >> 32));
        if ( (unsigned __int16)v27 <= 0x7FFEuLL )
          v28 = v27 >> 16;
        else
          v28 = (v27 >> 16) + 1;
        *(_DWORD *)(a2 + v25) = v28;
        v25 += 4;
      }
      while ( v24 != 224 );
      ++v10;
      v14 += 36;
    }
    while ( v10 != 9 );
    mmrm_sw_print_client_data(a1, a2);
    return 0;
  }
  else
  {
LABEL_20:
    if ( (~msm_mmrm_debug & 0x10002) == 0 )
      printk(&unk_DC04, "high", "mmrm_sw_update_curr");
    return 4294967274LL;
  }
}
