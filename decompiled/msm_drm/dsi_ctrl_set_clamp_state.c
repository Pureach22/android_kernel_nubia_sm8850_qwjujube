__int64 __fastcall dsi_ctrl_set_clamp_state(__int64 a1, char a2, char a3)
{
  __int64 v3; // x8
  __int64 v7; // x1
  __int64 v9; // x9
  _DWORD *v10; // x9

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
    return 4294967274LL;
  }
  v3 = *(unsigned int *)(a1 + 1608);
  if ( (unsigned int)v3 < 3 )
  {
    if ( !*(_QWORD *)(a1 + 720 + 8 * v3) || !*(_QWORD *)(a1 + 744 + 8 * v3) )
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: No clamp control for DSI controller\n", *(const char **)(a1 + 16));
      return 0;
    }
    mutex_lock(a1 + 32);
    if ( *(_DWORD *)(a1 + 2440) == 2 )
      v7 = *(_DWORD *)(a1 + 2448) | 0x10u;
    else
      v7 = 16;
    v9 = *(unsigned int *)(a1 + 1608);
    if ( (a2 & 1) != 0 )
    {
      if ( (unsigned int)v9 < 3 )
      {
        v10 = *(_DWORD **)(a1 + 720 + 8 * v9);
        if ( !v10 )
          goto LABEL_19;
        goto LABEL_16;
      }
    }
    else if ( (unsigned int)v9 <= 2 )
    {
      v10 = *(_DWORD **)(a1 + 744 + 8 * v9);
      if ( !v10 )
      {
LABEL_19:
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Clamp state = %d\n", *(const char **)(a1 + 16), a2 & 1);
        mutex_unlock(a1 + 32);
        return 0;
      }
LABEL_16:
      if ( *(v10 - 1) != -640374085 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, __int64, _QWORD))v10)(a1 + 96, v7, a3 & 1);
      goto LABEL_19;
    }
  }
  __break(0x5512u);
  return dsi_ctrl_set_clock_source();
}
