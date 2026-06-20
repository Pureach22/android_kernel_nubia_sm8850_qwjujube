__int64 __fastcall dp_mon_filter_update_1_0(
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
  __int64 v9; // x20
  unsigned __int8 *v11; // x24
  __int64 v12; // x5
  const char *v13; // x2
  __int64 result; // x0
  int target_type; // w22
  unsigned int v16; // w21
  __int64 v17; // x0
  int v18; // w23
  unsigned int (__fastcall *v19)(_QWORD); // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 (__fastcall *v28)(_QWORD); // x8
  int v29; // w0
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
  _QWORD v46[11]; // [xsp+8h] [xbp-68h] BYREF
  int v47; // [xsp+60h] [xbp-10h]
  __int64 v48; // [xsp+68h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  memset(v46, 0, sizeof(v46));
  if ( !a1 )
  {
    v13 = "%s: pdev Context is null";
LABEL_9:
    qdf_trace_msg(0x73u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "dp_mon_filter_update_1_0");
    goto LABEL_10;
  }
  v9 = *(_QWORD *)(a1 + 8);
  if ( !v9 )
  {
    v13 = "%s: Soc Context is null";
    goto LABEL_9;
  }
  v11 = *(unsigned __int8 **)(a1 + 95560);
  if ( v11[39097] )
  {
    v12 = *v11;
    if ( *((_QWORD *)v11 + 2) || (v12 & 1) != 0 )
    {
      qdf_trace_msg(
        0x73u,
        2u,
        "%s: %pK: Rx pktlog full/lite can't exist with modes\nMonitor Mode:%d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "dp_mon_filter_check_co_exist",
        v9,
        v12);
LABEL_10:
      result = 16;
      goto LABEL_11;
    }
  }
  target_type = hal_get_target_type(*(__int64 **)(v9 + 1128));
  if ( *(_BYTE *)(*(_QWORD *)(v9 + 40) + 633LL) )
    v16 = 2;
  else
    v16 = 0;
  v17 = dp_mon_filter_h2t_setup(v9, a1, v16, v46);
  v18 = LOBYTE(v46[0]);
  if ( LOBYTE(v46[0]) == 1 )
    goto LABEL_28;
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 95560) + 16LL) )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(v9 + 40) + 633LL) & 1) == 0 && target_type != 36 || *v11 != 1 )
      goto LABEL_31;
    goto LABEL_28;
  }
  v19 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v9 + 8) + 200LL);
  if ( !v19 )
    goto LABEL_28;
  if ( *((_DWORD *)v19 - 1) != 1696218653 )
    __break(0x8228u);
  if ( v19(v17) || (*(_BYTE *)(v9 + 20216) & 0x10) == 0 )
  {
LABEL_28:
    v29 = dp_mon_ht2_rx_ring_cfg(v9, a1, v16, (char *)v46 + 4);
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Reset rxdma buffer to regular filter",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "dp_mon_filter_dest_update");
  v28 = *(__int64 (__fastcall **)(_QWORD))(v9 + 1256);
  if ( *((_DWORD *)v28 - 1) != -1941278151 )
    __break(0x8228u);
  v29 = v28(v9);
LABEL_29:
  if ( v29 )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: %pK: Monitor destination ring filter setting failed",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "dp_mon_filter_update_1_0",
      v9);
    goto LABEL_10;
  }
LABEL_31:
  qdf_mem_set(v46, 0x5Cu, 0);
  dp_mon_filter_h2t_setup(v9, a1, 1, v46);
  if ( v18 && (v46[0] & 1) == 0 )
    dp_mon_filter_reset_mon_srng();
  result = dp_mon_ht2_rx_ring_cfg(v9, a1, 1, (char *)v46 + 4);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: %pK: Monitor status ring filter setting failed",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dp_mon_filter_update_1_0",
      v9);
    dp_mon_filter_reset_mon_srng();
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
