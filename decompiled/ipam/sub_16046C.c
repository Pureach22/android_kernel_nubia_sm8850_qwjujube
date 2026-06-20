void sub_16046C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = of_property_read_variable_u32_array;
  *(_QWORD *)(StatusReg + 80) = &ipa_gsb_delete_partial_hdr__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 20);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1603F4);
  JUMPOUT(0x16032C);
}
