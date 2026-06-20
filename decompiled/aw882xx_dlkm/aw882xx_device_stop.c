__int64 __fastcall aw882xx_device_stop(__int64 a1)
{
  void (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 *v7; // x8
  __int64 v8; // x1
  __int64 v9; // x1
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 v16; // x1
  __int64 *v17; // x8
  __int64 v18; // x1
  void (__fastcall *v19)(__int64, __int64, __int64, __int64); // x8
  __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x1
  void (__fastcall *v24)(__int64, __int64, __int64, __int64); // x8
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 *v28; // x8
  __int64 v29; // x1
  __int64 v30; // x1
  void (__fastcall *v31)(__int64, __int64, __int64, __int64); // x8
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 *v35; // x8
  __int64 v36; // x1
  __int64 *v37; // x8
  __int64 v38; // x1

  if ( !*(_DWORD *)a1 )
    return 0;
  *(_DWORD *)a1 = 0;
  aw882xx_monitor_stop(a1 + 672);
  aw882xx_dev_clear_int_status(a1);
  v3 = *(void (__fastcall **)(__int64, __int64, __int64))(a1 + 1152);
  v4 = *(_QWORD *)(a1 + 120);
  v5 = *(unsigned int *)(a1 + 296);
  v6 = *(unsigned int *)(a1 + 304);
  if ( *((_DWORD *)v3 - 1) != -1860236611 )
    __break(0x8228u);
  v3(v4, v5, v6);
  v7 = *(__int64 **)(a1 + 112);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_22D82, v8, "aw882xx_dev_set_intmask");
  v9 = *(unsigned int *)(a1 + 408);
  if ( (_DWORD)v9 != 255 )
  {
    v10 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v11 = *(_QWORD *)(a1 + 120);
    v12 = *(unsigned int *)(a1 + 412);
    v13 = *(unsigned int *)(a1 + 416);
    if ( *((_DWORD *)v10 - 1) != 370515439 )
      __break(0x8228u);
    v10(v11, v9, v12, v13);
    v14 = *(__int64 **)(a1 + 112);
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    printk(&unk_25B06, v15, "aw_dev_switch");
  }
  aw882xx_dev_mute(a1, 1);
  usleep_range_state(5000, 5010, 2);
  v16 = *(unsigned int *)(a1 + 424);
  if ( (_DWORD)v16 == 255 )
  {
    v17 = *(__int64 **)(a1 + 112);
    v18 = v17[14];
    if ( !v18 )
      v18 = *v17;
    printk(&unk_27FF7, v18, "aw_dev_i2s_enable");
  }
  else
  {
    v19 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v20 = *(_QWORD *)(a1 + 120);
    v21 = *(unsigned int *)(a1 + 428);
    v22 = *(unsigned int *)(a1 + 436);
    if ( *((_DWORD *)v19 - 1) != 370515439 )
      __break(0x8228u);
    v19(v20, v16, v21, v22);
  }
  usleep_range_state(1000, 1100, 2);
  v23 = *(unsigned int *)(a1 + 360);
  if ( (_DWORD)v23 != 255 )
  {
    v24 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v25 = *(_QWORD *)(a1 + 120);
    v26 = *(unsigned int *)(a1 + 364);
    v27 = *(unsigned int *)(a1 + 368);
    if ( *((_DWORD *)v24 - 1) != 370515439 )
      __break(0x8228u);
    v24(v25, v23, v26, v27);
    v28 = *(__int64 **)(a1 + 112);
    v29 = v28[14];
    if ( !v29 )
      v29 = *v28;
    printk(&unk_25B06, v29, "aw_dev_switch");
  }
  v30 = *(unsigned int *)(a1 + 336);
  if ( (_DWORD)v30 != 255 )
  {
    v31 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(a1 + 1168);
    v32 = *(_QWORD *)(a1 + 120);
    v33 = *(unsigned int *)(a1 + 340);
    v34 = *(unsigned int *)(a1 + 344);
    if ( *((_DWORD *)v31 - 1) != 370515439 )
      __break(0x8228u);
    v31(v32, v30, v33, v34);
    v35 = *(__int64 **)(a1 + 112);
    v36 = v35[14];
    if ( !v36 )
      v36 = *v35;
    printk(&unk_25B06, v36, "aw_dev_switch");
  }
  v37 = *(__int64 **)(a1 + 112);
  v38 = v37[14];
  if ( !v38 )
    v38 = *v37;
  printk(&unk_22D82, v38, "aw882xx_device_stop");
  return 0;
}
