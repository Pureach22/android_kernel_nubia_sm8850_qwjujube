__int64 __fastcall wlan_ipa_uc_enable_pipes(
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
  unsigned __int64 StatusReg; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  unsigned int v20; // w20
  __int64 v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 (*v32)(void); // x8
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w3
  int v51; // w4
  int v52; // w5
  int v53; // w6
  int v54; // w7
  unsigned __int64 v55; // x8
  __int64 v56; // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w4
  int v66; // w5
  int v67; // w6
  int v68; // w7
  char v70; // [xsp+0h] [xbp+0h]

  qdf_trace_msg(0x61u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_ipa_uc_enable_pipes");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 3400);
  }
  else
  {
    raw_spin_lock_bh(a1 + 3400);
    *(_QWORD *)(a1 + 3408) |= 1uLL;
  }
  if ( *(_BYTE *)(a1 + 3442) == 1 )
  {
    qdf_trace_msg(
      0x61u,
      3u,
      "%s: IPA Pipes Enable in progress",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_ipa_uc_enable_pipes");
    v19 = *(_QWORD *)(a1 + 3408);
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 3408) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 3400);
    }
    else
    {
      raw_spin_unlock(a1 + 3400);
    }
    return 6;
  }
  v21 = *(_QWORD *)(a1 + 3408);
  *(_BYTE *)(a1 + 3442) = 1;
  if ( (v21 & 1) == 0 )
  {
    raw_spin_unlock(a1 + 3400);
    if ( !*(_DWORD *)(a1 + 3416) )
      goto LABEL_12;
    goto LABEL_11;
  }
  *(_QWORD *)(a1 + 3408) = v21 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 3400);
  if ( *(_DWORD *)(a1 + 3416) )
  {
LABEL_11:
    *(_QWORD *)(a1 + 3424) = 0;
    *(_DWORD *)(a1 + 3416) = 0;
    qdf_trace_msg(0x61u, 4u, "%s: done", v22, v23, v24, v25, v26, v27, v28, v29, "wlan_ipa_reset_pending_tx_timer");
  }
LABEL_12:
  if ( !*(_DWORD *)(a1 + 3436) )
    goto LABEL_21;
  v30 = *(_QWORD *)(a1 + 1456);
  if ( !v30 || !*(_QWORD *)v30 || (v31 = *(_QWORD *)(*(_QWORD *)v30 + 152LL)) == 0 )
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v22, v23, v24, v25, v26, v27, v28, v29, "cdp_ipa_enable_pipes");
    v33 = 16;
    goto LABEL_26;
  }
  v32 = *(__int64 (**)(void))(v31 + 152);
  if ( v32 )
  {
    if ( *((_DWORD *)v32 - 1) != 1755644319 )
      __break(0x8228u);
    v33 = v32();
    if ( v33 )
    {
LABEL_26:
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Enable IPA WDI PIPE failed: ret=%d",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "wlan_ipa_uc_enable_pipes",
        v33);
      wlan_ipa_log_message(
        (int)"wlan_ipa_uc_enable_pipes",
        (int)"Enable IPA WDI PIPE failed: ret=%d",
        v33,
        v50,
        v51,
        v52,
        v53,
        v54,
        v70);
      v20 = 16;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
        goto LABEL_29;
      goto LABEL_27;
    }
  }
  *(_DWORD *)(a1 + 3436) = 0;
LABEL_21:
  qdf_event_reset(a1 + 7392);
  if ( *(_DWORD *)(a1 + 3432) )
    qdf_trace_msg(
      0x61u,
      4u,
      "%s: opt_dp: enable pipes. Do not enable autonomy",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "wlan_ipa_uc_enable_pipes");
  v20 = 0;
  *(_BYTE *)(a1 + 7513) = 4;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
    goto LABEL_29;
LABEL_27:
  v55 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v55 + 16) & 0xF0000) == 0 && (*(_DWORD *)(v55 + 16) & 0xFF00) == 0 )
  {
    raw_spin_lock_bh(a1 + 3400);
    *(_QWORD *)(a1 + 3408) |= 1uLL;
    goto LABEL_30;
  }
LABEL_29:
  raw_spin_lock(a1 + 3400);
LABEL_30:
  if ( !*(_DWORD *)(a1 + 3436) )
    *(_BYTE *)(a1 + 3440) = 0;
  v56 = *(_QWORD *)(a1 + 3408);
  *(_BYTE *)(a1 + 3442) = 0;
  if ( (v56 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 3408) = v56 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 3400);
  }
  else
  {
    raw_spin_unlock(a1 + 3400);
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: exit: ipa_pipes_down=%d, status=%d",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    "wlan_ipa_uc_enable_pipes",
    *(unsigned __int8 *)(a1 + 3440),
    v20);
  wlan_ipa_log_message(
    (int)"wlan_ipa_uc_enable_pipes",
    (int)"exit: ipa_pipes_down=%d, status=%d",
    *(unsigned __int8 *)(a1 + 3440),
    v20,
    v65,
    v66,
    v67,
    v68,
    v70);
  return v20;
}
