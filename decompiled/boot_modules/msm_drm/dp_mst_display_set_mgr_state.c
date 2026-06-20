__int64 __fastcall dp_mst_display_set_mgr_state(
        _QWORD *a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x22
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  int v16; // w6
  int v17; // w7
  int v18; // w7
  unsigned int v19; // w20
  __int64 ipc_log_context; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v9 = a1[5];
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_display_set_mgr_state", 2096, 8, 4369, a2 & 1, -1059143953, a8, vars0);
  if ( (a2 & 1) != 0 )
    *(_BYTE *)(v9 + 4236) = 1;
  dp_mst_clear_edid_cache(a1, v11, v12, v13, v14, v15, v16, v17);
  *(_QWORD *)(v9 + 4128) = &drm_dp_mst_fw_helper_ops;
  v19 = drm_dp_mst_topology_mgr_set_mst(v9 + 32, a2 & 1);
  if ( (v19 & 0x80000000) != 0 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to set topology mgr state to %d. rc %d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a2 & 1,
      v19);
    printk(&unk_261B24, "dp_mst_display_set_mgr_state");
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_display_set_mgr_state", 2115, 8, 8738, v19, -1059143953, v18, vars0a);
  return v19;
}
