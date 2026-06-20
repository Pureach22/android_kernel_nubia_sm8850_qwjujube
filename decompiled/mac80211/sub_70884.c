void __fastcall sub_70884(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        char a10)
{
  unsigned __int64 StatusReg; // x23
  __int64 v11; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ieee80211_check_fast_rx__alloc_tag;
  kmemdup_noprof(&a10, 48);
  *(_QWORD *)(StatusReg + 80) = v11;
  JUMPOUT(0x705F4);
}
