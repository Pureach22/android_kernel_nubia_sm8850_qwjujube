void zsw_pm_record_resume_stats()
{
  __int64 v0; // x21
  const char *v1; // x0
  _QWORD *v2; // x0
  unsigned __int64 v3; // x25
  __int64 (*v4)(void); // x8
  unsigned __int64 v5; // x8
  bool v6; // cf
  __int64 v7; // x8

  v0 = 0;
  while ( *(_DWORD *)((char *)&subsystems_zte + v0 + 16) != 1 )
  {
LABEL_3:
    v0 += 48;
    if ( v0 == 960 )
      return;
  }
  v2 = (_QWORD *)qcom_smem_get(
                   *(unsigned int *)((char *)&subsystems_zte + v0 + 12),
                   *(unsigned int *)((char *)&subsystems_zte + v0 + 8),
                   0);
  if ( (unsigned __int64)v2 <= 0xFFFFFFFFFFFFF000LL )
  {
    v3 = v2[3];
    if ( v2[1] > v2[2] )
    {
      v4 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v3 = v4() + v3 - v2[1];
    }
    v1 = *(const char **)((char *)&subsystems_zte + v0);
    *(_QWORD *)((char *)&subsystems_zte + v0 + 32) = v3;
    if ( !strcmp(v1, "apss") )
    {
      v5 = *(_QWORD *)((char *)&subsystems_zte + v0 + 24);
      v6 = v3 >= v5;
      v7 = v3 - v5;
      if ( !v6 )
        v7 = 0;
      Ap_sleepcounter_time_thistime = v7;
    }
    goto LABEL_3;
  }
  zsw_getsmem_error = 1;
  printk(&unk_A3F1);
}
