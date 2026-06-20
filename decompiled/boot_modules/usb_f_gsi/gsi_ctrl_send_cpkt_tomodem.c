__int64 __fastcall gsi_ctrl_send_cpkt_tomodem(__int64 a1, const void *a2, size_t a3)
{
  __int64 v6; // x20
  void **v7; // x0
  void **v9; // x21
  void **v10; // x0
  void *v11; // x2
  void **v12; // x1

  v6 = raw_spin_lock_irqsave(a1 + 1304);
  if ( (*(_BYTE *)(a1 + 1232) & 1) == 0 )
  {
    if ( a1 )
      ipc_log_string(
        *(_QWORD *)(a1 + 1344),
        "%s: ctrl device %s is not open",
        "gsi_ctrl_send_cpkt_tomodem",
        (const char *)(a1 + 1056));
    ++*(_DWORD *)(a1 + 1332);
    return raw_spin_unlock_irqrestore(a1 + 1304, v6);
  }
  v7 = (void **)gsi_ctrl_pkt_alloc(a3, 0x820u);
  if ( (unsigned __int64)v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( a1 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: Reset func pkt allocation failed", "gsi_ctrl_send_cpkt_tomodem");
      printk(&unk_10E43, "gsi_ctrl_send_cpkt_tomodem");
    }
    return raw_spin_unlock_irqrestore(a1 + 1304, v6);
  }
  v9 = v7;
  memcpy(*v7, a2, a3);
  *((_DWORD *)v9 + 2) = a3;
  v10 = v9 + 2;
  v11 = (void *)(a1 + 1264);
  v12 = *(void ***)(a1 + 1272);
  if ( v9 + 2 == (void **)(a1 + 1264) || v12 == v10 || *v12 != v11 )
  {
    _list_add_valid_or_report(v10);
  }
  else
  {
    *(_QWORD *)(a1 + 1272) = v10;
    v9[2] = v11;
    v9[3] = v12;
    *v12 = v10;
  }
  ++*(_DWORD *)(a1 + 1316);
  raw_spin_unlock_irqrestore(a1 + 1304, v6);
  if ( a1 )
    ipc_log_string(*(_QWORD *)(a1 + 1344), "%s: Wake up read queue", "gsi_ctrl_send_cpkt_tomodem");
  return _wake_up(a1 + 1240, 3, 1, 0);
}
