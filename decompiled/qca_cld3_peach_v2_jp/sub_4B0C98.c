__int64 __fastcall sub_4B0C98(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __asm { STGP            X4, X10, [X25,#-0xA8]! }
  return dp_h2t_3tuple_config_send(a1, a2, a3, a4, _X4);
}
