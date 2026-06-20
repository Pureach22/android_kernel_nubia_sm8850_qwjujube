__int64 __fastcall msm_vidc_adjust_mark_ltr(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  int v3; // w8

  if ( a2 )
    v2 = *(unsigned int *)(a2 + 196);
  else
    v2 = *(unsigned int *)(a1 + 25688);
  v3 = *(_DWORD *)(a1 + 11744);
  if ( v3 )
  {
    if ( (v2 & 0x80000000) != 0 || (int)v2 > v3 - 1 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_8EC65, "err ", a1 + 340, "msm_vidc_adjust_mark_ltr", v2);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64))msm_vidc_update_cap_value)(a1, 127);
    }
  }
  return 0;
}
