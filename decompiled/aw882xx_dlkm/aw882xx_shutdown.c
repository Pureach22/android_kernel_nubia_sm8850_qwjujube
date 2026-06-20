__int64 __fastcall aw882xx_shutdown(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(); // x9
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 *v6; // x8
  __int64 v7; // x1
  void *v8; // x0
  __int64 *v9; // x8

  v3 = off_350;
  v4 = *(_QWORD *)(a2 + 96);
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8229u);
  v5 = ((__int64 (__fastcall *)(__int64))v3)(v4);
  if ( *(_DWORD *)(a1 + 60) )
  {
    v9 = *(__int64 **)(v5 + 64);
    v7 = v9[14];
    if ( !v7 )
      v7 = *v9;
    v8 = &unk_27DE7;
  }
  else
  {
    v6 = *(__int64 **)(v5 + 64);
    *(_DWORD *)(v5 + 4) = 0;
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    v8 = &unk_27A5E;
  }
  return printk(v8, v7, "aw882xx_shutdown");
}
