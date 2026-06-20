__int64 __fastcall qpnpint_irq_unmask(__int64 a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x9
  __int64 v4; // x20
  __int64 (*v5)(void); // x8
  unsigned int *v6; // x0
  __int64 v7; // x21
  __int64 result; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x9
  __int64 v11; // x20
  __int64 v12; // x0
  unsigned __int8 v13[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v3 = *(_QWORD *)(a1 + 8);
  *(_WORD *)v13 = 0;
  v4 = (v3 >> 16) & 7;
  v5 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)v2 + 56LL) + 72LL);
  if ( *((_DWORD *)v5 - 1) != -395291818 )
    __break(0x8228u);
  v6 = (unsigned int *)v5();
  writel_relaxed(1u, v6);
  v7 = *(_QWORD *)(a1 + 48);
  result = pmic_arb_read_cmd(
             *(_QWORD *)(v7 + 40),
             56,
             (*(_QWORD *)(a1 + 8) >> 28) & 0x1F,
             (*(_QWORD *)(a1 + 8) >> 12) & 0xFFFFFF00 | 0x15,
             (__int64)v13,
             1);
  if ( (_DWORD)result )
  {
    result = __ratelimit(&qpnpint_spmi_read__rs, "qpnpint_spmi_read");
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)(v7 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a1 + 4));
  }
  v9 = 1LL << v4;
  if ( ((1LL << v4) & v13[0]) == 0 )
  {
    v10 = *(_QWORD *)(a1 + 8);
    v11 = *(_QWORD *)(a1 + 48);
    v12 = *(_QWORD *)(v11 + 40);
    v13[0] = v9;
    v13[1] = v9;
    result = pmic_arb_write_cmd(v12, 0x30u, (v10 >> 28) & 0x1F, (v10 >> 12) & 0xFFFFFF00 | 0x14, (__int64)v13, 2);
    if ( (_DWORD)result )
    {
      result = __ratelimit(&qpnpint_spmi_write__rs, "qpnpint_spmi_write");
      if ( (_DWORD)result )
        result = dev_err(*(_QWORD *)(v11 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a1 + 4));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
