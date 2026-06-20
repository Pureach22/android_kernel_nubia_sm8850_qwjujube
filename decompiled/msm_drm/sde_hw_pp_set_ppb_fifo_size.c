__int64 __fastcall sde_hw_pp_set_ppb_fifo_size(__int64 result, unsigned int a2)
{
  if ( result )
    return sde_reg_write(result, 0x1Cu, (a2 >> 2) & 0xFFF, "PPB_FIFO_SIZE_CFG");
  return result;
}
