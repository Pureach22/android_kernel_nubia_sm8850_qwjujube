__int64 __fastcall cnss_request_firmware_direct(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x9
  const char *v12; // x1
  __int16 v13; // w10
  const char *v14; // x9
  int qmi_timeout; // w0
  __int64 v16; // x22
  __int64 v17; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else
  {
    v13 = *(_DWORD *)(StatusReg + 16);
    v14 = (const char *)(StatusReg + 2320);
    if ( (v13 & 0xFF00) != 0 )
      v12 = "soft_irq";
    else
      v12 = v14;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_request_firmware_direct",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    a3,
    a8,
    vars0);
  qmi_timeout = cnss_get_qmi_timeout(a1);
  v16 = jiffies;
  v17 = _msecs_to_jiffies((unsigned int)(qmi_timeout + 65000));
  mod_timer(a1 + 784, v17 + v16);
  return firmware_request_nowarn(a2, a3, *a1 + 16LL);
}
