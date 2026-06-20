__int64 init_module()
{
  __int64 compatible_node; // x0
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x19
  void *v4; // x0
  void *v5; // x20
  void *v6; // x0
  _QWORD s[11]; // [xsp+8h] [xbp-58h] BYREF

  s[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  compatible_node = of_find_compatible_node(0, 0, "google,debug-kinfo");
  if ( !compatible_node )
  {
    v6 = &unk_67AD;
LABEL_11:
    printk(v6);
    goto LABEL_12;
  }
  v1 = compatible_node;
  memset(s, 0, 0x50u);
  if ( (unsigned int)_of_parse_phandle_with_args(v1, "memory-region", 0, 0, 0, s) || !s[0] )
  {
    v6 = &unk_6840;
    goto LABEL_11;
  }
  v2 = of_reserved_mem_lookup();
  if ( !v2 )
  {
    v6 = &unk_67EB;
    goto LABEL_11;
  }
  v3 = v2;
  v4 = (void *)memremap(*(_QWORD *)(v2 + 24), *(_QWORD *)(v2 + 32), 1);
  debug_symbol_vaddr = (__int64)v4;
  if ( !v4 )
  {
    v6 = &unk_6877;
    goto LABEL_11;
  }
  v5 = v4;
  memset(v4, 0, 0x1D8u);
  *(_QWORD *)(v3 + 40) = v5;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return 0;
}
