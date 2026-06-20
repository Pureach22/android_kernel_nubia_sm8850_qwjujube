__int64 __fastcall lim_update_eht_bw_cap_mcs(__int64 result, __int64 a2)
{
  int v2; // w9
  __int64 v3; // x10

  if ( *(_BYTE *)(result + 10071) == 1 )
  {
    v2 = *(_DWORD *)(result + 7036);
    if ( v2 )
    {
      if ( !a2 || v2 != 2 )
        return result;
    }
    else if ( !a2 )
    {
      return result;
    }
    if ( *(_BYTE *)(a2 + 2740) )
    {
      v3 = *(_QWORD *)(a2 + 2741);
      if ( (v3 & 0x20000) == 0 )
      {
        *(_QWORD *)(result + 10073) &= ~0x20000uLL;
        v3 = *(_QWORD *)(a2 + 2741);
      }
      if ( (~(_DWORD)v3 & 0x220000) != 0 )
        *(_QWORD *)(result + 10073) &= 0xFFFFFC7FFFFFFFFFLL;
    }
  }
  return result;
}
