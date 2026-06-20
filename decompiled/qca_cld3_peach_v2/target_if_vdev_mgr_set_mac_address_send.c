__int64 __fastcall target_if_vdev_mgr_set_mac_address_send(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x9
  _QWORD *v12; // x10
  unsigned int v13; // w19
  __int64 result; // x0
  const char *v15; // x2
  const char *v16; // x2
  __int64 v17; // x20
  __int64 v18; // x9
  _DWORD *v19; // x9
  __int64 v20; // x0
  const char *v21; // x2

  _ReadStatusReg(SP_EL0);
  v11 = *(_QWORD *)(a11 + 216);
  if ( !v11 )
  {
    v15 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v12 = *(_QWORD **)(v11 + 1240);
  if ( !v12 || !*v12 )
  {
    v15 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x68u, 2u, v15, a1, a2, a3, a4, a5, a6, a7, a8, "target_if_vdev_mgr_wmi_handle_get");
    v16 = "%s: Failed to get WMI handle!";
    goto LABEL_9;
  }
  v13 = *(unsigned __int8 *)(a11 + 168);
  if ( (*(_BYTE *)(a11 + 67) & 2) != 0 )
  {
    v17 = *(_QWORD *)(v11 + 80);
    if ( v17 )
    {
      v18 = *(_QWORD *)(v17 + 2136);
      if ( v18 )
      {
        v19 = *(_DWORD **)(v18 + 1136);
        if ( v19 )
        {
          if ( *(v19 - 1) != -672477040 )
            __break(0x8229u);
          v20 = ((__int64 (__fastcall *)(__int64, _QWORD))v19)(v17, v13);
          if ( v20 )
          {
            *(_DWORD *)(v20 + 72) = 10000;
            target_if_vdev_mgr_rsp_timer_start(v17, v20, 6u);
            goto LABEL_5;
          }
          v21 = "%s: VDEV %d: No vdev rsp timer";
          goto LABEL_22;
        }
      }
      else
      {
        qdf_trace_msg(0x38u, 2u, "%s: rx_ops is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "target_if_vdev_mgr_get_rx_ops");
      }
      v21 = "%s: VDEV %d:No Rx Ops";
LABEL_22:
      qdf_trace_msg(0x68u, 2u, v21, a1, a2, a3, a4, a5, a6, a7, a8, "target_if_vdev_mgr_set_mac_address_send", v13);
      goto LABEL_10;
    }
    v16 = "%s: PSOC NULL";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v16, a1, a2, a3, a4, a5, a6, a7, a8, "target_if_vdev_mgr_set_mac_address_send");
LABEL_10:
    result = 4;
    goto LABEL_11;
  }
LABEL_5:
  result = wmi_unified_send_set_mac_addr();
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
