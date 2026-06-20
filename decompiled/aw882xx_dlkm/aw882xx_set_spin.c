__int64 __fastcall aw882xx_set_spin(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  __int64 v7; // x3
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 result; // x0
  __int64 *v11; // x8
  __int64 v12; // x1
  __int64 *v13; // x9
  __int64 v14; // x1
  unsigned int v15; // w19

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_QWORD *)(a2 + 72);
  v8 = v6;
  v9 = *(_QWORD *)(v6 + 96);
  if ( (v7 & 0xFFFFFFFC) != 0 )
  {
    v11 = *(__int64 **)(v9 + 112);
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    printk(&unk_27E71, v12, "aw882xx_set_spin");
    return 4294967274LL;
  }
  else
  {
    result = aw882xx_spin_value_set(v9, (unsigned int)v7, *(_DWORD *)(v8 + 8) != 0);
    if ( (_DWORD)result )
    {
      v13 = *(__int64 **)(v8 + 64);
      v14 = v13[14];
      if ( !v14 )
        v14 = *v13;
      v15 = result;
      printk(&unk_272E1, v14, "aw882xx_set_spin");
      return v15;
    }
  }
  return result;
}
