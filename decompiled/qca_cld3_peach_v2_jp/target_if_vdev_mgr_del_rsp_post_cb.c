__int64 __fastcall target_if_vdev_mgr_del_rsp_post_cb(
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
  __int64 v9; // x19
  unsigned int v10; // w4
  const char *v11; // x2
  __int64 result; // x0
  __int64 v13; // x8
  _DWORD *v14; // x8
  __int64 v15; // x0
  _BYTE v16[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v9 = *(_QWORD *)(a1 + 8)) == 0 )
  {
    v11 = "%s: Msg or Msg bodyptr is NULL";
LABEL_6:
    qdf_trace_msg(0x68u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_del_rsp_post_cb");
    goto LABEL_7;
  }
  v10 = *(unsigned __int8 *)(a1 + 4);
  if ( v10 >= 6 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: VDEV %d: Invalid",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_vdev_mgr_del_rsp_post_cb");
LABEL_7:
    result = 4;
    goto LABEL_8;
  }
  v13 = *(_QWORD *)(v9 + 2136);
  if ( !v13 )
  {
    qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_vdev_mgr_get_rx_ops");
    v11 = "%s: No Rx Ops";
    goto LABEL_6;
  }
  v14 = *(_DWORD **)(v13 + 1088);
  v15 = *(_QWORD *)(a1 + 8);
  v16[0] = v10;
  if ( *(v14 - 1) != -2103606579 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _BYTE *))v14)(v15, v16);
  target_if_wake_lock_timeout_release(v9, 2);
  result = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
