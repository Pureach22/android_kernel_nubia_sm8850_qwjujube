__int64 cmd_db_ready()
{
  if ( !cmd_db_header )
    return 4294966779LL;
  if ( *(_DWORD *)(cmd_db_header + 4) == 201535707 )
    return 0;
  return 4294967274LL;
}
