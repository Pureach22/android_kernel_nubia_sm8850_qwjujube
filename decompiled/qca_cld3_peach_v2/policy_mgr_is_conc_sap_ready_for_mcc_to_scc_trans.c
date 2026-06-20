bool __fastcall policy_mgr_is_conc_sap_ready_for_mcc_to_scc_trans(__int64 a1)
{
  unsigned __int8 mode_specific_conn_info; // w21
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  int v12; // w20
  unsigned __int64 v13; // x24
  __int64 v14; // x25
  bool v15; // w23
  __int64 v16; // x0
  __int64 v17; // x22
  __int64 active_channel; // x21
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v29; // [xsp+8h] [xbp-28h] BYREF
  char v30; // [xsp+Ch] [xbp-24h]
  _QWORD v31[2]; // [xsp+10h] [xbp-20h] BYREF
  int v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v31[0] = 0;
  v31[1] = 0;
  v30 = 0;
  v29 = 0;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                              a1,
                              (unsigned __int64)v31,
                              (unsigned __int64)&v29,
                              1u);
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v12 = *(unsigned __int8 *)(context + 2200);
    v13 = mode_specific_conn_info;
    if ( mode_specific_conn_info )
      goto LABEL_3;
LABEL_11:
    v15 = 0;
    goto LABEL_12;
  }
  qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_mcc_scc_switch");
  v12 = 0;
  v13 = mode_specific_conn_info;
  if ( !mode_specific_conn_info )
    goto LABEL_11;
LABEL_3:
  v14 = 0;
  v15 = 1;
  do
  {
    if ( v14 == 5 )
    {
      __break(0x5512u);
      __break(1u);
    }
    v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            *((unsigned __int8 *)&v29 + v14),
            24);
    if ( v16 )
    {
      v17 = v16;
      active_channel = wlan_vdev_get_active_channel(v16);
      wlan_objmgr_vdev_release_ref(v17, 0x18u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( active_channel )
      {
        if ( (policy_mgr_is_restart_sap_required(
                a1,
                *((unsigned __int8 *)&v29 + v14),
                *((_DWORD *)v31 + v14),
                v12,
                *(_DWORD *)(active_channel + 20))
            & 1) != 0 )
          break;
      }
    }
    v15 = ++v14 < v13;
  }
  while ( v13 != v14 );
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v15;
}
