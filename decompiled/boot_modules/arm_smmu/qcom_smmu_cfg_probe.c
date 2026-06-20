__int64 __fastcall qcom_smmu_cfg_probe(__int64 a1)
{
  unsigned int v1; // w8
  int v3; // w9
  __int64 v4; // x8
  unsigned int v5; // w20
  _DWORD *v6; // x8
  _DWORD **v7; // x8
  _DWORD *v8; // x8
  __int64 v9; // x0
  char v10; // w8
  char v11; // w11
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x1
  _DWORD *v16; // x8
  __int64 v17; // x8
  __int64 v18; // x2
  void (__fastcall *v19)(__int64, __int64, __int64, __int64); // x8
  int v20; // w21
  int i; // w20
  _DWORD **v22; // x8
  _DWORD *v23; // x8
  int v24; // w0
  __int64 v25; // x9
  __int64 v26; // x8
  unsigned __int64 v34; // x10

  v1 = *(_DWORD *)(a1 + 92);
  if ( v1 >= 0x81 )
  {
    dev_notice(*(_QWORD *)a1, "\tLimiting the stream matching groups to 128\n");
    v1 = 128;
    *(_DWORD *)(a1 + 92) = 128;
  }
  v3 = 4 * v1;
  v4 = *(_QWORD *)(a1 + 48);
  v5 = v3 + 3068;
  if ( v4 && (v6 = *(_DWORD **)(v4 + 8)) != nullptr )
  {
    if ( *(v6 - 1) != -1008624849 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v6)(a1, 0, v5, 65791);
    v7 = *(_DWORD ***)(a1 + 48);
    if ( !v7 )
      goto LABEL_7;
  }
  else
  {
    writel_relaxed_1(0x100FFu, (unsigned int *)(*(_QWORD *)(a1 + 8) + v5));
    v7 = *(_DWORD ***)(a1 + 48);
    if ( !v7 )
    {
LABEL_7:
      v9 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 8) + v5));
      goto LABEL_8;
    }
  }
  v8 = *v7;
  if ( !v8 )
    goto LABEL_7;
  if ( *(v8 - 1) != 616069899 )
    __break(0x8228u);
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v8)(a1, 0, v5);
LABEL_8:
  if ( (v9 & 0x30000) != 0x10000 )
  {
    v10 = *(_BYTE *)(a1 + 56);
    *(_BYTE *)(a1 + 336) = 1;
    v11 = v10 - 1;
    v12 = (unsigned __int8)(v10 - 1) >> 6;
    v13 = 1LL << (v10 - 1);
    *(_BYTE *)(a1 + 337) = v11;
    _X9 = (unsigned __int64 *)(a1 + 64 + 8 * v12);
    __asm { PRFM            #0x11, [X9] }
    do
      v34 = __ldxr(_X9);
    while ( __stxr(v34 | v13, _X9) );
    v14 = *(_QWORD *)(a1 + 48);
    v15 = *(_DWORD *)(a1 + 24) + (unsigned int)*(unsigned __int8 *)(a1 + 337);
    if ( v14 && (v16 = *(_DWORD **)(v14 + 8)) != nullptr )
    {
      if ( *(v16 - 1) != -1008624849 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v16)(a1, v15, 0, 0);
    }
    else
    {
      writel_relaxed_1(0, (unsigned int *)(*(_QWORD *)(a1 + 8) + (int)((_DWORD)v15 << *(_DWORD *)(a1 + 28))));
    }
    v17 = *(_QWORD *)(a1 + 48);
    v18 = 4LL * *(unsigned __int8 *)(a1 + 337);
    if ( v17 )
    {
      v19 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v17 + 8);
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -1008624849 )
          __break(0x8228u);
        v19(a1, 1, v18, 0x10000);
        if ( *(_DWORD *)(a1 + 92) )
          goto LABEL_17;
        return 0;
      }
    }
    writel_relaxed_1(0x10000u, (unsigned int *)(*(_QWORD *)(a1 + 8) + (1 << *(_DWORD *)(a1 + 28)) + v18));
  }
  if ( *(_DWORD *)(a1 + 92) )
  {
LABEL_17:
    v20 = 0;
    for ( i = 2048; ; i += 4 )
    {
      v22 = *(_DWORD ***)(a1 + 48);
      if ( v22 )
      {
        v23 = *v22;
        if ( v23 )
          break;
      }
      v24 = readl_relaxed_1((unsigned int *)(*(_QWORD *)(a1 + 8) + i));
      if ( v24 < 0 )
        goto LABEL_22;
LABEL_18:
      if ( (unsigned int)++v20 >= *(_DWORD *)(a1 + 92) )
        return 0;
    }
    if ( *(v23 - 1) != 616069899 )
      __break(0x8228u);
    v24 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v23)(a1, 0, (unsigned int)i);
    if ( (v24 & 0x80000000) == 0 )
      goto LABEL_18;
LABEL_22:
    v25 = 8LL * v20;
    *(_WORD *)(*(_QWORD *)(a1 + 104) + v25 + 2) = v24;
    *(_WORD *)(*(_QWORD *)(a1 + 104) + v25) = HIWORD(v24) & 0x7FFF;
    *(_BYTE *)(*(_QWORD *)(a1 + 104) + v25 + 4) = 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 104) + v25 + 6) = 1;
    v26 = 24LL * v20;
    *(_QWORD *)(*(_QWORD *)(a1 + 112) + v26 + 12) = 1;
    *(_BYTE *)(*(_QWORD *)(a1 + 112) + v26 + 20) = -1;
    goto LABEL_18;
  }
  return 0;
}
