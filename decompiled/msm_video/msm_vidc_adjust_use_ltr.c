__int64 __fastcall msm_vidc_adjust_use_ltr(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  int v3; // w8

  if ( a2 )
    v2 = *(unsigned int *)(a2 + 196);
  else
    v2 = *(unsigned int *)(a1 + 25520);
  v3 = *(_DWORD *)(a1 + 11744);
  if ( v3 )
  {
    if ( (int)v2 >= 1 && (int)v2 <= ~(-1 << v3) )
    {
      ((void (__fastcall *)(__int64, __int64))msm_vidc_update_cap_value)(a1, 126);
    }
    else if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_8EC65, "err ", a1 + 340, "msm_vidc_adjust_use_ltr", v2);
    }
  }
  return 0;
}
