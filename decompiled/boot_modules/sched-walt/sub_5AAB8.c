__int64 __fastcall sub_5AAB8(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x1E, [X22,#0x2CD0] }
  return smart_freq_update_reason_common(a1, a2, a3);
}
