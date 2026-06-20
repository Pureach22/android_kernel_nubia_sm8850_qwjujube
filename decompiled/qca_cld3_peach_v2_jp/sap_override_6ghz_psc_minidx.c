__int64 __fastcall sap_override_6ghz_psc_minidx(__int64 result, _DWORD *a2, unsigned __int8 a3, _BYTE *a4)
{
  __int64 v6; // x21
  __int64 v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( a3 && (*(_BYTE *)(*(_QWORD *)(result + 8) + 5371LL) & 1) != 0 )
  {
    v6 = 0;
    v7 = a3;
    while ( 1 )
    {
      result = wlan_reg_is_6ghz_chan_freq(*a2);
      if ( (result & 1) != 0 )
      {
        result = wlan_reg_is_6ghz_psc_chan_freq(*a2, v8, v9, v10, v11, v12, v13, v14, v15);
        if ( (result & 1) != 0 )
          break;
      }
      ++v6;
      a2 += 6;
      if ( v7 == v6 )
        return result;
    }
    *a4 = v6;
  }
  return result;
}
