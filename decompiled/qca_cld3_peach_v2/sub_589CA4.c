__int64 sub_589CA4()
{
  __asm { PRFM            #0x11, loc_62D610 }
  return hal_tx_update_tidmap_prty_generic_be();
}
