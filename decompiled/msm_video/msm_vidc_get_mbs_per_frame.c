__int64 __fastcall msm_vidc_get_mbs_per_frame(_DWORD *a1)
{
  int v1; // w8
  unsigned int v2; // w8
  int v3; // w9

  v1 = a1[77];
  if ( v1 == 1 )
  {
    v2 = a1[472];
    v3 = a1[473];
  }
  else if ( v1 == 2 )
  {
    v2 = a1[98];
    if ( v2 <= a1[472] )
      v2 = a1[472];
    if ( a1[99] <= a1[473] )
      v3 = a1[473];
    else
      v3 = a1[99];
  }
  else
  {
    v2 = 0;
    v3 = 0;
  }
  return (unsigned int)(((v3 + 15) >> 4) * ((int)(v2 + 15) >> 4));
}
