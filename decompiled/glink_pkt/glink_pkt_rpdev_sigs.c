__int64 __fastcall glink_pkt_rpdev_sigs(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 v4; // x20
  __int64 v5; // x0

  v4 = *(_QWORD *)(a1 + 136);
  ipc_log_string(
    glink_pkt_ilctxt,
    "[%s]: Received signal new:0x%x old:0x%x on channel:%s\n",
    "glink_pkt_rpdev_sigs",
    a4,
    a3,
    *(const char **)(v4 + 232));
  v5 = raw_spin_lock_irqsave(v4 - 132);
  *(_DWORD *)(v4 - 56) = 1;
  raw_spin_unlock_irqrestore(v4 - 132, v5);
  _wake_up(v4 - 80, 1, 1, 0);
  return 0;
}
