__int64 __fastcall uaudio_qmi_bye_cb(__int64 result, int a2)
{
  __int64 v2; // x22
  _QWORD *v3; // x23
  __int64 v4; // x0

  v2 = uaudio_svc;
  if ( *(_QWORD *)uaudio_svc == result )
  {
    if ( *(_BYTE *)(uaudio_svc + 20) == 1 )
    {
      v3 = (_QWORD *)(uaudio_svc + 12);
      if ( *(_DWORD *)(uaudio_svc + 12) == a2 )
      {
        ipc_log_string(
          *(_QWORD *)(uaudio_svc + 24),
          "%s%s: node: %d\n",
          (const char *)&unk_B13E,
          "uaudio_qmi_bye_cb",
          a2);
        v4 = printk("%s%s: node: %d\n", &unk_B8A7);
        result = uaudio_qmi_disconnect(v4);
        *(_WORD *)(v2 + 8) = 0;
        *v3 = 0;
        *(_BYTE *)(v2 + 20) = 0;
      }
    }
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: handle mismatch\n",
      (const char *)&unk_B13E,
      "uaudio_qmi_bye_cb");
    return printk("%s%s: handle mismatch\n", &unk_B45D);
  }
  return result;
}
