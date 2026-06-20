__int64 __fastcall dsi_conn_dcs_cmd_tx(__int64 a1)
{
  if ( *(_QWORD *)a1 && *(_QWORD *)(*(_QWORD *)a1 + 2760LL) )
    return dsi_display_dcs_cmd_tx();
  else
    return 4294967274LL;
}
