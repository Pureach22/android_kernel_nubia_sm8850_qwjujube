__int64 __fastcall policy_mgr_check_sap_go_force_scc(__int64 a1, __int64 a2, int a3)
{
  char is_force_scc; // w0
  char v7; // w8
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  const char *v18; // x2
  __int64 v19; // x25
  __int64 v20; // x24
  unsigned int v21; // w21
  unsigned int v22; // w23
  unsigned int operation_chan_freq; // w22
  int v24; // w23
  unsigned __int8 existing_con_info; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int8 v34; // w8
  bool v35; // zf
  int v36; // w9
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // [xsp+Ch] [xbp-14h] BYREF
  int v46; // [xsp+10h] [xbp-10h] BYREF
  int v47; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 7;
  v45 = 0;
  v46 = 0;
  is_force_scc = policy_mgr_is_force_scc(a1);
  v7 = 0;
  if ( (is_force_scc & 1) != 0 )
    v7 = policy_mgr_is_hw_dbs_capable(a1) ^ 1;
  if ( a3 != 2 && a3 != 13 && (v7 & 1) == 0 )
    goto LABEL_8;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v18 = "%s: Invalid Context";
LABEL_28:
    qdf_trace_msg(0x4Fu, 2u, v18, v9, v10, v11, v12, v13, v14, v15, v16, "policy_mgr_check_sap_go_force_scc");
    result = 4;
    goto LABEL_29;
  }
  if ( *(_BYTE *)(context + 2200) == 4 )
  {
LABEL_8:
    result = 0;
    goto LABEL_29;
  }
  if ( !a2 )
  {
    v18 = "%s: vdev is null";
    goto LABEL_28;
  }
  v19 = *(_QWORD *)(context + 2096);
  if ( !v19 )
  {
    v18 = "%s: invalid work info";
    goto LABEL_28;
  }
  v20 = context;
  v21 = *(unsigned __int8 *)(a2 + 168);
  v22 = *(_DWORD *)(a2 + 16);
  operation_chan_freq = wlan_get_operation_chan_freq(a2);
  v24 = policy_mgr_qdf_opmode_to_pm_con_mode(a1, v22, v21);
  existing_con_info = policy_mgr_fetch_existing_con_info(a1, v21, operation_chan_freq, &v47, &v46, &v45);
  if ( existing_con_info == 255 )
    goto LABEL_8;
  v34 = existing_con_info;
  if ( v24 == 3 && v47 == 1
    || ((result = 0, v47 != 3) ? (v35 = v47 == 1) : (v35 = 1), !v35 ? (v36 = 0) : (v36 = 1), v24 == 1 && v36) )
  {
    *(_DWORD *)(v19 + 44) = a3;
    *(_BYTE *)(v19 + 48) = v21;
    *(_BYTE *)(v19 + 49) = v34;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: initiator vdev %d freq %d, existing vdev %d freq %d reason %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "policy_mgr_check_sap_go_force_scc",
      v21,
      operation_chan_freq,
      a3);
    if ( (_qdf_delayed_work_start(v20 + 1008, 0x3E8u) & 1) == 0 )
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: change interface request already queued",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "policy_mgr_check_sap_go_force_scc");
    result = 24;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
