__int64 __fastcall aw882xx_codec_remove(__int64 a1)
{
  __int64 (__fastcall *v1)(); // x8
  __int64 v2; // x0
  __int64 *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x1
  __int64 result; // x0

  v1 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v2 = ((__int64 (__fastcall *)(__int64))v1)(a1);
  v3 = *(__int64 **)(v2 + 64);
  v4 = v2;
  v5 = v3[14];
  if ( !v5 )
    v5 = *v3;
  printk(&unk_26EB3, v5, "aw882xx_codec_remove");
  aw882xx_dev_deinit(*(_QWORD *)(v4 + 96));
  result = destroy_workqueue(*(_QWORD *)(v4 + 104));
  *(_QWORD *)(v4 + 104) = 0;
  return result;
}
