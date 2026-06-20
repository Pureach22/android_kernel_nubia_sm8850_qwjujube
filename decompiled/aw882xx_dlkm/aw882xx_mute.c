__int64 __fastcall aw882xx_mute(__int64 a1, int a2, int a3)
{
  __int64 v3; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v7; // x0
  __int64 *v8; // x8
  __int64 v9; // x19
  __int64 v10; // x1
  __int64 v11; // x0
  unsigned int v13; // w0
  unsigned int v14; // w20
  __int64 *v15; // x8
  __int64 v16; // x1
  void *v17; // x0
  __int64 *v18; // x8
  __int64 *v19; // x8
  __int64 v20; // x1

  v3 = *(_QWORD *)(a1 + 96);
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v7 = ((__int64 (__fastcall *)(__int64))v5)(v3);
  v8 = *(__int64 **)(v7 + 64);
  v9 = v7;
  v10 = v8[14];
  if ( !v10 )
    v10 = *v8;
  printk(&unk_286F2, v10, "aw882xx_mute");
  if ( a3 )
  {
    v15 = *(__int64 **)(v9 + 64);
    v16 = v15[14];
    if ( !v16 )
      v16 = *v15;
    v17 = &unk_233FE;
    goto LABEL_20;
  }
  if ( a2 )
  {
    *(_DWORD *)(v9 + 8) = 0;
    cancel_delayed_work_sync(v9 + 320);
    cancel_delayed_work_sync(v9 + 112);
    mutex_lock(v9 + 528);
    v11 = *(_QWORD *)(v9 + 96);
    g_algo_auth_st = 0;
    aw882xx_device_stop(v11);
    mutex_unlock(v9 + 528);
    return 0;
  }
  if ( !*(_BYTE *)(v9 + 36) )
  {
    v18 = *(__int64 **)(v9 + 64);
    v16 = v18[14];
    if ( !v16 )
      v16 = *v18;
    v17 = &unk_25C2B;
LABEL_20:
    printk(v17, v16, "aw882xx_mute");
    return 0;
  }
  *(_DWORD *)(v9 + 8) = 1;
  mutex_lock(v9 + 528);
  queue_delayed_work_on(32, *(_QWORD *)(v9 + 104), v9 + 112, 0);
  if ( !*(_DWORD *)(*(_QWORD *)(v9 + 96) + 52LL) && (v13 = ((__int64 (*)(void))aw882xx_spin_set_record_val)()) != 0 )
  {
    v19 = *(__int64 **)(v9 + 64);
    v14 = v13;
    v20 = v19[14];
    if ( !v20 )
      v20 = *v19;
    printk(&unk_25C5F, v20, "aw882xx_mute");
  }
  else
  {
    v14 = 0;
  }
  mutex_unlock(v9 + 528);
  return v14;
}
