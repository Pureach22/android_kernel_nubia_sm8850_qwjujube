_QWORD *__fastcall pm_subsystems_resume_suspend(char a1)
{
  _QWORD *result; // x0
  __int64 v2; // x20
  _QWORD *v3; // x19
  char *v4; // x23
  __int64 (*v5)(void); // x8

  if ( (a1 & 1) == 0 )
  {
    result = (_QWORD *)printk(&unk_A565);
    v2 = 0;
    while ( 1 )
    {
      if ( *(_DWORD *)((char *)&subsystems_zte + v2 + 16) == 1 )
      {
        result = (_QWORD *)qcom_smem_get(
                             *(unsigned int *)((char *)&subsystems_zte + v2 + 12),
                             *(unsigned int *)((char *)&subsystems_zte + v2 + 8),
                             0);
        if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL )
        {
          zsw_getsmem_error = 1;
          return (_QWORD *)printk(&unk_A323);
        }
        v3 = result;
        v4 = (char *)result[3];
        if ( result[1] > result[2] )
        {
          v5 = (__int64 (*)(void))arch_timer_read_counter;
          if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
            __break(0x8228u);
          result = (_QWORD *)v5();
          v4 = &v4[(_QWORD)result - v3[1]];
        }
        *(_QWORD *)((char *)&subsystems_zte + v2 + 24) = v4;
      }
      v2 += 48;
      if ( v2 == 960 )
        return result;
    }
  }
  printk(&unk_996B);
  zsw_pm_record_resume_stats();
  return (_QWORD *)zsw_pm_resume_calculate_wakepercent();
}
