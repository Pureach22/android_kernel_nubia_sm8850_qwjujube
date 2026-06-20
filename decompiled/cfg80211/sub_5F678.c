void __fastcall sub_5F678(
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
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        __int64 a16,
        __int64 a17,
        __int64 a18,
        __int64 a19,
        __int64 a20,
        __int64 a21,
        __int64 a22,
        __int64 a23,
        __int64 a24,
        __int64 a25,
        __int64 a26)
{
  unsigned __int64 StatusReg; // x22
  __int64 v27; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v27 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &nl80211_nan_add_func__alloc_tag_169;
  kmemdup_noprof(a26 + 4, *(unsigned __int8 *)(a1 + 40), 3264);
  *(_QWORD *)(StatusReg + 80) = v27;
  JUMPOUT(0x5F228);
}
