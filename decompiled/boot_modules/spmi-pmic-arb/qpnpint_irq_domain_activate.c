__int64 __fastcall qpnpint_irq_domain_activate(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w5
  int v5; // w6
  __int64 v6; // x0
  __int64 v8; // x20
  __int64 result; // x0
  _BYTE v10[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a2 + 48);
  v3 = *(_QWORD *)(a2 + 8);
  v4 = *(unsigned __int8 *)(*v2 + 49LL);
  v5 = *(unsigned __int8 *)(v2[19] + 4 * (v3 & 0x1FFF) + 3);
  if ( v5 == v4 )
  {
    v6 = v2[5];
    v10[0] = 1LL << (BYTE2(v3) & 7);
    if ( (unsigned int)pmic_arb_write_cmd(v6, 0x30u, (v3 >> 28) & 0x1F, (v3 >> 12) & 0xFFFFFF00 | 0x16, (__int64)v10, 1)
      && (unsigned int)__ratelimit(&qpnpint_spmi_write__rs, "qpnpint_spmi_write") )
    {
      dev_err(v2[5], "failed irqchip transaction on %x\n", *(_DWORD *)(a2 + 4));
    }
    v8 = *(_QWORD *)(a2 + 48);
    result = pmic_arb_write_cmd(
               *(_QWORD *)(v8 + 40),
               0x30u,
               (*(_QWORD *)(a2 + 8) >> 28) & 0x1F,
               (*(_QWORD *)(a2 + 8) >> 12) & 0xFFFFFF00 | 0x14,
               (__int64)v10,
               1);
    if ( (_DWORD)result )
    {
      result = __ratelimit(&qpnpint_spmi_write__rs, "qpnpint_spmi_write");
      if ( (_DWORD)result )
      {
        dev_err(*(_QWORD *)(v8 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a2 + 4));
        result = 0;
      }
    }
  }
  else
  {
    dev_err(
      v2[5],
      "failed to xlate sid = %#x, periph = %#x, irq = %u: ee=%u but owner=%u\n",
      (v3 >> 28) & 0x1F,
      (unsigned __int8)((unsigned int)v3 >> 20),
      WORD1(v3) & 7,
      v4,
      v5);
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
