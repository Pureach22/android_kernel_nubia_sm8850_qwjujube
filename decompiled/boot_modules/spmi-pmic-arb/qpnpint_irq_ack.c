__int64 __fastcall qpnpint_irq_ack(__int64 a1)
{
  __int64 v2; // x20
  __int64 (*v3)(void); // x8
  unsigned int *v4; // x0
  unsigned __int64 v5; // x8
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 result; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 1LL << (WORD1(*(_QWORD *)(a1 + 8)) & 7);
  v3 = *(__int64 (**)(void))(*(_QWORD *)(**(_QWORD **)(a1 + 48) + 56LL) + 88LL);
  if ( *((_DWORD *)v3 - 1) != -395291818 )
    __break(0x8228u);
  v4 = (unsigned int *)v3();
  writel_relaxed(v2, v4);
  v5 = *(_QWORD *)(a1 + 8);
  v6 = *(_QWORD *)(a1 + 48);
  v7 = *(_QWORD *)(v6 + 40);
  v9[0] = v2;
  result = pmic_arb_write_cmd(v7, 0x30u, (v5 >> 28) & 0x1F, (v5 >> 12) & 0xFFFFFF00 | 0x14, (__int64)v9, 1);
  if ( (_DWORD)result )
  {
    result = __ratelimit(&qpnpint_spmi_write__rs, "qpnpint_spmi_write");
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)(v6 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a1 + 4));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
