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
  __int64 v13; // x22
  __int64 v14; // x25
  __int64 rso_config_fl; // x0
  __int64 v16; // x21
  unsigned int v17; // w23
  __int64 v18; // x0
  int v19; // w9
  char v20; // w10
  void *v21; // x20
  unsigned int v22; // w8
  char v23; // w9
  __int16 v24; // w9
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x4
  __int64 v35; // x5
  unsigned int v36; // w19
  __int64 v37; // x4
  __int64 v38; // x5
  const char *v39; // x2
  __int64 v40; // [xsp+8h] [xbp-58h] BYREF
  void *v41; // [xsp+10h] [xbp-50h]
  __int64 v42; // [xsp+18h] [xbp-48h]
  __int64 v43; // [xsp+20h] [xbp-40h]
  __int64 v44; // [xsp+28h] [xbp-38h]
  __int64 v45; // [xsp+30h] [xbp-30h]
  int v46; // [xsp+38h] [xbp-28h] BYREF
  char v47; // [xsp+3Ch] [xbp-24h]
  char v48; // [xsp+3Dh] [xbp-23h]
  unsigned __int64 time_of_the_day_us; // [xsp+3Eh] [xbp-22h]
  unsigned __int64 StatusReg; // [xsp+46h] [xbp-1Ah]
  __int16 v51; // [xsp+4Eh] [xbp-12h]
  char v52; // [xsp+50h] [xbp-10h]
  char v53; // [xsp+51h] [xbp-Fh]
  char v54; // [xsp+52h] [xbp-Eh]
  __int16 v55; // [xsp+53h] [xbp-Dh]
  char v56; // [xsp+55h] [xbp-Bh]
  __int64 v57; // [xsp+58h] [xbp-8h]

  result = 16;
  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
    goto LABEL_17;
  v13 = *(_QWORD *)(a1 + 152);
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = nullptr;
  if ( !v13 )
  {
    v37 = *((unsigned __int8 *)a2 + 4);
    v38 = *a2;
    v39 = "%s: vdev %d cm_id 0x%x: pdev not found";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v39, a3, a4, a5, a6, a7, a8, a9, a10, "cm_handle_disconnect_req", v37, v38);
    goto LABEL_16;
  }
  if ( !*(_QWORD *)(v13 + 80) )
  {
    v37 = *((unsigned __int8 *)a2 + 4);
    v38 = *a2;
    v39 = "%s: vdev %d cm_id 0x%x: psoc not found";
    goto LABEL_15;
  }
  v14 = a1;
  rso_config_fl = wlan_cm_get_rso_config_fl(a1, "cm_handle_disconnect_req", 206);
  if ( !rso_config_fl )
  {
LABEL_16:
    result = 4;
    goto LABEL_17;
  }
  v16 = rso_config_fl;
  v17 = *(unsigned __int8 *)(v14 + 104);
  qdf_mem_set(&v40, 0x30u, 0);
  v18 = _qdf_mem_malloc(0x18u, "cm_handle_disconnect_req", 213);
  if ( !v18 )
  {
    result = 2;
    goto LABEL_17;
  }
  v19 = *(_DWORD *)(v14 + 16);
  v20 = *((_BYTE *)a2 + 4);
  v21 = (void *)v18;
  v46 = 1703946;
  v47 = v19;
  v48 = v20;
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  v22 = a2[2];
  v51 = a2[3];
  v23 = *((_BYTE *)a2 + 22);
  v53 = v22;
  LOBYTE(v22) = *((_BYTE *)a2 + 16);
  v52 = v23;
  v24 = *(_WORD *)((char *)a2 + 17);
  v54 = v22;
  LOBYTE(v22) = *((_BYTE *)a2 + 21);
  v55 = v24;
  v56 = v22;
  wlan_cp_stats_cstats_write_to_buff(0, &v46, 30);
  cm_csr_handle_diconnect_req(v14, a2);
  wlan_roam_reset_roam_params(v14);
  if ( a2[2] == 18 )
  {
    if ( *(_DWORD *)(v14 + 16) )
      goto LABEL_9;
  }
  else
  {
    cm_roam_restore_default_config(v13, v17);
    if ( *(_DWORD *)(v14 + 16) )
    {
LABEL_9:
      v25 = *(_QWORD *)(v16 + 848);
      if ( !v25 )
        goto LABEL_11;
      goto LABEL_10;
    }
  }
  wlan_cm_roam_state_change(v13, v17, 0, 4);
  v25 = *(_QWORD *)(v16 + 848);
  if ( v25 )
LABEL_10:
    _qdf_mem_free(v25);
LABEL_11:
  *(_QWORD *)(v16 + 848) = 0;
  *(_BYTE *)(v16 + 840) = 0;
  qdf_mem_copy(v21, a2, 0x18u);
  v41 = v21;
  LOWORD(v40) = 5292;
  result = scheduler_post_message_debug(
             0x1Fu,
             0x35u,
             53,
             (unsigned __int16 *)&v40,
             0xF4u,
             (__int64)"cm_handle_disconnect_req");
  if ( (_DWORD)result )
  {
    v34 = *((unsigned __int8 *)a2 + 4);
    v35 = *a2;
    v36 = result;
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: msg post fail",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "cm_handle_disconnect_req",
      v34,
      v35);
    _qdf_mem_free((__int64)v21);
    result = v36;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
