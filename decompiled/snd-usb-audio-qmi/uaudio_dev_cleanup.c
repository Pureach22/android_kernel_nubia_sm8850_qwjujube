__int64 __fastcall uaudio_dev_cleanup(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x24
  __int64 i; // x25
  __int64 v5; // x0
  __int64 result; // x0

  if ( *(_QWORD *)a1 )
  {
    v1 = *(_DWORD *)(a1 + 64);
    if ( v1 >= 1 )
    {
      v3 = 0;
      for ( i = 0; i < v1; ++i )
      {
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 72) + v3 + 76) == 1 )
        {
          uaudio_dev_intf_cleanup(*(_QWORD *)a1);
          ipc_log_string(
            *(_QWORD *)(uaudio_svc + 24),
            "%s%s: release resources: intf# %d card# %d\n",
            (const char *)&unk_B13E,
            "uaudio_dev_cleanup",
            *(unsigned __int8 *)(*(_QWORD *)(a1 + 72) + v3 + 72),
            *(_DWORD *)(a1 + 16));
          printk("%s%s: release resources: intf# %d card# %d\n", &unk_B8A7);
          v1 = *(_DWORD *)(a1 + 64);
        }
        v3 += 80;
      }
    }
    v5 = *(_QWORD *)(a1 + 72);
    *(_DWORD *)(a1 + 64) = 0;
    kfree(v5);
    *(_QWORD *)(a1 + 72) = 0;
    result = uaudio_event_ring_cleanup_free(a1);
    *(_QWORD *)a1 = 0;
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: USB audio device memory is already freed.\n",
      (const char *)&unk_B13E,
      "uaudio_dev_cleanup");
    return printk("%s%s: USB audio device memory is already freed.\n", &unk_B8A7);
  }
  return result;
}
