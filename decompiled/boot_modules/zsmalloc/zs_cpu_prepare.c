__int64 __fastcall zs_cpu_prepare(unsigned int a1)
{
  __int64 v1; // x19
  char *v2; // x20
  __int64 v4; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x22

  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v6 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &_zs_cpu_up__alloc_tag;
    v4 = _kmalloc_cache_noprof(_cpuhp_remove_state, 3264, 4096);
    *(_QWORD *)(StatusReg + 80) = v6;
  }
  else
  {
    v2 = (char *)&zs_map_area;
    v1 = _per_cpu_offset[a1];
    if ( *(_QWORD *)((char *)&zs_map_area + v1) )
      return 0;
    v4 = _kmalloc_cache_noprof(_cpuhp_remove_state, 3264, 4096);
  }
  *(_QWORD *)&v2[v1] = v4;
  if ( v4 )
    return 0;
  else
    return 4294967284LL;
}
