void __fastcall msm_geni_serial_enable_interrupts(__int64 a1)
{
  int v2; // w20
  int v3; // w0
  __int64 v4; // x8
  int v5; // w20
  unsigned int v6; // w21
  unsigned int v7; // w0
  __int64 v8; // x8
  int v9; // w20
  int v10; // w21
  int v11; // w22
  int v12; // w0

  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
  v4 = *(_QWORD *)(a1 + 208);
  v5 = v2 | 0xCC00030;
  if ( v4 && *(_QWORD *)(v4 + 152) )
  {
    v6 = v3 | 0xC001C30;
  }
  else
  {
    v5 &= 0xF73FFFFF;
    v6 = v3 & 0xF3FFE3CF | 0xC000030;
  }
  ipc_log_string(
    *(_QWORD *)(a1 + 992),
    "%s: geni_m_irq_en = 0x%x geni_s_irq_en = 0x%x\n",
    "msm_geni_serial_enable_interrupts",
    v5,
    v6);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: geni_m_irq_en = 0x%x geni_s_irq_en = 0x%x\n");
  if ( *(_BYTE *)(a1 + 1136) )
    v7 = v5 & 0xFBFFFFFF;
  else
    v7 = v5;
  if ( *(_BYTE *)(a1 + 1136) )
    v6 &= ~0x4000000u;
  writel_relaxed(v7, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
  writel_relaxed(v6, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
  if ( *(_DWORD *)(a1 + 584) == 2 )
  {
    writel_relaxed(0x400Fu, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3148LL));
    writel_relaxed(0x41EFu, (unsigned int *)(*(_QWORD *)(a1 + 16) + 3404LL));
  }
  v8 = *(_QWORD *)(a1 + 264);
  if ( !v8 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v8 + 74) )
  {
    v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1556LL));
    v10 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1604LL));
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3144LL));
    v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3400LL));
    ipc_log_string(
      *(_QWORD *)(a1 + 992),
      "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n",
      "msm_geni_serial_enable_interrupts",
      v9,
      v10,
      v11,
      v12);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: M_IRQ_EN:0x%x S_IRQ_EN:0x%x TX_IRQ_EN:0x%x RX_IRQ_EN:0x%x\n");
  }
}
