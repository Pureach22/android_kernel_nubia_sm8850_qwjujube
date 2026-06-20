__int64 __fastcall qcom_subsystem_sleep_stats_show(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x21
  __int64 v4; // x20
  __int64 (*v5)(void); // x8

  v2 = (_QWORD *)qcom_smem_get(
                   *(unsigned int *)(*(_QWORD *)(a1 + 128) + 12LL),
                   *(unsigned int *)(*(_QWORD *)(a1 + 128) + 8LL),
                   0);
  if ( (unsigned __int64)v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = v2;
    v4 = v2[3];
    if ( v2[1] > v2[2] )
    {
      v5 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v4 = v5() + v4 - v2[1];
    }
    seq_printf(a1, "Count: %u\n", *((_DWORD *)v3 + 1));
    seq_printf(a1, "Last Entered At: %llu\n", v3[1]);
    seq_printf(a1, "Last Exited At: %llu\n", v3[2]);
    seq_printf(a1, "Accumulated Duration: %llu\n", v4);
  }
  return 0;
}
