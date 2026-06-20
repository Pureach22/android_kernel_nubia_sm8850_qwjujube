__int64 sub_10F790()
{
  __asm { PRFM            #0x19, [X14,#0x5C8] }
  return cam_soc_util_put_optional_clk();
}
