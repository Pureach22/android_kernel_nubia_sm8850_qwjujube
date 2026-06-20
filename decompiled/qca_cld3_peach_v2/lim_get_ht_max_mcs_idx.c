__int64 __fastcall lim_get_ht_max_mcs_idx(__int64 a1)
{
  int v1; // w9
  int v2; // w10
  unsigned int v3; // w8

  v1 = *(char *)(a1 + 4);
  v2 = (v1 & 1) - 1;
  if ( (v1 & 2) != 0 )
    v2 = 1;
  if ( (v1 & 4) != 0 )
    v3 = 2;
  else
    v3 = v2;
  if ( (v1 & 8) != 0 )
    v3 = 3;
  if ( (v1 & 0x10) != 0 )
    v3 = 4;
  if ( (v1 & 0x20) != 0 )
    v3 = 5;
  if ( (v1 & 0x40) != 0 )
    v3 = 6;
  if ( v1 < 0 )
    return 7;
  else
    return v3;
}
