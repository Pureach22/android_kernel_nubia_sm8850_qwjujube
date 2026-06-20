__int64 __fastcall sde_hw_set_mem_type_v1(__int64 result, unsigned int a2, char a3)
{
  unsigned int v3; // w20
  char v4; // w22
  __int64 v6; // x21
  int v7; // w0

  if ( result && a2 <= 0xF )
  {
    if ( a2 <= 7 )
      v3 = 352;
    else
      v3 = 356;
    v4 = 4 * (a2 & 7);
    v6 = result;
    v7 = sde_reg_read(result, v3);
    sde_reg_write(v6, v3, v7 & ~(7 << v4) | ((a3 & 7) << v4), "reg_off");
    sde_reg_read(v6, 0x170u);
    sde_reg_write(v6, 0x170u, 0, "VBIF_OUT_AXI_ASHARED");
    sde_reg_read(v6, 0x174u);
    return sde_reg_write(v6, 0x174u, 0, "VBIF_OUT_AXI_AINNERSHARED");
  }
  return result;
}
