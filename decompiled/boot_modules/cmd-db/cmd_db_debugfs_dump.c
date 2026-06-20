__int64 __fastcall cmd_db_debugfs_dump(__int64 a1)
{
  __int64 i; // x25
  __int64 v3; // x28
  int v4; // w8
  unsigned __int16 *v5; // x28
  int v6; // t1
  bool v7; // zf
  const char *v8; // x2
  unsigned int v9; // w26
  __int64 v10; // x24
  size_t v11; // x0

  seq_write(a1, "Command DB DUMP\n", 16);
  for ( i = 0; i != 8; ++i )
  {
    v3 = cmd_db_header + 16 * i;
    v6 = *(unsigned __int16 *)(v3 + 8);
    v5 = (unsigned __int16 *)(v3 + 8);
    v4 = v6;
    v7 = v6 == 3;
    if ( v6 <= 3 )
    {
      v8 = (const char *)&unk_6A30;
      if ( v7 )
        goto LABEL_11;
      if ( !v4 )
        return 0;
      goto LABEL_9;
    }
    if ( v4 != 5 )
    {
      if ( v4 == 4 )
      {
        v8 = "VRM";
        goto LABEL_11;
      }
LABEL_9:
      v8 = "Unknown";
      goto LABEL_11;
    }
    v8 = "BCM";
LABEL_11:
    seq_printf(a1, "Slave %s (v%u.%u)\n", v8, HIBYTE(v5[4]), (unsigned __int8)v5[4]);
    seq_write(a1, "-------------------------\n", 26);
    if ( v5[3] )
    {
      v9 = 0;
      v10 = cmd_db_header + v5[1] + 144;
      do
      {
        v11 = strnlen((const char *)v10, 8u);
        if ( v11 >= 9 )
        {
          _fortify_panic(2, 8, v11 + 1);
          JUMPOUT(0x665C);
        }
        seq_printf(a1, "0x%05x: %*pEp", *(_DWORD *)(v10 + 16), v11, (const void *)v10);
        if ( *(_WORD *)(v10 + 20) )
          seq_printf(
            a1,
            " [%*ph]",
            *(unsigned __int16 *)(v10 + 20),
            (const void *)(cmd_db_header + v5[2] + (unsigned __int64)*(unsigned __int16 *)(v10 + 22) + 144));
        seq_putc(a1, 10);
        ++v9;
        v10 += 24;
      }
      while ( v9 < v5[3] );
    }
  }
  return 0;
}
