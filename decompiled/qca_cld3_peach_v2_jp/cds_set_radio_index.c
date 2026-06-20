__int64 __fastcall cds_set_radio_index(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  unsigned int v5; // w8
  int v7; // w20
  __int64 v8; // x2
  __int64 v9; // x3

  v4 = gp_cds_context;
  if ( gp_cds_context
    || (v7 = a1, printk(&unk_94D98D, "cds_get_global_context", a3, a4), v4 = gp_cds_context, a1 = v7, gp_cds_context) )
  {
    v5 = 0;
    *(_DWORD *)(v4 + 80) = a1;
  }
  else
  {
    printk(&unk_9C9096, "cds_set_radio_index", v8, v9);
    return 16;
  }
  return v5;
}
