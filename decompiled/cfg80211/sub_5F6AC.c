void __fastcall sub_5F6AC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12)
{
  unsigned __int64 StatusReg; // x22
  __int64 v13; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &nl80211_nan_add_func__alloc_tag_173;
  kmemdup_noprof(a12 + 4, *(unsigned __int8 *)(a1 + 56), 3264);
  *(_QWORD *)(StatusReg + 80) = v13;
  JUMPOUT(0x5F404);
}
