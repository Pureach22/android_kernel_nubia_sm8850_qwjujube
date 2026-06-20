__int64 __fastcall msm_vidc_decide_quality_mode_iris4(__int64 a1, __int64 a2)
{
  __int64 v3; // x20

  if ( *(_DWORD *)(a1 + 308) == 1 )
  {
    if ( *(_DWORD *)(a1 + 312) != 8
      && !*(_QWORD *)(a1 + 24512)
      && !*(_QWORD *)(a1 + 16112)
      && *(__int64 *)(a1 + 34928) >= 50 )
    {
      v3 = a1;
      msm_vidc_get_mbs_per_frame(a1, a2);
      msm_vidc_get_fps(v3);
      a1 = v3;
    }
    ((void (__fastcall *)(__int64, __int64))msm_vidc_update_cap_value)(a1, 172);
  }
  return 0;
}
