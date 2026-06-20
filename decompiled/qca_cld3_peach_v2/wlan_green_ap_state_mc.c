__int64 __fastcall wlan_green_ap_state_mc(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v12; // x9
  _QWORD *v13; // x24
  unsigned int v14; // w20
  unsigned __int64 StatusReg; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 (__fastcall *v25)(_QWORD); // x8
  __int64 v26; // x0
  __int16 v27; // w22
  __int64 (__fastcall *v28)(_QWORD); // x8
  __int64 v29; // x0
  int v30; // w23
  const char *v31; // x2
  const char *v32; // x2
  __int64 v34; // x4
  int v35; // w8
  int v36; // w8
  int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w4
  const char *v47; // x2
  _DWORD *v48; // x8
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  _DWORD *v59; // x8
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  const char *v69; // x2
  _DWORD *v70; // x8
  __int64 v71; // x0
  int v72; // w8
  __int64 v73; // x8
  __int64 v74; // x0
  _DWORD *v75; // x8
  __int64 v76; // x1
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7

  if ( !a1 )
  {
    v31 = "%s: green ap context obtained is NULL";
LABEL_21:
    qdf_trace_msg(0x5Du, 2u, v31, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_green_ap_state_mc");
    return 16;
  }
  v10 = *a1;
  if ( !*a1 )
  {
    v31 = "%s: pdev obtained is NULL";
    goto LABEL_21;
  }
  v12 = *(_QWORD *)(v10 + 80);
  if ( !v12 )
  {
    v32 = "%s: pdev context obtained is NULL";
LABEL_20:
    qdf_trace_msg(0x5Du, 2u, v32, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_psoc_get_green_ap_tx_ops");
    v31 = "%s: green ap tx ops obtained are NULL";
    goto LABEL_21;
  }
  v13 = *(_QWORD **)(v12 + 2128);
  if ( !v13 )
  {
    v32 = "%s: tx_ops is NULL";
    goto LABEL_20;
  }
  if ( !v13[231] )
  {
    v31 = "%s: tx op for sending enable/disable green ap is NULL";
    goto LABEL_21;
  }
  v14 = *(unsigned __int8 *)(v10 + 40);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 11);
    v25 = (__int64 (__fastcall *)(_QWORD))v13[233];
    if ( v25 )
      goto LABEL_10;
  }
  else
  {
    raw_spin_lock_bh(a1 + 11);
    a1[12] |= 1uLL;
    v25 = (__int64 (__fastcall *)(_QWORD))v13[233];
    if ( v25 )
    {
LABEL_10:
      v26 = *a1;
      if ( *((_DWORD *)v25 - 1) != -1779848236 )
        __break(0x8228u);
      v27 = v25(v26);
      v28 = (__int64 (__fastcall *)(_QWORD))v13[234];
      if ( v28 )
        goto LABEL_13;
LABEL_26:
      v30 = 1;
      goto LABEL_27;
    }
  }
  v27 = 1;
  v28 = (__int64 (__fastcall *)(_QWORD))v13[234];
  if ( !v28 )
    goto LABEL_26;
LABEL_13:
  v29 = *a1;
  if ( *((_DWORD *)v28 - 1) != 155122633 )
    __break(0x8228u);
  v30 = v28(v29);
LABEL_27:
  v34 = a2;
  if ( (int)a2 > 4 )
  {
    if ( a2 - 7 < 2 )
      goto LABEL_42;
    if ( a2 == 5 )
    {
      v37 = *((_DWORD *)a1 + 5) + 1;
    }
    else
    {
      if ( a2 != 6 )
        goto LABEL_38;
      v36 = *((_DWORD *)a1 + 5);
      if ( !v36 )
        goto LABEL_42;
      v37 = v36 - 1;
    }
    *((_DWORD *)a1 + 5) = v37;
    goto LABEL_42;
  }
  if ( a2 - 1 < 2 )
    goto LABEL_42;
  if ( a2 == 3 )
  {
    ++*((_DWORD *)a1 + 4);
    goto LABEL_42;
  }
  if ( a2 != 4 )
  {
LABEL_38:
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: Invalid event: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_green_ap_state_mc",
      a2);
    v34 = a2;
    goto LABEL_42;
  }
  v35 = *((_DWORD *)a1 + 4);
  if ( v35 )
    *((_DWORD *)a1 + 4) = v35 - 1;
