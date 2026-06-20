bool __fastcall phy_mux_is_enabled(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x1
  char v3; // w9
  int v4; // w8
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(unsigned int *)(a1 - 8);
  v6 = 0;
  regmap_read(v1, v2, &v6);
  v3 = v6;
  v4 = v6 & 3;
  v6 = v4;
  if ( (v3 & 1) != 0 )
  {
    __break(0x800u);
    v4 = v6;
  }
  _ReadStatusReg(SP_EL0);
  return v4 == 0;
}
