__int64 __fastcall ieee80211_set_ap_mbssid_options(__int64 a1, __int64 a2, __int16 a3, __int64 a4)
{
  unsigned int v4; // w8

  *(_QWORD *)(a1 + 5888) = 0;
  *(_BYTE *)(a4 + 304) = 0;
  *(_WORD *)(a4 + 311) = 0;
  *(_BYTE *)(a4 + 313) = 0;
  v4 = -22;
  if ( *(_DWORD *)(a1 + 4720) != 3 || !a2 )
    return v4;
  if ( a2 != 16 )
  {
    if ( a2 - 16 == a1 )
    {
      *(_QWORD *)(a1 + 5888) = a1 + 4720;
      v4 = 0;
      if ( (a3 & 0x100) == 0 )
        return v4;
    }
    else
    {
      *(_QWORD *)(a1 + 5888) = a2 + 4704;
      *(_BYTE *)(a4 + 304) = 1;
      *(_BYTE *)(a4 + 311) = a3;
      v4 = 0;
      if ( (a3 & 0x100) == 0 )
        return v4;
    }
    *(_BYTE *)(a4 + 313) = 1;
    return v4;
  }
  return 4294967274LL;
}
