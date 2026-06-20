__int64 __fastcall qce_core_irq_bottom_half(__int64 a1)
{
  unsigned int v2; // w25
  unsigned int v3; // w21
  unsigned int v4; // w22
  unsigned int v5; // w23
  unsigned int v6; // w24
  unsigned int v7; // w0
  __int64 v8; // x2
  unsigned int v9; // w20
  __int64 result; // x0
  unsigned int v11; // w26
  void (__fastcall *v12)(__int64, __int64 *); // x8
  __int64 v13; // x0
  int v14; // w25
  void (__fastcall *v15)(__int64, __int64 *); // x8
  __int64 v16; // x0
  void (__fastcall *v17)(__int64, __int64 *); // x8
  __int64 v18; // x0
  void (__fastcall *v19)(__int64, __int64 *); // x8
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, __int64 *); // x8
  __int64 v22; // x0
  void (__fastcall *v23)(__int64, __int64 *); // x8
  __int64 v24; // x0
  void (__fastcall *v25)(__int64, __int64 *); // x8
  __int64 v26; // x0
  void (__fastcall *v27)(__int64, __int64 *); // x8
  __int64 v28; // x0
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  char v30; // [xsp+10h] [xbp-10h]
  __int64 v31; // [xsp+18h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106752LL));
  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106756LL));
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106780LL));
  v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106788LL));
  v6 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106792LL));
  v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 80) + 106812LL));
  if ( (v2 & 0x80) != 0 )
    panic("QCE CORE IRQ for DOUT_RDY is unimplemented.\n");
  if ( (v2 & 0x40) != 0 )
    panic("QCE CORE IRQ for DIN_RDY is unimplemented.\n");
  if ( (v2 & 0x20) != 0 )
    panic("QCE CORE IRQ for OP_DONE is unimplemented.\n");
  v9 = v7;
  if ( (v2 & 0x10) != 0 )
  {
    v11 = v2;
    printk(&unk_152E5, "qce_core_error_intr_irq", v8);
    v30 = 0;
    v29 = 0;
    qce_get_crypto_status(a1, (__int64)&v29);
    if ( *(_DWORD *)(a1 + 2624) && *(_BYTE *)(a1 + 2628) == 1 )
    {
      *(_BYTE *)(a1 + 2628) = 0;
      printk(&unk_158D6, "qce_core_error_intr_irq", 0);
      v12 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 9936);
      if ( !v12 )
      {
        v14 = 0;
        goto LABEL_59;
      }
      v13 = *(_QWORD *)(a1 + 9952);
      if ( *((_DWORD *)v12 - 1) != 1804681785 )
        __break(0x8228u);
      v12(v13, &v29);
    }
    if ( *(_DWORD *)(a1 + 10056) && *(_BYTE *)(a1 + 10060) == 1 )
    {
      *(_BYTE *)(a1 + 10060) = 0;
      v14 = 1;
      printk(&unk_158D6, "qce_core_error_intr_irq", 1);
      v15 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 17368);
      if ( !v15 )
        goto LABEL_59;
      v16 = *(_QWORD *)(a1 + 17384);
      if ( *((_DWORD *)v15 - 1) != 1804681785 )
        __break(0x8228u);
      v15(v16, &v29);
      v2 = v11;
    }
    if ( *(_DWORD *)(a1 + 17488) && *(_BYTE *)(a1 + 17492) == 1 )
    {
      *(_BYTE *)(a1 + 17492) = 0;
      v14 = 2;
      printk(&unk_158D6, "qce_core_error_intr_irq", 2);
      v17 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 24800);
      if ( !v17 )
        goto LABEL_59;
      v18 = *(_QWORD *)(a1 + 24816);
      if ( *((_DWORD *)v17 - 1) != 1804681785 )
        __break(0x8228u);
      v17(v18, &v29);
      v2 = v11;
    }
    if ( *(_DWORD *)(a1 + 24920) && *(_BYTE *)(a1 + 24924) == 1 )
    {
      *(_BYTE *)(a1 + 24924) = 0;
      v14 = 3;
      printk(&unk_158D6, "qce_core_error_intr_irq", 3);
      v19 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 32232);
      if ( !v19 )
        goto LABEL_59;
      v20 = *(_QWORD *)(a1 + 32248);
      if ( *((_DWORD *)v19 - 1) != 1804681785 )
        __break(0x8228u);
      v19(v20, &v29);
      v2 = v11;
    }
    if ( *(_DWORD *)(a1 + 32352) && *(_BYTE *)(a1 + 32356) == 1 )
    {
      *(_BYTE *)(a1 + 32356) = 0;
      v14 = 4;
      printk(&unk_158D6, "qce_core_error_intr_irq", 4);
      v21 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 39664);
      if ( !v21 )
        goto LABEL_59;
      v22 = *(_QWORD *)(a1 + 39680);
      if ( *((_DWORD *)v21 - 1) != 1804681785 )
        __break(0x8228u);
      v21(v22, &v29);
      v2 = v11;
    }
    if ( *(_DWORD *)(a1 + 39784) && *(_BYTE *)(a1 + 39788) == 1 )
    {
      *(_BYTE *)(a1 + 39788) = 0;
      v14 = 5;
      printk(&unk_158D6, "qce_core_error_intr_irq", 5);
      v23 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 47096);
      if ( !v23 )
        goto LABEL_59;
      v24 = *(_QWORD *)(a1 + 47112);
      if ( *((_DWORD *)v23 - 1) != 1804681785 )
        __break(0x8228u);
      v23(v24, &v29);
      v2 = v11;
    }
    if ( *(_DWORD *)(a1 + 47216) && *(_BYTE *)(a1 + 47220) == 1 )
    {
      *(_BYTE *)(a1 + 47220) = 0;
      v14 = 6;
      printk(&unk_158D6, "qce_core_error_intr_irq", 6);
      v25 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 54528);
      if ( !v25 )
        goto LABEL_59;
      v26 = *(_QWORD *)(a1 + 54544);
      if ( *((_DWORD *)v25 - 1) != 1804681785 )
        __break(0x8228u);
      v25(v26, &v29);
      v2 = v11;
    }
    if ( !*(_DWORD *)(a1 + 54648) || *(_BYTE *)(a1 + 54652) != 1 )
    {
LABEL_22:
      v2 &= 0xFFFFFF0F;
      goto LABEL_5;
    }
    *(_BYTE *)(a1 + 54652) = 0;
    v14 = 7;
    printk(&unk_158D6, "qce_core_error_intr_irq", 7);
    v27 = *(void (__fastcall **)(__int64, __int64 *))(a1 + 61960);
    if ( v27 )
    {
      v28 = *(_QWORD *)(a1 + 61976);
      if ( *((_DWORD *)v27 - 1) != 1804681785 )
        __break(0x8228u);
      v27(v28, &v29);
      v2 = v11;
      goto LABEL_22;
    }
LABEL_59:
    panic("No error callback for req_info: %d.\n", v14);
  }
LABEL_5:
  writel_relaxed(v2, *(_QWORD *)(a1 + 80) + 106752LL);
  writel_relaxed(v3, *(_QWORD *)(a1 + 80) + 106756LL);
  writel_relaxed(v4, *(_QWORD *)(a1 + 80) + 106780LL);
  writel_relaxed(v5, *(_QWORD *)(a1 + 80) + 106788LL);
  writel_relaxed(v6, *(_QWORD *)(a1 + 80) + 106792LL);
  result = writel_relaxed(v9, *(_QWORD *)(a1 + 80) + 106812LL);
  _ReadStatusReg(SP_EL0);
  return result;
}
