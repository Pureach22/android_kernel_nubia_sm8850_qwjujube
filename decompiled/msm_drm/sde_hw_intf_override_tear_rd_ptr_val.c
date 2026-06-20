__int64 __fastcall sde_hw_intf_override_tear_rd_ptr_val(__int64 result, int a2)
{
  if ( result )
  {
    if ( a2 )
    {
      result = sde_reg_write(result, 656, (unsigned __int16)a2, "INTF_TEAR_SYNC_WRCOUNT");
      __dsb(0xEu);
    }
  }
  return result;
}
