__int64 __fastcall sde_hw_setup_clk_force_ctrl(__int64 a1, unsigned int a2, char a3)
{
  unsigned int v3; // w8
  __int64 v6; // x8
  unsigned int v7; // w20
  int v8; // w23
  int v9; // w22
  __int64 v10; // x23
  unsigned int v11; // w2

  v3 = 0;
  if ( a1 && a2 - 20 >= 0xFFFFFFED )
  {
    v6 = *(_QWORD *)(a1 + 40) + 8LL * a2;
    v7 = *(_DWORD *)(v6 + 76);
    v8 = *(_DWORD *)(v6 + 80);
    v9 = sde_reg_read(a1, v7);
    v10 = 1LL << v8;
    if ( (a3 & 1) != 0 )
      v11 = v9 | v10;
    else
      v11 = v9 & ~(_DWORD)v10;
    sde_reg_write(a1, v7, v11, "reg_off");
    __dsb(0xEu);
    return ((unsigned int)v10 & v9) == 0;
  }
  return v3;
}
