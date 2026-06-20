__int64 __fastcall sde_encoder_early_wakeup(__int64 result)
{
  __int64 v1; // x8
  unsigned int v2; // w6
  int v3; // w5
  int v4; // w4
  __int64 v5; // x8

  if ( !result )
  {
    result = printk(&unk_26FCAB, "sde_encoder_check_curr_mode");
    if ( (_drm_debug & 4) == 0 )
      return result;
    v4 = -1;
    return _drm_dev_dbg(0, 0, 0, "enc%d should only early wake up command mode display\n", v4);
  }
  if ( *(_DWORD *)(result + 648) != 2 )
  {
    if ( (_drm_debug & 4) == 0 )
      return result;
    v4 = *(_DWORD *)(result + 24);
    return _drm_dev_dbg(0, 0, 0, "enc%d should only early wake up command mode display\n", v4);
  }
  v1 = *(_QWORD *)(result + 1360);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 160);
    if ( v2 <= 0xF )
    {
      v5 = *(_QWORD *)result;
      _ReadStatusReg(SP_EL0);
      return kthread_queue_work(*(_QWORD *)(v5 + 56) + 1128LL + 80LL * v2 + 24, result + 1024);
    }
    else if ( (_drm_debug & 4) != 0 )
    {
      v3 = 0;
      return _drm_dev_dbg(0, 0, 0, "enc%d invalid CRTC: %d or crtc index: %d\n", *(_DWORD *)(result + 24), v3, v2);
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    v2 = -22;
    v3 = 1;
    return _drm_dev_dbg(0, 0, 0, "enc%d invalid CRTC: %d or crtc index: %d\n", *(_DWORD *)(result + 24), v3, v2);
  }
  return result;
}
