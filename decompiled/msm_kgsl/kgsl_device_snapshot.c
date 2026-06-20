__int64 __fastcall kgsl_device_snapshot(__int64 result, __int64 a2, __int64 a3, char a4)
{
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 (*v9)(void); // x8
  int v10; // w8
  __int64 v11; // x22
  _BYTE *v12; // x25
  int v13; // w8
  __int64 v14; // x24
  __int64 v15; // x8
  __int64 v16; // x9
  void (__fastcall *v17)(__int64, __int64, __int64, __int64); // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x21
  __int64 v20; // x0
  __int64 v21; // x10
  __int64 v22; // x11
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x0
  __int64 real_seconds; // x0
  __int64 v27; // x8
  __int64 v28; // x3
  __int64 v29; // x8
  __int64 v30; // x0
  const char *v31; // x2
  __int64 v32; // x8
  unsigned __int64 v33; // x9
  __int64 v34; // x8
  unsigned __int64 v35; // x12
  unsigned __int64 v36; // x9
  __int64 v37; // x2
  __int64 v38; // x1
  __int64 v39; // x8
  unsigned __int64 v40; // x12
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 v43; // x0
  _QWORD *v44; // x24
  _QWORD *v45; // x0
  _QWORD *v46; // x27
  __int64 v47; // x0
  _QWORD v48[3]; // [xsp+8h] [xbp-18h] BYREF

  v7 = result;
  v48[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(result + 8752);
  v48[0] = 0;
  v48[1] = 0;
  v9 = *(__int64 (**)(void))(v8 + 288);
  if ( v9 )
  {
    if ( *((_DWORD *)v9 - 1) != 1058568764 )
      __break(0x8228u);
    result = v9();
  }
  if ( !*(_QWORD *)(v7 + 11216) )
  {
    result = dev_err(*(_QWORD *)v7, "snapshot: no snapshot memory available\n");
    goto LABEL_36;
  }
  v10 = *(_DWORD *)(v7 + 11120);
  if ( v10 != 2 && v10 != 32 )
  {
    result = _warn_printk("snapshot: device is powered off\n");
    __break(0x800u);
    goto LABEL_36;
  }
  v11 = *(_QWORD *)(v7 + 11240);
  v12 = (_BYTE *)(v7 + 11300);
  v13 = *(_DWORD *)(v7 + 11296) + 1;
  *(_BYTE *)(v7 + 13192) = a4 & 1;
  *(_DWORD *)(v7 + 11296) = v13;
  if ( v11 )
  {
    if ( *(_BYTE *)(v7 + 11302) != 1 || *(_BYTE *)(v11 + 245) != 1 || (a4 & 1) == 0 )
      goto LABEL_36;
    if ( !*(_DWORD *)(v11 + 240) )
    {
      v44 = *(_QWORD **)(v11 + 248);
      wait_for_completion(v11 + 192);
      v45 = *(_QWORD **)(v11 + 128);
      if ( v45 != (_QWORD *)(v11 + 128) )
      {
        do
        {
          v46 = (_QWORD *)*v45;
          kgsl_snapshot_put_object(v45 - 5);
          v45 = v46;
        }
        while ( v46 != (_QWORD *)(v11 + 128) );
      }
      v47 = *(_QWORD *)(v11 + 112);
      if ( v47 )
        vfree(v47);
      kfree(v11);
      dev_err(*v44, "snapshot: objects released\n");
    }
    *(_QWORD *)(v7 + 11240) = 0;
  }
  result = _kmalloc_cache_noprof(mutex_unlock, 3520, 256);
  if ( !result )
  {
LABEL_36:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  *(_DWORD *)(result + 192) = 0;
  v14 = result;
  _init_swait_queue_head(result + 200, "&x->wait", &init_completion___key_6);
  *(_QWORD *)(v14 + 128) = v14 + 128;
  *(_QWORD *)(v14 + 136) = v14 + 128;
  *(_QWORD *)(v14 + 144) = v14 + 144;
  *(_QWORD *)(v14 + 152) = v14 + 144;
  *(_QWORD *)(v14 + 160) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v14 + 168) = v14 + 168;
  *(_QWORD *)(v14 + 176) = v14 + 168;
  v15 = *(_QWORD *)(v7 + 11216);
  *(_QWORD *)(v14 + 184) = kgsl_snapshot_save_frozen_objs;
  v16 = *(unsigned int *)(v7 + 11232);
  *(_DWORD *)(v14 + 240) = 0;
  *(_QWORD *)(v14 + 72) = v15;
  *(_QWORD *)(v14 + 88) = v15;
  *(_QWORD *)(v14 + 96) = v16;
  *(_WORD *)(v14 + 244) = 1;
  v17 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v7 + 8752) + 88LL);
  if ( *((_DWORD *)v17 - 1) != -988183093 )
    __break(0x8228u);
  v17(v7, v14, a2, a3);
  v18 = *(_QWORD *)(v14 + 96);
  if ( v18 >= 8 )
  {
    v19 = *(_QWORD *)(v14 + 88);
    v20 = kgsl_snapshot_eventlog_buffer((_QWORD *)v7, (_QWORD *)(v19 + 8), v18 - 8);
    if ( v20 )
    {
      v21 = (unsigned int)(v20 + 8);
      *(_DWORD *)v19 = 436317133;
      *(_DWORD *)(v19 + 4) = v21;
      v22 = *(_QWORD *)(v14 + 80);
      v23 = *(_QWORD *)(v14 + 88) + v21;
      v24 = *(_QWORD *)(v14 + 96);
      *(_QWORD *)(v14 + 88) = v23;
      *(_QWORD *)(v14 + 96) = v24 - *(unsigned int *)(v19 + 4);
      *(_QWORD *)(v14 + 80) = v22 + *(unsigned int *)(v19 + 4);
    }
  }
  v25 = getboottime64(v48);
  real_seconds = ktime_get_real_seconds(v25);
  v27 = v48[0];
  v28 = *(_QWORD *)(v7 + 11224);
  *(_QWORD *)(v7 + 11240) = v14;
  v29 = real_seconds - v27;
  v30 = *(_QWORD *)v7;
  *(_QWORD *)(v14 + 248) = v7;
  *(_QWORD *)(v14 + 104) = v29;
  if ( (a4 & 1) != 0 )
    v31 = "GMU";
  else
    v31 = "GPU";
  if ( !v28 )
  {
    v32 = (__int64)(*(_QWORD *)(v7 + 11216) << 8) >> 8;
    v33 = v32 + 0x8000000000LL;
    v34 = v32 - kimage_voffset;
    v35 = v33 >> 38;
    v36 = v33 + memstart_addr;
    if ( v35 )
      v28 = v34;
    else
      v28 = v36;
  }
  dev_err(v30, "%s snapshot created at pa %llx++0x%zx\n", v31, v28, *(_QWORD *)(v14 + 80));
  v37 = *(_QWORD *)(v7 + 11224);
  v38 = *(_QWORD *)(v7 + 11216);
  if ( !v37 )
  {
    v39 = v38 << 8 >> 8;
    v40 = (unsigned __int64)(v39 + 0x8000000000LL) >> 38;
    v41 = memstart_addr + v39 + 0x8000000000LL;
    v42 = v39 - kimage_voffset;
    if ( v40 )
      v37 = v42;
    else
      v37 = v41;
  }
  v43 = kgsl_add_to_minidump("GPU_SNAPSHOT", v38, v37, *(unsigned int *)(v7 + 11232));
  if ( *(_BYTE *)(v7 + 11301) != 1 || *v12 != 1 )
  {
    sysfs_notify(v7 + 11320, 0, "timestamp");
    if ( *v12 == 1 )
      result = kgsl_snapshot_save_frozen_objs(v14 + 160);
    else
      result = queue_work_on(32, qword_3A900, v14 + 160);
    goto LABEL_36;
  }
  __break(0x800u);
  return kgsl_free_snapshot(v43);
}
