__int64 __fastcall rmnet_shs_genl_dma_init(__int64 a1, __int64 a2)
{
  rmnet_shs_ll_deinit();
  if ( a2 )
    return 0;
  else
    return 0xFFFFFFFFLL;
}
