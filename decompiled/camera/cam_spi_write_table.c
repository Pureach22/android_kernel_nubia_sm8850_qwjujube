__int64 __fastcall cam_spi_write_table(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int v5; // w23
  unsigned int *v6; // x25
  unsigned int v7; // w8
  unsigned int v8; // w19

  result = 4294967282LL;
  if ( a1
    && a2
    && (unsigned int)(*(_DWORD *)(a2 + 12) - 5) >= 0xFFFFFFFC
    && (unsigned int)(*(_DWORD *)(a2 + 16) - 5) >= 0xFFFFFFFC )
  {
    if ( *(_DWORD *)(a2 + 8) )
    {
      v5 = 0;
      v6 = (unsigned int *)(*(_QWORD *)a2 + 4LL);
      do
      {
        if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x4000000000LL,
            4,
            "cam_spi_write_table",
            578,
            "addr %x data %x",
            *(v6 - 1),
            *v6);
        result = cam_spi_write(a1, *(v6 - 1), *v6, *(_DWORD *)(a2 + 12), *(_DWORD *)(a2 + 16));
        if ( (result & 0x80000000) != 0 )
          break;
        ++v5;
        v6 += 4;
      }
      while ( v5 < *(_DWORD *)(a2 + 8) );
    }
    v7 = *(unsigned __int16 *)(a2 + 20);
    if ( v7 < 0x15 )
    {
      if ( !*(_WORD *)(a2 + 20) )
        return result;
      v8 = result;
      usleep_range_state(1000LL * v7, 1000 * v7 + 1000, 2);
    }
    else
    {
      v8 = result;
      msleep(v7);
    }
    return v8;
  }
  return result;
}
