__int64 __fastcall dp_lphw_hpd_isr(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  int v4; // w20
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned __int64 v9; // x21
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 ipc_log_context; // x0
  void *v14; // x0
  __int64 v15; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v14 = &unk_275B6D;
    return printk(v14, "dp_lphw_hpd_isr");
  }
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 80) + 16LL);
  if ( *((_DWORD *)v2 - 1) != -1629746922 )
    __break(0x8228u);
  result = v2();
  v4 = result;
  if ( (result & 8) == 0 )
  {
    if ( (result & 2) != 0 )
    {
      v5 = get_ipc_log_context(result);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v5, "[d][%-4d]hpd_irq interrupt, hpd isr state: 0x%x\n", *(_DWORD *)(StatusReg + 1800), v4);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]hpd_irq interrupt, hpd isr state: 0x%x\n",
          *(_DWORD *)(StatusReg + 1800),
          v4);
      result = queue_work_on(32, *(_QWORD *)(a1 + 128), a1 + 304);
      if ( (result & 1) == 0 )
      {
        v7 = get_ipc_log_context(result);
        result = ipc_log_string(v7, "[d][%-4d]attention not queued\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          return _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]attention not queued\n",
                   *(unsigned int *)(StatusReg + 1800));
      }
    }
    return result;
  }
  v8 = get_ipc_log_context(result);
  v9 = _ReadStatusReg(SP_EL0);
  v10 = ipc_log_string(v8, "[d][%-4d]disconnect interrupt, hpd isr state: 0x%x\n", *(_DWORD *)(v9 + 1800), v4);
  if ( (_drm_debug & 4) != 0 )
    v10 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]disconnect interrupt, hpd isr state: 0x%x\n",
            *(_DWORD *)(v9 + 1800),
            v4);
  if ( *(_BYTE *)(a1 + 8) != 1 )
  {
    v15 = get_ipc_log_context(v10);
    ipc_log_string(v15, "[e][%-4d]already disconnected\n", *(_DWORD *)(v9 + 1800));
    v14 = &unk_21511A;
    return printk(v14, "dp_lphw_hpd_isr");
  }
  v11 = *(_QWORD *)(a1 + 128);
  *(_BYTE *)(a1 + 348) = 0;
  *(_WORD *)(a1 + 8) = 0;
  *(_BYTE *)(a1 + 10) = 0;
  result = queue_work_on(32, v11, a1 + 272);
  if ( (result & 1) == 0 )
  {
    v12 = get_ipc_log_context(result);
    result = ipc_log_string(v12, "[d][%-4d]disconnect not queued\n", *(_DWORD *)(v9 + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]disconnect not queued\n", *(unsigned int *)(v9 + 1800));
  }
  return result;
}
