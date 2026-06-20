__int64 __fastcall sme_ps_set_powersave(__int64 a1, unsigned int a2, char a3, unsigned int a4, char a5)
{
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w24
  int opmode_from_vdev_id; // w24
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w1
  _QWORD *v55; // x0
  unsigned int v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x21
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w2
  char v76[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v77; // [xsp+8h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v76[0] = 0;
  v10 = sme_acquire_global_lock(a1 + 12768);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Allow power save %d vdev %d timeout %d imm ps %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "sme_ps_set_powersave",
      a3 & 1,
      (unsigned __int8)a2,
      a4,
      a5 & 1);
    mlme_set_user_ps(*(_QWORD *)(a1 + 21552), a2, a3 & 1);
    opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), a2);
    if ( (a3 & 1) != 0 && !opmode_from_vdev_id && (a5 & 1) == 0 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Defer power-save due to AP spec non-conformance",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "sme_ps_set_powersave");
      a4 = 1500;
    }
    if ( (a3 & 1) != 0 )
    {
      if ( (opmode_from_vdev_id | 2) != 2
        || (qdf_trace_msg(
              0x34u,
              8u,
              "%s: Disabling Auto Power save timer",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "sme_ps_set_powersave"),
            !sme_is_session_id_valid(a1, (unsigned __int8)a2, v29, v30, v31, v32, v33, v34, v35, v36)) )
      {
LABEL_13:
        wlan_mlme_is_bmps_enabled(*(_QWORD *)(a1 + 21552), v76);
        if ( v76[0] == 1 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Wlan driver Entering Power save",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "sme_ps_set_powersave");
          v54 = (unsigned __int8)a2;
          v55 = (_QWORD *)a1;
          if ( a4 )
          {
            v56 = sme_ps_enable_auto_ps_timer(a1, (unsigned __int8)a2, a4);
LABEL_26:
            v19 = v56;
            goto LABEL_27;
          }
          v74 = 0;
LABEL_25:
          v56 = sme_ps_enable_disable(v55, v54, v74);
          goto LABEL_26;
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Power Save is not enabled in the cfg",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "sme_ps_set_powersave");
        goto LABEL_23;
      }
      if ( (unsigned __int8)a2 < 7u )
      {
        v37 = a1 + 13120 + 192LL * (unsigned __int8)a2;
        if ( (unsigned int)qdf_mc_timer_get_current_state(v37 + 24) == 21 )
        {
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Stop auto_ps_enable_timer Timer for session ID: %d",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "sme_ps_disable_auto_ps_timer",
            (unsigned __int8)a2);
          qdf_mc_timer_stop(v37 + 24);
        }
        goto LABEL_13;
      }
LABEL_29:
      __break(0x5512u);
      JUMPOUT(0x75C9D90);
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Wlan driver Entering Full Power",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "sme_ps_set_powersave");
    if ( sme_is_session_id_valid(a1, (unsigned __int8)a2, v57, v58, v59, v60, v61, v62, v63, v64) )
    {
      if ( (unsigned __int8)a2 >= 7u )
        goto LABEL_29;
      v65 = a1 + 13120 + 192LL * (unsigned __int8)a2;
      if ( (unsigned int)qdf_mc_timer_get_current_state(v65 + 24) == 21 )
      {
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Stop auto_ps_enable_timer Timer for session ID: %d",
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          "sme_ps_disable_auto_ps_timer",
          (unsigned __int8)a2);
        qdf_mc_timer_stop(v65 + 24);
      }
    }
    wlan_mlme_is_bmps_enabled(*(_QWORD *)(a1 + 21552), v76);
    if ( v76[0] == 1 )
    {
      v54 = (unsigned __int8)a2;
      v55 = (_QWORD *)a1;
      v74 = 1;
      goto LABEL_25;
    }
LABEL_23:
    v19 = 0;
LABEL_27:
    sme_release_global_lock(a1 + 12768);
    goto LABEL_28;
  }
  v19 = v10;
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: can't acquire sme global lock",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "sme_ps_set_powersave");
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return v19;
}
