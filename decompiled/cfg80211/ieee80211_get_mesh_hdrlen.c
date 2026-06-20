__int64 __fastcall ieee80211_get_mesh_hdrlen(_BYTE *a1)
{
  int v1; // w9
  unsigned int v2; // w8

  v1 = *a1 & 3;
  if ( v1 == 1 )
    v2 = 12;
  else
    v2 = 6;
  if ( v1 == 2 )
    return 18;
  else
    return v2;
}
