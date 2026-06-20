unsigned __int64 dp_audio_teardown_done()
{
  unsigned __int64 result; // x0
  __int64 v1; // x8
  unsigned __int64 v2; // x19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 (*v7)(void); // x8
  void (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  result = dp_audio_get_data();
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    v1 = *(_QWORD *)(result + 136);
    v2 = result;
    if ( v1 && *(_QWORD *)(v1 + 1176) )
    {
      if ( *(_BYTE *)(result + 360) == 1 )
      {
        ipc_log_context = get_ipc_log_context(result);
        StatusReg = _ReadStatusReg(SP_EL0);
        result = ipc_log_string(ipc_log_context, "[d][%-4d]TUI session active\n", *(_DWORD *)(StatusReg + 1800));
        if ( (_drm_debug & 4) != 0 )
          return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TUI session active\n", *(unsigned int *)(StatusReg + 1800));
      }
      else if ( *(_DWORD *)(v1 + 912) >= 2u )
      {
        v13 = get_ipc_log_context(result);
        ipc_log_string(
          v13,
          "[w][%-4d]invalid stream id: %d\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(*(_QWORD *)(v2 + 136) + 912LL));
        return printk(&unk_24ED5B, "dp_audio_teardown_done");
      }
      else
      {
        v5 = mutex_lock(result + 304);
        *(_BYTE *)(v2 + 152) = 0;
        v6 = *(_QWORD *)(v2 + 16);
        if ( *(_DWORD *)(v2 + 148) )
        {
          *(_DWORD *)(v6 + 8) = 0;
          v7 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 136) + 1176LL);
          if ( *((_DWORD *)v7 - 1) != -1505889699 )
            __break(0x8228u);
          if ( (v7() & 1) != 0 )
          {
            v8 = *(void (__fastcall **)(_QWORD))(v6 + 24);
            if ( *((_DWORD *)v8 - 1) != 1586062320 )
              __break(0x8228u);
            v8(v6);
          }
        }
        else
        {
          v14 = get_ipc_log_context(v5);
          ipc_log_string(v14, "[w][%-4d]session inactive. enable=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), 0);
          printk(&unk_21C490, "dp_audio_enable");
        }
        mutex_unlock(v2 + 304);
        *(_DWORD *)(v2 + 384) = 1;
        v9 = complete_all(v2 + 160);
        v10 = get_ipc_log_context(v9);
        v11 = _ReadStatusReg(SP_EL0);
        result = ipc_log_string(v10, "[d][%-4d]audio engine disabled\n", *(_DWORD *)(v11 + 1800));
        if ( (_drm_debug & 4) != 0 )
          return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]audio engine disabled\n", *(unsigned int *)(v11 + 1800));
      }
    }
    else
    {
      v12 = get_ipc_log_context(result);
      ipc_log_string(v12, "[e][%-4d]invalid panel data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      return printk(&unk_2760FF, "dp_audio_teardown_done");
    }
  }
  return result;
}
