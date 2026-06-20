__int64 __fastcall aw882xx_voltage_offset_get(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x9
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x20
  void (__fastcall *v9)(__int64, int *); // x8
  __int64 *v10; // x8
  __int64 v11; // x1
  int v12; // w3
  __int64 v13; // x0
  __int64 *v14; // x8
  __int64 v15; // x1
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = aw_componet_codec_ops[0];
  v17 = -1;
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8229u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_QWORD *)(v6 + 96);
  v8 = v6;
  v9 = *(void (__fastcall **)(__int64, int *))(v7 + 1216);
  if ( v9 )
  {
    v13 = *(_QWORD *)(v6 + 96);
    if ( *((_DWORD *)v9 - 1) != 1479983538 )
      __break(0x8228u);
    v9(v13, &v17);
    if ( *(_DWORD *)(v7 + 68) )
      goto LABEL_9;
  }
  else
  {
    v10 = *(__int64 **)(v7 + 112);
    v11 = v10[14];
    if ( !v11 )
      v11 = *v10;
    printk(&unk_2768C, v11, "aw882xx_voltage_offset_get");
    v17 = 0xFFFF;
    if ( *(_DWORD *)(v7 + 68) )
    {
LABEL_9:
      v12 = *(_DWORD *)(v7 + 72);
      v17 = v12;
      goto LABEL_14;
    }
  }
  v12 = v17;
LABEL_14:
  *(_QWORD *)(a2 + 72) = v12;
  v14 = *(__int64 **)(v8 + 64);
  v15 = v14[14];
  if ( !v15 )
    v15 = *v14;
  printk(&unk_2226B, v15, "aw882xx_voltage_offset_get");
  _ReadStatusReg(SP_EL0);
  return 0;
}
