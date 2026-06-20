__int64 sub_171758()
{
  __asm { PRFM            #0x18, loc_26DB3C }
  return osif_vdev_mgr_set_legacy_cb();
}
