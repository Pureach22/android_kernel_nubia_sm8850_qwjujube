__int64 __fastcall sub_702544(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29

  if ( (v3 & 0x20000000000LL) == 0 )
    JUMPOUT(0x704DE4);
  return ucfg_twt_responder_disable(a1, a2, a3);
}
