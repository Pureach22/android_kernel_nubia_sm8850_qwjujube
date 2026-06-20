__int64 __fastcall sdhci_msm_registers_restore(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  unsigned int *v3; // x24
  unsigned int v4; // w25
  int v5; // w26
  _QWORD *v6; // x20
  __int64 v7; // x0
  _DWORD *v8; // x8
  __int64 v9; // x0
  _DWORD *v10; // x8
  __int64 v11; // x0
  _DWORD *v12; // x8
  __int64 v13; // x0
  _DWORD *v14; // x8
  __int64 v15; // x0
  _DWORD *v16; // x8
  __int64 v17; // x0
  _DWORD *v18; // x8
  __int64 v19; // x0
  _DWORD *v20; // x8
  __int64 (__fastcall **v21)(__int64, __int64); // x8
  __int64 v22; // x1
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  char v24; // w0
  __int64 v25; // x22
  unsigned int v26; // w21
  int v27; // w23
  __int64 v29; // x2
  _DWORD *v30; // x8
  __int64 v31; // x1
  unsigned int (__fastcall *v32)(__int64, __int64); // x8
  int v33; // w9
  _DWORD *v34; // x8
  bool v35; // zf
  __int64 v36; // x8
  __int64 v37; // x1
  __int64 v38; // x8
  unsigned int *v39; // x23
  __int64 v40; // x21
  __int64 v41; // x1
  void (__fastcall *v42)(__int64, __int64); // x8
  __int64 v43; // x1
  void (__fastcall *v44)(__int64, __int64); // x8
  __int64 v45; // x1
  void (__fastcall *v46)(__int64, __int64); // x8

  v1 = *(_QWORD *)(result + 72);
  v2 = result;
  v3 = *(unsigned int **)(result + 1624);
  v4 = *(_DWORD *)(v1 + 1040);
  v5 = *(unsigned __int8 *)(v1 + 1056);
  v6 = *(_QWORD **)(v1 + 1464);
  if ( *(_BYTE *)(result + 2040) == 1 && (*(_BYTE *)(result + 2041) & 1) != 0 || *(_BYTE *)(result + 2009) == 1 )
  {
    writel_relaxed(0, (unsigned int *)(*(_QWORD *)(result + 24) + v3[11]));
    writel_relaxed(*(_DWORD *)(v2 + 2056), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[17]));
    writel_relaxed(*(_DWORD *)(v2 + 2060), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[20]));
    writel_relaxed(*(_DWORD *)(v2 + 2064), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[24]));
    v7 = *(unsigned int *)(v2 + 2068);
    v8 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v8 )
    {
      if ( *(v8 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v8)(v2, (unsigned int)v7, 44);
    }
    else
    {
      writel(v7, *(_QWORD *)(v2 + 24) + 44LL);
    }
    v9 = *(unsigned int *)(v2 + 2084);
    v10 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v10 )
    {
      if ( *(v10 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v10)(v2, (unsigned int)v9, 60);
    }
    else
    {
      writel(v9, *(_QWORD *)(v2 + 24) + 60LL);
    }
    v11 = *(unsigned int *)(v2 + 2080);
    v12 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v12 )
    {
      if ( *(v12 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v12)(v2, (unsigned int)v11, 56);
    }
    else
    {
      writel(v11, *(_QWORD *)(v2 + 24) + 56LL);
    }
    v13 = *(unsigned int *)(v2 + 2076);
    v14 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v14 )
    {
      if ( *(v14 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v14)(v2, (unsigned int)v13, 52);
    }
    else
    {
      writel(v13, *(_QWORD *)(v2 + 24) + 52LL);
    }
    v15 = *(unsigned int *)(v2 + 2072);
    v16 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v16 )
    {
      if ( *(v16 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v16)(v2, (unsigned int)v15, 40);
    }
    else
    {
      writel(v15, *(_QWORD *)(v2 + 24) + 40LL);
    }
    v17 = *(unsigned int *)(v2 + 2112);
    v18 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v18 )
    {
      if ( *(v18 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v18)(v2, (unsigned int)v17, 608);
    }
    else
    {
      writel(v17, *(_QWORD *)(v2 + 24) + 608LL);
    }
    writel_relaxed(*(_DWORD *)(v2 + 2052), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[21]));
    v19 = *(unsigned int *)(v2 + 2088);
    v20 = *(_DWORD **)(*(_QWORD *)(v2 + 64) + 24LL);
    if ( v20 )
    {
      if ( *(v20 - 1) != 1259614694 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD, __int64))v20)(v2, (unsigned int)v19, 68);
    }
    else
    {
      writel(v19, *(_QWORD *)(v2 + 24) + 68LL);
    }
    writel_relaxed(*(_DWORD *)(v2 + 2092), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[6]));
    v21 = *(__int64 (__fastcall ***)(__int64, __int64))(v2 + 1616);
    *(_BYTE *)(v2 + 2041) = 0;
    v22 = v3[10];
    v23 = *v21;
    if ( *((_DWORD *)v23 - 1) != -1793813973 )
      __break(0x8228u);
    v24 = v23(v2, v22);
    v25 = *(_QWORD *)(v2 + 1624);
    v26 = v24 & 0xF;
    v27 = -11;
    while ( !__CFADD__(v27++, 1) )
    {
      v29 = *(unsigned int *)(v25 + 48);
      v30 = *(_DWORD **)(*(_QWORD *)(v2 + 1616) + 8LL);
      if ( *(v30 - 1) != 1443578770 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD, __int64, __int64))v30)(v26, v2, v29);
      __dsb(0xFu);
      _const_udelay(42950);
      v31 = *(unsigned int *)(v25 + 40);
      v32 = **(unsigned int (__fastcall ***)(__int64, __int64))(v2 + 1616);
      if ( *((_DWORD *)v32 - 1) != -1793813973 )
        __break(0x8228u);
      if ( (v32(v2, v31) & v26) == 0 )
        goto LABEL_27;
    }
    v36 = *(_QWORD *)(v2 + 72);
    v37 = *(_QWORD *)(v36 + 120);
    if ( !v37 )
      v37 = *(_QWORD *)(v36 + 8);
    printk(&unk_105AA, v37);
    v38 = *(_QWORD *)(v2 + 72);
    v39 = *(unsigned int **)(v2 + 1624);
    v40 = *(_QWORD *)(v38 + 120);
    if ( !v40 )
      v40 = *(_QWORD *)(v38 + 8);
    v41 = v39[10];
    v42 = **(void (__fastcall ***)(__int64, __int64))(v2 + 1616);
    if ( *((_DWORD *)v42 - 1) != -1793813973 )
      __break(0x8228u);
    v42(v2, v41);
    v43 = v39[11];
    v44 = **(void (__fastcall ***)(__int64, __int64))(v2 + 1616);
    if ( *((_DWORD *)v44 - 1) != -1793813973 )
      __break(0x8228u);
    v44(v2, v43);
    v45 = v39[13];
    v46 = **(void (__fastcall ***)(__int64, __int64))(v2 + 1616);
    if ( *((_DWORD *)v46 - 1) != -1793813973 )
      __break(0x8228u);
    v46(v2, v45);
    printk(&unk_FB5C, v40);
    __break(0x800u);
