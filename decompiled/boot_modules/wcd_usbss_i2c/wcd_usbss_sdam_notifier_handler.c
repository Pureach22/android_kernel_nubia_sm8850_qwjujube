__int64 __fastcall wcd_usbss_sdam_notifier_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  unsigned __int8 *v4; // x0
  unsigned __int8 *v5; // x19
  __int64 v6; // x8
  int v7; // w0
  __int64 v8; // x8
  const char *v10; // x3
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 520);
  v11[0] = 0;
  v4 = (unsigned __int8 *)nvmem_cell_read(v3, v11);
  v5 = v4;
  if ( (unsigned __int64)v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(a2 + 8), "nvmem cell read failed, rc:%d\n", (_DWORD)v4);
  }
  else
  {
    *v4 &= 7u;
    mutex_lock(wcd_usbss_ctxt_ + 408);
    v6 = *v5;
    if ( *(_DWORD *)(a2 + 508) == (_DWORD)v6 )
    {
      if ( (unsigned int)v6 > 8 )
        v10 = "UNDEFINED";
      else
        v10 = off_B3E8[v6];
      dev_info(*(_QWORD *)(a2 + 8), "%s: wcd already in %s mode:\n", "wcd_usbss_sdam_notifier_handler", v10);
    }
    else
    {
      v7 = acquire_runtime_env(wcd_usbss_ctxt_);
      if ( v7 != -13 && v7 < 0 )
      {
        dev_err(*(_QWORD *)(a2 + 8), "%s: acquire_runtime_env failed: %d\n", "wcd_usbss_sdam_notifier_handler", v7);
      }
      else
      {
        v8 = wcd_usbss_ctxt_;
        if ( *(_BYTE *)(wcd_usbss_ctxt_ + 528) == 1 )
        {
          *(_BYTE *)(wcd_usbss_ctxt_ + 529) = 1;
          *(_DWORD *)(v8 + 532) = *v5;
        }
        else if ( !(unsigned int)wcd_usbss_sdam_handle_events_locked(*v5) )
        {
          *(_DWORD *)(a2 + 508) = *v5;
        }
        release_runtime_env(wcd_usbss_ctxt_);
      }
    }
    mutex_unlock(wcd_usbss_ctxt_ + 408);
    kfree(v5);
    LODWORD(v5) = 1;
  }
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
