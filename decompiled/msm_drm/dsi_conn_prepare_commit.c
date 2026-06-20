__int64 __fastcall dsi_conn_prepare_commit(__int64 a1, __int64 a2)
{
  if ( a1 && a2 )
    return dsi_display_pre_commit();
  printk(&unk_25C57C, a2);
  return 4294967274LL;
}
