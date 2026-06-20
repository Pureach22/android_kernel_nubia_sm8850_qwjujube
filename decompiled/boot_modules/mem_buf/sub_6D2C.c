void __fastcall sub_6D2C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x22
  __int64 (__fastcall *v6)(_QWORD); // x0
  __int64 v7; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  v6 = kvfree;
  *(_QWORD *)(StatusReg + 80) = &mem_buf_cleanup_alloc_req__alloc_tag;
  v7 = _kmalloc_cache_noprof(v6, 3520, 8, a4);
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v7 )
    JUMPOUT(0x6CFC);
  JUMPOUT(0x6C50);
}
