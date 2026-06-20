__int64 __fastcall sub_64BA7C(__int64 a1, __int64 a2)
{
  __asm { STGP            X24, X9, [X24],#-0xC4 }
  return tgt_twt_enable_req_send(a1, a2);
}
