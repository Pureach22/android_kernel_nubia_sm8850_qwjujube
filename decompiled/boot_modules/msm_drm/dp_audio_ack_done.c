__int64 __fastcall dp_audio_ack_done(__int64 a1, char a2)
{
  unsigned __int64 data; // x0
  unsigned __int64 v4; // x19
  __int64 v5; // x0
  unsigned __int64 v6; // x21
  __int64 ipc_log_context; // x0
  int v8; // w8
  unsigned __int64 StatusReg; // x20
  const char *v10; // x3
  const char *v11; // x5

  data = dp_audio_get_data();
  v4 = data;
  if ( data < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (a2 & 0x20) != 0 )
    {
      *(_BYTE *)(data + 144) = (a2 & 0x10) != 0;
      ipc_log_context = get_ipc_log_context(data);
      v8 = *(unsigned __int8 *)(v4 + 144);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( v8 )
        v10 = "enabled";
      else
        v10 = "disabled";
      ipc_log_string(ipc_log_context, "[d][%-4d]audio ack feature %s\n", *(unsigned int *)(StatusReg + 1800), v10);
      if ( (_drm_debug & 4) != 0 )
      {
        if ( *(_BYTE *)(v4 + 144) )
          v11 = "enabled";
        else
          v11 = "disabled";
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]audio ack feature %s\n", *(unsigned int *)(StatusReg + 1800), v11);
      }
    }
    else if ( *(_BYTE *)(data + 144) == 1 )
    {
      v5 = get_ipc_log_context(data);
      v6 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v5, "[d][%-4d]acknowledging audio (%d)\n", *(_DWORD *)(v6 + 1800), a2 & 1);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]acknowledging audio (%d)\n", *(_DWORD *)(v6 + 1800), a2 & 1);
      if ( (*(_BYTE *)(v4 + 152) & 1) == 0 )
      {
        *(_DWORD *)(v4 + 384) = 1;
        complete_all(v4 + 160);
      }
    }
    LODWORD(v4) = 0;
  }
  return (unsigned int)v4;
}
