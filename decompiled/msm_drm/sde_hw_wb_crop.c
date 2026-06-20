__int64 __fastcall sde_hw_wb_crop(__int64 a1, __int64 a2, char a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  const char *v5; // x3
  unsigned int v6; // w1
  unsigned int v7; // w2

  if ( (a3 & 1) != 0 )
  {
    v3 = *(_DWORD *)(a2 + 84);
    v4 = a1;
    sde_reg_write(a1, 0x154u, 1u, "WB_CROP_CTRL");
    v5 = "WB_CROP_OFFSET";
    a1 = v4;
    v6 = 344;
    v7 = v3;
  }
  else
  {
    v5 = "WB_CROP_CTRL";
    v6 = 340;
    v7 = 0;
  }
  return sde_reg_write(a1, v6, v7, v5);
}
