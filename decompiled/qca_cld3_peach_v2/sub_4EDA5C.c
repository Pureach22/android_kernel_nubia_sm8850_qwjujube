__int64 __fastcall sub_4EDA5C(__int64 a1)
{
  __asm { LDSMINALH       W20, W23, [X11] }
  return wma_post_chan_switch_setup(a1);
}
