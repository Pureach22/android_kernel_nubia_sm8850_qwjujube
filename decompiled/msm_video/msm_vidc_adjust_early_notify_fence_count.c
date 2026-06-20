__int64 __fastcall msm_vidc_adjust_early_notify_fence_count(__int64 a1)
{
  unsigned __int64 v2; // x5
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x2
  unsigned __int64 v5; // x20

  if ( (((__int64 (__fastcall *)(__int64, __int64, __int64, const char *))is_parent_available)(
          a1,
          56,
          55,
          "msm_vidc_adjust_early_notify_fence_count")
      & 1) == 0 )
    return 4294967274LL;
  if ( *(_QWORD *)(a1 + 13424) )
  {
    v2 = *(_QWORD *)(a1 + 13592);
    if ( v2 )
    {
      v3 = *(unsigned int *)(a1 + 396);
      if ( v3 % v2 )
        v4 = v3 / v2 + 1;
      else
        v4 = v3 / v2;
      if ( v4 >= 0xB )
      {
        v5 = v4;
        if ( a1 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_81BD5, "err ", a1 + 340, "msm_vidc_adjust_early_notify_fence_count", v4);
        }
        msm_vidc_change_state(a1, 5, "msm_vidc_adjust_early_notify_fence_count");
        v4 = v5;
      }
    }
    else
    {
      v4 = 1;
    }
  }
  else
  {
    v4 = 0;
  }
  ((void (__fastcall *)(__int64, __int64, unsigned __int64, const char *))msm_vidc_update_cap_value)(
    a1,
    56,
    v4,
    "msm_vidc_adjust_early_notify_fence_count");
  return 0;
}
