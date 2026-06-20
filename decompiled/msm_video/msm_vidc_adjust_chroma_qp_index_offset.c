__int64 __fastcall msm_vidc_adjust_chroma_qp_index_offset(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x2

  if ( a2 )
    v2 = *(_DWORD *)(a2 + 196);
  else
    v2 = *(_DWORD *)(a1 + 31232);
  if ( v2 == -12 )
    v3 = 0;
  else
    v3 = 3084;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    160,
    v3,
    "msm_vidc_adjust_chroma_qp_index_offset");
  return 0;
}
