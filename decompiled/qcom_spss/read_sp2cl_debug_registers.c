__int64 __fastcall read_sp2cl_debug_registers(_QWORD *a1)
{
  __int64 v2; // x2
  unsigned int *v3; // x0
  __int64 v4; // x20
  unsigned int *v5; // x21
  int v6; // w22
  int v7; // w0
  __int64 v8; // x2
  unsigned int *v9; // x0
  __int64 v10; // x20
  unsigned int *v11; // x21
  int v12; // w22
  int v13; // w0
  __int64 v14; // x2
  unsigned int *v15; // x0
  __int64 v16; // x19
  unsigned int *v18; // x20
  int v19; // w21
  int v20; // w0

  if ( arm64_use_ng_mappings )
    v2 = 0x68000000000F13LL;
  else
    v2 = 0x68000000000713LL;
  v3 = (unsigned int *)ioremap_prot(25714720, 8, v2);
  v4 = *a1;
  if ( v3 )
  {
    v5 = v3;
    v6 = readl_relaxed(v3);
    v7 = readl_relaxed(v5 + 1);
    dev_info(v4, "Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n", 0, v6, v7);
    iounmap(v5);
  }
  else
  {
    dev_err(*a1, "Iteration: [0x%x] is NULL\n", 0);
  }
  if ( arm64_use_ng_mappings )
    v8 = 0x68000000000F13LL;
  else
    v8 = 0x68000000000713LL;
  v9 = (unsigned int *)ioremap_prot(25722912, 8, v8);
  v10 = *a1;
  if ( v9 )
  {
    v11 = v9;
    v12 = readl_relaxed(v9);
    v13 = readl_relaxed(v11 + 1);
    dev_info(v10, "Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n", 1, v12, v13);
    iounmap(v11);
  }
  else
  {
    dev_err(*a1, "Iteration: [0x%x] is NULL\n", 1);
  }
  if ( arm64_use_ng_mappings )
    v14 = 0x68000000000F13LL;
  else
    v14 = 0x68000000000713LL;
  v15 = (unsigned int *)ioremap_prot(25739296, 8, v14);
  v16 = *a1;
  if ( !v15 )
    return dev_err(v16, "Iteration: [0x%x] is NULL\n", 2);
  v18 = v15;
  v19 = readl_relaxed(v15);
  v20 = readl_relaxed(v18 + 1);
  dev_info(v16, "Iteration: [0x%x], Debug Data1: [0x%x], Debug Data2: [0x%x]\n", 2, v19, v20);
  return iounmap(v18);
}
