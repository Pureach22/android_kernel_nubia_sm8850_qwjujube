__int64 __fastcall aw882xx_algo_volume_put(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 *v7; // x8
  __int64 v8; // x19
  __int64 v9; // x1
  _DWORD *v10; // x8
  int v11; // w9
  __int64 v12; // x8
  __int64 *v14; // x8
  __int64 v15; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(__int64 **)(v6 + 64);
  v8 = v6;
  v9 = v7[14];
  if ( !v9 )
    v9 = *v7;
  printk(&unk_2694B, v9, "aw882xx_algo_volume_put");
  v10 = *(_DWORD **)(v8 + 96);
  v11 = v10[19];
  if ( !v11 )
  {
    v10[20] = *(_DWORD *)(a2 + 72) - 128;
    v10 = *(_DWORD **)(v8 + 96);
    v11 = v10[19];
  }
  if ( v11 == 1 )
  {
    v10[21] = *(_QWORD *)(a2 + 80);
    v14 = *(__int64 **)(v8 + 64);
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    printk(&unk_28B46, v15, "aw882xx_algo_volume_put");
    aw882xx_dsp_write_volume(*(_QWORD *)(v8 + 96), *(_QWORD *)(v8 + 96) + 80LL, 8);
    v10 = *(_DWORD **)(v8 + 96);
    v11 = v10[19];
  }
  v10[19] = v11 + 1;
  v12 = *(_QWORD *)(v8 + 96);
  if ( *(_DWORD *)(v12 + 76) == 2 )
    *(_DWORD *)(v12 + 76) = 0;
  return 0;
}
