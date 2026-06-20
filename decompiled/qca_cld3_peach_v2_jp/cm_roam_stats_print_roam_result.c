__int64 __fastcall cm_roam_stats_print_roam_result(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // x0
  char *v17; // x22
  const char *roam_fail_reason_str; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  __int64 *v28; // x8
  const char *roam_status_str; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // [xsp+0h] [xbp-20h] BYREF
  __int64 v47; // [xsp+8h] [xbp-18h]
  __int64 v48; // [xsp+10h] [xbp-10h]
  __int64 v49; // [xsp+18h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v46 = 0;
  cm_roam_result_info_event(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  result = _qdf_mem_malloc(0x3Cu, "cm_roam_stats_print_roam_result", 3852);
  if ( !result )
    goto LABEL_12;
  v17 = (char *)result;
  if ( *(_DWORD *)(a3 + 8) == 1 )
  {
    roam_fail_reason_str = mlme_get_roam_fail_reason_str(*(_DWORD *)(a3 + 12));
    snprintf(v17, 0x3Cu, "Reason: %s", roam_fail_reason_str);
  }
  mlme_get_converted_timestamp(*(_DWORD *)(a3 + 4), (char *)&v46);
  v27 = jiffies;
  if ( *(_DWORD *)(a3 + 12) == 35 )
  {
    if ( cm_roam_stats_print_roam_result___last_ticks - jiffies + 125 >= 0 )
      goto LABEL_10;
    qdf_trace_msg(
      0x68u,
      4u,
      "%s [ROAM_RESULT]: VDEV[%d] %s",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      &v46,
      (unsigned __int8)a5,
      v17);
    v28 = &cm_roam_stats_print_roam_result___last_ticks;
  }
  else
  {
    if ( cm_roam_stats_print_roam_result___last_ticks_172 - jiffies + 125 >= 0 )
      goto LABEL_10;
    roam_status_str = mlme_get_roam_status_str(*(_DWORD *)(a3 + 8));
    qdf_trace_msg(
      0x68u,
      4u,
      "%s [ROAM_RESULT]: VDEV[%d] %s %s",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      &v46,
      (unsigned __int8)a5,
      roam_status_str,
      v17);
    v28 = &cm_roam_stats_print_roam_result___last_ticks_172;
  }
  *v28 = v27;
LABEL_10:
  _qdf_mem_free((__int64)v17);
  result = wlan_cm_update_roam_states(a1, a5, *(_DWORD *)(a3 + 12), 2);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: failed to update rt stats roam fail reason",
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               "cm_roam_stats_print_roam_result",
               v46,
               v47,
               v48,
               v49);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
