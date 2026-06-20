__int64 sub_20F5C0()
{
  __asm { PRFM            #0xA, [X17,#0x3CD8] }
  return ucfg_reg_cache_channel_freq_state();
}
