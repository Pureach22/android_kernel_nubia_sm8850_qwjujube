__int64 __fastcall msm_vidc_adjust_preprocess(__int64 a1)
{
  unsigned int v1; // w20
  unsigned int v2; // w21
  unsigned int frame_rate; // w22
  unsigned int operating_rate; // w0
  __int64 v6; // x2

  v1 = *(_DWORD *)(a1 + 1888);
  v2 = *(_DWORD *)(a1 + 1892);
  frame_rate = msm_vidc_get_frame_rate();
  operating_rate = msm_vidc_get_operating_rate(a1);
  if ( frame_rate <= operating_rate )
    frame_rate = operating_rate;
  if ( (is_valid_cap(a1, 72) & 1) == 0 )
    goto LABEL_7;
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          74,
          72,
          "msm_vidc_adjust_preprocess")
      & 1) != 0 )
  {
    if ( *(_QWORD *)(a1 + 16448) )
    {
      v6 = (unsigned int)res_is_less_than_or_equal_to(v1, v2, 3840, 2160) & (frame_rate < 0x3D);
LABEL_8:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
        a1,
        74,
        v6,
        "msm_vidc_adjust_preprocess");
      return 0;
    }
LABEL_7:
    v6 = 0;
    goto LABEL_8;
  }
  return 4294967274LL;
}
