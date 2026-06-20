__int64 __fastcall qpnpint_irq_mask(__int64 a1)
{
  unsigned __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(_QWORD *)(a1 + 48);
  v4 = *(_QWORD *)(v3 + 40);
  v6[0] = 1LL << (BYTE2(v2) & 7);
  result = pmic_arb_write_cmd(v4, 0x30u, (v2 >> 28) & 0x1F, (v2 >> 12) & 0xFFFFFF00 | 0x16, (__int64)v6, 1);
  if ( (_DWORD)result )
  {
    result = __ratelimit(&qpnpint_spmi_write__rs, "qpnpint_spmi_write");
    if ( (_DWORD)result )
      result = dev_err(*(_QWORD *)(v3 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a1 + 4));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
