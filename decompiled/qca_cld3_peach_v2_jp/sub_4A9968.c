__int64 __fastcall sub_4A9968(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { STGP            X5, X20, [X23],#-0xAC }
  return dp_tx_update_bank_profile(a1, a2, a3, a4, a5, _X5);
}
