void pm_show_rpmh_master_stats()
{
  __int64 v0; // x22
  unsigned __int64 v1; // x0
  __int64 v2; // x20
  void (*v3)(void); // x8

  v0 = 0;
  while ( *(_DWORD *)((char *)&subsystems_zte + v0 + 24) != 1 )
  {
LABEL_3:
    v0 += 32;
    if ( v0 == 640 )
      return;
  }
  v1 = qcom_smem_get(
         *(unsigned int *)((char *)&subsystems_zte + v0 + 12),
         *(unsigned int *)((char *)&subsystems_zte + v0 + 8),
         0);
  if ( v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v2 = *(_QWORD *)((char *)&subsystems_zte + v0);
    if ( *(_QWORD *)(v1 + 8) > *(_QWORD *)(v1 + 16) )
    {
      v3 = (void (*)(void))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v3();
    }
    printk(&unk_A450, v2);
    goto LABEL_3;
  }
}
