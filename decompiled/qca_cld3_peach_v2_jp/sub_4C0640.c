__int64 sub_4C0640()
{
  __asm { STGP            XZR, X0, [X12],#-0xD8 }
  return dp_soc_map_pdev_to_lmac();
}
