__int64 __fastcall wlan_mlme_update_ratemask_params(
        __int64 a1,
        unsigned __int8 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 cmpt_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x19
  __int64 v23; // x24
  __int64 v24; // x25
  _DWORD *v25; // x26
  unsigned int v26; // w1
  const char *v27; // x2
  unsigned __int64 v28; // x1
  _DWORD *v29; // x8
  int v30; // w9

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cmpt_obj )
    return 16;
  if ( a2 )
  {
    v22 = cmpt_obj;
    v23 = cmpt_obj + 332;
    v24 = a2;
    v25 = (_DWORD *)(a3 + 16);
    do
    {
      v28 = *((unsigned __int8 *)v25 - 15);
      if ( v28 >= 5 )
      {
        v26 = 2;
        v27 = "%s: Invalid ratemask type";
      }
      else
      {
        v29 = (_DWORD *)(v23 + 16 * v28);
        v30 = *(v25 - 3);
        if ( *v29 == v30 && v29[2] == *(v25 - 1) && v29[1] == *(v25 - 2) && v29[3] == *v25 )
        {
          v26 = 8;
          v27 = "%s: Ratemask same as configured mask";
        }
        else
        {
          *v29 = v30;
          v29[1] = *(v25 - 2);
          v29[2] = *(v25 - 1);
          v29[3] = *v25;
          if ( !(unsigned int)((__int64 (__fastcall *)(__int64))wlan_util_vdev_mlme_set_ratemask_config)(v22) )
            goto LABEL_6;
          v26 = 2;
          v27 = "%s: ratemask config failed";
        }
      }
      qdf_trace_msg(0x1Fu, v26, v27, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_mlme_update_ratemask_params");
LABEL_6:
      --v24;
      v25 += 5;
    }
    while ( v24 );
  }
  return 0;
}
