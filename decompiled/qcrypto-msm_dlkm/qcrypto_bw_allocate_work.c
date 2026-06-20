_DWORD *__fastcall qcrypto_bw_allocate_work(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 v5; // x0
  int v6; // w8

  v1 = *(_DWORD **)(a1 - 160);
  v3 = a1 - 192;
  v4 = raw_spin_lock_irqsave(v1 + 13);
  *(_DWORD *)(a1 - 80) = 3;
  raw_spin_unlock_irqrestore(v1 + 13, v4);
  qcrypto_ce_set_bus(v3, 1);
  *(_QWORD *)(a1 - 56) = jiffies + 250LL;
  mod_timer(a1 - 72);
  v5 = raw_spin_lock_irqsave(v1 + 13);
  v6 = *(_DWORD *)(a1 + 32);
  *(_DWORD *)(a1 - 80) = 1;
  *(_BYTE *)(a1 - 76) = 0;
  *(_DWORD *)(a1 + 32) = v6 + 1;
  *(_BYTE *)(a1 + 40) = 1;
  raw_spin_unlock_irqrestore(v1 + 13, v5);
  return start_qcrypto_process(v1, v3);
}
