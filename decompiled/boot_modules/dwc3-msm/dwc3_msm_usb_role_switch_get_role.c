__int64 dwc3_msm_usb_role_switch_get_role()
{
  __int64 drvdata; // x0
  unsigned int v1; // w19

  drvdata = usb_role_switch_get_drvdata();
  if ( (*(_BYTE *)(drvdata + 746) & 1) != 0 )
    v1 = 2;
  else
    v1 = *(_DWORD *)(drvdata + 752) == 0;
  ipc_log_string(
    *(_QWORD *)(drvdata + 1256),
    "%s: get_role:%s\n",
    "dwc3_msm_usb_role_switch_get_role",
    usb_role_strings[v1]);
  return v1;
}
