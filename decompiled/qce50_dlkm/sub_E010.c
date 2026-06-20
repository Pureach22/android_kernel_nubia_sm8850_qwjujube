void sub_E010()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 (__fastcall *v3)(_QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = kfree;
  *(_QWORD *)(StatusReg + 80) = &qce_open__alloc_tag_36;
  v4 = _kmalloc_cache_noprof(v3, 3520, 64);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 720) = v4;
  if ( !v4 )
    JUMPOUT(0xDD64);
  JUMPOUT(0xDA88);
}
