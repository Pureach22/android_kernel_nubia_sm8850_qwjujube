__int64 __fastcall wcd939x_handle_swrslv_reset(__int64 a1)
{
  __int64 result; // x0
  int v3; // [xsp+Ch] [xbp-14h] BYREF
  int v4; // [xsp+10h] [xbp-10h] BYREF
  int v5; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v3 = 0;
  v4 = 0;
  if ( a1 )
  {
    regmap_read(*(_QWORD *)(a1 + 32), 13422, &v5);
    regmap_read(*(_QWORD *)(a1 + 32), 13423, &v4);
    regmap_read(*(_QWORD *)(a1 + 32), 13424, &v3);
    regmap_write(*(_QWORD *)(a1 + 32), 13425, 0);
    regmap_write(*(_QWORD *)(a1 + 32), 13426, 0);
    regmap_write(*(_QWORD *)(a1 + 32), 13427, 0);
    result = 0;
  }
  else
  {
    printk(&unk_19200, "wcd939x_handle_swrslv_reset");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
