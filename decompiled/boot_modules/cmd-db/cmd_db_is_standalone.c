__int64 cmd_db_is_standalone()
{
  bool v0; // w9

  if ( cmd_db_header )
    v0 = *(_DWORD *)(cmd_db_header + 4) == 201535707;
  else
    v0 = 0;
  return v0 & *(_BYTE *)(cmd_db_header + 140);
}
