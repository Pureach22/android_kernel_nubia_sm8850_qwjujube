__int64 __fastcall sub_649218(
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
  return osif_twt_requestor_disable();
}
