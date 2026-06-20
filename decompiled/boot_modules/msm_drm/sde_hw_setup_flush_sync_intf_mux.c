__int64 __fastcall sde_hw_setup_flush_sync_intf_mux(__int64 result, unsigned int a2)
{
  if ( result )
    return sde_reg_write(result, 0x42Cu, a2, "MDP_FLUSH_SYNC_INTF_MUX");
  return result;
}
