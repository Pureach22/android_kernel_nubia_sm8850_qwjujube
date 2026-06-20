__int64 __fastcall msm_vidc_adjust_dec_input_tx_fence_type(__int64 a1)
{
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          60,
          58,
          "msm_vidc_adjust_dec_input_tx_fence_type")
      & 1) == 0 )
    return 4294967274LL;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    60,
    2LL * (*(_QWORD *)(a1 + 14096) != 0),
    "msm_vidc_adjust_dec_input_tx_fence_type");
  return 0;
}
