__int64 __fastcall sdhci_msm_registers_save(__int64 result)
{
  __int64 v1; // x19
  unsigned int *v2; // x21
  _QWORD *v3; // x20
  int v4; // w0
  __int64 (__fastcall **v5)(__int64, __int64); // x8
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  int v7; // w0
  __int64 (__fastcall **v8)(__int64, __int64); // x8
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  int v10; // w0
  int v11; // w0
  __int64 (__fastcall **v12)(__int64, __int64); // x8
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  int v14; // w0
  __int64 (__fastcall **v15)(__int64, __int64); // x8
  __int64 (__fastcall *v16)(__int64, __int64); // x8
  int v17; // w0
  __int64 (__fastcall **v18)(__int64, __int64); // x8
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  int v20; // w0
  int v21; // w0
  __int64 (__fastcall **v22)(__int64, __int64); // x8
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  int v24; // w0
  __int64 (__fastcall **v25)(__int64, __int64); // x8
  __int64 (__fastcall *v26)(__int64, __int64); // x8
  int v27; // w0
  _DWORD *v28; // x8
  int v29; // w0

  v1 = result;
  v2 = *(unsigned int **)(result + 1624);
  v3 = *(_QWORD **)(*(_QWORD *)(result + 72) + 1464LL);
  if ( (*(_BYTE *)(result + 2040) & 1) != 0 || *(_BYTE *)(result + 2009) == 1 )
  {
    *(_DWORD *)(result + 2056) = readl_relaxed((unsigned int *)(*(_QWORD *)(result + 24) + v2[17]));
    *(_DWORD *)(v1 + 2044) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[11]));
    *(_DWORD *)(v1 + 2060) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[20]));
    v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[24]));
    v5 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2064) = v4;
    v6 = *v5;
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != 1381278590 )
        __break(0x8228u);
      v7 = v6(v1, 44);
    }
    else
    {
      v7 = readl(*(_QWORD *)(v1 + 24) + 44LL);
    }
    v8 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2068) = v7;
    v9 = *v8;
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != 1381278590 )
        __break(0x8228u);
      v10 = v9(v1, 60);
    }
    else
    {
      v10 = readl(*(_QWORD *)(v1 + 24) + 60LL);
    }
    *(_DWORD *)(v1 + 2084) = v10;
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[13]));
    v12 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2048) = v11;
    v13 = *v12;
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != 1381278590 )
        __break(0x8228u);
      v14 = v13(v1, 56);
    }
    else
    {
      v14 = readl(*(_QWORD *)(v1 + 24) + 56LL);
    }
    v15 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2080) = v14;
    v16 = *v15;
    if ( v16 )
    {
      if ( *((_DWORD *)v16 - 1) != 1381278590 )
        __break(0x8228u);
      v17 = v16(v1, 52);
    }
    else
    {
      v17 = readl(*(_QWORD *)(v1 + 24) + 52LL);
    }
    v18 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2076) = v17;
    v19 = *v18;
    if ( v19 )
    {
      if ( *((_DWORD *)v19 - 1) != 1381278590 )
        __break(0x8228u);
      v20 = v19(v1, 40);
    }
    else
    {
      v20 = readl(*(_QWORD *)(v1 + 24) + 40LL);
    }
    *(_DWORD *)(v1 + 2072) = v20;
    v21 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[21]));
    v22 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2052) = v21;
    v23 = *v22;
    if ( v23 )
    {
      if ( *((_DWORD *)v23 - 1) != 1381278590 )
        __break(0x8228u);
      v24 = v23(v1, 68);
    }
    else
    {
      v24 = readl(*(_QWORD *)(v1 + 24) + 68LL);
    }
    v25 = *(__int64 (__fastcall ***)(__int64, __int64))(v1 + 64);
    *(_DWORD *)(v1 + 2088) = v24;
    v26 = *v25;
    if ( v26 )
    {
      if ( *((_DWORD *)v26 - 1) != 1381278590 )
        __break(0x8228u);
      v27 = v26(v1, 608);
    }
    else
    {
      v27 = readl(*(_QWORD *)(v1 + 24) + 608LL);
    }
    *(_DWORD *)(v1 + 2112) = v27;
    *(_DWORD *)(v1 + 2092) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[6]));
    *(_DWORD *)(v1 + 2096) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[15]));
    *(_DWORD *)(v1 + 2100) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[25]));
    *(_DWORD *)(v1 + 2096) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[15]));
    *(_DWORD *)(v1 + 2104) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[26]));
    *(_DWORD *)(v1 + 2108) = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 24) + v2[29]));
    if ( v3 )
    {
      v28 = *(_DWORD **)(*v3 + 16LL);
      if ( v28 )
      {
        if ( *(v28 - 1) != 1427797680 )
          __break(0x8228u);
        v29 = ((__int64 (__fastcall *)(_QWORD *, __int64))v28)(v3, 2560);
      }
      else
      {
        v29 = readl_relaxed((unsigned int *)(v3[1] + 2560LL));
      }
      *(_DWORD *)(v1 + 2116) = v29;
    }
    result = *(_QWORD *)(v1 + 2160);
    *(_BYTE *)(v1 + 2041) = 1;
    if ( result )
    {
      if ( *(_BYTE *)(v1 + 2168) == 1 )
        return ipc_log_string(result, "%s: Registers saved\n", "sdhci_msm_registers_save");
    }
  }
  return result;
}
