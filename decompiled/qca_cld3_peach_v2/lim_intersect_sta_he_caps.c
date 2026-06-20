__int64 __fastcall lim_intersect_sta_he_caps(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x23
  __int64 v8; // x20
  __int64 v9; // x9

  if ( *(_BYTE *)(a4 + 38) == 1 )
  {
    v4 = *(_QWORD *)(result + 8);
    v8 = result;
    if ( (unsigned int)*(unsigned __int8 *)(a3 + 154) - 10 < 4 || !*(_BYTE *)(a3 + 154) )
    {
      result = lim_intersect_he_caps((int)a2 + 3372, (int)a4 + 864);
      if ( (*(_BYTE *)(v4 + 1496) & 2) != 0
        && *(_DWORD *)(a3 + 88) == 1
        && (result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284)), (result & 1) != 0)
        && *(_DWORD *)(a3 + 7176) == 1 )
      {
        *(_WORD *)(a4 + 924) = 0;
      }
      else if ( *(_BYTE *)(a2 + 3436) && *(_BYTE *)(a2 + 3456) )
      {
        *(_WORD *)(a4 + 924) = *(_WORD *)(a2 + 3457);
        result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a3 + 284));
        v9 = 1494;
        if ( (result & 1) != 0 )
          v9 = 1492;
        *(_WORD *)(a4 + 924) &= *(_WORD *)(*(_QWORD *)(v8 + 8) + v9);
      }
    }
  }
  return result;
}
