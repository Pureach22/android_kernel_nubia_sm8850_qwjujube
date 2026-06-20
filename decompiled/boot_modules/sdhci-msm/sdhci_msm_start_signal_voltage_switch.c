__int64 __fastcall sdhci_msm_start_signal_voltage_switch(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  int v6; // w0
  unsigned int v7; // w20
  _DWORD *v8; // x8
  unsigned int (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x0
  const char *v11; // x2

  if ( *(_DWORD *)(a1 + 2592) < 2u )
    return 0;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1856) + 8LL);
  if ( v5 )
  {
    v10 = a1 + 1792;
    if ( *((_DWORD *)v5 - 1) != -1608852288 )
      __break(0x8228u);
    v6 = v5(v10, 62);
  }
  else
  {
    v6 = readw(*(_QWORD *)(a1 + 1816) + 62LL);
  }
  if ( *(_BYTE *)(a2 + 17) != 1 )
  {
    if ( !*(_BYTE *)(a2 + 17) && (*(_BYTE *)(a1 + 2589) & 0x40) != 0 )
    {
      v7 = v6 & 0xFFFFFFF7;
      goto LABEL_12;
    }
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(a1 + 2589) & 0x80) == 0 )
    return 4294967274LL;
  v7 = v6 | 8;
LABEL_12:
  v8 = *(_DWORD **)(*(_QWORD *)(a1 + 1856) + 32LL);
  if ( v8 )
  {
    if ( *(v8 - 1) != -139597297 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, __int64))v8)(a1 + 1792, v7, 62);
  }
  else
  {
    writew(v7, *(_QWORD *)(a1 + 1816) + 62LL);
  }
  usleep_range_state(5000, 5500, 2);
  v9 = *(unsigned int (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1856) + 8LL);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != -1608852288 )
      __break(0x8228u);
    if ( ((v9(a1 + 1792, 62) ^ v7) & 8) == 0 )
      return 0;
  }
  else if ( (((unsigned int)readw(*(_QWORD *)(a1 + 1816) + 62LL) ^ v7) & 8) == 0 )
  {
    return 0;
  }
  v11 = *(const char **)(a1 + 120);
  if ( !v11 )
    v11 = *(const char **)(a1 + 8);
  dev_warn(*(_QWORD *)a1, "%s: Regulator output did not became stable\n", v11);
  return 4294967285LL;
}
