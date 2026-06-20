void sub_A8210()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = kthread_create_on_node;
  *(_QWORD *)(StatusReg + 80) = &edp_pll_clock_register_4nm__alloc_tag;
  v4 = _kmalloc_cache_noprof(v3, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 384) = v4;
  if ( !v4 )
    JUMPOUT(0xA8154);
  JUMPOUT(0xA7FFC);
}
