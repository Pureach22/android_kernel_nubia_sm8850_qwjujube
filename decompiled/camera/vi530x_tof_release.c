__int64 vi530x_tof_release()
{
  __int64 v0; // x19
  __int64 v1; // x0
  void (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  void (__fastcall *v7)(_QWORD); // x8

  v0 = tof_ctl;
  printk(&unk_42B215);
  if ( qword_3C84B0 )
  {
    kthread_stop();
    qword_3C84B0 = 0;
  }
  v1 = tof_ctl;
  if ( tof_flag == 1 && tof_ctl )
  {
    v2 = *(void (__fastcall **)(_QWORD))(vi530x_func_tbl + 40);
    if ( *((_DWORD *)v2 - 1) != 1318018478 )
      __break(0x8228u);
    v2(v1);
    if ( !v0 )
      goto LABEL_12;
  }
  else if ( !v0 )
  {
    goto LABEL_13;
  }
  if ( *(_BYTE *)(v0 + 232) == 1 )
  {
    v3 = *(unsigned int *)(v0 + 220);
    *(_BYTE *)(v0 + 232) = 0;
    disable_irq(v3);
    synchronize_irq(*(unsigned int *)(v0 + 220));
  }
LABEL_12:
  v1 = tof_ctl;
LABEL_13:
  *(_DWORD *)(v0 + 224) = 0;
  tof_enable = 0;
  *(_BYTE *)(v0 + 233) = 0;
  tof_flag = 0;
  if ( v1 )
  {
    v4 = *(_QWORD *)(v1 + 96);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v4 + 24);
      if ( v5 )
      {
        if ( *(_BYTE *)(v1 + 312) == 1 )
        {
          v6 = *(_QWORD *)(v5 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v6, 4);
        }
      }
    }
  }
  else
  {
    printk(&unk_41F890);
  }
  v7 = *(void (__fastcall **)(_QWORD))(vi530x_func_tbl + 8);
  if ( *((_DWORD *)v7 - 1) != 1318018478 )
    __break(0x8228u);
  v7(v0);
  dword_3C84D0 = 0;
  return 0;
}
