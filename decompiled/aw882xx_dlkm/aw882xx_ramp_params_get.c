__int64 __fastcall aw882xx_ramp_params_get(__int64 a1, _QWORD *a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 *v7; // x8
  __int64 v8; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  a2[9] = *(int *)(*(_QWORD *)(v6 + 96) + 96LL);
  a2[10] = *(int *)(*(_QWORD *)(v6 + 96) + 100LL);
  a2[11] = *(int *)(*(_QWORD *)(v6 + 96) + 104LL);
  a2[12] = *(int *)(*(_QWORD *)(v6 + 96) + 108LL);
  v7 = *(__int64 **)(v6 + 64);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_245AE, v8, "aw882xx_ramp_params_get");
  return 0;
}
