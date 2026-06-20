__int64 __fastcall dp_mst_bridge_pre_enable_part2(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v10; // x22
  __int64 v11; // x20
  int v12; // w5
  __int64 result; // x0
  void (__fastcall *v14)(_QWORD); // x8
  unsigned __int8 *mst_payload_state; // x0
  void (__fastcall *v16)(__int64, unsigned __int8 *); // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v19; // x0
  void *v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 1344);
  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 408) + 40LL);
  v11 = *(_QWORD *)(v8 + 2776);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v8 = *(_QWORD *)(a1 + 1344);
  }
  if ( v8 )
    v12 = *(_DWORD *)(v8 + 64);
  else
    v12 = 0;
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "_dp_mst_bridge_pre_enable_part2",
             760,
             8,
             4369,
             v12,
             -1059143953,
             a8,
             vars0);
  if ( *(_DWORD *)(v10 + 4232) != 1 )
  {
    v14 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v10 + 4128) + 64LL);
    if ( *((_DWORD *)v14 - 1) != -81624539 )
      __break(0x8228u);
    v14(v10 + 32);
    mst_payload_state = (unsigned __int8 *)drm_atomic_get_mst_payload_state(*(_QWORD *)(v10 + 120), v11);
    if ( mst_payload_state )
    {
      if ( *(_QWORD *)mst_payload_state )
      {
        if ( *(_QWORD *)(*(_QWORD *)mst_payload_state + 1624LL) )
        {
          if ( mst_payload_state[8] != 255 )
          {
            v16 = *(void (__fastcall **)(__int64, unsigned __int8 *))(*(_QWORD *)(v10 + 4128) + 16LL);
            if ( *((_DWORD *)v16 - 1) != 4509629 )
              __break(0x8228u);
            v16(v10 + 32, mst_payload_state);
            ipc_log_context = get_ipc_log_context();
            StatusReg = _ReadStatusReg(SP_EL0);
            result = ipc_log_string(
                       ipc_log_context,
                       "[d][%-4d]mst bridge [%d] _pre enable part-2 complete\n",
                       *(_DWORD *)(StatusReg + 1800),
                       *(_DWORD *)(a1 + 400));
            if ( (_drm_debug & 4) != 0 )
              return _drm_dev_dbg(
                       0,
                       0,
                       0,
                       "[msm-dp-debug][%-4d]mst bridge [%d] _pre enable part-2 complete\n",
                       *(_DWORD *)(StatusReg + 1800),
                       *(_DWORD *)(a1 + 400));
            return result;
          }
          v23 = get_ipc_log_context();
          ipc_log_string(
            v23,
            "[e][%-4d]mst bridge [%d] _pre enable part-2 failed, payload alloc part 1 failed\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 400));
          v20 = &unk_2731A8;
        }
        else
        {
          v22 = get_ipc_log_context();
          ipc_log_string(
            v22,
            "[e][%-4d]mst bridge [%d] _pre enable part-2 failed, null connector\n",
            *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
            *(_DWORD *)(a1 + 400));
          v20 = &unk_27CE03;
        }
      }
      else
      {
        v21 = get_ipc_log_context();
        ipc_log_string(
          v21,
          "[e][%-4d]mst bridge [%d] _pre enable part-2 failed, null port\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(a1 + 400));
        v20 = &unk_24F6A8;
      }
    }
    else
    {
      v19 = get_ipc_log_context();
      ipc_log_string(
        v19,
        "[e][%-4d]mst bridge [%d] _pre enable part-2 failed, null payload\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 400));
      v20 = &unk_211BB3;
    }
    return printk(v20, "_dp_mst_bridge_pre_enable_part2");
  }
  return result;
}
