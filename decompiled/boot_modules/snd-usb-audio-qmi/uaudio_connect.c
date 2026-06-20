__int64 __fastcall uaudio_connect(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w20
  unsigned int v5; // w8
  __int64 result; // x0
  unsigned int v7; // w9
  unsigned int v8; // w9

  if ( **(int **)(a1 + 16) >= 32 )
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: Invalid card number\n",
      (const char *)&unk_B13E,
      "uaudio_connect");
    return printk("%s%s: Invalid card number\n", &unk_B45D);
  }
  v5 = *(_DWORD *)(a1 + 256) - 1;
  if ( v5 >= 0x10 )
    goto LABEL_9;
  result = xhci_sideband_register(*(_QWORD *)(a1 + 8LL * v5 + 24), 1, 0);
  if ( !result )
    return result;
  v7 = **(_DWORD **)(a1 + 16);
  if ( v7 > 0x1F || (uadev[11 * v7 + 10] = a1, v8 = **(_DWORD **)(a1 + 16), v8 > 0x1F) )
  {
LABEL_9:
    __break(0x5512u);
    atomic_store(v3, (unsigned int *)(a3 - 112));
    return uaudio_disconnect();
  }
  uadev[11 * v8 + 7] = result;
  return result;
}
