__int64 __fastcall lim_decide_sta_protection_on_assoc(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w9
  int v4; // w9
  bool v5; // w9
  int v6; // w10
  int v7; // w9

  if ( !a3 )
    goto LABEL_32;
  v3 = *(_DWORD *)(a3 + 168);
  if ( v3 )
  {
    if ( v3 != 1 )
      goto LABEL_32;
    v4 = (*(_DWORD *)(a2 + 1262) >> 8) & 3;
    if ( v4 == 3 )
    {
LABEL_7:
      if ( (*(_WORD *)(result + 8880) & 0x100) != 0 )
      {
        *(_BYTE *)(a3 + 7161) = 1;
        if ( !*(_BYTE *)(a3 + 155) )
          return result;
        goto LABEL_33;
      }
LABEL_32:
      if ( !*(_BYTE *)(a3 + 155) )
        return result;
      goto LABEL_33;
    }
    if ( v4 != 2 )
    {
      if ( v4 != 1 )
        goto LABEL_32;
      goto LABEL_7;
    }
    if ( (*(_WORD *)(result + 8880) & 0x800) == 0 )
      goto LABEL_32;
LABEL_31:
    *(_BYTE *)(a3 + 7164) = 1;
    goto LABEL_32;
  }
  if ( *(_DWORD *)(a3 + 7232) != 1 )
  {
    v5 = (*(_WORD *)(result + 8880) & 0x200) != 0 && *(_BYTE *)(a2 + 2475) && (*(_BYTE *)(a2 + 1132) & 3) != 0;
    *(_BYTE *)(a3 + 7162) = v5;
  }
  if ( !*(_BYTE *)(a3 + 155) || !*(_BYTE *)(a2 + 1260) )
    goto LABEL_32;
  v6 = (*(_DWORD *)(a2 + 1262) >> 8) & 3;
  *(_BYTE *)(a3 + 7168) = (*(_DWORD *)(a2 + 1262) & 0x1000) != 0;
  if ( (*(_WORD *)(result + 8880) & 0x400) == 0 )
    goto LABEL_28;
  if ( v6 > 1 )
  {
    if ( v6 == 2 )
      goto LABEL_30;
    goto LABEL_26;
  }
  if ( v6 )
  {
LABEL_26:
    if ( !*(_BYTE *)(a3 + 7162) )
      *(_BYTE *)(a3 + 7163) = 1;
LABEL_28:
    if ( !v6 )
      goto LABEL_36;
    if ( v6 != 2 )
      goto LABEL_32;
LABEL_30:
    *(_BYTE *)(a3 + 7163) = 0;
    if ( (*(_WORD *)(result + 8880) & 0x800) == 0 )
      goto LABEL_32;
    goto LABEL_31;
  }
LABEL_36:
  *(_WORD *)(a3 + 7163) = 0;
  if ( !*(_BYTE *)(a3 + 155) )
    return result;
LABEL_33:
  if ( *(_BYTE *)(a2 + 1260) )
  {
    v7 = *(_DWORD *)(a2 + 1262);
    *(_BYTE *)(a3 + 7167) = (*(_WORD *)(a2 + 1266) & 0x200) != 0;
    *(_BYTE *)(a3 + 7166) = (v7 & 8) != 0;
    *(_BYTE *)(a3 + 7165) = (v7 & 0x400) != 0;
  }
  return result;
}
