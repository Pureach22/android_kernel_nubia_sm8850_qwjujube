__int64 __fastcall sub_5A66BC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 _X7)
{
  __asm { STGP            X30, X27, [X7],#0x5C }
  return ucfg_nan_send_pasn_peer_create_cmd(a1, a2, a3);
}
