__int64 __fastcall dbg_sensors_show(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w22

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL);
  seq_printf(a1, "max: %2d\nnum: %2d\n\n", *(_DWORD *)(*(_QWORD *)(v2 + 2544) + 8LL), *(_DWORD *)(v2 + 8));
  seq_write(a1, "      id    slope   offset\n--------------------------\n", 54);
  if ( *(_DWORD *)(v2 + 8) )
  {
    v3 = 0;
    do
    {
      seq_printf(
        a1,
        "%8d %8d %8d\n",
        *(_DWORD *)(v2 + 2600 + 88LL * (int)v3 + 68),
        *(_DWORD *)(v2 + 2600 + 88LL * (int)v3 + 72),
        *(_DWORD *)(v2 + 2600 + 88LL * (int)v3 + 64));
      ++v3;
    }
    while ( v3 < *(_DWORD *)(v2 + 8) );
  }
  return 0;
}
