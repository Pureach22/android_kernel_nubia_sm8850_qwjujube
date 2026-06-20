__int64 __fastcall sub_AFC8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { STZG            X14, [X4],#-0x140 }
  return trace_event_raw_event_memlat_dev_update(a1, a2, a3, a4, a5);
}
