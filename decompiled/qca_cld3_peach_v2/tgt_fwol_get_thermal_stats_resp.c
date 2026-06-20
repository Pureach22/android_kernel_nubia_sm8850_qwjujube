__int64 __fastcall tgt_fwol_get_thermal_stats_resp(__int64 a1, __int64 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  unsigned int ref; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  __int64 v33; // x9
  __int64 v34; // x10
  __int64 v35; // x11
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x12
  __int64 v39; // x9
  __int64 v40; // x10
  __int64 v41; // x11
  __int64 v42; // x12
  __int64 v43; // x10
  __int64 v44; // x12
  __int64 v45; // x11
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w19
  __int64 *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // [xsp+8h] [xbp-38h] BYREF
  __int64 *v65; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v66)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v67)(__int64, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v68; // [xsp+28h] [xbp-18h]
  __int64 v69; // [xsp+30h] [xbp-10h]
  __int64 v70; // [xsp+38h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v69 = 0;
  v66 = nullptr;
  v67 = nullptr;
  v64 = 0;
  v65 = nullptr;
  v4 = _qdf_mem_malloc(0x80u, "tgt_fwol_get_thermal_stats_resp", 226);
  if ( v4 )
  {
    v13 = v4;
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0x47u, v5, v6, v7, v8, v9, v10, v11, v12);
    if ( ref )
    {
      v23 = ref;
      qdf_trace_msg(
        0x66u,
        2u,
        "%s: Failed to get psoc ref",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "tgt_fwol_get_thermal_stats_resp");
      fwol_release_rx_event((__int64 *)v13, v24, v25, v26, v27, v28, v29, v30, v31);
      result = v23;
    }
    else
    {
      *(_QWORD *)v13 = a1;
      *(_DWORD *)(v13 + 8) = 2;
      v34 = a2[1];
      v33 = a2[2];
      v35 = *a2;
      LOWORD(v64) = 2;
      *(_QWORD *)(v13 + 12) = v35;
      *(_QWORD *)(v13 + 28) = v33;
      *(_QWORD *)(v13 + 20) = v34;
      v36 = a2[5];
      v37 = a2[3];
      v38 = a2[4];
      *(_QWORD *)(v13 + 60) = a2[6];
      *(_QWORD *)(v13 + 52) = v36;
      *(_QWORD *)(v13 + 44) = v38;
      *(_QWORD *)(v13 + 36) = v37;
      v40 = a2[9];
      v39 = a2[10];
      v65 = (__int64 *)v13;
      v66 = fwol_process_event;
      v41 = a2[7];
      v42 = a2[8];
      *(_QWORD *)(v13 + 92) = v39;
      *(_QWORD *)(v13 + 84) = v40;
      *(_QWORD *)(v13 + 76) = v42;
      *(_QWORD *)(v13 + 68) = v41;
      v44 = a2[12];
      v43 = a2[13];
      LODWORD(v39) = *((_DWORD *)a2 + 28);
      v45 = a2[11];
      v67 = fwol_flush_callback;
      *(_DWORD *)(v13 + 124) = v39;
      *(_QWORD *)(v13 + 116) = v43;
      *(_QWORD *)(v13 + 108) = v44;
      *(_QWORD *)(v13 + 100) = v45;
      result = scheduler_post_message_debug(
                 0x66u,
                 0x66u,
                 73,
                 (unsigned __int16 *)&v64,
                 0xF6u,
                 (__int64)"tgt_fwol_get_thermal_stats_resp");
      if ( (_DWORD)result )
      {
        v54 = result;
        qdf_trace_msg(
          0x66u,
          2u,
          "%s: failed to send WLAN_FWOL_EVT_GET_THERMAL_STATS_RESPONSE msg",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "tgt_fwol_get_thermal_stats_resp");
        v55 = v65;
        v65 = nullptr;
        fwol_release_rx_event(v55, v56, v57, v58, v59, v60, v61, v62, v63);
        result = v54;
      }
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
