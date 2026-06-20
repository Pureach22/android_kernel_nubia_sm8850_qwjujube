bool __fastcall msm_serial_try_disable_interrupts(__int64 a1)
{
  unsigned __int64 StatusReg; // x21
  int v8; // w19
  int v9; // w21
  int v10; // w22
  __int64 v11; // x8
  int v12; // w21
  int v13; // w22
  int v14; // w23
  int v15; // w0

  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v8 = raw_spin_trylock();
  if ( v8 )
  {
    raw_spin_unlock_irqrestore(a1, StatusReg);
  }
  else
  {
    _WriteStatusReg(DAIF, StatusReg);
    v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
    writel_relaxed(v9 & 0xF33FFFCF, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
    writel_relaxed(v10 & 0xF3FFFFCF, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
    if ( *(_DWORD *)(a1 + 584) == 2 )
    {
      writel_relaxed(0x400Fu, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3152LL));
      writel_relaxed(0x41EFu, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3408LL));
    }
    v11 = *(_QWORD *)(a1 + 264);
    if ( !v11 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v11 + 74) )
    {
      v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
      v13 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
      v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3144LL));
      v15 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3400LL));
      ipc_log_string(
        *(_QWORD *)(a1 + 992),
        "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
        "msm_serial_try_disable_interrupts",
        v12,
        v13,
        v14,
        v15);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n");
    }
  }
  return v8 == 0;
}
