__int64 __fastcall icnss_setup_dms_mac(__int64 a1)
{
  _BYTE *v2; // x20
  __int64 result; // x0
  int v4; // w21

  v2 = (_BYTE *)(a1 + 4096);
  result = ((__int64 (*)(void))icnss_qmi_get_dms_mac)();
  if ( !(_DWORD)result && v2[1552] || !v2[1560] )
    goto LABEL_17;
  if ( !v2[1552] )
  {
    result = icnss_qmi_get_dms_mac(a1);
    if ( (_DWORD)result == -11 )
    {
      result = msleep(50);
      v4 = 199;
      do
      {
        if ( v2[1552] )
          break;
        result = icnss_qmi_get_dms_mac(a1);
        if ( (_DWORD)result != -11 )
          break;
        result = msleep(50);
        --v4;
      }
      while ( v4 );
    }
  }
  if ( v2[1553] || v2[1552] )
  {
LABEL_17:
    if ( v2[1552] )
      return icnss_wlfw_wlan_mac_req_send_sync(a1, a1 + 5650, 6);
  }
  else
  {
    printk("%sicnss2: Unable to get MAC from DMS after retries\n", byte_130B32);
    return ipc_log_string(
             icnss_ipc_log_context,
             "%sicnss2: Unable to get MAC from DMS after retries\n",
             (const char *)&unk_12DBF3);
  }
  return result;
}
