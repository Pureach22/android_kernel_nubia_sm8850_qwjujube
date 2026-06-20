// write access to const memory has been detected, the output may be wrong!
__int64 vi530x_tof_open()
{
  __int64 v0; // x19
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x0
  int v4; // w10
  __int64 v5; // x0
  void (__fastcall *v6)(__int64); // x8
  __int64 v7; // x8
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = tof_ctl;
  dword_3C84D0 = 0;
  if ( !tof_ctl )
  {
    printk(&unk_41F890);
    if ( (tof_enable & 1) != 0 )
      goto LABEL_13;
    tof_enable = 1;
    dword_E0 = 1;
    goto LABEL_10;
  }
  v1 = *(_QWORD *)(tof_ctl + 96);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 24);
    if ( v2 )
    {
      if ( *(_BYTE *)(tof_ctl + 312) == 1 )
      {
        v3 = *(_QWORD *)(v2 + 208);
        ++tof_i2c_open_count;
        if ( (_pm_runtime_resume(v3, 4) & 0x80000000) != 0 )
          printk(&unk_3CC265);
      }
    }
  }
  if ( (tof_enable & 1) == 0 )
  {
    v4 = *(unsigned __int8 *)(v0 + 232);
    tof_enable = 1;
    *(_DWORD *)(v0 + 224) = 1;
    if ( !v4 )
    {
      v5 = *(unsigned int *)(v0 + 220);
      *(_BYTE *)(v0 + 232) = 1;
      enable_irq(v5);
    }
LABEL_10:
    v6 = *(void (__fastcall **)(__int64))vi530x_func_tbl;
    if ( *(_DWORD *)(*(_QWORD *)vi530x_func_tbl - 4LL) != 1318018478 )
      __break(0x8228u);
    v6(v0);
    v9 = 0;
    v10 = 0;
    ktime_get_real_ts64(&v9);
    v7 = v10 / 1000;
    *(_QWORD *)(v0 + 192) = v9;
    *(_QWORD *)(v0 + 200) = v7;
    camera_zte_tof_thread();
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return 0;
}
