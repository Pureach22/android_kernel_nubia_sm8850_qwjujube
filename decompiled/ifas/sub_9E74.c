void __usercall sub_9E74(__int64 a1@<X8>)
{
  int v1; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20

  v1 = *(_DWORD *)(a1 + 1460);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cpu_ctrl_init__alloc_tag;
  _kmalloc_noprof(344LL * v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x99F4);
}
