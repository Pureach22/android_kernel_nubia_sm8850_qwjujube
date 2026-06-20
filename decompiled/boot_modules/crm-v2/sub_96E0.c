__int64 sub_96E0()
{
  __asm { STR             P16, [X16,#-0x68,MUL VL] }
  return crm_write_bw_pt_vote();
}
