_DWORD *__fastcall qcrypto_bw_reaper_work(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 v3; // x0
  int v4; // w21
  __int64 v5; // x22
  __int64 v6; // x0
  _DWORD *result; // x0

  v1 = *(_DWORD **)(a1 - 128);
  v3 = raw_spin_lock_irqsave(v1 + 13);
  v4 = *(_DWORD *)(a1 + 64);
  v5 = v3;
  if ( *(_DWORD *)(a1 - 48) == 1 && v4 == *(_DWORD *)(a1 + 68) )
  {
    if ( *(int *)(a1 + 88) < 1 )
    {
      *(_DWORD *)(a1 - 48) = 2;
      raw_spin_unlock_irqrestore(v1 + 13, v3);
      qcrypto_ce_set_bus(a1 - 160, 0);
      v5 = raw_spin_lock_irqsave(v1 + 13);
      if ( *(_BYTE *)(a1 - 44) == 1 )
      {
        *(_DWORD *)(a1 - 48) = 3;
        raw_spin_unlock_irqrestore(v1 + 13, v5);
        qcrypto_ce_set_bus(a1 - 160, 1);
        v6 = raw_spin_lock_irqsave(v1 + 13);
        *(_DWORD *)(a1 - 48) = 1;
        *(_BYTE *)(a1 - 44) = 0;
        *(_DWORD *)(a1 + 68) = v4;
        raw_spin_unlock_irqrestore(v1 + 13, v6);
        result = start_qcrypto_process(v1, a1 - 160);
        goto LABEL_11;
      }
      *(_DWORD *)(a1 - 48) = 0;
    }
    else
    {
      if ( *(_BYTE *)(a1 + 72) == 1 )
        dev_warn(*(_QWORD *)(a1 - 136) + 16LL, "The engine appears to be stuck seq %d.\n", v4);
      *(_BYTE *)(a1 + 72) = 0;
    }
  }
  *(_DWORD *)(a1 + 68) = v4;
  result = (_DWORD *)raw_spin_unlock_irqrestore(v1 + 13, v5);
LABEL_11:
  if ( *(_DWORD *)(a1 - 48) )
  {
    *(_QWORD *)(a1 - 24) = jiffies + 250LL;
    return (_DWORD *)mod_timer(a1 - 40);
  }
  return result;
}
