void __fastcall sub_D1C4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10)
{
  unsigned __int64 StatusReg; // x19
  __int64 v11; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gh_rm_vm_get_status__alloc_tag;
  kmemdup_noprof(a10, a9, 3264);
  *(_QWORD *)(StatusReg + 80) = v11;
  JUMPOUT(0xD130);
}
