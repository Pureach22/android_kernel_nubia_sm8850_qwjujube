__int64 __fastcall wlan_vdev_mlme_ser_start_bss(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 result; // x0
  __int64 v30; // [xsp+8h] [xbp-28h] BYREF
  int v31; // [xsp+10h] [xbp-20h]
  int v32; // [xsp+14h] [xbp-1Ch]
  __int64 v33; // [xsp+18h] [xbp-18h]
  __int64 v34; // [xsp+20h] [xbp-10h]
  __int64 v35; // [xsp+28h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v10 = *(_QWORD *)(a1 + 32)) != 0 )
  {
    if ( (wlan_ser_is_vdev_queue_enabled(v10) & 1) == 0 )
    {
      result = 4;
      goto LABEL_11;
    }
    v19 = *(_QWORD *)(a1 + 32);
    v30 = 0x1500000000LL;
    v31 = 0;
    v33 = v19;
    v32 = 6;
    v34 = 2;
    wlan_serialization_cancel_request((unsigned int *)&v30, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( (wlan_serialization_is_cmd_present_in_active_queue(
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            0,
            (unsigned int *)a1)
        & 1) == 0
      || (wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a1 + 32)), !(unsigned int)mlme_vdev_enqueue_exp_ser_cmd()) )
    {
      result = wlan_serialization_request((unsigned int *)a1, a2, a3, a4, a5, a6, a7, a8, a9);
      goto LABEL_11;
    }
    v28 = "%s: Unable to add the exception cmd request";
  }
  else
  {
    v28 = "%s: Null input";
  }
  qdf_trace_msg(0x68u, 2u, v28, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_ser_start_bss");
  result = 6;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
