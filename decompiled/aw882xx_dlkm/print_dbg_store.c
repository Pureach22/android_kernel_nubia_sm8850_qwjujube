__int64 __fastcall print_dbg_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  int v6; // w0
  __int64 *v8; // x8
  __int64 v9; // x1

  v4 = *(_QWORD *)(a1 + 152);
  v6 = kstrtouint(a3, 0, &g_print_dbg);
  if ( v6 < 0 )
    return v6;
  v8 = *(__int64 **)(v4 + 64);
  v9 = v8[14];
  g_print_dbg = g_print_dbg != 0;
  if ( !v9 )
    v9 = *v8;
  printk(&unk_26BB7, v9, "print_dbg_store");
  return a4;
}
