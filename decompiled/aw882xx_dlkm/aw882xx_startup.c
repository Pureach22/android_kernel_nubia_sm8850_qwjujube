__int64 __fastcall aw882xx_startup(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v3)(); // x9
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x19

  v3 = off_350;
  v4 = *(_QWORD *)(a2 + 96);
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8229u);
  v5 = ((__int64 (__fastcall *)(__int64))v3)(v4);
  v6 = *(__int64 **)(v5 + 64);
  v7 = v6[14];
  if ( *(_DWORD *)(a1 + 60) )
  {
    if ( !v7 )
      v7 = *v6;
    printk(&unk_2503E, v7, "aw882xx_startup");
  }
  else
  {
    v8 = v5;
    if ( !v7 )
      v7 = *v6;
    printk(&unk_27DB4, v7, "aw882xx_startup");
    aw882xx_dev_init_cali_re(*(_QWORD *)(v8 + 96));
  }
  return 0;
}
