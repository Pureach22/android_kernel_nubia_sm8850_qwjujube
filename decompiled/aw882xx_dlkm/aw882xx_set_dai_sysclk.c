__int64 __fastcall aw882xx_set_dai_sysclk(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 *v7; // x8
  _DWORD *v8; // x20
  __int64 v9; // x1

  v3 = *(_QWORD *)(a1 + 96);
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v3);
  v7 = *(__int64 **)(v6 + 64);
  v8 = (_DWORD *)v6;
  v9 = v7[14];
  if ( !v9 )
    v9 = *v7;
  printk(&unk_24DE3, v9, "aw882xx_set_dai_sysclk");
  *v8 = a3;
  return 0;
}
