__int64 sub_107BC8()
{
  __asm { PRFM            #5, [X25,#0xF0] }
  return gmu_core_trace_header_init();
}
