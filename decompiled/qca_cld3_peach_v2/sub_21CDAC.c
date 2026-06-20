__int64 sub_21CDAC()
{
  __asm { PRFM            #0xA, [X17,#0x3CD8] }
  return ucfg_scan_filter_valid_channel();
}
