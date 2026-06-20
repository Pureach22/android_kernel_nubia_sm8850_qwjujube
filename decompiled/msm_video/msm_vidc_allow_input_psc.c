__int64 __fastcall msm_vidc_allow_input_psc(__int64 a1)
{
  if ( (is_sub_state(a1, 2) & 1) == 0 )
    return 1;
  if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_96337, "err ", a1 + 340, "msm_vidc_allow_input_psc", a1 + 180);
  }
  return 0;
}
