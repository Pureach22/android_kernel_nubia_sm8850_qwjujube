__int64 __fastcall aw882xx_iv_output_set(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = *(_QWORD *)(((__int64 (__fastcall *)(__int64))v5)(v4) + 96);
  g_iv_output = *(_QWORD *)(a2 + 72) == 0;
  aw882xx_dev_iv_forbidden_output(v6);
  return 0;
}
