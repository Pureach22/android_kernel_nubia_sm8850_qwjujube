__int64 __fastcall aw882xx_monitor_set(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x20
  int v7; // w19
  __int64 *v8; // x8
  __int64 v9; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = *(_QWORD *)(((__int64 (__fastcall *)(__int64))v5)(v4) + 96);
  v7 = *(_DWORD *)(a2 + 72);
  v8 = *(__int64 **)(v6 + 112);
  v9 = v8[14];
  if ( !v9 )
    v9 = *v8;
  printk(&unk_27B2D, v9, "aw882xx_monitor_set");
  if ( *(_DWORD *)(v6 + 780) == v7 )
    return 0;
  *(_DWORD *)(v6 + 780) = v7;
  if ( v7 )
    aw882xx_monitor_start(v6 + 672);
  return 1;
}
