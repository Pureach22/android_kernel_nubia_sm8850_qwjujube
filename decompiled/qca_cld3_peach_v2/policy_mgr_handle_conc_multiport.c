__int64 __fastcall policy_mgr_handle_conc_multiport(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 context; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  unsigned int v28; // w20
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  _QWORD v46[4]; // [xsp+0h] [xbp-30h] BYREF
  int v47; // [xsp+20h] [xbp-10h]
  _BYTE v48[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48[0] = 0;
  v47 = 0;
  memset(v46, 0, sizeof(v46));
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
    a1,
    (unsigned __int8)a2,
    v46,
    v48);
  if ( (policy_mgr_check_for_session_conc(a1, a2, a3) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Conc not allowed for the vdev %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_handle_conc_multiport",
      (unsigned __int8)a2);
    v28 = 16;
    goto LABEL_12;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v27 = "%s: Invalid context";
    goto LABEL_7;
  }
  if ( (unsigned int)qdf_event_reset(context + 16) )
  {
    v27 = "%s: clear event failed";
LABEL_7:
    qdf_trace_msg(0x4Fu, 2u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "policy_mgr_reset_connection_update");
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: clearing event failed",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "policy_mgr_handle_conc_multiport");
  }
  v28 = policy_mgr_current_connections_update(a1, (unsigned __int8)a2, a3, a4, a5);
  if ( v28 == 16 )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: connections update failed",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "policy_mgr_handle_conc_multiport");
  if ( v48[0] )
    policy_mgr_restore_deleted_conn_info(a1, v46);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v28;
}
