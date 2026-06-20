__int64 sub_183320()
{
  __asm { UDOT            V12.8H, V28.16B, V22.16B }
  return sde_hw_ctl_get_pending_flush();
}
