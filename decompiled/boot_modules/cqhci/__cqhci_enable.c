__int64 __fastcall _cqhci_enable(unsigned int *a1)
{
  __int64 v1; // x20
  __int64 (*v3)(void); // x8
  unsigned int v4; // w21
  _DWORD *v5; // x8
  _DWORD *v6; // x8
  unsigned int v7; // w21
  unsigned int v8; // w0
  _DWORD *v9; // x8
  unsigned int v10; // w0
  _DWORD *v11; // x8
  unsigned int v12; // w0
  _DWORD *v13; // x8
  _DWORD *v14; // x8
  _DWORD *v15; // x8
  _DWORD *v16; // x8
  __int64 (__fastcall *v17)(unsigned int *, __int64); // x8
  _DWORD *v18; // x8
  void (__fastcall *v19)(_QWORD); // x8
  void (__fastcall *v20)(unsigned int *, __int64, __int64); // x8
  __int64 (__fastcall *v21)(unsigned int *, __int64, __int64); // x8
  __int64 result; // x0

  v1 = *((_QWORD *)a1 + 2);
  v3 = *(__int64 (**)(void))(*(_QWORD *)a1 + 16LL);
  if ( !v3 )
  {
    v4 = readl_relaxed((unsigned int *)(*((_QWORD *)a1 + 1) + 8LL));
    if ( (v4 & 1) == 0 )
      goto LABEL_5;
    goto LABEL_3;
  }
  if ( *((_DWORD *)v3 - 1) != 1427797680 )
    __break(0x8228u);
  v4 = v3();
  if ( (v4 & 1) != 0 )
  {
LABEL_3:
    v4 &= ~1u;
    v5 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
    if ( v5 )
    {
      if ( *(v5 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v5)(a1, v4, 8);
    }
    else
    {
      writel_relaxed(v4, (unsigned int *)(*((_QWORD *)a1 + 1) + 8LL));
    }
  }
LABEL_5:
  v6 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  v7 = (*(_DWORD *)(v1 + 1000) >> 12) & 0x1000
     | v4 & 0xFFFFEEFF
     | (*(_DWORD *)(v1 + 1000) >> 26) & 2
     | ((a1[12] & 1) << 8);
  if ( v6 )
  {
    if ( *(v6 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v6)(a1, v7, 8);
  }
  else
  {
    writel_relaxed(v7, (unsigned int *)(*((_QWORD *)a1 + 1) + 8LL));
  }
  v8 = a1[28];
  v9 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v9 )
  {
    if ( *(v9 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v9)(a1, v8, 32);
  }
  else
  {
    writel_relaxed(v8, (unsigned int *)(*((_QWORD *)a1 + 1) + 32LL));
  }
  v10 = a1[29];
  v11 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v11 )
  {
    if ( *(v11 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v11)(a1, v10, 36);
  }
  else
  {
    writel_relaxed(v10, (unsigned int *)(*((_QWORD *)a1 + 1) + 36LL));
  }
  v12 = a1[7];
  v13 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v13 )
  {
    if ( *(v13 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v13)(a1, v12, 68);
  }
  else
  {
    writel_relaxed(v12, (unsigned int *)(*((_QWORD *)a1 + 1) + 68LL));
  }
  v14 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v14 )
  {
    if ( *(v14 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v14)(a1, 0, 20);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(*((_QWORD *)a1 + 1) + 20LL));
  }
  v15 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v15 )
  {
    if ( *(v15 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v15)(a1, 0, 24);
  }
  else
  {
    writel_relaxed(0, (unsigned int *)(*((_QWORD *)a1 + 1) + 24LL));
  }
  v16 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
  if ( v16 )
  {
    if ( *(v16 - 1) != -1433747670 )
      __break(0x8228u);
    ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v16)(a1, v7 | 1, 8);
  }
  else
  {
    writel_relaxed(v7 | 1, (unsigned int *)(*((_QWORD *)a1 + 1) + 8LL));
  }
  v17 = *(__int64 (__fastcall **)(unsigned int *, __int64))(*(_QWORD *)a1 + 16LL);
  if ( !v17 )
  {
    if ( (readl_relaxed((unsigned int *)(*((_QWORD *)a1 + 1) + 12LL)) & 1) == 0 )
      goto LABEL_23;
    goto LABEL_21;
  }
  if ( *((_DWORD *)v17 - 1) != 1427797680 )
    __break(0x8228u);
  if ( (v17(a1, 12) & 1) != 0 )
  {
LABEL_21:
    v18 = *(_DWORD **)(*(_QWORD *)a1 + 8LL);
    if ( v18 )
    {
      if ( *(v18 - 1) != -1433747670 )
        __break(0x8228u);
      ((void (__fastcall *)(unsigned int *, _QWORD, __int64))v18)(a1, 0, 12);
    }
    else
    {
      writel_relaxed(0, (unsigned int *)(*((_QWORD *)a1 + 1) + 12LL));
    }
  }
LABEL_23:
  *(_BYTE *)(v1 + 1477) = 1;
  v19 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)a1 + 24LL);
  if ( v19 )
  {
    if ( *((_DWORD *)v19 - 1) != -452870896 )
      __break(0x8228u);
    v19(v1);
  }
  __dsb(0xEu);
  v20 = *(void (__fastcall **)(unsigned int *, __int64, __int64))(*(_QWORD *)a1 + 8LL);
  if ( v20 )
  {
    if ( *((_DWORD *)v20 - 1) != -1433747670 )
      __break(0x8228u);
    v20(a1, 54, 20);
  }
  else
  {
    writel_relaxed(0x36u, (unsigned int *)(*((_QWORD *)a1 + 1) + 20LL));
  }
  v21 = *(__int64 (__fastcall **)(unsigned int *, __int64, __int64))(*(_QWORD *)a1 + 8LL);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -1433747670 )
      __break(0x8228u);
    result = v21(a1, 54, 24);
  }
  else
  {
    result = writel_relaxed(0x36u, (unsigned int *)(*((_QWORD *)a1 + 1) + 24LL));
  }
  *((_BYTE *)a1 + 59) = 1;
  return result;
}
