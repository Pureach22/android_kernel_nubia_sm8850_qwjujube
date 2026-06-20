__int64 __fastcall dwc3_restart_usb_work(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  char v3; // w8
  int v4; // w22
  int v6; // w21
  int v7; // w8

  if ( !*(_DWORD *)(result + 232) )
  {
    v1 = result;
    v2 = (_QWORD *)(result - 600);
    mutex_lock(result + 480);
    if ( *(_BYTE *)(v1 + 146) == 1 )
    {
      result = mutex_unlock(v1 + 480);
      v3 = *(_BYTE *)(v1 + 146);
      *(_BYTE *)(v1 + 32) = 1;
      if ( (v3 & 1) != 0 )
      {
        dwc3_dbg_print(*(_QWORD *)(v1 + 656), 0xFFu, "RestartUSB", 0, (const char *)&unk_16A05);
        dwc3_resume_work(v1 - 32);
        v4 = -49;
        while ( *(_DWORD *)(*v2 + 500LL) != 2 || (*(_WORD *)(*v2 + 488LL) & 7) != 0 )
        {
          msleep(20);
          if ( __CFADD__(v4++, 1) )
          {
            dwc3_dbg_print(
              *(_QWORD *)(v1 + 656),
              0xFFu,
              "ReStart:RT SUSP",
              *(_DWORD *)(*v2 + 480LL),
              (const char *)&unk_16A05);
            _pm_runtime_suspend(*v2, 0);
            break;
          }
        }
        v7 = *(unsigned __int8 *)(v1 + 146);
        *(_BYTE *)(v1 + 32) = 0;
        if ( v7 == 1 )
          dwc3_resume_work(v1 - 32);
        *(_BYTE *)(v1 + 644) = 0;
        return flush_work(v1 + 56);
      }
      else
      {
        *(_BYTE *)(v1 + 644) = 0;
        *(_BYTE *)(v1 + 32) = 0;
      }
    }
    else
    {
      v6 = *(_DWORD *)(v1 + 152);
      result = mutex_unlock(v1 + 480);
      if ( v6 )
      {
        return dev_err(*v2, "incorrect role during restart\n");
      }
      else if ( (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 - 560) + 168LL) + 384LL) + 168LL) + 376LL)
               & 0x40) != 0 )
      {
        mutex_lock(v1 + 480);
        if ( *(_DWORD *)(v1 + 152) != 1 && !(unsigned int)dwc3_start_stop_host((__int64)v2, 0) )
        {
          ipc_log_string(*(_QWORD *)(v1 + 656), "%s: start host mode", "dwc3_start_stop_host");
          *(_DWORD *)(v1 + 152) = 0;
          *(_BYTE *)(v1 + 146) = 0;
          dwc3_ext_event_notify((__int64)v2);
        }
        return mutex_unlock(v1 + 480);
      }
    }
  }
  return result;
}
