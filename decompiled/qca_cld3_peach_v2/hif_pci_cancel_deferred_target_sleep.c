__int64 __fastcall hif_pci_cancel_deferred_target_sleep(_QWORD *a1)
{
  __int64 v2; // x22
  _QWORD *v3; // x21
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x1

  v2 = a1[5];
  v3 = a1 + 3072;
  v4 = raw_spin_lock_irqsave(a1 + 3409);
  v5 = *((unsigned __int8 *)v3 + 2733);
  v6 = v4;
  a1[3410] = v4;
  if ( v5 == 1 )
  {
    timer_delete(a1 + 3414);
    if ( (*((_BYTE *)v3 + 2732) & 1) == 0 )
      hif_write32_mb_reg_window(
        (__int64)a1,
        v2 + *(_DWORD *)(a1[79] + 160LL) + *(_DWORD *)(a1[79] + 168LL),
        *(_DWORD *)(a1[79] + 164LL));
    v6 = a1[3410];
    *((_BYTE *)v3 + 2733) = 0;
  }
  return raw_spin_unlock_irqrestore(a1 + 3409, v6);
}
