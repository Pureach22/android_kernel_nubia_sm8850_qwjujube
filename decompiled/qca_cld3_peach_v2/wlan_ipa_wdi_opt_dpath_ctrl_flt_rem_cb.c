__int64 __fastcall wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb(
        __int64 a1,
        unsigned __int8 *a2,
        __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x23
  unsigned int v14; // w21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w2
  int v32; // w3
  int v33; // w4
  int v34; // w5
  int v35; // w6
  int v36; // w7
  const char *v37; // x1
  _DWORD *v39; // x22
  __int64 v40; // x20
  __int64 v41; // x27
  unsigned __int64 StatusReg; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x28
  char v52; // w26
  unsigned int *v53; // x22
  int v54; // w3
  int v55; // w4
  int v56; // w5
  int v57; // w6
  int v58; // w7
  int v59; // w3
  int v60; // w4
  int v61; // w5
  int v62; // w6
  int v63; // w7
  int v64; // w3
  int v65; // w4
  int v66; // w5
  int v67; // w6
  int v68; // w7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x0
  __int64 v78; // x8
  void (*v79)(void); // x8
  __int64 v80; // x8
  int v81; // w3
  int v82; // w4
  int v83; // w5
  int v84; // w6
  int v85; // w7
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  int v94; // w0
  int v95; // w19
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  unsigned int v104; // w19
  int v105; // w3
  int v106; // w4
  int v107; // w5
  int v108; // w6
  int v109; // w7
  __int64 v110; // x8
  int v111; // w2
  int v112; // w3
  int v113; // w4
  int v114; // w5
  int v115; // w6
  int v116; // w7
  __int64 v117; // x8
  char v118; // [xsp+0h] [xbp-10h]

  v11 = *(_QWORD *)a1;
  if ( a2 )
  {
    v14 = *a2;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: num of filters to be removed %d:",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
      *a2);
  }
  else
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: delete all active filter request",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
    v14 = 3;
  }
  if ( !lmac_get_htc_hdl(v11, v15, v16, v17, v18, v19, v20, v21, v22) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: HTC Handle is null",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
    v37 = "HTC Handle is null";
    goto LABEL_8;
  }
  if ( v14 > 3 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: opt_dp_ctrl, num of flts received from ipa is invalid",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
    v37 = "opt_dp_ctrl, num of flts received from ipa is invalid";
LABEL_8:
    wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb", (int)v37, v31, v32, v33, v34, v35, v36, v118);
    return 201;
  }
  if ( v14 )
  {
    v39 = a2 + 4;
    if ( a2 && (unsigned int)(*v39 - 19) <= 0xFFFFFFFC )
    {
      v40 = 0;
LABEL_66:
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: opt_dp_ctrl, wrong flt hdl %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
        (int)"opt_dp_ctrl, wrong flt hdl %d",
        v39[v40],
        v105,
        v106,
        v107,
        v108,
        v109,
        v118);
      return 201;
    }
    if ( v14 != 1 )
    {
      if ( a2 && (unsigned int)(*((_DWORD *)a2 + 2) - 19) < 0xFFFFFFFD )
      {
        v40 = 1;
        goto LABEL_66;
      }
      if ( v14 != 2 && a2 && (unsigned int)(*((_DWORD *)a2 + 3) - 19) < 0xFFFFFFFD )
      {
        v40 = 2;
        goto LABEL_66;
      }
    }
  }
  v41 = a1 + 4096;
  *(_DWORD *)(a1 + 8396) += v14;
  if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 && (*(_DWORD *)(StatusReg + 16) & 0xFF00) == 0 )
    {
      raw_spin_lock_bh(a1 + 8056);
      *(_QWORD *)(a1 + 8064) |= 1uLL;
      if ( v14 )
        goto LABEL_19;
LABEL_75:
      if ( (*(_BYTE *)(a1 + 7465) & 1) != 0 || *(_BYTE *)(a1 + 7464) == 1 )
      {
        v110 = *(_QWORD *)(a1 + 8064);
        if ( (v110 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 8064) = v110 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 8056);
        }
        else
        {
          raw_spin_unlock(a1 + 8056);
        }
        return 0;
      }
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: opt_dp_ctrl, filter received not found in internal DB",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
        (int)"opt_dp_ctrl, filter received not found in internal DB",
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v118);
      v117 = *(_QWORD *)(a1 + 8064);
      if ( (v117 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 8064) = v117 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 8056);
      }
      else
      {
        raw_spin_unlock(a1 + 8056);
      }
      return 201;
    }
  }
  raw_spin_lock(a1 + 8056);
  if ( !v14 )
    goto LABEL_75;
