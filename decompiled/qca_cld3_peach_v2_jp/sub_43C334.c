__int64 __fastcall sub_43C334(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { STTR            H14, [X14,#0x83] }
  return sme_create_mon_session(a1, a2, a3);
}
