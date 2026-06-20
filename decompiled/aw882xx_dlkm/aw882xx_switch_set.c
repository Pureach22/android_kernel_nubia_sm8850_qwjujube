__int64 __fastcall aw882xx_switch_set(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 v7; // x19
  int v8; // w8
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = v6;
  if ( !*(_DWORD *)(v6 + 8) )
  {
    mutex_lock(v6 + 528);
    *(_BYTE *)(v7 + 19) = *(_QWORD *)(a2 + 72) != 0;
LABEL_10:
    mutex_unlock(v7 + 528);
    return 0;
  }
  if ( *(_QWORD *)(a2 + 72) )
  {
    cancel_delayed_work_sync(v6 + 112);
    mutex_lock(v7 + 528);
    v8 = *(unsigned __int8 *)(v7 + 36);
    *(_BYTE *)(v7 + 19) = 1;
    if ( v8 == 1 )
    {
      aw882xx_start_pa(v7);
    }
    else
    {
      v12 = *(__int64 **)(v7 + 64);
      v13 = v12[14];
      if ( !v13 )
        v13 = *v12;
      printk(&unk_25C2B, v13, "aw882xx_switch_set");
    }
    goto LABEL_10;
  }
  cancel_delayed_work_sync(v6 + 320);
  cancel_delayed_work_sync(v7 + 112);
  mutex_lock(v7 + 528);
  aw882xx_device_stop(*(_QWORD *)(v7 + 96));
  *(_BYTE *)(v7 + 19) = 0;
  mutex_unlock(v7 + 528);
  v10 = *(__int64 **)(v7 + 64);
  v11 = v10[14];
  if ( !v11 )
    v11 = *v10;
  printk(&unk_2255C, v11, "aw882xx_switch_set");
  return 0;
}
