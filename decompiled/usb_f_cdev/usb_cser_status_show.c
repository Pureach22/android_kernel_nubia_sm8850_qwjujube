__int64 __fastcall usb_cser_status_show(__int64 a1, __int64 a2)
{
  __int64 v2; // x23
  __int64 v5; // x20
  __int64 v6; // x0
  const char *v7; // x8
  __int64 v8; // x22
  int v9; // w21
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  int v15; // w19
  __int64 v17; // [xsp+0h] [xbp-20h]
  __int64 v18; // [xsp+8h] [xbp-18h]
  int v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v2 = *(_QWORD *)(a1 + 176);
  v5 = _kmalloc_cache_noprof(class_destroy, 3520, 512);
  if ( !v5 )
    return -12;
  v6 = raw_spin_lock_irqsave(v2 + 1068);
  v7 = "Opened";
  v8 = v6;
  if ( !*(_BYTE *)(v2 + 1561) )
    v7 = "Closed";
  v9 = scnprintf(
         v5,
         512,
         "###PORT:%s###\n"
         "port_no:%d\n"
         "func:%s\n"
         "nbytes_to_host: %lu\n"
         "nbytes_from_host: %lu\n"
         "nbytes_to_port_bridge:  %lu\n"
         "nbytes_from_port_bridge: %lu\n"
         "cbits_to_modem:  %u\n"
         "Port Opened: %s\n",
         v2 + 1052,
         *(unsigned int *)(v2 + 1048),
         *(_QWORD *)(a1 + 184),
         *(_QWORD *)(v2 + 1576),
         *(_QWORD *)(v2 + 1568),
         *(_QWORD *)(v2 + 1584),
         *(_QWORD *)(v2 + 1592),
         *(_DWORD *)(v2 + 1544),
         v7);
  raw_spin_unlock_irqrestore(v2 + 1068, v8);
  v15 = scnprintf(a2, v9, v5, v10, v11, v12, v13, v14, v17, v18, v19, v20);
  kfree(v5);
  return v15;
}
