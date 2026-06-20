void sub_690C()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ghd_rm_mem_share;
  *(_QWORD *)(StatusReg + 80) = &tlmm_vm_get_vmid__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 8);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x68C4);
  JUMPOUT(0x6898);
}
