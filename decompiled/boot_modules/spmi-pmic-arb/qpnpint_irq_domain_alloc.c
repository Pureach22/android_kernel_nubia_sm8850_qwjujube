__int64 __fastcall qpnpint_irq_domain_alloc(__int64 a1, int a2, int a3)
{
  __int64 v6; // x22
  __int64 result; // x0
  int v8; // w24

  _ReadStatusReg(SP_EL0);
  v6 = *(_QWORD *)(a1 + 32);
  result = qpnpint_irq_domain_translate();
  if ( !(_DWORD)result )
  {
    if ( a3 )
    {
      v8 = 0;
      do
      {
        irq_domain_set_info(a1, (unsigned int)(a2 + v8), v8, &pmic_arb_irqchip, v6, &handle_level_irq, 0, 0);
        ++v8;
      }
      while ( a3 != v8 );
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
