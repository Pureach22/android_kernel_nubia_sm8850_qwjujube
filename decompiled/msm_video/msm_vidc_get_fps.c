__int64 __fastcall msm_vidc_get_fps(__int64 a1)
{
  unsigned int v1; // w8
  unsigned int v2; // w9

  v1 = *(_DWORD *)(a1 + 19474);
  v2 = *(_DWORD *)(a1 + 19642);
  if ( v2 <= v1 )
    return v1;
  else
    return v2;
}
