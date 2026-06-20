__int64 __fastcall msm_vidc_state_change_input_psc(__int64 a1)
{
  unsigned int v2; // w20

  v2 = 80;
  if ( (is_state(a1, 1) & 1) == 0 )
  {
    if ( (is_state(a1, 0) & 1) != 0 )
      v2 = 80;
    else
      v2 = 18;
  }
  return msm_vidc_change_sub_state(a1, 0, v2, "msm_vidc_state_change_input_psc");
}
