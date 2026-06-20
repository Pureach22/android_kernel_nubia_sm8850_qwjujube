__int64 __fastcall aw882xx_get_spin(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 *v12; // x8
  __int64 v13; // x1
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_DWORD *)(v6 + 8);
  v8 = v6;
  v9 = *(_QWORD *)(v6 + 96);
  v14 = 0;
  if ( (unsigned int)aw882xx_spin_value_get(v9, &v14, v7 != 0) )
  {
    v12 = *(__int64 **)(v8 + 64);
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    printk(&unk_28B82, v13, "aw882xx_get_spin");
    v10 = 0;
  }
  else
  {
    v10 = v14;
  }
  *(_QWORD *)(a2 + 72) = v10;
  _ReadStatusReg(SP_EL0);
  return 0;
}
