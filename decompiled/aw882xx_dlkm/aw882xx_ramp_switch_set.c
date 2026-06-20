__int64 __fastcall aw882xx_ramp_switch_set(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x19
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
  aw882xx_dsp_write_ramp_enable(*(_QWORD *)(v6 + 96), *(unsigned int *)(a2 + 72));
  *(_DWORD *)(*(_QWORD *)(v6 + 96) + 88LL) = *(_QWORD *)(a2 + 72);
  v7 = *(__int64 **)(v6 + 64);
  v8 = v7[14];
  if ( !v8 )
    v8 = *v7;
  printk(&unk_24E11, v8, "aw882xx_ramp_switch_set");
  return 0;
}
