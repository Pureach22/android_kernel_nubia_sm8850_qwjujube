__int64 __fastcall island_stats_show(__int64 a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v4; // x20
  __int64 i; // x23
  __int64 v6; // x22

  v2 = qcom_smem_get(2, 653, 0);
  if ( v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v4 = v2;
    for ( i = 0; i != 432; i += 72 )
    {
      v6 = v4 + i;
      if ( strcmp((const char *)(v4 + i), "DEADDEAD") )
      {
        seq_printf(a1, "Name: %s\n", (const char *)(v4 + i));
        seq_printf(a1, "Count: %u\n", *(_DWORD *)(v6 + 16));
        seq_printf(a1, "Last Entered At: %llu\n", *(_QWORD *)(v6 + 24));
        seq_printf(a1, "Last Exited At: %llu\n", *(_QWORD *)(v6 + 32));
        seq_printf(a1, "Accumulated Duration: %llu\n", *(_QWORD *)(v6 + 40));
        seq_printf(a1, "Vid: %u\n", *(_DWORD *)(v6 + 48));
        seq_printf(a1, "task_id: %u\n", *(_DWORD *)(v6 + 52));
      }
    }
  }
  return 0;
}
