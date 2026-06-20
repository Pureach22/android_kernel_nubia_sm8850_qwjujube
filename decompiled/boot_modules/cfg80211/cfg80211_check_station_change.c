__int64 __fastcall cfg80211_check_station_change(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w8
  int v5; // w8

  if ( a3 != 1 && *(_DWORD *)(a2 + 20) != -1
    || a3 != 1 && *(_DWORD *)(a2 + 92) != -1
    || *(_WORD *)(a2 + 24) && a3 != 1 && (*(_DWORD *)(a2 + 12) & 0x40) == 0 )
  {
    return 4294967274LL;
  }
  if ( (unsigned int)(a3 - 5) < 2 )
  {
    if ( (*(_BYTE *)(a2 + 12) & 0x40) == 0 )
      return 4294967274LL;
  }
  else
  {
    if ( (unsigned int)(a3 - 7) > 1 )
    {
      if ( *(_BYTE *)(a2 + 30) || *(_DWORD *)(a2 + 36) || (*(_BYTE *)(a2 + 16) & 4) != 0 )
        return 4294967274LL;
      if ( (unsigned int)(a3 - 7) > 0xFFFFFFFD )
        goto LABEL_16;
    }
    else if ( (*(_DWORD *)(a2 + 8) & 0xFFFFFFCD) != 0 )
    {
      return 4294967274LL;
    }
    if ( (*(_BYTE *)(a2 + 12) & 0x40) != 0 )
      return 4294967274LL;
  }
  v3 = *(_DWORD *)(a2 + 8) & 0xFFFFFFBF;
  *(_DWORD *)(a2 + 8) = v3;
  if ( (a3 | 4) != 5 )
  {
    if ( (*(_BYTE *)(a2 + 16) & 3) != 0
      || *(_QWORD *)(a2 + 128)
      || *(_QWORD *)(a2 + 48)
      || *(_QWORD *)(a2 + 144)
      || *(_QWORD *)(a2 + 152)
      || *(_QWORD *)(a2 + 168) )
    {
      return 4294967274LL;
    }
    v4 = -22;
    if ( *(_QWORD *)(a2 + 200) || (v3 & 0x100) != 0 )
      return v4;
  }
  if ( (unsigned int)a3 >= 2 )
  {
LABEL_16:
    if ( *(_QWORD *)a2 )
      return 4294967274LL;
  }
  if ( a3 > 4 )
  {
    if ( a3 > 6 )
    {
      if ( a3 == 7 )
      {
        if ( (*(_BYTE *)(a2 + 16) & 4) == 0 )
          goto LABEL_56;
      }
      else if ( a3 != 8 || (*(unsigned __int8 *)(a2 + 30) | 2) == 2 )
      {
        goto LABEL_56;
      }
    }
    else if ( a3 == 5
           && (*(_DWORD *)(a2 + 8) & 0xFFFFFFF5) == 0
           && ((*(_BYTE *)(a2 + 12) & 2) == 0 || *(_QWORD *)(a2 + 128)) )
    {
      return 0;
    }
  }
  else if ( (unsigned int)a3 < 2 )
  {
    v5 = *(_DWORD *)(a2 + 8);
    if ( (v5 & 0xFFFFFE41) == 0 && ((v5 & 0xA0) == 0 || (*(_DWORD *)(a1 + 108) & 0x8000) != 0) )
    {
      if ( a3 == 1 )
        return 0;
      goto LABEL_56;
    }
  }
  else
  {
    if ( (unsigned int)(a3 - 3) >= 2 )
    {
      if ( a3 == 2 && (*(_BYTE *)(a2 + 8) & 2) == 0 )
        return 4294967201LL;
      goto LABEL_56;
    }
    if ( (*(_DWORD *)(a2 + 8) & 0xFFFFFFFD) == 0 )
    {
LABEL_56:
      v4 = 0;
      *(_BYTE *)(a2 + 161) = 0;
      return v4;
    }
  }
  return 4294967274LL;
}
