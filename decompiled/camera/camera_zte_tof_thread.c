__int64 camera_zte_tof_thread()
{
  __int64 v0; // x8
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 (__fastcall *v4)(_QWORD); // x8
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x9
  __int64 v9; // x0

  mutex_lock(tof_ctl + 264);
  if ( tof_ctl )
  {
    v0 = *(_QWORD *)(tof_ctl + 96);
    if ( v0 )
    {
      v1 = *(_QWORD *)(v0 + 24);
      if ( v1 )
      {
        if ( *(_BYTE *)(tof_ctl + 312) == 1 )
        {
          v2 = *(_QWORD *)(v1 + 208);
          ++tof_i2c_open_count;
          if ( (_pm_runtime_resume(v2, 4) & 0x80000000) != 0 )
            printk(&unk_3CC265);
        }
      }
    }
  }
  else
  {
    printk(&unk_41F890);
  }
  printk(&unk_3E0119);
  v3 = tof_ctl;
  v4 = *(__int64 (__fastcall **)(_QWORD))(vi530x_func_tbl + 64);
  if ( *((_DWORD *)v4 - 1) != 1318018478 )
    __break(0x8228u);
  v5 = v4(v3);
  v6 = tof_ctl;
  dword_3C84D0 = v5;
  *(_BYTE *)(tof_ctl + 233) = 1;
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 96);
    if ( v7 )
    {
      v8 = *(_QWORD *)(v7 + 24);
      if ( v8 )
      {
        if ( *(_BYTE *)(v6 + 312) == 1 )
        {
          v9 = *(_QWORD *)(v8 + 208);
          --tof_i2c_open_count;
          _pm_runtime_idle(v9, 4);
        }
      }
    }
  }
  else
  {
    printk(&unk_41F890);
  }
  printk(&unk_3DC0F5);
  mutex_unlock(tof_ctl + 264);
  return 0;
}
