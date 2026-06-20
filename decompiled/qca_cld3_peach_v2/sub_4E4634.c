__int64 __fastcall sub_4E4634(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STZG            X20, [X30],#-0x2E0 }
  return wma_beacon_miss_handler(a1, a2, a3);
}
