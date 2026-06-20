__int64 __fastcall sde_hw_set_axi_halt(__int64 a1)
{
  __int64 result; // x0

  sde_reg_write(a1, 4u, 1u, "VBIF_CLKON");
  result = sde_reg_write(a1, 0x208u, 1u, "VBIF_AXI_HALT_CTRL0");
  __dsb(0xEu);
  return result;
}
