void __fastcall sub_185628(__int64 a1, __int64 a2, char a3)
{
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x23
  __int64 v6; // x1
  __int64 v7; // x0

  v3 = of_property_read_variable_u32_array;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  if ( (a3 & 1) != 0 )
    v6 = 2336;
  else
    v6 = 3520;
  *(_QWORD *)(StatusReg + 80) = &ipa_imm_cmd_construct_dma_shared_mem__alloc_tag;
  v7 = _kmalloc_cache_noprof(v3, v6, 20);
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v7 )
    JUMPOUT(0x185570);
  JUMPOUT(0x1854D4);
}
