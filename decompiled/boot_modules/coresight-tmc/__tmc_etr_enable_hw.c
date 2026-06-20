__int64 __fastcall _tmc_etr_enable_hw(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w19
  int v4; // w8
  int v5; // w9
  unsigned int v6; // w8
  __int64 v7; // x0
  __int64 v8; // x23
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x21
  __int64 v11; // x23
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x21
  __int64 v14; // x23
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x21
  int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v21; // x8
  __int64 v22; // x0
  _DWORD *v23; // x8
  _DWORD *v24; // x8
  __int64 v25; // x0
  _DWORD *v26; // x8
  _DWORD *v27; // x8
  __int64 v28; // x0
  _DWORD *v29; // x8

  v2 = *(_QWORD *)(a1 + 120);
  writel_relaxed_1(3316436565LL, *(_QWORD *)(a1 + 8) + 4016LL);
  __dsb(0xFu);
  v3 = tmc_wait_for_tmcready(a1);
  if ( v3 )
  {
    dev_err(*(_QWORD *)(a1 + 16) + 56LL, "Failed to enable : TMC not ready\n");
    v19 = *(_QWORD *)(a1 + 8);
    __dsb(0xFu);
    goto LABEL_19;
  }
  writel_relaxed_1((*(_QWORD *)(v2 + 16) + (*(__int64 *)(v2 + 16) < 0 ? 3uLL : 0)) >> 2, *(_QWORD *)(a1 + 8) + 4LL);
  writel_relaxed_1(0, *(_QWORD *)(a1 + 8) + 40LL);
  v4 = readl_relaxed_1(*(_QWORD *)(a1 + 8) + 272LL) & 0xFFFFF040 | ((*(_DWORD *)(a1 + 136) & 0xF) << 8);
  if ( (*(_DWORD *)(a1 + 204) & 2) != 0 )
    v5 = 983102;
  else
    v5 = 62;
  v6 = v4 | v5;
  if ( *(_DWORD *)(v2 + 4) == 1 )
    v7 = v6 | 0x80;
  else
    v7 = v6;
  writel_relaxed_1(v7, *(_QWORD *)(a1 + 8) + 272LL);
  v8 = *(_QWORD *)(a1 + 16);
  v9 = *(_QWORD *)(v2 + 24);
  v10 = HIDWORD(v9);
  if ( *(_BYTE *)(v8 + 32) != 1 )
  {
    v21 = *(_DWORD **)(v8 + 48);
    v22 = (unsigned int)*(_QWORD *)(v2 + 24);
    if ( *(v21 - 1) != -166272269 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v21)(v22, 280, 1, 0);
    v23 = *(_DWORD **)(v8 + 48);
    if ( *(v23 - 1) != -166272269 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned __int64, __int64, __int64, _QWORD))v23)(v10, 284, 1, 0);
    if ( (*(_BYTE *)(a1 + 204) & 4) == 0 )
      goto LABEL_15;
    goto LABEL_10;
  }
  writel_relaxed_1(v9, *(_QWORD *)(v8 + 40) + 280LL);
  writel_relaxed_1((unsigned int)v10, *(_QWORD *)(v8 + 40) + 284LL);
  if ( (*(_BYTE *)(a1 + 204) & 4) != 0 )
  {
LABEL_10:
    v11 = *(_QWORD *)(a1 + 16);
    v12 = *(_QWORD *)(v2 + 24);
    v13 = HIDWORD(v12);
    if ( *(_BYTE *)(v11 + 32) == 1 )
    {
      writel_relaxed_1(v12, *(_QWORD *)(v11 + 40) + 20LL);
      writel_relaxed_1((unsigned int)v13, *(_QWORD *)(v11 + 40) + 56LL);
    }
    else
    {
      v24 = *(_DWORD **)(v11 + 48);
      v25 = (unsigned int)*(_QWORD *)(v2 + 24);
      if ( *(v24 - 1) != -166272269 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v24)(v25, 20, 1, 0);
      v26 = *(_DWORD **)(v11 + 48);
      if ( *(v26 - 1) != -166272269 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned __int64, __int64, __int64, _QWORD))v26)(v13, 56, 1, 0);
    }
    v14 = *(_QWORD *)(a1 + 16);
    v15 = *(_QWORD *)(v2 + 24);
    v16 = HIDWORD(v15);
    if ( *(_BYTE *)(v14 + 32) == 1 )
    {
      writel_relaxed_1(v15, *(_QWORD *)(v14 + 40) + 24LL);
      writel_relaxed_1((unsigned int)v16, *(_QWORD *)(v14 + 40) + 60LL);
    }
    else
    {
      v27 = *(_DWORD **)(v14 + 48);
      v28 = (unsigned int)*(_QWORD *)(v2 + 24);
      if ( *(v27 - 1) != -166272269 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v27)(v28, 24, 1, 0);
      v29 = *(_DWORD **)(v14 + 48);
      if ( *(v29 - 1) != -166272269 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned __int64, __int64, __int64, _QWORD))v29)(v16, 60, 1, 0);
    }
    v17 = readl_relaxed_1(*(_QWORD *)(a1 + 8) + 12LL);
    writel_relaxed_1(v17 & 0xFFFFFFFE, *(_QWORD *)(a1 + 8) + 12LL);
  }
LABEL_15:
  if ( *(_BYTE *)(a1 + 344) )
    v18 = 4403;
  else
    v18 = 307;
  writel_relaxed_1(v18, *(_QWORD *)(a1 + 8) + 772LL);
  writel_relaxed_1(*(unsigned int *)(a1 + 200), *(_QWORD *)(a1 + 8) + 28LL);
  tmc_enable_hw(a1);
  v19 = *(_QWORD *)(a1 + 8);
  __dsb(0xFu);
LABEL_19:
  writel_relaxed_1(0, v19 + 4016);
  return v3;
}
