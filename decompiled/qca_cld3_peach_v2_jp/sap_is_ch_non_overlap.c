__int64 __fastcall sap_is_ch_non_overlap(__int64 a1, unsigned __int16 a2)
{
  unsigned int v2; // w8

  v2 = 0x842u >> a2;
  if ( a2 > 0xBu )
    LOBYTE(v2) = 0;
  if ( (*(_BYTE *)(a1 + 1528) & 1) != 0 )
    LOBYTE(v2) = 1;
  return v2 & 1;
}
