__int64 __fastcall qmp_notify_timeout(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned int v4; // w23
  __int64 v5; // x21
  __int64 v6; // x22

  v1 = a1 - 72;
  v3 = *(_QWORD *)(a1 - 360);
  v4 = *(_DWORD *)(a1 - 212);
  v5 = raw_spin_lock_irqsave(a1 - 72);
  if ( (*(_BYTE *)(a1 - 215) & 1) == 0 )
    return raw_spin_unlock_irqrestore(v1, v5);
  v6 = v3 + 248LL * v4;
  if ( (unsigned int)__ratelimit(&qmp_notify_timeout__rs, "qmp_notify_timeout") )
    printk("%s[%s]: tx timeout for %d\n", &unk_8479);
  ipc_log_string(
    *(_QWORD *)(*(_QWORD *)(a1 + 104) + 144LL),
    "%s[%s]: tx timeout for %d\n",
    (const char *)&unk_826D,
    "qmp_notify_timeout",
    *(_DWORD *)(a1 - 212));
  writel(0, *(_QWORD *)(a1 - 224) + *(unsigned int *)(a1 - 208));
  *(_BYTE *)(a1 - 215) = 0;
  raw_spin_unlock_irqrestore(v1, v5);
  return mbox_chan_txdone(v6, 4294967234LL);
}
