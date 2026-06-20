__int64 __fastcall cds_get_radio_index(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v6; // x2
  __int64 v7; // x3

  v4 = gp_cds_context;
  if ( gp_cds_context )
    return *(unsigned int *)(v4 + 80);
  printk(&unk_94D98D, "cds_get_global_context", a3, a4);
  v4 = gp_cds_context;
  if ( gp_cds_context )
    return *(unsigned int *)(v4 + 80);
  printk(&unk_9C9096, "cds_get_radio_index", v6, v7);
  return 4294967274LL;
}
