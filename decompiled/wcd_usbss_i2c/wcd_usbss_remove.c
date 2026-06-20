__int64 __fastcall wcd_usbss_remove(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x21
  __int64 v3; // x19
  int v4; // w20
  __int64 v5; // x20
  unsigned int v6; // w8
  unsigned int v13; // w10

  v1 = *(_QWORD *)(result + 184);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 8);
    v3 = result;
    v4 = _pm_runtime_resume(v2, 4);
    if ( v4 < 0 )
    {
      v6 = *(_DWORD *)(v2 + 480);
      do
      {
        if ( !v6 )
          break;
        _X12 = (unsigned int *)(v2 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v13 = __ldxr(_X12);
          if ( v13 != v6 )
            break;
          if ( !__stlxr(v6 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v13 == v6;
        v6 = v13;
      }
      while ( !_ZF );
      dev_err(*(_QWORD *)(v1 + 8), "%s: pm_runtime_resume_and_get failed: %i\n", "wcd_usbss_remove", v4);
    }
    if ( *(_BYTE *)(wcd_usbss_ctxt_ + 372) == 1 && *(_QWORD *)(wcd_usbss_ctxt_ + 384) )
    {
      kthread_stop();
      *(_QWORD *)(wcd_usbss_ctxt_ + 384) = 0;
    }
    typec_mux_unregister(*(_QWORD *)(v1 + 24));
    cancel_work_sync(v1 + 40);
    pm_relax(*(_QWORD *)(v1 + 8));
    if ( (v4 & 0x80000000) == 0 )
      _pm_runtime_idle(*(_QWORD *)(v1 + 8), 4);
    _pm_runtime_use_autosuspend(*(_QWORD *)(v1 + 8), 0);
    _pm_runtime_disable(*(_QWORD *)(v1 + 8), 1);
    v5 = *(_QWORD *)(v1 + 8);
    device_wakeup_disable(v5);
    result = device_set_wakeup_capable(v5, 0);
    *(_QWORD *)(v3 + 184) = 0;
    wcd_usbss_ctxt_ = 0;
  }
  return result;
}