LABEL_19:
  v51 = 0;
  v52 = 0;
  do
  {
    while ( 1 )
    {
      v53 = (unsigned int *)&a2[4 * v51 + 4];
      if ( a2 )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: flt handle received from ipa %u",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
          *v53);
        if ( *v53 != *(_DWORD *)(a1 + 7792) )
        {
LABEL_26:
          if ( *v53 != *(_DWORD *)(a1 + 7896) )
            goto LABEL_30;
          goto LABEL_27;
        }
      }
      if ( *(_BYTE *)(a1 + 7797) == 1 && !*(_BYTE *)(a1 + 7796) )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: filter hdl found in DB %d:",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
          *(unsigned int *)(a1 + 7792));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
          (int)"opt_dp_ctrl: filter hdl found in DB %d:",
          *(_DWORD *)(a1 + 7792),
          v59,
          v60,
          v61,
          v62,
          v63,
          v118);
        v52 = 1;
        *(_BYTE *)(a1 + 7796) = 1;
        qdf_event_reset(a1 + 7800);
        *(_WORD *)(a1 + 7840) = a3;
        if ( a2 )
          goto LABEL_26;
      }
      else if ( a2 )
      {
        goto LABEL_26;
      }
LABEL_27:
      if ( *(_BYTE *)(a1 + 7901) == 1 && !*(_BYTE *)(a1 + 7900) )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: filter hdl found in DB %d:",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
          *(unsigned int *)(a1 + 7896));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
          (int)"opt_dp_ctrl: filter hdl found in DB %d:",
          *(_DWORD *)(a1 + 7896),
          v64,
          v65,
          v66,
          v67,
          v68,
          v118);
        v52 = 1;
        *(_BYTE *)(a1 + 7900) = 1;
        qdf_event_reset(a1 + 7904);
        *(_WORD *)(a1 + 7944) = a3;
        if ( !a2 )
          goto LABEL_31;
      }
      else if ( !a2 )
      {
        goto LABEL_31;
      }
LABEL_30:
      if ( *v53 != *(_DWORD *)(a1 + 8000) )
        break;
LABEL_31:
      if ( *(_BYTE *)(a1 + 8005) != 1 || *(_BYTE *)(a1 + 8004) )
        break;
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: filter hdl found in DB %d:",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
        *(unsigned int *)(a1 + 8000));
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
        (int)"opt_dp_ctrl: filter hdl found in DB %d:",
        *(_DWORD *)(a1 + 8000),
        v54,
        v55,
        v56,
        v57,
        v58,
        v118);
      v52 = 1;
      *(_BYTE *)(a1 + 8004) = 1;
      qdf_event_reset(a1 + 8008);
      ++v51;
      *(_WORD *)(a1 + 8048) = a3;
      if ( v51 == v14 )
        goto LABEL_40;
    }
    ++v51;
  }
  while ( v51 != v14 );
  if ( (v52 & 1) == 0 )
    goto LABEL_75;
LABEL_40:
  *(_WORD *)(a1 + 7736) = 256;
  *(_BYTE *)(a1 + 7738) = v14;
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: op %d, pdev_id %d. num_flts %d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
    1,
    0,
    v14);
  v77 = *(_QWORD *)(a1 + 1456);
  if ( v77 && *(_QWORD *)v77 && (v78 = *(_QWORD *)(*(_QWORD *)v77 + 152LL)) != 0 )
  {
    v79 = *(void (**)(void))(v78 + 232);
    if ( v79 )
    {
      if ( *((_DWORD *)v79 - 1) != -1963433128 )
        __break(0x8228u);
      v79();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "cdp_ipa_tx_super_rule_setup");
  }
  v80 = *(_QWORD *)(a1 + 8064);
  if ( (v80 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 8056);
    if ( *(_BYTE *)(a1 + 7796) )
      goto LABEL_53;
LABEL_72:
    v94 = 0;
    if ( !*(_BYTE *)(a1 + 7900) )
      goto LABEL_55;
LABEL_54:
    v94 = qdf_wait_single_event(a1 + 7904, 0x64u);
    goto LABEL_55;
  }
  *(_QWORD *)(a1 + 8064) = v80 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 8056);
  if ( !*(_BYTE *)(a1 + 7796) )
    goto LABEL_72;
LABEL_53:
  v94 = qdf_wait_single_event(a1 + 7800, 0x64u);
  if ( *(_BYTE *)(a1 + 7900) )
    goto LABEL_54;
LABEL_55:
  if ( *(_BYTE *)(a1 + 8004) )
    v94 = qdf_wait_single_event(a1 + 8008, 0x64u);
  *(_BYTE *)(a1 + 7796) = 0;
  *(_BYTE *)(a1 + 7900) = 0;
  *(_BYTE *)(a1 + 8004) = 0;
  if ( v94 )
  {
    v95 = v94;
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: flt delete failure",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
    if ( v95 == 15 )
    {
      if ( (*(_BYTE *)(v41 + 3369) & 1) != 0 || *(_BYTE *)(v41 + 3368) == 1 )
      {
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl, ssr or shutdown casereturn success",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
        v104 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: TIMEOUT_OCCURS",
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
        v104 = 202;
      }
    }
    else
    {
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Error on event wait for filter rem cb",
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb");
      v104 = 201;
    }
  }
  else
  {
    v104 = 0;
  }
  wlan_ipa_log_message(
    (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_rem_cb",
    (int)"opt_dp_ctrl: filter del status - %d",
    v104,
    v81,
    v82,
    v83,
    v84,
    v85,
    v118);
  return v104;
}
