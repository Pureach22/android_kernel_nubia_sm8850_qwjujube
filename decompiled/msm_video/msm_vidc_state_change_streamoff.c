__int64 __fastcall msm_vidc_state_change_streamoff(__int64 a1, int a2)
{
  __int64 v3; // x19
  unsigned int v4; // w20
  __int64 v5; // x1
  char v6; // w8

  if ( (a2 & 0xFFFFFFFE) == 2 )
    return 0;
  if ( a2 == 1 )
  {
    v3 = a1;
    if ( (is_state(a1, 2) & 1) == 0 )
    {
      v4 = 1;
LABEL_11:
      v6 = is_state(v3, 3);
      a1 = v3;
      if ( (v6 & 1) != 0 )
        v5 = v4;
      else
        v5 = 5;
      return msm_vidc_change_state(a1, v5, "msm_vidc_state_change_streamoff");
    }
  }
  else
  {
    if ( a2 )
    {
      v5 = 5;
      return msm_vidc_change_state(a1, v5, "msm_vidc_state_change_streamoff");
    }
    v3 = a1;
    if ( (is_state(a1, 1) & 1) == 0 )
    {
      v4 = 2;
      goto LABEL_11;
    }
  }
  v5 = 0;
  a1 = v3;
  return msm_vidc_change_state(a1, v5, "msm_vidc_state_change_streamoff");
}
