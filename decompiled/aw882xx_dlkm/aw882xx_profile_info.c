__int64 __fastcall aw882xx_profile_info(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x20
  int profile_count; // w3
  unsigned int v8; // w2
  __int64 *v10; // x8
  __int64 v11; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  *(_DWORD *)(a2 + 64) = 3;
  *(_DWORD *)(a2 + 72) = 1;
  profile_count = aw882xx_dev_get_profile_count(*(_QWORD *)(v6 + 96));
  if ( profile_count <= 0 )
  {
    *(_DWORD *)(a2 + 80) = 0;
    v10 = *(__int64 **)(v6 + 64);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_260E3, v11, "aw882xx_profile_info");
  }
  else
  {
    v8 = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(a2 + 80) = profile_count;
    if ( v8 >= profile_count )
      *(_DWORD *)(a2 + 84) = profile_count - 1;
    if ( (unsigned int)aw88xx_dev_get_profile_name(*(_QWORD *)(v6 + 96), a2 + 88) )
      strcpy((char *)(a2 + 88), "null");
  }
  return 0;
}
