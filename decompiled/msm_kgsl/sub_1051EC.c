__int64 __fastcall sub_1051EC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __asm { SUBG            X16, X17, #0x370, #0xC }
  return log_kgsl_cmdbatch_retired_event(a1, a2, a3, a4, a5, a6);
}
