void __fastcall sub_E674(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  unsigned __int64 StatusReg; // x21
  __int64 v10; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &tpfwupgrade_store__alloc_tag_195;
  vmalloc_noprof(HIDWORD(a9) + 24LL);
  *(_QWORD *)(StatusReg + 80) = v10;
  JUMPOUT(0xE56C);
}
