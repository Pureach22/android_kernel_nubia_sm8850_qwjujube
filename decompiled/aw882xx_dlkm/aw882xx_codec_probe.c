__int64 __fastcall aw882xx_codec_probe(__int64 a1)
{
  __int64 (__fastcall *v2)(); // x8
  __int64 v3; // x0
  __int64 *v4; // x8
  __int64 v5; // x19
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x20
  char *v16; // x0
  void (__fastcall *v17)(__int64, __int64, __int64); // x8
  __int64 v18; // x0
  void (__fastcall *v19)(__int64, void *, __int64); // x8
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, void *, __int64); // x8
  __int64 v22; // x0

  v2 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v3 = ((__int64 (__fastcall *)(__int64))v2)(a1);
  v4 = *(__int64 **)(v3 + 64);
  v5 = v3;
  v6 = v4[14];
  if ( !v6 )
    v6 = *v4;
  printk(&unk_26EB3, v6, "aw882xx_codec_probe");
  v7 = alloc_workqueue("%s", (const char *)0x6000A);
  *(_QWORD *)(v5 + 104) = v7;
  if ( v7 )
  {
    *(_QWORD *)(*(_QWORD *)(v5 + 96) + 184LL) = v7;
    *(_QWORD *)(v5 + 112) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v5 + 120) = v5 + 120;
    *(_QWORD *)(v5 + 128) = v5 + 120;
    *(_QWORD *)(v5 + 136) = aw882xx_startup_work;
    init_timer_key(v5 + 144, &delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v5 + 216) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v5 + 224) = v5 + 224;
    *(_QWORD *)(v5 + 232) = v5 + 224;
    *(_QWORD *)(v5 + 240) = aw882xx_interrupt_work;
    init_timer_key(v5 + 248, &delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v5 + 320) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v5 + 328) = v5 + 328;
    *(_QWORD *)(v5 + 336) = v5 + 328;
    *(_QWORD *)(v5 + 344) = aw882xx_dc_prot_work;
    init_timer_key(v5 + 352, &delayed_work_timer_fn, 0x200000, 0, 0);
    *(_QWORD *)(v5 + 424) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v5 + 432) = v5 + 432;
    *(_QWORD *)(v5 + 440) = v5 + 432;
    *(_QWORD *)(v5 + 448) = aw882xx_request_firmware;
    init_timer_key(v5 + 456, &delayed_work_timer_fn, 0x200000, 0, 0);
    v8 = *(_QWORD *)(v5 + 96);
    *(_QWORD *)(v5 + 40) = a1;
    if ( !*(_DWORD *)(v8 + 52) )
    {
      v12 = *(__int64 **)(v5 + 64);
      v13 = v12[14];
      if ( !v13 )
        v13 = *v12;
      printk(&unk_26EB3, v13, "aw882xx_add_codec_controls");
      v14 = devm_kmalloc(*(_QWORD *)(*(_QWORD *)(v5 + 40) + 24LL), 80, 3520);
      if ( v14 )
      {
        v15 = v14;
        v16 = (char *)devm_kmalloc(*(_QWORD *)(*(_QWORD *)(v5 + 40) + 24LL), 50, 3520);
        if ( v16 )
        {
          *(_QWORD *)(v15 + 16) = v16;
          strcpy(v16, "aw_algo_auth");
          *(_DWORD *)v15 = 2;
          *(_DWORD *)(v15 + 28) = 268435504;
          *(_QWORD *)(v15 + 40) = aw882xx_algo_auth_info;
          *(_QWORD *)(v15 + 64) = aw882xx_algo_auth_tlv_rw;
          v17 = (void (__fastcall *)(__int64, __int64, __int64))off_358;
          v18 = *(_QWORD *)(v5 + 40);
          if ( *((_DWORD *)off_358 - 1) != -467765670 )
            __break(0x8228u);
          v17(v18, v15, 1);
          v19 = (void (__fastcall *)(__int64, void *, __int64))off_358;
          v20 = *(_QWORD *)(v5 + 40);
          if ( *((_DWORD *)off_358 - 1) != -467765670 )
            __break(0x8228u);
          v19(v20, &aw882xx_controls, 6);
          if ( *(_DWORD *)(*(_QWORD *)(v5 + 96) + 936LL) == 1 )
          {
            v21 = (void (__fastcall *)(__int64, void *, __int64))off_358;
            v22 = *(_QWORD *)(v5 + 40);
            if ( *((_DWORD *)off_358 - 1) != -467765670 )
              __break(0x8228u);
            v21(v22, &aw882xx_spin_control, 1);
          }
        }
      }
    }
    if ( *(_BYTE *)(v5 + 24) )
      aw882xx_request_firmware(v5 + 424);
    else
      queue_delayed_work_on(32, *(_QWORD *)(v5 + 104), v5 + 424, 0);
    aw882xx_dev_init_cali_re(*(_QWORD *)(v5 + 96));
    return 0;
  }
  else
  {
    v10 = *(__int64 **)(v5 + 64);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_2691E, v11, "aw882xx_codec_probe");
    return 4294967274LL;
  }
}
