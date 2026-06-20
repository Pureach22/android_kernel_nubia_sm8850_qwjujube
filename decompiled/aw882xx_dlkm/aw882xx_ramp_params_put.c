__int64 __fastcall aw882xx_ramp_params_put(__int64 a1, __int64 a2)
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
  printk(&unk_245AE, v9, "aw882xx_ramp_params_put");
  v10 = *(_DWORD **)(v8 + 96);
  v11 = v10[23];
  if ( v11 )
  {
    if ( v11 != 1 )
      goto LABEL_9;
  }
  else
  {
    v10[24] = *(_DWORD *)(a2 + 72) - 1440;
    v10 = *(_DWORD **)(v8 + 96);
    v11 = v10[23];
    if ( v11 != 1 )
    {
LABEL_9:
      if ( v11 != 2 )
        goto LABEL_10;
LABEL_14:
      v10[26] = *(_DWORD *)(a2 + 88) - 1440;
      v10 = *(_DWORD **)(v8 + 96);
      v11 = v10[23];
      if ( v11 != 3 )
        goto LABEL_15;
      goto LABEL_18;
    }
  }
  v10[25] = *(_QWORD *)(a2 + 80);
  v10 = *(_DWORD **)(v8 + 96);
  v11 = v10[23];
  if ( v11 == 2 )
    goto LABEL_14;
LABEL_10:
  if ( v11 != 3 )
    goto LABEL_15;
LABEL_18:
  v10[27] = *(_QWORD *)(a2 + 96);
  v14 = *(__int64 **)(v8 + 64);
  v15 = v14[14];
  if ( !v15 )
    v15 = *v14;
  printk(&unk_284AD, v15, "aw882xx_ramp_params_put");
  aw882xx_dsp_write_ramp_params(*(_QWORD *)(v8 + 96), *(_QWORD *)(v8 + 96) + 96LL, 16);
  v10 = *(_DWORD **)(v8 + 96);
  v11 = v10[23];
LABEL_15:
  v10[23] = v11 + 1;
  v12 = *(_QWORD *)(v8 + 96);
  if ( *(_DWORD *)(v12 + 92) == 4 )
    *(_DWORD *)(v12 + 92) = 0;
  return 0;
}
