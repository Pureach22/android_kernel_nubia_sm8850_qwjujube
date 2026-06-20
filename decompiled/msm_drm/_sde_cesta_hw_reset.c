__int64 __fastcall sde_cesta_hw_reset(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v3; // w2
  __int64 result; // x0

  if ( a2 >= 0xA )
  {
    __break(0x5512u);
    JUMPOUT(0x1B8454);
  }
  if ( (a3 & 1) != 0 )
    v3 = 0x80000000;
  else
    v3 = 0;
  result = dss_reg_w(a1 + 16LL * a2 + 544, 4u, v3, *(_DWORD *)(a1 + 1160));
  __dsb(0xEu);
  return result;
}
