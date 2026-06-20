__int64 __fastcall sdhci_msm_set_clock(__int64 a1, unsigned int a2)
{
  unsigned __int64 v4; // x1
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 result; // x0
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w0

  if ( a2 )
  {
    sdhci_msm_hc_select_mode(a1);
    msm_set_clock_rate_for_bus_mode(a1, a2);
    if ( (*(_BYTE *)(a1 + 1641) & 1) == 0 )
    {
      v4 = *(_QWORD *)(a1 + 1520);
      if ( *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1055LL) )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 72) + 1055LL) == 2 )
          v4 >>= 1;
      }
      else
      {
        v4 >>= 3;
      }
      sdhci_msm_bus_get_and_set_vote(a1, v4);
    }
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 1520) = 0;
    *(_DWORD *)(v5 + 1440) = 0;
  }
  v6 = *(_DWORD **)(*(_QWORD *)(a1 + 64) + 32LL);
  if ( !v6 )
  {
    result = writew(0, *(_QWORD *)(a1 + 24) + 44LL);
    if ( !a2 )
      return result;
    goto LABEL_11;
  }
  if ( *(v6 - 1) != -139597297 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v6)(a1, 0, 44);
  if ( a2 )
  {
LABEL_11:
    v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 64) + 8LL);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != -1608852288 )
        __break(0x8228u);
      v9 = v8(a1, 44);
    }
    else
    {
      v9 = readw(*(_QWORD *)(a1 + 24) + 44LL);
    }
    return sdhci_enable_clk(a1, v9);
  }
  return result;
}
