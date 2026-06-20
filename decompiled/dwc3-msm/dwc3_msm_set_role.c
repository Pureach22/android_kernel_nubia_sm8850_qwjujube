__int64 __fastcall dwc3_msm_set_role(__int64 a1, unsigned int a2)
{
  int v5; // w22
  const char *v6; // x4
  __int64 v7; // x0
  int v8; // w3
  int v9; // w8
  __int64 v10; // x0
  int v11; // w3
  int v12; // w3
  const char *v13; // x3
  __int64 v14; // x0
  int v15; // w4

  if ( a2 == 2 )
  {
    if ( *(_DWORD *)(a1 + 700) == 1 )
      return 4294967274LL;
  }
  else if ( a2 == 1 && *(_DWORD *)(a1 + 700) == 2 )
  {
    return 4294967274LL;
  }
  mutex_lock(a1 + 1080);
  if ( (*(_BYTE *)(a1 + 746) & 1) != 0 )
    v5 = 2;
  else
    v5 = *(_DWORD *)(a1 + 752) == 0;
  if ( a2 > 2 )
    v6 = "Invalid";
  else
    v6 = usb_role_strings[a2];
  ipc_log_string(
    *(_QWORD *)(a1 + 1256),
    "%s: cur_role:%s new_role:%s refcnt:%d\n",
    "dwc3_msm_set_role",
    usb_role_strings[v5],
    v6,
    *(_DWORD *)(a1 + 2568));
  if ( v5 != a2 || !*(_DWORD *)(a1 + 696) )
  {
    if ( a2 )
    {
      if ( a2 == 2 )
      {
        v10 = *(_QWORD *)(a1 + 1256);
        v11 = *(_DWORD *)(a1 + 2568);
        *(_BYTE *)(a1 + 746) = 1;
        *(_DWORD *)(a1 + 752) = 1;
        ipc_log_string(v10, "%s: refcnt:%d reset refcnt_dp_usb\n", "dwc3_msm_set_role", v11);
        v9 = 0;
      }
      else
      {
        if ( a2 != 1 )
        {
          v13 = "Invalid";
          goto LABEL_27;
        }
        v7 = *(_QWORD *)(a1 + 1256);
        v8 = *(_DWORD *)(a1 + 2568);
        *(_BYTE *)(a1 + 746) = 0;
        *(_DWORD *)(a1 + 752) = 0;
        ipc_log_string(v7, "%s: refcnt:%d start host mode\n", "dwc3_msm_set_role", v8);
        if ( v5 == 1 )
        {
LABEL_25:
          v13 = usb_role_strings[a2];
LABEL_27:
          ipc_log_string(
            *(_QWORD *)(a1 + 1256),
            "%s: new_role:%s refcnt:%d\n",
            "dwc3_msm_set_role",
            v13,
            *(_DWORD *)(a1 + 2568));
          mutex_unlock(a1 + 1080);
          dwc3_ext_event_notify(a1);
          return 0;
        }
        v9 = *(_DWORD *)(a1 + 2568) + 1;
      }
    }
    else
    {
      v12 = *(_DWORD *)(a1 + 2572);
      if ( v12 != 1 )
      {
        v14 = *(_QWORD *)(a1 + 1256);
        v15 = *(_DWORD *)(a1 + 2568) - 1;
        *(_DWORD *)(a1 + 2568) = v15;
        ipc_log_string(v14, "%s: DP (%d)session active, refcnt:%d\n", "dwc3_msm_set_role", v12, v15);
        goto LABEL_15;
      }
      v9 = 0;
      *(_BYTE *)(a1 + 746) = 0;
      *(_DWORD *)(a1 + 752) = 1;
    }
    *(_DWORD *)(a1 + 2568) = v9;
    goto LABEL_25;
  }
  ipc_log_string(*(_QWORD *)(a1 + 1256), "%s: no USB role change", "dwc3_msm_set_role");
LABEL_15:
  mutex_unlock(a1 + 1080);
  return 0;
}
