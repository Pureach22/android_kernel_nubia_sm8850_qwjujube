__int64 __fastcall wcd939x_handle_post_irq(__int64 a1)
{
  __int64 v2; // x0
  bool v3; // w8
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 32);
  v5 = 0;
  v6[0] = 0;
  regmap_read(v2, 13422, (char *)v6 + 4);
  regmap_read(*(_QWORD *)(a1 + 32), 13423, v6);
  regmap_read(*(_QWORD *)(a1 + 32), 13424, &v5);
  if ( v6[0] )
    v3 = 1;
  else
    v3 = v5 != 0;
  *(_BYTE *)(*(_QWORD *)(a1 + 48) + 1008LL) = v3;
  _ReadStatusReg(SP_EL0);
  return 1;
}
