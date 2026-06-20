__int64 __fastcall counter_info_file_show(__int64 a1)
{
  __int64 v2; // x8
  unsigned int v3; // w3
  unsigned __int16 v4; // w10
  __int64 v5; // x9
  unsigned __int16 v6; // w24

  seq_write(a1, "'ent' stands for Entry counter\n", 31);
  seq_write(a1, "'tnr' stands for Tenure counter\n", 32);
  seq_write(a1, "_0 for soc centric counters\n", 28);
  seq_write(a1, "_1 for cluster centric counters\n", 32);
  seq_write(a1, "_2 for core centriC counter\n", 28);
  seq_write(a1, "'a' in _1a, represents cluster_id\n", 34);
  seq_write(a1, "'b' in _2b represent core_id\n", 29);
  seq_write(a1, "e.g. name c2ent_2n implies c2 entry for core n\n", 47);
  seq_printf(a1, "\n\n%-15s %-15s\n", "Name", "ID");
  v2 = telemetry;
  if ( *(_DWORD *)(telemetry + 28) )
  {
    v3 = 0;
    v4 = 0;
    v5 = pvalue;
    do
    {
      v6 = v4;
      if ( *(_QWORD *)(v5 + 8LL * v4) != -1 )
      {
        seq_printf(a1, "%-15s %-15u\n", (const char *)(pname + 16LL * v4), v3);
        v5 = pvalue;
        v2 = telemetry;
      }
      v4 = v6 + 1;
      v3 = (unsigned __int16)(v6 + 1);
    }
    while ( *(_DWORD *)(v2 + 28) > v3 );
  }
  return 0;
}
