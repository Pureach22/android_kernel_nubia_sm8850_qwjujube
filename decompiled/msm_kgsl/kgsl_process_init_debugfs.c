unsigned __int64 __fastcall kgsl_process_init_debugfs(__int64 a1)
{
  __int64 v2; // x8
  int v3; // w3
  unsigned __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x3
  __int64 v7; // x8
  __int64 v8; // x3
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
    v3 = *(_DWORD *)(v2 + 112);
  else
    v3 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  snprintf(s, 0x10u, "%d", v3);
  result = debugfs_create_dir(s, proc_d_debugfs);
  *(_QWORD *)(a1 + 200) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( v5 )
      v6 = *(int *)(v5 + 112);
    else
      v6 = 0;
    if ( (unsigned __int64)debugfs_create_file("mem", 292, result, v6, &process_mem_fops) >= 0xFFFFFFFFFFFFF001LL
      && (kgsl_process_init_debugfs___already_done_11 & 1) == 0 )
    {
      kgsl_process_init_debugfs___already_done_11 = 1;
      _warn_printk(s);
      __break(0x800u);
    }
    v7 = *(_QWORD *)(a1 + 8);
    if ( v7 )
      v8 = *(int *)(v7 + 112);
    else
      v8 = 0;
    result = debugfs_create_file("vbos", 292, *(_QWORD *)(a1 + 200), v8, &vbo_fops);
  }
  else
  {
    if ( (kgsl_process_init_debugfs___already_done & 1) == 0 )
    {
      kgsl_process_init_debugfs___already_done = 1;
      result = _warn_printk(s);
      __break(0x800u);
    }
    *(_QWORD *)(a1 + 200) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
