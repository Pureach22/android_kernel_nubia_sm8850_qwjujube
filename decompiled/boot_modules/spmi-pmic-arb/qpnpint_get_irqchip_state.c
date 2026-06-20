__int64 __fastcall qpnpint_get_irqchip_state(__int64 a1, int a2, _BYTE *a3)
{
  unsigned __int64 v3; // x8
  __int64 v4; // x22
  __int64 v7; // x20
  __int64 result; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 8);
  v9[0] = 0;
  if ( a2 == 3 )
  {
    v4 = *(_QWORD *)(a1 + 48);
    v7 = (v3 >> 16) & 7;
    if ( (unsigned int)pmic_arb_read_cmd(
                         *(_QWORD *)(v4 + 40),
                         56,
                         (v3 >> 28) & 0x1F,
                         (v3 >> 12) & 0xFFFFFF00 | 0x10,
                         (__int64)v9,
                         1)
      && (unsigned int)__ratelimit(&qpnpint_spmi_read__rs, "qpnpint_spmi_read") )
    {
      dev_err(*(_QWORD *)(v4 + 40), "failed irqchip transaction on %x\n", *(_DWORD *)(a1 + 4));
    }
    result = 0;
    *a3 = ((unsigned __int64)v9[0] >> v7) & 1;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
