__int64 __fastcall msm_vidc_adjust_dec_input_rx_fence_type(__int64 a1)
{
  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          59,
          57,
          "msm_vidc_adjust_dec_input_rx_fence_type")
      & 1) == 0 )
    return 4294967274LL;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    59,
    2LL * (*(_QWORD *)(a1 + 13928) != 0),
    "msm_vidc_adjust_dec_input_rx_fence_type");
  return 0;
}
