__int64 __fastcall sub_436EDC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { LDTRSH          X27, [SP,#var_BD] }
  return dot11f_unpack_channel_usage_req(a1, a2, a3, a4, a5);
}
