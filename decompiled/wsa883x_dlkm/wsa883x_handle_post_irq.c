__int64 __fastcall wsa883x_handle_post_irq(_QWORD *a1)
{
  __int64 v2; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v4[0] = 0;
  regmap_read(v2, 13443, (char *)v4 + 4);
  regmap_read(*a1, 13444, v4);
  *(_BYTE *)(a1[2] + 1008LL) = v4[0] != 0;
  _ReadStatusReg(SP_EL0);
  return 1;
}
