__int64 __fastcall kgsl_bus_get_table(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v6; // w0
  __int64 v7; // x24
  __int64 v8; // x0
  __int64 v9; // x22
  __int64 v10; // x25
  __int64 v11; // x23

  v6 = of_property_count_elems_of_size(*(_QWORD *)(a1 + 760), a2, 4);
  if ( v6 < 1 )
    return -22;
  v7 = (unsigned int)v6;
  v8 = _kmalloc_noprof(4LL * (unsigned int)v6, 3520);
  if ( !v8 )
    return -12;
  v9 = 0;
  v10 = v8;
  v11 = v8;
  do
  {
    of_property_read_u32_index(*(_QWORD *)(a1 + 760), a2, (unsigned int)v9++, v11);
    v11 += 4;
  }
  while ( v7 != v9 );
  *a3 = v7;
  return v10;
}