LABEL_42:
  qdf_trace_msg(
    0x5Du,
    8u,
    "%s: Green-AP event: %d, state: %d, num_nodes: %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_green_ap_state_mc",
    v34,
    *((unsigned int *)a1 + 6),
    *((unsigned int *)a1 + 4));
  if ( !*((_BYTE *)a1 + 8) )
  {
    qdf_trace_msg(
      0x5Du,
      8u,
      "%s: Green-AP is disabled",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_green_ap_state_mc");
    if ( *((_DWORD *)a1 + 6) == 4 )
    {
      v48 = (_DWORD *)v13[231];
      v49 = *a1;
      if ( *(v48 - 1) != -478210983 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v48)(v49, 0, v14) )
        qdf_trace_msg(
          0x5Du,
          2u,
          "%s: failed to set green ap mode",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "wlan_green_ap_state_mc");
      wlan_green_ap_ant_ps_reset(a1);
    }
    v58 = 1;
    goto LABEL_88;
  }
  v46 = *((_DWORD *)a1 + 6);
  if ( v46 <= 2 )
  {
    if ( v46 != 1 )
    {
      if ( v46 == 2 )
      {
        if ( (*((_DWORD *)a1 + 4) || *((_BYTE *)a1 + 9) != 1) && (*((_DWORD *)a1 + 5) || *((_BYTE *)a1 + 9) != 2) )
          goto LABEL_89;
        v47 = "%s: Transition to WAIT from OFF";
        goto LABEL_99;
      }
      goto LABEL_68;
    }
    if ( (!*((_DWORD *)a1 + 4) || *((_BYTE *)a1 + 9) != 1) && (!*((_DWORD *)a1 + 5) || *((_BYTE *)a1 + 9) != 2) )
    {
      v47 = "%s: Transition to WAIT from IDLE";
LABEL_99:
      qdf_trace_msg(0x5Du, 4u, v47, v38, v39, v40, v41, v42, v43, v44, v45, "wlan_green_ap_state_mc");
      v76 = (unsigned int)(1000 * *((_DWORD *)a1 + 3));
      a1[3] = 0x800000003LL;
LABEL_100:
      qdf_timer_start(a1 + 4, v76);
      goto LABEL_89;
    }
    v69 = "%s: Transition to OFF from IDLE";
LABEL_74:
    qdf_trace_msg(0x5Du, 4u, v69, v38, v39, v40, v41, v42, v43, v44, v45, "wlan_green_ap_state_mc");
    goto LABEL_87;
  }
  if ( v46 == 3 )
  {
    if ( (*((_DWORD *)a1 + 4) || *((_BYTE *)a1 + 9) != 1) && (*((_DWORD *)a1 + 5) || *((_BYTE *)a1 + 9) != 2) )
    {
      qdf_trace_msg(
        0x5Du,
        4u,
        "%s: Transition to OFF from WAIT",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "wlan_green_ap_state_mc");
      timer_delete(a1 + 4);
      goto LABEL_87;
    }
    if ( a2 != 6 )
    {
      if ( v27 && v30 )
      {
        a1[3] = 0x800000004LL;
        qdf_trace_msg(
          0x5Du,
          4u,
          "%s: Transition to ON from WAIT",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlan_green_ap_state_mc");
        v70 = (_DWORD *)v13[231];
        v71 = *a1;
        if ( *(v70 - 1) != -478210983 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, __int64, _QWORD))v70)(v71, 1, v14);
        wlan_green_ap_ant_ps_reset(a1);
        v72 = *((unsigned __int8 *)a1 + 10);
        if ( !*((_BYTE *)a1 + 10) )
          goto LABEL_89;
      }
      else
      {
        v72 = *((unsigned __int8 *)a1 + 10);
      }
      goto LABEL_103;
    }
  }
  else
  {
    if ( v46 != 4 )
    {
LABEL_68:
      qdf_trace_msg(0x5Du, 2u, "%s: invalid state %d", v38, v39, v40, v41, v42, v43, v44, v45, "wlan_green_ap_state_mc");
LABEL_87:
      v58 = 2;
LABEL_88:
      a1[3] = v58 & 0xFFFF0000FFFFFFFFLL | 0x800000000LL;
      goto LABEL_89;
    }
    if ( *((_DWORD *)a1 + 4) && *((_BYTE *)a1 + 9) == 1 || *((_DWORD *)a1 + 5) && *((_BYTE *)a1 + 9) == 2 )
    {
      timer_delete(a1 + 4);
      v59 = (_DWORD *)v13[231];
      v60 = *a1;
      if ( *(v59 - 1) != -478210983 )
        __break(0x8228u);
      if ( !((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v59)(v60, 0, v14) )
      {
        wlan_green_ap_ant_ps_reset(a1);
        v69 = "%s: Transition to OFF from ON\n";
        goto LABEL_74;
      }
LABEL_97:
      qdf_trace_msg(
        0x5Du,
        2u,
        "%s: Failed to set Green AP mode",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "wlan_green_ap_state_mc");
      goto LABEL_89;
    }
    if ( *((_DWORD *)a1 + 7) == 8 && *((_BYTE *)a1 + 10) )
    {
      v74 = *a1;
      a1[3] = 0x700000003LL;
      v75 = (_DWORD *)v13[231];
      if ( *(v75 - 1) != -478210983 )
        __break(0x8228u);
      if ( ((unsigned int (__fastcall *)(__int64, _QWORD, _QWORD))v75)(v74, 0, v14) )
        goto LABEL_97;
      wlan_green_ap_ant_ps_reset(a1);
      qdf_trace_msg(
        0x5Du,
        4u,
        "%s: Transition to WAIT from ON\n",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "wlan_green_ap_state_mc");
      v72 = *((_DWORD *)a1 + 3);
LABEL_103:
      v76 = (unsigned int)(1000 * v72);
      goto LABEL_100;
    }
  }
LABEL_89:
  v73 = a1[12];
  if ( (v73 & 1) != 0 )
  {
    a1[12] = v73 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 11);
  }
  else
  {
    raw_spin_unlock(a1 + 11);
  }
  return 0;
}
