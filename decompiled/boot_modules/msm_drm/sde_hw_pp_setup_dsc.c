__int64 __fastcall sde_hw_pp_setup_dsc(__int64 a1)
{
  int v2; // w0

  if ( !a1 )
    return 4294967274LL;
  v2 = sde_reg_read(a1, 0xC8u);
  sde_reg_write(a1, 0xC8u, v2 | 0x40000, "PP_DCE_DATA_OUT_SWAP");
  return 0;
}
