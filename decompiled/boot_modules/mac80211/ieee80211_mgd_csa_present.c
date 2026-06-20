__int64 __fastcall ieee80211_mgd_csa_present(__int64 a1, __int64 a2, unsigned __int8 a3, char a4)
{
  __int64 elem_match; // x0
  _BYTE *v9; // x23
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x3
  _BYTE *v14; // x8
  int v15; // w9
  _BOOL4 v16; // w0
  __int64 v17; // x1
  _BOOL4 v18; // w19

  if ( !a2 )
    return 0;
  elem_match = cfg80211_find_elem_match(37, a2 + 29, *(unsigned int *)(a2 + 24), 0, 0, 0);
  if ( elem_match )
  {
    if ( *(_BYTE *)(elem_match + 1) == 3 )
      v9 = (_BYTE *)(elem_match + 2);
    else
      v9 = nullptr;
  }
  else
  {
    v9 = nullptr;
  }
  v11 = cfg80211_find_elem_match(60, a2 + 29, *(unsigned int *)(a2 + 24), 0, 0, 0);
  if ( v11 )
  {
    if ( *(_BYTE *)(v11 + 1) == 4 )
      v14 = (_BYTE *)(v11 + 2);
    else
      v14 = nullptr;
    v15 = a3;
    if ( !v9 )
      goto LABEL_19;
  }
  else
  {
    v14 = nullptr;
    v15 = a3;
    if ( !v9 )
      goto LABEL_19;
  }
  if ( v9[2] )
  {
    if ( *v9 )
    {
      v16 = 1;
      if ( !v14 )
        return v16 | (unsigned int)v14;
    }
    else
    {
      v16 = (unsigned __int8)v9[1] != v15;
      if ( !v14 )
        return v16 | (unsigned int)v14;
    }
    goto LABEL_20;
  }
LABEL_19:
  v16 = 0;
  if ( !v14 )
    return v16 | (unsigned int)v14;
LABEL_20:
  if ( !v14[3] )
  {
    LODWORD(v14) = 0;
    return v16 | (unsigned int)v14;
  }
  if ( !*v14 )
  {
    LODWORD(v14) = (unsigned __int8)v14[2] != v15;
    if ( (a4 & 1) != 0 )
      goto LABEL_28;
    return v16 | (unsigned int)v14;
  }
  LODWORD(v14) = 1;
  if ( (a4 & 1) == 0 )
    return v16 | (unsigned int)v14;
LABEL_28:
  if ( !(_DWORD)v14 )
    return v16 | (unsigned int)v14;
  v17 = a1 + 1640;
  v18 = v16;
  printk(&unk_BBA29, v17, v12, v13);
  return v18;
}
