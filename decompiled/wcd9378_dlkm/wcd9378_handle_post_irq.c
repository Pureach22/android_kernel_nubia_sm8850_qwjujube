__int64 __fastcall wcd9378_handle_post_irq(__int64 a1)
{
  __int64 v2; // x0
  bool v3; // w8
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 48);
  v5 = 0;
  v6[0] = 0;
  regmap_write(v2, 88, 255);
  regmap_write(*(_QWORD *)(a1 + 48), 89, 255);
  regmap_write(*(_QWORD *)(a1 + 48), 90, 255);
  regmap_read(*(_QWORD *)(a1 + 48), 88, (char *)v6 + 4);
  regmap_read(*(_QWORD *)(a1 + 48), 89, v6);
  regmap_read(*(_QWORD *)(a1 + 48), 90, &v5);
  if ( v6[0] )
    v3 = 1;
  else
    v3 = v5 != 0;
  *(_BYTE *)(*(_QWORD *)(a1 + 64) + 1008LL) = v3;
  _ReadStatusReg(SP_EL0);
  return 1;
}
