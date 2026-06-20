void zsw_pm_record_suspend_stats()
{
  __int64 v0; // x20
  _QWORD *v1; // x0
  __int64 v2; // x23
  __int64 (*v3)(void); // x8

  v0 = 0;
  while ( *(_DWORD *)((char *)&subsystems_zte + v0 + 16) != 1 )
  {
LABEL_3:
    v0 += 48;
    if ( v0 == 960 )
      return;
  }
  v1 = (_QWORD *)qcom_smem_get(
                   *(unsigned int *)((char *)&subsystems_zte + v0 + 12),
                   *(unsigned int *)((char *)&subsystems_zte + v0 + 8),
                   0);
  if ( (unsigned __int64)v1 < 0xFFFFFFFFFFFFF001LL )
  {
    v2 = v1[3];
    if ( v1[1] > v1[2] )
    {
      v3 = (__int64 (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v2 = v3() + v2 - v1[1];
    }
    *(_QWORD *)((char *)&subsystems_zte + v0 + 24) = v2;
    goto LABEL_3;
  }
  zsw_getsmem_error = 1;
  printk(&unk_A323);
}
