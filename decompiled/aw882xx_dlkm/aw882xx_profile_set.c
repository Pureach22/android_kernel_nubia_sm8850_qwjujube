__int64 __fastcall aw882xx_profile_set(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 *v8; // x8
  __int64 v9; // x1
  void *v10; // x0
  __int64 v12; // x21
  __int64 *v13; // x8
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 *v16; // x8
  __int64 v17; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  v6 = v4;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v7 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  if ( !*(_BYTE *)(v7 + 18) )
  {
    v8 = *(__int64 **)(v6 + 24);
    v9 = v8[14];
    if ( !v9 )
      v9 = *v8;
    v10 = &unk_23EA7;
LABEL_9:
    printk(v10, v9, "aw882xx_profile_set");
    return 0;
  }
  v12 = v7;
  if ( (unsigned int)aw882xx_dev_check_profile_index(*(_QWORD *)(v7 + 96), *(unsigned int *)(a2 + 72)) )
  {
    v14 = *(__int64 **)(v6 + 24);
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    printk(&unk_2367B, v15, "aw882xx_profile_set");
    return 4294967274LL;
  }
  else
  {
    if ( *(_QWORD *)(a2 + 72) == (int)aw882xx_dev_get_profile_index(*(_QWORD *)(v12 + 96)) )
    {
      v13 = *(__int64 **)(v6 + 24);
      v9 = v13[14];
      if ( !v9 )
        v9 = *v13;
      v10 = &unk_22F02;
      goto LABEL_9;
    }
    mutex_lock(v12 + 528);
    aw882xx_dev_set_profile_index(*(_QWORD *)(v12 + 96), *(unsigned int *)(a2 + 72));
    if ( *(_DWORD *)(v12 + 8) && *(_BYTE *)(v12 + 19) )
    {
      aw882xx_device_stop(*(_QWORD *)(v12 + 96));
      aw882xx_start_pa(v12);
    }
    mutex_unlock(v12 + 528);
    v16 = *(__int64 **)(v6 + 24);
    v17 = v16[14];
    if ( !v17 )
      v17 = *v16;
    printk(&unk_27E2E, v17, "aw882xx_profile_set");
    return 1;
  }
}
