__int64 __fastcall sub_24D43C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { STGP            X7, X13, [X18],#0x5C }
  return hfi_read_message(a1, a2, a3, a4, a5);
}
