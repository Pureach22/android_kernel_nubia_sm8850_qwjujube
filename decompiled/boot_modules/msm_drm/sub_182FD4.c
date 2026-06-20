__int64 sub_182FD4()
{
  __asm { UDOT            V12.8H, V28.16B, V22.16B }
  return sde_hw_ctl_update_pending_flush();
}
