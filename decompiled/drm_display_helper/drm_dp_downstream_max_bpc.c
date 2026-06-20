__int64 __fastcall drm_dp_downstream_max_bpc(unsigned __int8 *a1, _BYTE *a2, __int64 a3)
{
  unsigned int v3; // w8
  unsigned __int8 *v4; // x19
  _BYTE *v5; // x20
  __int64 v6; // x0
  __int64 v7; // x8

  if ( (a1[5] & 1) == 0 )
    return 0;
  if ( *a1 <= 0x10u )
    return 8 * (unsigned int)((a1[5] & 6) != 0);
  v3 = *a2 & 7;
  if ( v3 - 1 < 3 )
    goto LABEL_6;
  if ( (*a2 & 7) == 0 )
    return v3;
  if ( v3 != 5 )
    return 8;
  v4 = a1;
  v5 = a2;
  v6 = drm_edid_raw(a3);
  a2 = v5;
  v7 = v6;
  a1 = v4;
  if ( !v7 || *(unsigned __int8 *)(v7 + 19) < 4u || (*(_BYTE *)(v7 + 20) & 0x87) != 0x85 )
  {
LABEL_6:
    if ( (a1[5] & 0x10) != 0 )
      return dword_1EE48[a2[2] & 3];
    return 8;
  }
  return 0;
}
