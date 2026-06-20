void sub_1EDF8()
{
  __int64 v0; // x28
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &fastrpc_multidomain_ctx_obj_init__alloc_tag_439;
  _kmalloc_noprof(v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1E590);
}
