__int64 __fastcall monitor_update_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x22
  __int64 result; // x0
  __int64 *v8; // x8
  __int64 v9; // x1
  __int64 *v10; // x8
  __int64 v11; // x1
  int v12; // w8
  __int64 v13; // x1
  __int64 v14; // x1
  __int64 v15; // x2
  int v16; // w19
  __int64 *v17; // x0
  unsigned __int64 v18; // x19
  _DWORD *v19; // x20
  __int64 v20; // x0
  size_t v21; // x21
  bool v22; // cf
  __int64 v23; // x19
  int v24; // w19
  __int64 *v25; // x0
  __int64 v26; // x1
  __int64 v27; // x1
  __int64 v28; // x0
  int v29; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v30[2]; // [xsp+10h] [xbp-10h] BYREF

  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v29 = 0;
  v5 = *(_QWORD *)(v4 + 96);
  if ( !a4 )
  {
    result = 0;
    goto LABEL_5;
  }
  LODWORD(result) = kstrtouint(a3, 0, &v29);
  if ( (result & 0x80000000) != 0 )
  {
    result = (int)result;
LABEL_5:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v8 = *(__int64 **)(v5 + 112);
  v9 = v8[14];
  if ( !v9 )
    v9 = *v8;
  printk(&unk_27D65, v9, "monitor_update_store");
  if ( !v29 )
  {
LABEL_9:
    result = a4;
    goto LABEL_5;
  }
  v10 = *(__int64 **)(v5 + 112);
  v11 = v10[14];
  if ( !v11 )
    v11 = *v10;
  printk(&unk_26EB3, v11, "aw882xx_monitor_stop");
  v12 = *(unsigned __int8 *)(v5 + 876);
  *(_DWORD *)(v5 + 620) = 0;
  *(_BYTE *)(v5 + 872) = 0;
  if ( !v12 )
    cancel_delayed_work_sync(v5 + 672);
  v13 = *(_QWORD *)(v5 + 848);
  *(_BYTE *)(v5 + 776) = 0;
  if ( v13 )
  {
    devm_kfree(*(_QWORD *)(v5 + 112), v13);
    *(_QWORD *)(v5 + 848) = 0;
  }
  v14 = *(_QWORD *)(v5 + 864);
  if ( v14 )
  {
    devm_kfree(*(_QWORD *)(v5 + 112), v14);
    *(_QWORD *)(v5 + 864) = 0;
  }
  v30[0] = 0;
  v15 = *(_QWORD *)(v5 + 112);
  *(_QWORD *)(v5 + 856) = 0;
  *(_QWORD *)(v5 + 864) = 0;
  *(_QWORD *)(v5 + 840) = 0;
  *(_QWORD *)(v5 + 848) = 0;
  *(_QWORD *)(v5 + 824) = 0;
  *(_QWORD *)(v5 + 832) = 0;
  *(_QWORD *)(v5 + 808) = 0;
  *(_QWORD *)(v5 + 816) = 0;
  *(_QWORD *)(v5 + 792) = 0;
  *(_QWORD *)(v5 + 800) = 0;
  *(_QWORD *)(v5 + 776) = 0;
  *(_QWORD *)(v5 + 784) = 0;
  v16 = request_firmware(v30, v5 + 128, v15);
  v17 = *(__int64 **)(v5 + 112);
  if ( v16 < 0 )
  {
    v26 = v17[14];
    if ( !v26 )
      v26 = *v17;
    printk(&unk_24D06, v26, "aw_monitor_real_time_update_monitor");
    v20 = v30[0];
    goto LABEL_26;
  }
  v18 = *(_QWORD *)v30[0];
  v19 = (_DWORD *)devm_kmalloc(v17, *(_QWORD *)v30[0] + 4LL, 3520);
  v20 = v30[0];
  if ( !v19 )
  {
    v16 = -12;
LABEL_26:
    release_firmware(v20);
    result = v16;
    goto LABEL_5;
  }
  if ( v18 > 0xFFFFFFFFFFFFFFFBLL )
  {
    __break(1u);
  }
  else
  {
    v21 = *(_QWORD *)v30[0];
    v22 = v18 >= *(_QWORD *)v30[0];
    *v19 = *(_QWORD *)v30[0];
    if ( v22 )
    {
      v23 = v30[0];
      memcpy(v19 + 1, *(const void **)(v30[0] + 8LL), v21);
      release_firmware(v23);
      v24 = aw882xx_monitor_parse_fw((_DWORD *)(v5 + 672), v19 + 1, (unsigned int)v21);
      v25 = *(__int64 **)(v5 + 112);
      if ( v24 < 0 )
      {
        v27 = v25[14];
        if ( !v27 )
          v27 = *v25;
        printk(&unk_24D2B, v27, "aw_monitor_real_time_update_monitor");
        devm_kfree(*(_QWORD *)(v5 + 112), v19);
        result = v24;
        goto LABEL_5;
      }
      devm_kfree(v25, v19);
      aw882xx_monitor_start(v5 + 672);
      goto LABEL_9;
    }
  }
  v28 = _fortify_panic(17);
  return aw_dev_set_channal_mode(v28);
}
