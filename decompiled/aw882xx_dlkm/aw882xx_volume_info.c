__int64 __fastcall aw882xx_volume_info(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x10

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = *(_QWORD *)(((__int64 (__fastcall *)(__int64))v5)(v4) + 96);
  *(_DWORD *)(a2 + 64) = 2;
  *(_DWORD *)(a2 + 72) = 1;
  *(_QWORD *)(a2 + 80) = 0;
  *(_QWORD *)(a2 + 88) = *(int *)(v6 + 612);
  return 0;
}
