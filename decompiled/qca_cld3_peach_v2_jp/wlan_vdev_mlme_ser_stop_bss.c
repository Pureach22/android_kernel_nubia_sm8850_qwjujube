__int64 __fastcall wlan_vdev_mlme_ser_stop_bss(
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
  unsigned __int8 is_cmd_present_in_pending_queue; // w0
  __int64 v20; // x8
  unsigned __int8 v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  unsigned int v39; // w1
  __int64 result; // x0
  unsigned int v41; // w9
  __int64 v42; // [xsp+8h] [xbp-28h] BYREF
  int v43; // [xsp+10h] [xbp-20h]
  int v44; // [xsp+14h] [xbp-1Ch]
  __int64 v45; // [xsp+18h] [xbp-18h]
  __int64 v46; // [xsp+20h] [xbp-10h]
  __int64 v47; // [xsp+28h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v10 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    v38 = "%s: Null input";
    v39 = 2;
    goto LABEL_7;
  }
  if ( (wlan_ser_is_vdev_queue_enabled(v10) & 1) == 0 )
  {
    result = 4;
    goto LABEL_12;
  }
  is_cmd_present_in_pending_queue = wlan_serialization_is_cmd_present_in_pending_queue(
                                      v11,
                                      v12,
                                      v13,
                                      v14,
                                      v15,
                                      v16,
                                      v17,
                                      v18,
                                      0,
                                      (unsigned int *)a1);
  v20 = *(_QWORD *)(a1 + 32);
  v21 = is_cmd_present_in_pending_queue;
  v42 = 0x100000000LL;
  v43 = 0;
  v45 = v20;
  v44 = 7;
  v46 = 2;
  wlan_serialization_cancel_request((unsigned int *)&v42, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( (wlan_serialization_is_cmd_present_in_active_queue(v30, v31, v32, v33, v34, v35, v36, v37, 0, (unsigned int *)a1)
      & 1) != 0 )
  {
    v38 = "%s: Cmd already exist in the active queue";
    v39 = 8;
LABEL_7:
    qdf_trace_msg(0x68u, v39, v38, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_mlme_ser_stop_bss");
    result = 6;
    goto LABEL_12;
  }
  v41 = (unsigned __int8)wlan_serialization_request((unsigned int *)a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (v21 & (v41 == 0)) != 0 )
    result = 5;
  else
    result = v41;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
