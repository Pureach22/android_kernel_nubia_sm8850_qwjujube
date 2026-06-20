__int64 pm_show_rpm_stats()
{
  __int64 v0; // x19
  unsigned __int64 v1; // x0
  __int64 v2; // x22
  char *v3; // x20
  __int64 v4; // x20
  void (*v5)(void); // x8
  __int64 v6; // x0
  __int64 result; // x0
  _QWORD v8[5]; // [xsp+8h] [xbp-28h] BYREF

  v8[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v8, 0, 32);
  _memcpy_fromio(v8, soc_aosd_0, 32);
  v0 = HIDWORD(v8[0]);
  if ( vmin_count == HIDWORD(v8[0]) )
  {
    v1 = printk(&unk_A220, HIDWORD(v8[0]));
    v2 = 0;
    while ( 1 )
    {
      v3 = (char *)&subsystems_zte + v2;
      if ( *(_DWORD *)((char *)&subsystems_zte + v2 + 24) == 1 )
      {
        v1 = qcom_smem_get(*((unsigned int *)v3 + 3), *((unsigned int *)v3 + 2), 0);
        if ( v1 > 0xFFFFFFFFFFFFF000LL )
        {
LABEL_12:
          result = debug_suspend_enabled(v1);
          goto LABEL_13;
        }
        v4 = *(_QWORD *)v3;
        if ( *(_QWORD *)(v1 + 8) > *(_QWORD *)(v1 + 16) )
        {
          v5 = (void (*)(void))arch_timer_read_counter;
          if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
            __break(0x8228u);
          v5();
        }
        v1 = printk(&unk_A450, v4);
      }
      v2 += 32;
      if ( v2 == 640 )
        goto LABEL_12;
    }
  }
  v6 = printk(&unk_A3B5, vmin_count);
  vmin_count = v0;
  result = debug_suspend_disable(v6);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
