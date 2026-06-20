__int64 __fastcall sub_649324(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int _W7)
{
  __asm { STLLR           W7, [X27] }
  return osif_twt_responder_disable();
}
