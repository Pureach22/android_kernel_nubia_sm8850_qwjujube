__int64 __fastcall sde_encoder_control_idle_pc(
        __int64 result,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w5
  __int64 v9; // x19
  char v10; // [xsp+0h] [xbp+0h]

  if ( !result )
    return printk(&unk_26FCAB, "sde_encoder_control_idle_pc");
  v8 = a2 & 1;
  if ( *(unsigned __int8 *)(result + 836) != v8 )
  {
    *(_BYTE *)(result + 836) = v8;
    if ( (_drm_debug & 4) != 0 )
    {
      v9 = result;
      _drm_dev_dbg(0, 0, 0, "idle-pc state:%d\n", a2 & 1);
      v8 = *(unsigned __int8 *)(v9 + 836);
      result = v9;
    }
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_control_idle_pc",
             2787,
             -1,
             *(_DWORD *)(result + 24),
             v8,
             -1059143953,
             a8,
             v10);
  }
  return result;
}
