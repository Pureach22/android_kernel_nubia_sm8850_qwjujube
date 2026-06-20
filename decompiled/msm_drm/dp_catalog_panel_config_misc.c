__int64 __fastcall dp_catalog_panel_config_misc(__int64 a1)
{
  unsigned int v1; // w8
  __int64 v3; // x20
  unsigned int v4; // w21
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v7; // x3
  _DWORD *v8; // x8
  __int64 v10; // x0
  __int64 ipc_log_context; // x0

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 204);
    if ( v1 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(a1);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream_id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 204));
      return printk(&unk_272496, "dp_catalog_panel_config_misc");
    }
    else
    {
      v3 = *(_QWORD *)(a1 - 552);
      if ( v1 == 1 )
        v4 = 1068;
      else
        v4 = 44;
      v5 = get_ipc_log_context(a1);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v5, "[d][%-4d]misc settings = 0x%x\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(a1 + 200));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]misc settings = 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(a1 + 200));
      v7 = *(unsigned int *)(a1 + 200);
      v8 = *(_DWORD **)(a1 - 448);
      if ( *(v8 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v8)(a1 - 576, v3, v4, v7);
    }
  }
  else
  {
    v10 = get_ipc_log_context(0);
    ipc_log_string(v10, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_misc");
  }
}
