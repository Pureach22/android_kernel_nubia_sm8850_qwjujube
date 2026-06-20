__int64 __fastcall sde_hw_wb_roi(__int64 a1, _DWORD *a2)
{
  unsigned int v2; // w19
  unsigned int v3; // w20

  v2 = a2[19];
  v3 = a2[20];
  sde_reg_write(a1, 0x2C0u, a2[3] | (a2[4] << 16), "WB_OUT_IMAGE_SIZE");
  sde_reg_write(a1, 0x2C4u, v2, "WB_OUT_XY");
  return sde_reg_write(a1, 0x74u, v3, "WB_OUT_SIZE");
}
