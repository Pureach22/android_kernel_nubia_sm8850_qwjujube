__int64 __fastcall dp_rx_tm_set_cpu_mask(unsigned __int8 *a1)
{
  unsigned int v1; // w8
  unsigned __int64 v3; // x21

  v1 = *a1;
  if ( *a1 )
  {
    v3 = 0;
    do
    {
      if ( *(_QWORD *)(*((_QWORD *)a1 + 3) + 8 * v3) )
      {
        qdf_thread_set_cpus_allowed_mask();
        v1 = *a1;
      }
      ++v3;
    }
    while ( v3 < v1 );
  }
  return 0;
}
