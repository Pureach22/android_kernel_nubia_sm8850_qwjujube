__int64 __fastcall icnss_create_ramdump_device(__int64 a1, const char *a2)
{
  __int64 v4; // x0
  unsigned int *v5; // x19
  unsigned int v6; // w3
  unsigned __int64 v7; // x0
  int v8; // w22
  __int64 v9; // x20

  v4 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 48);
  v5 = (unsigned int *)v4;
  if ( !v4 )
    return -12;
  if ( a2 )
  {
    snprintf((char *)(v4 + 4), 0x20u, "icnss_%s", a2);
    v6 = ida_alloc_range(&rd_minor_id, 0, 255, 3264);
    *v5 = v6;
    if ( (v6 & 0x80000000) != 0 )
    {
      printk("%sicnss2: %s: No more minor numbers left! rc:%d\n", byte_130B32, "icnss_create_ramdump_device", v6);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: %s: No more minor numbers left! rc:%d\n",
        (const char *)&unk_12DBF3,
        "icnss_create_ramdump_device",
        *v5);
      v9 = -19;
      goto LABEL_9;
    }
    v7 = device_create(*(_QWORD *)(a1 + 5792), 0, *(_DWORD *)(a1 + 5800) & 0xFFF00000 | v6, v5, v5 + 1);
    *((_QWORD *)v5 + 5) = v7;
    if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
    {
      v8 = v7;
      printk(
        "%sicnss2: %s: Device create failed for %s (%d)\n",
        byte_130B32,
        "icnss_create_ramdump_device",
        (const char *)v5 + 4,
        v7);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: %s: Device create failed for %s (%d)\n",
        (const char *)&unk_12DBF3,
        "icnss_create_ramdump_device",
        (const char *)v5 + 4,
        v8);
      ida_free(&rd_minor_id, *v5);
      v9 = v8;
LABEL_9:
      kfree(v5);
      return v9;
    }
  }
  else
  {
    printk("%sicnss2: %s: Invalid device name.\n", byte_130B32, "icnss_create_ramdump_device");
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2: %s: Invalid device name.\n",
      (const char *)&unk_12DBF3,
      "icnss_create_ramdump_device");
    return 0;
  }
  return (__int64)v5;
}
