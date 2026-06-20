__int64 __fastcall drm_dp_dsc_sink_supported_input_bpcs(_BYTE *a1, _BYTE *a2)
{
  char v3; // w9
  unsigned int v4; // w8

  if ( (*a1 & 1) == 0 )
    return 0;
  v3 = a1[10];
  if ( (v3 & 8) == 0 )
  {
    v4 = 0;
    if ( (a1[10] & 4) == 0 )
      goto LABEL_8;
    goto LABEL_7;
  }
  *a2 = 12;
  v4 = 1;
  if ( (v3 & 4) != 0 )
LABEL_7:
    a2[v4++] = 10;
LABEL_8:
  a2[v4] = 8;
  return v4 + 1;
}
