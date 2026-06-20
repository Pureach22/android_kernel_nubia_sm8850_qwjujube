__int64 __fastcall sde_cesta_hw_force_db_update(
        __int64 a1,
        unsigned int a2,
        char a3,
        int a4,
        char a5,
        char a6,
        char a7)
{
  __int64 v7; // x27
  int v14; // w26
  int v15; // w0
  int v16; // w8
  int v17; // w21
  unsigned int v18; // w24
  int v19; // w0
  int v20; // w8
  int v21; // w8
  unsigned int v22; // w2
  __int64 result; // x0

  if ( a2 < 0xA )
  {
    v7 = a1 + 16LL * a2;
    v14 = dss_reg_r(v7 + 544, 0);
    v15 = dss_reg_r(v7 + 544, 4u);
    if ( (a3 & 1) != 0 )
      v16 = 8;
    else
      v16 = 0;
    v17 = v15;
    v18 = v16 & 0xFFFFFFFE | a5 & 1 | v14 & 0xFFFFFFF6;
    if ( (a7 & 1) == 0 )
      goto LABEL_13;
    v18 |= 0x100u;
    v19 = dss_reg_r(a1 + 768, 0);
    v20 = *(_DWORD *)(a1 + 1176);
    if ( (a6 & 1) != 0 )
      v21 = v20 - 1;
    else
      v21 = v20 + 1;
    *(_DWORD *)(a1 + 1176) = v21;
    if ( v21 )
    {
      if ( v21 != 1 )
        goto LABEL_13;
      v22 = v19 & 0xFFFFFFEF;
      if ( v19 == (v19 & 0xFFFFFFEF) )
        goto LABEL_13;
    }
    else
    {
      v22 = v19 | 0x10;
      if ( v19 == (v19 | 0x10) )
        goto LABEL_13;
    }
    dss_reg_w(a1 + 768, 0, v22, *(_DWORD *)(a1 + 1160));
    __dsb(0xEu);
LABEL_13:
    dss_reg_w(v7 + 544, 0, v18 & 0xFFFFFFF9 | (2 * a4), *(_DWORD *)(a1 + 1160));
    result = dss_reg_w(v7 + 544, 4u, v17 | 1u, *(_DWORD *)(a1 + 1160));
    __dsb(0xEu);
    return result;
  }
  __break(0x5512u);
  return sde_cesta_hw_reset();
}
