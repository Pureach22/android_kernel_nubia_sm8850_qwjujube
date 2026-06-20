__int64 __fastcall msm_vidc_state_change_streamon(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v5; // x1
  char v6; // w8

  if ( (a2 & 0xFFFFFFFE) == 2 )
    return 0;
  if ( (_DWORD)a2 == 1 )
  {
    v3 = a1;
    if ( (is_state(a1, 0) & 1) != 0 )
    {
      v4 = 2;
      a1 = v3;
      return msm_vidc_change_state(a1, v4, "msm_vidc_state_change_streamon");
    }
    v5 = 1;
LABEL_12:
    v6 = is_state(v3, v5);
    a1 = v3;
    if ( (v6 & 1) != 0 )
      v4 = 3;
    else
      v4 = 5;
    return msm_vidc_change_state(a1, v4, "msm_vidc_state_change_streamon");
  }
  if ( (_DWORD)a2 )
  {
    v4 = 5;
    return msm_vidc_change_state(a1, v4, "msm_vidc_state_change_streamon");
  }
  v3 = a1;
  if ( (is_state(a1, a2) & 1) == 0 )
  {
    v5 = 2;
    goto LABEL_12;
  }
  v4 = 1;
  a1 = v3;
  return msm_vidc_change_state(a1, v4, "msm_vidc_state_change_streamon");
}
