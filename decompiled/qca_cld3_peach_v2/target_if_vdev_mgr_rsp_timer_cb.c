__int64 __fastcall target_if_vdev_mgr_rsp_timer_cb(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  _QWORD *v10; // x23
  __int64 result; // x0
  const char *v12; // x2
  unsigned int v13; // w20
  __int64 v14; // x5
  const char *v15; // x2
  __int64 v16; // x4
  __int64 v17; // x9
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 (__fastcall *v34)(__int64, __int64 *); // x8
  _DWORD *v35; // x8
  __int64 v36; // x0
  int v37; // w8
  __int64 (__fastcall *v38)(__int64, __int64 *); // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v48; // [xsp+8h] [xbp-48h] BYREF
  _BYTE v49[4]; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v50; // [xsp+18h] [xbp-38h] BYREF
  __int64 v51; // [xsp+20h] [xbp-30h]
  __int64 v52; // [xsp+28h] [xbp-28h]
  __int64 v53; // [xsp+30h] [xbp-20h]
  __int64 v54; // [xsp+38h] [xbp-18h]
  int v55; // [xsp+40h] [xbp-10h]
  __int64 v56; // [xsp+48h] [xbp-8h]

  v56 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v55 = 0;
  v53 = 0;
  v54 = 0;
  v51 = 0;
  v52 = 0;
  v50 = 0;
  v48 = 0;
  if ( !a1 )
  {
    v12 = "%s: Vdev response timer is NULL";
LABEL_20:
    result = qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_rsp_timer_cb");
    goto LABEL_21;
  }
  v9 = *a1;
  if ( !*a1 )
  {
    v12 = "%s: PSOC is NULL";
    goto LABEL_20;
  }
  v10 = *(_QWORD **)(v9 + 2136);
  if ( !v10 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    goto LABEL_19;
  }
  if ( !v10[142] )
  {
LABEL_19:
    v12 = "%s: No Rx Ops";
    goto LABEL_20;
  }
  if ( (a1[8] & 1) == 0
    && (a1[8] & 2) == 0
    && (a1[8] & 4) == 0
    && (a1[8] & 8) == 0
    && (a1[8] & 0x10) == 0
    && (a1[8] & 0x20) == 0
    && (a1[8] & 0x40) == 0 )
  {
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: No response bit is set, ignoring actions :%d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "target_if_vdev_mgr_rsp_timer_cb",
               *((unsigned __int8 *)a1 + 84));
    goto LABEL_21;
  }
  v13 = *((unsigned __int8 *)a1 + 84);
  if ( v13 >= 6 )
  {
    v14 = *(unsigned __int8 *)(v9 + 48);
    v15 = "%s: Invalid VDEV_%d PSOC_%d";
    v16 = *((unsigned __int8 *)a1 + 84);
LABEL_17:
    result = qdf_trace_msg(0x68u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_rsp_timer_cb", v16, v14);
    goto LABEL_21;
  }
  *((_DWORD *)a1 + 19) = 15;
  if ( (a1[8] & 1) != 0 || (a1[8] & 2) != 0 )
  {
    LOBYTE(v50) = v13;
    v17 = a1[8];
    LODWORD(v51) = 6;
    HIDWORD(v51) = !(v17 & 1);
    target_if_vdev_mgr_rsp_timer_stop(v9, a1, !(v17 & 1));
    qdf_trace_msg(
      0x68u,
      2u,
      "PSOC_%d VDEV_%d: %s rsp timeout",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      *(unsigned __int8 *)(v9 + 48),
      v13,
      string_from_rsp_bit_strings[HIDWORD(v51)]);
    if ( (qdf_is_recovering() & 1) != 0 || (qdf_is_fw_down(v26, v27, v28, v29, v30, v31, v32, v33) & 1) != 0 )
      qdf_trace_msg(
        0x68u,
        8u,
        "PSOC_%d VDEV_%d: Panic not allowed",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        *(unsigned __int8 *)(v9 + 48),
        v13);
    else
      _qdf_trigger_self_recovery();
    v34 = (__int64 (__fastcall *)(__int64, __int64 *))v10[134];
    if ( *((_DWORD *)v34 - 1) != 926887046 )
      __break(0x8228u);
    result = v34(v9, &v50);
    goto LABEL_21;
  }
  if ( (a1[8] & 4) != 0 )
  {
    v49[0] = v13;
    target_if_vdev_mgr_rsp_timer_stop(v9, a1, 2);
    target_if_vdev_mgr_handle_recovery(v9, v13, 17, 2);
    v35 = (_DWORD *)v10[135];
    v36 = v9;
    if ( *(v35 - 1) != -552073721 )
      __break(0x8228u);
    goto LABEL_39;
  }
  if ( (a1[8] & 8) != 0 )
  {
    v49[0] = v13;
    target_if_vdev_mgr_rsp_timer_stop(v9, a1, 3);
    target_if_vdev_mgr_handle_recovery(v9, v13, 18, 3);
    v35 = (_DWORD *)v10[136];
    v36 = v9;
    if ( *(v35 - 1) != -2103606579 )
      __break(0x8228u);
LABEL_39:
    result = ((__int64 (__fastcall *)(__int64, _BYTE *))v35)(v36, v49);
    goto LABEL_21;
  }
  if ( (a1[8] & 0x10) == 0 )
  {
    if ( (a1[8] & 0x20) != 0 )
    {
      target_if_vdev_mgr_rsp_timer_stop(v9, a1, 5);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: No rsp from FW received , continue with disconnect",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "target_if_vdev_mgr_rsp_timer_cb");
      result = target_if_cm_send_rso_stop_failure_rsp(v9, v13);
      goto LABEL_21;
    }
    if ( (a1[8] & 0x40) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: VDEV %d MAC addr update resp timeout",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_vdev_mgr_rsp_timer_cb",
        v13);
      result = target_if_vdev_mgr_mac_addr_rsp_timeout(v9, a1, v13);
      goto LABEL_21;
    }
    v16 = *(unsigned __int8 *)(v9 + 48);
    v15 = "%s: PSOC_%d VDEV_%d: Unknown error";
    v14 = v13;
    goto LABEL_17;
  }
  v37 = *((_DWORD *)a1 + 22);
  LOBYTE(v48) = v13;
  HIDWORD(v48) = v37;
  target_if_vdev_mgr_rsp_timer_stop(v9, a1, 4);
  target_if_vdev_mgr_handle_recovery(v9, v13, 19, 4);
  v38 = (__int64 (__fastcall *)(__int64, __int64 *))v10[139];
  if ( *((_DWORD *)v38 - 1) != 794477332 )
    __break(0x8228u);
  result = v38(v9, &v48);
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
