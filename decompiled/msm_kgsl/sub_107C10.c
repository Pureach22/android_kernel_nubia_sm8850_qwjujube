__int64 __fastcall sub_107C10(__int64 a1)
{
  __asm { PRFM            #5, [X25,#0xF0] }
  return gmu_core_reset_trace_header(a1);
}
