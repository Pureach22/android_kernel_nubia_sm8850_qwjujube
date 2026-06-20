__int64 __fastcall reg_ignore_default_country(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x8

  LODWORD(v2) = *(_DWORD *)(a1 + 91112);
  if ( !(_DWORD)v2 )
    return v2 & 1;
  v3 = *(unsigned __int8 *)(a2 + 13);
  if ( v3 < 3 )
  {
    if ( (*(_BYTE *)(a1 + v3 + 91128) & 1) != 0 )
      return 0;
    if ( (*(_BYTE *)(a1 + v3 + 91131) & 1) != 0 )
      return 0;
    v2 = a1 + v3;
    if ( (*(_BYTE *)(v2 + 91134) & 1) != 0 )
      return 0;
    LOBYTE(v2) = *(_BYTE *)(v2 + 91137) ^ 1;
    return v2 & 1;
  }
  __break(0x5512u);
  return reg_is_vlp_depriority_freq();
}
