__int64 __fastcall wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete(
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
  __int64 v9; // x21
  int v10; // w2
  int v11; // w3
  int v12; // w4
  int v13; // w5
  int v14; // w6
  int v15; // w7
  __int64 v18; // x23
  unsigned int v19; // w20
  __int16 v20; // w28
  __int64 v21; // x9
  __int64 v22; // x24
  unsigned __int16 *v23; // x8
  int v24; // w27
  int v25; // w26
  int v26; // w25
  int v27; // w6
  int v28; // w7
  __int64 v29; // x1
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x10
  int v39; // w8
  int v40; // w9
  __int64 v41; // x25
  unsigned int v42; // w26
  int v43; // w2
  int v44; // w3
  int v45; // w4
  int v46; // w5
  int v47; // w6
  int v48; // w7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned __int16 *v57; // x25
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  unsigned int v67; // w9
  __int64 v68; // x9
  __int16 v69; // w10
  __int64 v70; // x8
  unsigned __int16 v71; // w26
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x8
  int v81; // w2
  int v82; // w3
  int v83; // w4
  int v84; // w5
  int v85; // w6
  int v86; // w7
  char v87; // [xsp+0h] [xbp-40h]
  __int64 v88; // [xsp+8h] [xbp-38h]
  __int64 v89; // [xsp+10h] [xbp-30h]
  unsigned __int64 StatusReg; // [xsp+18h] [xbp-28h]
  __int64 v91; // [xsp+20h] [xbp-20h]
  __int64 v92; // [xsp+28h] [xbp-18h]
  _DWORD *v93; // [xsp+30h] [xbp-10h]
  __int64 v94; // [xsp+38h] [xbp-8h]

  v9 = gp_ipa;
  if ( !gp_ipa || *(_BYTE *)(gp_ipa + 7466) == 1 )
  {
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: opt_dp_ctrl: flt cleaned internally",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete");
    return wlan_ipa_log_message(
             (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
             (int)"opt_dp_ctrl: flt cleaned internally",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v87);
  }
  v18 = 0;
  v19 = 0;
  v93 = (_DWORD *)(gp_ipa + 8400);
  v94 = gp_ipa + 7744;
  v20 = 0;
  v89 = gp_ipa + 8408;
  v92 = gp_ipa + 8424;
  v21 = gp_ipa + 7848;
  v88 = gp_ipa + 7952;
  v22 = gp_ipa + 7800;
  StatusReg = _ReadStatusReg(SP_EL0);
  v91 = v21;
  do
  {
    v23 = (unsigned __int16 *)(a1 + v18);
    v24 = *(unsigned __int8 *)(a1 + v18 + 2);
    if ( !*(_BYTE *)(a1 + v18 + 2) )
      goto LABEL_6;
    v25 = *v23;
    v26 = *((unsigned __int8 *)v23 + 3);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: i: %d, valid: %d, result: %d, dst_port: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
      v19,
      *(unsigned __int8 *)(a1 + v18 + 2),
      *((unsigned __int8 *)v23 + 3),
      *v23);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
      (int)"opt_dp_ctrl: i: %d, valid: %d, result: %d, dst_port: %d",
      v19,
      v24,
      v26,
      v25,
      v27,
      v28,
      v87);
    if ( v26 == 2 )
    {
      v38 = (_DWORD *)v92;
      v39 = 0;
      v20 = 203;
      --*v93;
      v40 = 1;
LABEL_14:
      *v38 += v40;
      goto LABEL_15;
    }
    qdf_event_set(v22, v29);
    if ( v26 == 1 )
    {
      v38 = v93;
      v39 = 0;
      v20 = 0;
      v40 = -1;
      *(_DWORD *)(v9 + 7740) = 0;
      goto LABEL_14;
    }
    if ( !v26 )
    {
      v38 = (_DWORD *)v89;
      v40 = 1;
      *(_DWORD *)(v9 + 7740) = 49;
      v39 = 1;
      goto LABEL_14;
    }
    v39 = 0;
