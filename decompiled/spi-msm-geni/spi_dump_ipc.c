void __fastcall spi_dump_ipc(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  int v8; // w8
  unsigned int v9; // w9
  __int64 v10; // x5
  __int64 v11; // x23
  unsigned int v12; // w24

  if ( a3 )
  {
    raw_spin_lock(a1 + 160);
    v8 = *(_DWORD *)(a1 + 524);
    if ( v8 >= (int)a4 )
      v9 = a4;
    else
      v9 = *(_DWORD *)(a1 + 524);
    if ( v8 <= 0 )
      v10 = a4;
    else
      v10 = v9;
    if ( (int)v10 < 17 )
    {
      LODWORD(v11) = 0;
    }
    else
    {
      v11 = 0;
      do
      {
        v12 = v10;
        _spi_dump_ipc(a1, a2, a3 + v11, a4, (unsigned int)v11, 16);
        v11 += 16;
        v10 = v12 - 16;
      }
      while ( v12 > 0x20 );
    }
    _spi_dump_ipc(a1, a2, a3 + (int)v11, a4, (unsigned int)v11, v10);
    raw_spin_unlock(a1 + 160);
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 480), "%s : Err str is NULL\n", "spi_dump_ipc");
    if ( *(_QWORD *)(a1 + 200) )
      spi_trace_log();
  }
}
