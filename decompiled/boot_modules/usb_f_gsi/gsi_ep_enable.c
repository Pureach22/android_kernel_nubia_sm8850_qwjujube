__int64 __fastcall gsi_ep_enable(_QWORD *a1)
{
  __int64 v1; // x2
  __int64 v3; // x2
  __int64 result; // x0
  __int64 v5; // x8
  _QWORD *v6; // x1
  unsigned int v7; // w19

  v1 = a1[38];
  if ( !v1 || *(_QWORD *)(v1 + 24) )
    goto LABEL_3;
  result = config_ep_by_speed(a1[62], a1);
  if ( !(_DWORD)result )
  {
    if ( a1 )
      ipc_log_string(a1[168], "%s: Enable IN ep", "gsi_ep_enable");
    result = usb_gsi_ep_op(a1[38], a1 + 40, 0);
    if ( !(_DWORD)result )
    {
LABEL_3:
      v3 = a1[39];
      if ( v3 && !*(_QWORD *)(v3 + 24) )
      {
        result = config_ep_by_speed(a1[62], a1);
        if ( !(_DWORD)result )
        {
          if ( a1 )
            ipc_log_string(a1[168], "%s: Enable OUT ep", "gsi_ep_enable");
          result = usb_gsi_ep_op(a1[39], a1 + 51, 0);
          if ( (_DWORD)result )
          {
            v5 = a1[38];
            if ( v5 )
            {
              v6 = a1 + 40;
              v7 = result;
              usb_gsi_ep_op(v5, v6, 13);
              return v7;
            }
          }
        }
      }
      else
      {
        return 0;
      }
    }
  }
  return result;
}
