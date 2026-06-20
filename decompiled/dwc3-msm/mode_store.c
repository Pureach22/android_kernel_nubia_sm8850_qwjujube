__int64 __fastcall mode_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  unsigned int v7; // w21
  __int64 result; // x0

  v4 = *(_QWORD *)(a1 + 152);
  if ( (sysfs_streq(a3, "peripheral") & 1) != 0 )
    v7 = 2;
  else
    v7 = sysfs_streq(a3, "host") & 1;
  ipc_log_string(*(_QWORD *)(v4 + 1256), "%s: mode_request:%s\n", "mode_store", usb_role_strings[v7]);
  LODWORD(result) = dwc3_msm_set_role(v4, v7);
  if ( (int)result >= 0 )
    return a4;
  else
    return (int)result;
}
