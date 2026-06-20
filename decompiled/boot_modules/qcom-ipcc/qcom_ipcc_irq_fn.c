__int64 __fastcall qcom_ipcc_irq_fn(__int64 a1, __int64 a2)
{
  __int64 i; // x8
  unsigned int v4; // w0
  __int64 v5; // x8
  unsigned int v6; // w20
  unsigned int v7; // w21
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  for ( i = *(_QWORD *)(a2 + 8); ; i = *(_QWORD *)(a2 + 8) )
  {
    v4 = readl((unsigned int *)(i + 16));
    if ( v4 == -1 )
      break;
    v5 = *(_QWORD *)(a2 + 16);
    v6 = v4;
    v9 = 0;
    if ( _irq_resolve_mapping(v5, v4, &v9) )
      v7 = v9;
    else
      v7 = 0;
    writel(v6, (unsigned int *)(*(_QWORD *)(a2 + 8) + 28LL));
    generic_handle_irq(v7);
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
