__int64 __fastcall msm_vidc_update_state(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  unsigned int v5; // w8
  const char *v7; // x1
  const char *v8; // x4
  __int64 v9; // x23

  if ( a2 < 6 )
  {
    v3 = (__int64)*(&off_9DE98 + a2);
    if ( a2 == 5 )
    {
      if ( !a1 || (msm_vidc_debug & 1) == 0 )
        goto LABEL_12;
      v4 = a3;
      v7 = "err ";
      v8 = "ERROR";
    }
    else
    {
      if ( !a1 || (msm_vidc_debug & 2) == 0 )
        goto LABEL_12;
      v8 = state_name_arr[a2];
      v4 = a3;
      v7 = "high";
    }
    v9 = a1;
    printk(&unk_82D20, v7, a1 + 340, v4, v8);
    a1 = v9;
LABEL_12:
    v5 = 0;
    *(_DWORD *)(a1 + 160) = *(_DWORD *)v3;
    *(_QWORD *)(a1 + 168) = *(_QWORD *)(v3 + 8);
    return v5;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
    printk(&unk_8A773, "err ", a1 + 340, "msm_vidc_get_state_handle", "UNKNOWN STATE");
  return (unsigned int)-22;
}
