__int64 __fastcall wcd_irq_exit(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x1
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v3 = *(_QWORD *)(a1 + 32);
    v6 = 0;
    if ( _irq_resolve_mapping(a2, 0, &v6) )
      v4 = v6;
    else
      v4 = 0;
    devm_regmap_del_irq_chip(v3, v4, *(_QWORD *)(a1 + 24));
    result = 0;
  }
  else
  {
    printk(&unk_A0DD, "wcd_irq_exit");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
