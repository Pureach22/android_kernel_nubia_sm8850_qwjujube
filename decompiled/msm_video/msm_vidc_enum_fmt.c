__int64 __fastcall msm_vidc_enum_fmt(__int64 a1, unsigned int *a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a1 + 308);
  if ( v2 == 1 )
    return msm_venc_enum_fmt(a1, a2);
  if ( v2 == 2 )
    return msm_vdec_enum_fmt(a1, a2);
  return 4294967274LL;
}
