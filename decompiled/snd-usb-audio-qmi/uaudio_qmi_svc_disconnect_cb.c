__int64 __fastcall uaudio_qmi_svc_disconnect_cb(__int64 result, int a2, int a3)
{
  __int64 v3; // x23
  _QWORD *v4; // x24
  __int64 v5; // x0

  v3 = uaudio_svc;
  if ( uaudio_svc )
  {
    if ( *(_QWORD *)uaudio_svc == result )
    {
      if ( *(_BYTE *)(uaudio_svc + 20) == 1 )
      {
        v4 = (_QWORD *)(uaudio_svc + 12);
        if ( *(_DWORD *)(uaudio_svc + 12) == a2 && *(_DWORD *)(uaudio_svc + 16) == a3 )
        {
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: client node:%x port:%x\n",
            (const char *)&unk_B13E,
            "uaudio_qmi_svc_disconnect_cb",
            a2,
            a3);
          v5 = printk("%s%s: client node:%x port:%x\n", &unk_B8A7);
          result = uaudio_qmi_disconnect(v5);
          *(_WORD *)(v3 + 8) = 0;
          *v4 = 0;
          *(_BYTE *)(v3 + 20) = 0;
        }
      }
    }
    else
    {
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: handle mismatch\n",
        (const char *)&unk_B13E,
        "uaudio_qmi_svc_disconnect_cb");
      return printk("%s%s: handle mismatch\n", &unk_B45D);
    }
  }
  return result;
}
