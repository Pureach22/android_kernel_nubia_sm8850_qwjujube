__int64 sub_1FE4C8()
{
  __asm { PRFM            #0xA, [X17,#0x3CD8] }
  return ucfg_scan_filter_valid_channel();
}
