// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_278954@<X0>(
        unsigned int a1@<W0>,
        unsigned int a2@<W1>,
        __int64 a3@<X6>,
        int a4@<W8>,
        double a5@<D0>,
        double a6@<D1>,
        double a7@<D2>,
        double a8@<D3>,
        double a9@<D4>,
        double a10@<D5>,
        double a11@<D6>,
        double a12@<D7>)
{
  int v12; // w9
  int v13; // w10
  int v14; // w11
  int v15; // w19
  unsigned int v16; // w20
  __int64 v17; // x22
  __int64 v18; // x24
  __int64 v19; // x26
  unsigned int v20; // w27
  unsigned int v21; // w28
  __int64 v22; // x29
  unsigned int v23; // w20
  __int64 v24; // x1
  __int64 v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 **v34; // x21
  __int64 v35; // x19
  __int64 (__fastcall *v36)(_QWORD); // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  _DWORD *v40; // x8
  __int64 v41; // x8
  _DWORD *v42; // x8
  __int64 v43; // x8
  _DWORD *v44; // x8
  __int64 v45; // x8
  _DWORD *v46; // x8
  __int64 v47; // x8
  _DWORD *v48; // x8
  _DWORD *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  void (__fastcall *v59)(_QWORD); // x8
  __int64 v60; // x0
  __int64 result; // x0

  qdf_trace_msg(
    a1,
    a2,
    "%s: RX - packets %u, dropped %u, unsol_arp_mcast_drp %u, delivered %u, refused %u GRO - agg %u drop %u non-agg %u fl"
    "ush_skip %u low_tput_flush %u disabled(conc %u low-tput %u)",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    v19,
    v16,
    v21,
    a3,
    v20,
    v15,
    a4,
    v12,
    v13,
    v14,
    *(_DWORD *)(v18 + 2684),
    *(_DWORD *)(v17 + 1128),
    *(_DWORD *)(v17 + 1132));
  v23 = *(_DWORD *)(v22 - 92);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (*(_DWORD *)(*(_QWORD *)(v22 - 104) + 16LL) & 0xF0000) != 0
    || (*(_DWORD *)(*(_QWORD *)(v22 - 104) + 16LL) & 0xFF00) != 0 )
  {
    raw_spin_lock(v17 + 264);
  }
  else
  {
    raw_spin_lock_bh(v17 + 264);
    *(_QWORD *)(v17 + 272) |= 1uLL;
  }
  v24 = *(_QWORD *)(v22 - 56);
  *(_QWORD *)(v22 - 24) = v24;
  dp_get_next_intf_no_lock(v17, v24, v22 - 56);
  v25 = *(_QWORD *)(v17 + 272);
  if ( (v25 & 1) == 0 )
  {
    raw_spin_unlock(v17 + 264);
    if ( !*(_QWORD *)(v22 - 24) )
      goto LABEL_11;
LABEL_63:
    JUMPOUT(0x2787A0);
  }
  *(_QWORD *)(v17 + 272) = v25 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v17 + 264);
  if ( *(_QWORD *)(v22 - 24) )
    goto LABEL_63;
LABEL_11:
  v34 = *(__int64 ***)(v22 - 120);
  if ( *v34 )
  {
    v35 = *(_QWORD *)(v22 - 136);
    v36 = *(__int64 (__fastcall **)(_QWORD))(**v34 + 624);
    if ( v36 )
    {
      v37 = *(_QWORD *)(v22 - 120);
      if ( *((_DWORD *)v36 - 1) != -1355198606 )
        __break(0x8228u);
      v38 = v36(v37);
      if ( v38 )
        ((void (__fastcall *)(__int64))dp_rx_tm_dump_stats)(v38 + 16);
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "cdp_soc_get_dp_txrx_handle");
    v35 = *(_QWORD *)(v22 - 136);
  }
  if ( *v34 )
  {
    v39 = **v34;
    if ( !v39 )
      goto LABEL_53;
    v40 = *(_DWORD **)(v39 + 528);
    if ( v40 )
    {
      if ( *(v40 - 1) != 358154616 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, __int64, _QWORD))v40)(v34, 11, 0);
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_display_stats");
  }
  if ( *v34 )
  {
    v41 = **v34;
    if ( !v41 )
      goto LABEL_53;
    v42 = *(_DWORD **)(v41 + 528);
    if ( v42 )
    {
      if ( *(v42 - 1) != 358154616 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, __int64, _QWORD))v42)(v34, 12, 0);
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_display_stats");
  }
  if ( *v34 )
  {
    v43 = **v34;
    if ( !v43 )
      goto LABEL_53;
    v44 = *(_DWORD **)(v43 + 528);
    if ( v44 )
    {
      if ( *(v44 - 1) != 358154616 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, __int64, _QWORD))v44)(v34, 1, 0);
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_display_stats");
  }
  if ( *v34 )
  {
    v45 = **v34;
    if ( !v45 )
      goto LABEL_53;
    v46 = *(_DWORD **)(v45 + 528);
    if ( v46 )
    {
      if ( *(v46 - 1) != 358154616 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 **, __int64, _QWORD))v46)(v34, 5, 0);
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_display_stats");
  }
  if ( *v34 )
  {
    v47 = **v34;
    if ( v47 )
    {
      v48 = *(_DWORD **)(v47 + 528);
      if ( v48 )
      {
        if ( *(v48 - 1) != 358154616 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64 **, __int64, _QWORD))v48)(v34, 27, 0);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v26, v27, v28, v29, v30, v31, v32, v33, "cdp_display_stats");
  }
LABEL_53:
  v49 = *(_DWORD **)(v17 + 656);
  if ( *(v49 - 1) != -315990003 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v49)(v35, 0);
  if ( *v34 && (v58 = (*v34)[8]) != 0 )
  {
    v59 = *(void (__fastcall **)(_QWORD))(v58 + 280);
    if ( v59 )
    {
      if ( *((_DWORD *)v59 - 1) != 944657148 )
        __break(0x8228u);
      v59(v34);
    }
  }
  else
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "cdp_display_txrx_hw_info");
  }
  qdf_dp_trace_dump_stats(v50, v51, v52, v53, v54, v55, v56, v57);
  v60 = ((__int64 (__fastcall *)(__int64))wlan_dp_stc_dump_periodic_stats)(v17);
  ((void (__fastcall *)(__int64))ucfg_ipa_dump_logging_stats)(v60);
  dp_display_periodic_stats_counter = 0;
  dp_display_periodic_stats_data_in_time_period = 0;
  hif_affinity_mgr_set_affinity(*(_QWORD *)(v22 - 128));
  result = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_dp_lb_compute_stats_average)(v17, v23);
  _ReadStatusReg(SP_EL0);
  return result;
}
