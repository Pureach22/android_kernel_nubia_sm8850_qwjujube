long double __fastcall ipa3_usb_notify_do(unsigned int a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  const char *v5; // x4
  long double result; // q0
  __int64 ipc_logbuf_low; // x0
  const char *v8; // x4
  unsigned __int64 v9; // x9
  _DWORD *v10; // x8
  __int64 v11; // x1
  unsigned int v12; // w21
  __int64 v13; // x0
  const char *v14; // x4
  __int64 v15; // x0
  const char *v16; // x4

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( a2 )
      v5 = "IPA_USB_REMOTE_WAKEUP";
    else
      v5 = "IPA_USB_DEVICE_READY";
    ipc_log_string(ipc_logbuf, "ipa_usb %s:%d Trying to notify USB with %s\n", "ipa3_usb_notify_do", 480, v5);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    if ( a2 )
      v8 = "IPA_USB_REMOTE_WAKEUP";
    else
      v8 = "IPA_USB_DEVICE_READY";
    result = ipc_log_string(
               ipc_logbuf_low,
               "ipa_usb %s:%d Trying to notify USB with %s\n",
               "ipa3_usb_notify_do",
               480,
               v8);
  }
  v9 = ipa3_usb_ctx + ((unsigned __int64)a1 << 8);
  v10 = *(_DWORD **)(v9 + 640);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v9 + 648);
    if ( *(v10 - 1) != -1412914982 )
      __break(0x8228u);
    v12 = ((__int64 (__fastcall *)(_QWORD, __int64, long double))v10)(a2, v11, result);
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      if ( a2 )
        v14 = "IPA_USB_REMOTE_WAKEUP";
      else
        v14 = "IPA_USB_DEVICE_READY";
      ipc_log_string(
        v13,
        "ipa_usb %s:%d Notified USB with %s. is_dpl=%d result=%d\n",
        "ipa3_usb_notify_do",
        489,
        v14,
        a1 == 1,
        v12);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      if ( a2 )
        v16 = "IPA_USB_REMOTE_WAKEUP";
      else
        v16 = "IPA_USB_DEVICE_READY";
      return ipc_log_string(
               v15,
               "ipa_usb %s:%d Notified USB with %s. is_dpl=%d result=%d\n",
               "ipa3_usb_notify_do",
               489,
               v16,
               a1 == 1,
               v12);
    }
  }
  return result;
}
