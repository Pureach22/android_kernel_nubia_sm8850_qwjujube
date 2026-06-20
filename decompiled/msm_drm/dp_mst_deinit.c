__int64 __fastcall dp_mst_deinit(__int64 result)
{
  _BYTE *v1; // x19
  __int64 ipc_log_context; // x0
  void *v3; // x0
  void (*v4)(void); // x8
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x19

  if ( !result )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v3 = &unk_24B695;
    return printk(v3, "dp_mst_deinit");
  }
  v1 = *(_BYTE **)(result + 40);
  if ( *v1 == 1 )
  {
    v4 = *(void (**)(void))(result + 208);
    if ( *((_DWORD *)v4 - 1) != 1970643636 )
      __break(0x8228u);
    v4();
    drm_dp_mst_topology_mgr_destroy(v1 + 32);
    *v1 = 0;
    v5 = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v5, "[i][%-4d]dp drm mst topology manager deinit completed\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      return printk(&unk_2424F6, *(unsigned int *)(StatusReg + 1800));
    v3 = &unk_223B1C;
    return printk(v3, "dp_mst_deinit");
  }
  return result;
}
