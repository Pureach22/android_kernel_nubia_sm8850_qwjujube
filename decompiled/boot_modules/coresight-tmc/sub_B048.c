void __fastcall sub_B048(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x23
  __int64 v4; // x24
  __int64 v5; // x0
  __int64 v6; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(StatusReg + 80);
  v5 = arm64_use_ng_mappings;
  *(_QWORD *)(StatusReg + 80) = &tmc_alloc_etf_buffer__alloc_tag;
  v6 = _kmalloc_cache_node_noprof(v5, 3520, a3, 48);
  *(_QWORD *)(StatusReg + 80) = v4;
  if ( !v6 )
    JUMPOUT(0xB030);
  JUMPOUT(0xB018);
}
