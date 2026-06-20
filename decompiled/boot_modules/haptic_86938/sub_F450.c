void __fastcall sub_F450(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        _QWORD *a9)
{
  unsigned __int64 StatusReg; // x27
  __int64 v10; // x28

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rtp_work_routine__alloc_tag;
  vmalloc_noprof(*a9 + 4LL);
  *(_QWORD *)(StatusReg + 80) = v10;
  JUMPOUT(0xEF0C);
}
