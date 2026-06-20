__int64 __fastcall msm_vidc_change_state(__int64 result, unsigned int a2, __int64 a3)
{
  int v3; // w8
  const char *v4; // x4
  __int64 v5; // x9
  unsigned int v6; // w19
  __int64 v7; // x22
  const char *v9; // x4

  v3 = *(_DWORD *)(result + 160);
  if ( v3 == 5 )
  {
    if ( !result )
      return result;
    if ( (msm_vidc_debug & 2) != 0 )
    {
      if ( a2 <= 5 )
        v4 = state_name_arr[a2];
      else
        v4 = "UNKNOWN STATE";
      printk(&unk_9184E, "high", result + 340, a3, v4);
      return 0;
    }
    return 0;
  }
  if ( v3 == a2 )
    return 0;
  v5 = 0;
  while ( *(_DWORD *)((char *)&msm_vidc_allow_state_change_state + v5) != v3
       || *(_DWORD *)((char *)&msm_vidc_allow_state_change_state + v5 + 4) != a2 )
  {
    v5 += 12;
    if ( v5 == 432 )
    {
      v6 = 0;
      goto LABEL_15;
    }
  }
  v6 = *(_DWORD *)((char *)&msm_vidc_allow_state_change_state + v5 + 8);
  if ( v6 == 1 )
    return msm_vidc_update_state(result, a2, a3);
LABEL_15:
  if ( result && (msm_vidc_debug & 1) != 0 )
  {
    v7 = result;
    v9 = allow_name(v6);
    printk(&unk_8CEFA, "err ", v7 + 340, a3, v9);
  }
  if ( v6 )
    return 0;
  else
    return 4294967274LL;
}
