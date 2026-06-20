__int64 __fastcall target_if_vdev_mgr_create_send(
        __int64 a1,
        __int64 a2,
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
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v13; // x23
  __int64 *v14; // x8
  __int64 v15; // x20
  unsigned int v17; // w22
  unsigned int v18; // w0
  _DWORD *v19; // x8
  unsigned int v20; // w20
  __int64 result; // x0
  bool v22; // zf
  const char *v23; // x2
  const char *v24; // x2
  unsigned int v25; // w19
  __int64 v26; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v26) = 0;
  LODWORD(v26) = 0;
  if ( !a1 || !a2 )
  {
    v23 = "%s: Invalid input";
LABEL_18:
    qdf_trace_msg(0x68u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_create_send", v26);
LABEL_23:
    result = 4;
    goto LABEL_24;
  }
  v10 = *(_QWORD *)(a1 + 152);
  v11 = *(unsigned __int8 *)(a1 + 104);
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v24 = "%s: VDEV %d: Failed to get psoc";
LABEL_22:
    qdf_trace_msg(0x68u, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_create_send", v11, v26);
    goto LABEL_23;
  }
  v13 = *(_QWORD *)(v12 + 2128);
  if ( !v13 )
  {
    v25 = *(unsigned __int8 *)(a1 + 104);
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: tx_ops is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlme_get_lmac_tx_ops",
      v26,
      v27);
    v11 = v25;
    goto LABEL_21;
  }
  if ( !*(_QWORD *)(v13 + 1576) )
  {
LABEL_21:
    v24 = "%s: VDEV %d: Failed to get mlme txrx_ops";
    goto LABEL_22;
  }
  v14 = *(__int64 **)(v10 + 1232);
  if ( !v14 || (v15 = *v14) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: wmi_handle is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_vdev_mgr_wmi_handle_get",
      v11,
      v26,
      v27);
    v23 = "%s: Failed to get WMI handle!";
    goto LABEL_18;
  }
  v17 = *(unsigned __int8 *)(a1 + 104);
  qdf_mem_copy(&v26, (const void *)(a1 + 74), 6u);
  v18 = wmi_unified_vdev_create_send(v15, &v26, a2);
  v19 = *(_DWORD **)(v13 + 1576);
  v20 = v18;
  if ( *(v19 - 1) != -132374536 )
    __break(0x8228u);
  LODWORD(result) = ((__int64 (__fastcall *)(__int64, _QWORD))v19)(v12, v17);
  if ( v20 )
    v22 = 1;
  else
    v22 = (_DWORD)result == 0;
  if ( v22 )
    result = v20;
  else
    result = (unsigned int)result;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
