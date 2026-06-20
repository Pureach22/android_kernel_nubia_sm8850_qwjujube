__int64 __fastcall cm_handle_disconnect_req(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  __int64 v13; // x23
  __int64 rso_config_fl; // x0
  __int64 v15; // x22
  unsigned int v16; // w24
  __int64 v17; // x0
  int v18; // w9
  char v19; // w10
  void *v20; // x20
  unsigned int v21; // w8
  char v22; // w9
  __int16 v23; // w9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x4
  __int64 v42; // x5
  unsigned int v43; // w19
  __int64 v44; // x4
  __int64 v45; // x5
  const char *v46; // x2
  __int64 v47; // [xsp+8h] [xbp-58h] BYREF
  void *v48; // [xsp+10h] [xbp-50h]
  __int64 v49; // [xsp+18h] [xbp-48h]
  __int64 v50; // [xsp+20h] [xbp-40h]
  __int64 v51; // [xsp+28h] [xbp-38h]
  __int64 v52; // [xsp+30h] [xbp-30h]
  int v53; // [xsp+38h] [xbp-28h] BYREF
  char v54; // [xsp+3Ch] [xbp-24h]
  char v55; // [xsp+3Dh] [xbp-23h]
  unsigned __int64 time_of_the_day_us; // [xsp+3Eh] [xbp-22h]
  unsigned __int64 StatusReg; // [xsp+46h] [xbp-1Ah]
  __int16 v58; // [xsp+4Eh] [xbp-12h]
  char v59; // [xsp+50h] [xbp-10h]
  char v60; // [xsp+51h] [xbp-Fh]
  char v61; // [xsp+52h] [xbp-Eh]
  __int16 v62; // [xsp+53h] [xbp-Dh]
  char v63; // [xsp+55h] [xbp-Bh]
  __int64 v64; // [xsp+58h] [xbp-8h]

  result = 16;
  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_21;
  v13 = *(_QWORD *)(a1 + 216);
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = nullptr;
  if ( !v13 )
  {
    v44 = *((unsigned __int8 *)a2 + 4);
    v45 = *a2;
    v46 = "%s: vdev %d cm_id 0x%x: pdev not found";
LABEL_19:
    qdf_trace_msg(0x68u, 2u, v46, a3, a4, a5, a6, a7, a8, a9, a10, "cm_handle_disconnect_req", v44, v45);
    goto LABEL_20;
  }
  if ( !*(_QWORD *)(v13 + 80) )
  {
    v44 = *((unsigned __int8 *)a2 + 4);
    v45 = *a2;
    v46 = "%s: vdev %d cm_id 0x%x: psoc not found";
    goto LABEL_19;
  }
  rso_config_fl = wlan_cm_get_rso_config_fl(a1, "cm_handle_disconnect_req", 206);
  if ( !rso_config_fl )
  {
LABEL_20:
    result = 4;
    goto LABEL_21;
  }
  v15 = rso_config_fl;
  v16 = *(unsigned __int8 *)(a1 + 168);
  qdf_mem_set(&v47, 0x30u, 0);
  v17 = _qdf_mem_malloc(0x18u, "cm_handle_disconnect_req", 213);
  if ( v17 )
  {
    v18 = *(_DWORD *)(a1 + 16);
    v19 = *((_BYTE *)a2 + 4);
    v20 = (void *)v17;
    v53 = 1703946;
    v54 = v18;
    v55 = v19;
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v21 = a2[2];
    v58 = a2[3];
    v22 = *((_BYTE *)a2 + 22);
    v60 = v21;
    LOBYTE(v21) = *((_BYTE *)a2 + 16);
    v59 = v22;
    v23 = *(_WORD *)((char *)a2 + 17);
    v61 = v21;
    LOBYTE(v21) = *((_BYTE *)a2 + 21);
    v62 = v23;
    v63 = v21;
    wlan_cp_stats_cstats_write_to_buff(0, &v53, 30);
    cm_csr_handle_diconnect_req(a1, a2);
    wlan_roam_reset_roam_params(a1);
    if ( a2[2] != 18 )
      cm_roam_restore_default_config(v13, v16);
    if ( !*(_DWORD *)(a1 + 16)
      && ((wlan_vdev_mlme_is_mlo_vdev(a1, v24, v25, v26, v27, v28, v29, v30, v31) & 1) == 0
       || (*(_BYTE *)(a1 + 60) & 2) == 0) )
    {
      wlan_cm_roam_state_change(v13, v16, 0, 4);
    }
    v32 = *(_QWORD *)(v15 + 848);
    if ( v32 )
      _qdf_mem_free(v32);
    *(_QWORD *)(v15 + 848) = 0;
    *(_BYTE *)(v15 + 840) = 0;
    qdf_mem_copy(v20, a2, 0x18u);
    v48 = v20;
    LOWORD(v47) = 5292;
    result = scheduler_post_message_debug(
               0x1Fu,
               0x35u,
               53,
               (unsigned __int16 *)&v47,
               0xF4u,
               (__int64)"cm_handle_disconnect_req");
    if ( (_DWORD)result )
    {
      v41 = *((unsigned __int8 *)a2 + 4);
      v42 = *a2;
      v43 = result;
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: msg post fail",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "cm_handle_disconnect_req",
        v41,
        v42);
      _qdf_mem_free((__int64)v20);
      result = v43;
    }
  }
  else
  {
    result = 2;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
