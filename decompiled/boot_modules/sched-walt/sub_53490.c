void __fastcall sub_53490(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x2

  if ( a2 )
    v11 = a2 + 24;
  else
    v11 = 0;
  a11 = 0;
  bitmap_print_to_pagebuf(0, &a11, v11, nr_cpu_ids);
  JUMPOUT(0x53464);
}
