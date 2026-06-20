__int64 __fastcall cam_mem_trace_alloc(__int64 a1, unsigned int a2, char a3, const char *a4, unsigned int a5)
{
  unsigned __int64 v5; // x21
  __int64 v8; // x24
  unsigned __int64 v9; // x19
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x0
  unsigned __int64 *v13; // x1

  v5 = a5;
  v8 = a2;
  v9 = a1 + 156;
  if ( (a3 & 1) != 0 )
    v10 = _kmalloc_noprof(a1 + 156, a2 | 0x100);
  else
    v10 = _kvmalloc_node_noprof(a1 + 156, 0, a2 | 0x100, 0xFFFFFFFFLL);
  v11 = v10;
  if ( !v10 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_mem_trace_alloc",
      296,
      "Failed to alloc mem with size: %lu bytes",
      a1);
    return 0;
  }
  if ( v9 < 4 )
    goto LABEL_21;
  *(_DWORD *)v10 = 1545761;
  if ( (unsigned __int64)(a1 + 156) < 0x20 )
    goto LABEL_21;
  *(_QWORD *)(v10 + 24) = a1;
  if ( v9 < 0x20 )
    goto LABEL_21;
  if ( (a1 & 0xFFFFFFFFFFFFFFFCLL) == 0xFFFFFFFFFFFFFF84LL )
    goto LABEL_21;
  *(_DWORD *)(v10 + 32) = v8;
  if ( (unsigned __int64)(a1 + 156) < 0x90 )
    goto LABEL_21;
  v8 = v10 + 152;
  *(_QWORD *)(v10 + 136) = v10 + 152;
  v12 = ktime_get_with_offset(1);
  if ( (unsigned __int64)(a1 + 156) < 0x98 )
    goto LABEL_21;
  *(_QWORD *)(v11 + 144) = v12;
  if ( a4 )
    snprintf((char *)(v11 + 36), 0x64u, "%s[%d]", a4, v5);
  if ( a1 + 152 < 0 || v9 < a1 + 152 )
    goto LABEL_21;
  v5 = v11 + 8;
  *(_DWORD *)(v8 + a1) = 1545761;
  *(_QWORD *)(v11 + 8) = v11 + 8;
  *(_QWORD *)(v11 + 16) = v11 + 8;
  raw_spin_lock_irqsave(&dword_2FDB40);
  v13 = (unsigned __int64 *)qword_2FDB28;
  if ( qword_2FDB28 == v11 + 8 || *(__int64 **)qword_2FDB28 != &g_trace )
    goto LABEL_22;
  qword_2FDB28 = v11 + 8;
  if ( (unsigned __int64)(a1 + 156) < 0x10 || (*(_QWORD *)v5 = &g_trace, (unsigned __int64)(a1 + 156) < 0x18) )
  {
LABEL_21:
    __break(1u);
LABEL_22:
    _list_add_valid_or_report(v5);
    goto LABEL_20;
  }
  *(_QWORD *)(v11 + 16) = v13;
  *v13 = v5;
LABEL_20:
  qword_2FDB48 += v9;
  raw_spin_unlock_irqrestore();
  return v8;
}
