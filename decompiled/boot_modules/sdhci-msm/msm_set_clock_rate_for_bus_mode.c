unsigned __int64 __fastcall msm_set_clock_rate_for_bus_mode(__int64 a1, int a2)
{
  __int64 v2; // x8
  unsigned int v4; // w19
  unsigned int v6; // w9
  unsigned int v7; // w23
  __int64 v8; // x21
  __int64 v9; // x22
  unsigned __int64 result; // x0
  __int64 v11; // x23
  __int64 rate; // x0
  __int64 v13; // x8
  __int64 v14; // x1

  v2 = *(_QWORD *)(a1 + 72);
  v4 = *(unsigned __int8 *)(v2 + 1056);
  if ( v4 > 0xA || ((1 << v4) & 0x580) == 0 )
  {
    if ( (*(_DWORD *)(a1 + 796) & 0x2000) != 0 )
      v7 = 2;
    else
      v7 = 1;
    v6 = a2 << ((*(_DWORD *)(a1 + 796) & 0x2000u) >> 13);
    if ( v4 == 2 && *(_BYTE *)(a1 + 2145) == 1 && !*(_BYTE *)(a1 + 2169) )
      v6 = 37000000;
  }
  else
  {
    v6 = 2 * a2;
    v7 = 2;
  }
  v8 = v6;
  v9 = *(_QWORD *)(a1 + 1456);
  if ( (unsigned int)dev_pm_opp_set_rate(*(_QWORD *)v2, v6) )
  {
    v13 = *(_QWORD *)(a1 + 72);
    v14 = *(_QWORD *)(v13 + 120);
    if ( !v14 )
      v14 = *(_QWORD *)(v13 + 8);
    return printk(&unk_108AA, v14);
  }
  else
  {
    result = clk_get_rate(v9);
    *(_DWORD *)(*(_QWORD *)(a1 + 72) + 1440LL) = result / v7;
    v11 = *(_QWORD *)(a1 + 2160);
    *(_QWORD *)(a1 + 1520) = v8;
    if ( v11 )
    {
      if ( *(_BYTE *)(a1 + 2168) == 1 )
      {
        rate = clk_get_rate(v9);
        return ipc_log_string(
                 v11,
                 "%s: Setting clock at rate %lu at timing %d\n",
                 "msm_set_clock_rate_for_bus_mode",
                 rate,
                 v4);
      }
    }
  }
  return result;
}
