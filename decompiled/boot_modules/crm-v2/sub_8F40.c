__int64 sub_8F40()
{
  __asm { STR             P16, [X16,#-0x68,MUL VL] }
  return crm_write_perf_ol();
}
