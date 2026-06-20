__int64 sub_185E00()
{
  __asm { PRFM            #0x18, loc_2821E4 }
  return osif_vdev_mgr_set_legacy_cb();
}
