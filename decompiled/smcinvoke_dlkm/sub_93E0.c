void __fastcall sub_93E0(__int64 a1, __int64 a2, const char *a3, int a4, int a5)
{
  __int64 v5; // x25
  unsigned __int64 StatusReg; // x19
  __int64 v7; // x26
  __int64 v8; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v7 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v8 = _kmalloc_noprof(8 * v5, print_fmt_cbo_dispatch_wait, a3, a4, a5);
  *(_QWORD *)(StatusReg + 80) = v7;
  if ( !v8 )
    JUMPOUT(0x9368);
  JUMPOUT(0x90F0);
}
