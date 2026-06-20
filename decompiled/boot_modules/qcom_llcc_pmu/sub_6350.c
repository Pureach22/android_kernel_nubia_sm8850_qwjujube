void __fastcall sub_6350(
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
  unsigned __int64 StatusReg; // x20
  __int64 v10; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  if ( (a9 & 0x8000000000000000LL) == 0 )
    _kmalloc_noprof(4LL * HIDWORD(a9), 3520);
  *(_QWORD *)(StatusReg + 80) = v10;
  JUMPOUT(0x61C4);
}
