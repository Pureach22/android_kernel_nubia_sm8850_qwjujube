void __fastcall sub_7070(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_noprof(a1, 2080);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x7060);
}