LABEL_15:
    if ( v25 == *(unsigned __int16 *)(v9 + 7790) )
    {
      v41 = v94;
      v42 = 0;
    }
    else if ( v25 == *(unsigned __int16 *)(v9 + 7894) )
    {
      v41 = v91;
      v42 = 1;
    }
    else
    {
      if ( v25 != *(unsigned __int16 *)(v9 + 7998) )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: opt_dp_ctrl, handle not found in internal DB",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete");
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
          (int)"opt_dp_ctrl, handle not found in internal DB",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87);
        goto LABEL_6;
      }
      v41 = v88;
      v42 = 2;
    }
    if ( v39 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: filter with handle found but del failed on fw side",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete");
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
        (int)"opt_dp_ctrl: filter with handle found but del failed on fw side",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v87);
      v20 = 200;
    }
    else
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: filter with handle %d is deleting",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
        v42);
      *(_BYTE *)v41 = 0;
      qdf_mem_set((void *)(v41 + 1), 4u, 0);
      qdf_mem_set((void *)(v41 + 9), 0x10u, 0);
      qdf_mem_set((void *)(v41 + 5), 4u, 0);
      qdf_mem_set((void *)(v41 + 25), 0x10u, 0);
      *(_WORD *)(v41 + 52) = 0;
    }
    if ( *(_WORD *)(v94 + 104LL * v42 + 96) == 1 )
    {
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl, flt hdl %d delete due to shutdown",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlan_ipa_wdi_opt_dpath_ctrl_notify_flt_delete",
        v19 + 16);
      v20 = 204;
      *(_BYTE *)(v22 - 3) = 0;
    }
    v57 = *(unsigned __int16 **)(v9 + 2856);
    *(_WORD *)(v9 + 2864) |= 2u;
    if ( !v57 || !*((_QWORD *)v57 + 1) )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: list allocation failed",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wlan_fw_event_msg_list_enqueue_flt_hdl");
      goto LABEL_6;
    }
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: enqueue msg to the list",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wlan_fw_event_msg_list_enqueue_flt_hdl");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v57 + 12);
    }
    else
    {
      raw_spin_lock_bh(v57 + 12);
      *((_QWORD *)v57 + 4) |= 1uLL;
    }
    v66 = *v57;
    v67 = v57[1];
    if ( v67 <= (unsigned int)v66 )
    {
      if ( !((_WORD)v67 + v57[8] + ~(_WORD)v66) )
      {
LABEL_38:
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: list is full",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "wlan_fw_event_msg_list_enqueue_flt_hdl");
        v80 = *((_QWORD *)v57 + 4);
        if ( (v80 & 1) != 0 )
        {
          *((_QWORD *)v57 + 4) = v80 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v57 + 12);
        }
        else
        {
          raw_spin_unlock(v57 + 12);
        }
        goto LABEL_6;
      }
    }
    else if ( !((_WORD)v67 + ~(_WORD)v66) )
    {
      goto LABEL_38;
    }
    v68 = *((_QWORD *)v57 + 1) + 32 * v66;
    *(_DWORD *)(v68 + 20) = v19 + 16;
    *(_WORD *)(v68 + 24) = v20;
    *(_WORD *)(v68 + 16) = 14;
    v69 = v66 + 1;
    v70 = *((_QWORD *)v57 + 4);
    v71 = (v57[8] - 1) & v69;
    *v57 = v71;
    if ( (v70 & 1) != 0 )
    {
      *((_QWORD *)v57 + 4) = v70 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v57 + 12);
    }
    else
    {
      raw_spin_unlock(v57 + 12);
    }
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: hp value %d",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "wlan_fw_event_msg_list_enqueue_flt_hdl",
      v71);
LABEL_6:
    v18 += 4;
    ++v19;
    v22 += 104;
  }
  while ( v18 != 12 );
  return queue_work_on(32, system_wq, v9 + 2784);
}