LABEL_27:
    writel_relaxed(*(_DWORD *)(v2 + 2048), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[13]));
    writel_relaxed(*(_DWORD *)(v2 + 2044), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[11]));
    if ( v6 )
    {
      v33 = *(_DWORD *)(v2 + 2116);
      v34 = *(_DWORD **)(*v6 + 8LL);
      if ( v34 )
      {
        if ( *(v34 - 1) != -1433747670 )
          __break(0x8228u);
        ((void (__fastcall *)(_QWORD *, _QWORD, __int64))v34)(v6, v33 & 0x7FFFFFFF, 2560);
        if ( v5 != 5 )
          goto LABEL_32;
        goto LABEL_31;
      }
      writel_relaxed(v33 & 0x7FFFFFFF, (unsigned int *)(v6[1] + 2560LL));
    }
    if ( v5 != 5 )
      goto LABEL_32;
LABEL_31:
    if ( (*(_BYTE *)(v2 + 796) & 0x10) != 0 )
    {
LABEL_38:
      writel_relaxed(*(_DWORD *)(v2 + 2100), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[25]));
      writel_relaxed(*(_DWORD *)(v2 + 2104), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[26]));
      writel_relaxed(*(_DWORD *)(v2 + 2108), (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[29]));
      writel_relaxed(*(_DWORD *)(v2 + 2096) & 0x9FFFFFFF, (unsigned int *)(*(_QWORD *)(v2 + 24) + v3[15]));
      msm_init_cm_dll(v2, 1);
      msm_config_cm_dll_phase((_QWORD *)v2, *(_BYTE *)(v2 + 1563));
LABEL_39:
      result = *(_QWORD *)(v2 + 2160);
      if ( result )
      {
        if ( *(_BYTE *)(v2 + 2168) == 1 )
          return ipc_log_string(result, "%s: Registers restored\n", "sdhci_msm_registers_restore");
      }
      return result;
    }
LABEL_32:
    v35 = (unsigned int)(v5 - 9) <= 1 || v5 == 6;
    if ( !v35 || v4 < 0x5F5E101 )
      goto LABEL_39;
    goto LABEL_38;
  }
  return result;
}
