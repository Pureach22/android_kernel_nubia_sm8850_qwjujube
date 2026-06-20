__int64 __fastcall msm_vidc_adjust_hevc_b_frame_qp(__int64 a1, __int64 a2)
{
  __int64 v2; // x19

  if ( a2 )
  {
    v2 = a1;
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      36,
      *(int *)(a2 + 196),
      "msm_vidc_adjust_hevc_b_frame_qp");
    a1 = v2;
  }
  return msm_vidc_adjust_hevc_qp(a1, 0x24u);
}
