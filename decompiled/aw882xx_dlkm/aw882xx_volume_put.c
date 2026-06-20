__int64 __fastcall aw882xx_volume_put(__int64 a1, __int64 a2)
{
  __int64 (*v3)(void); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v5)(); // x8
  __int64 v6; // x0
  _DWORD *v7; // x20
  __int64 *v8; // x8
  signed int v9; // w19
  __int64 v10; // x1
  __int64 v11; // x21
  unsigned int v13; // w8
  __int64 v14; // x1

  v3 = aw_componet_codec_ops[0];
  if ( *((_DWORD *)aw_componet_codec_ops[0] - 1) != 1008210333 )
    __break(0x8228u);
  v4 = v3();
  v5 = off_350;
  if ( *((_DWORD *)off_350 - 1) != -1406325950 )
    __break(0x8228u);
  v6 = ((__int64 (__fastcall *)(__int64))v5)(v4);
  v7 = *(_DWORD **)(v6 + 96);
  v8 = *(__int64 **)(v6 + 64);
  v9 = *(_DWORD *)(a2 + 72);
  v10 = v8[14];
  if ( v7[153] < v9 || v9 < 0 )
  {
    if ( !v10 )
      v10 = *v8;
    printk(&unk_27E4C, v10, "aw882xx_volume_put");
    return 4294967274LL;
  }
  else
  {
    v11 = v6;
    if ( !v10 )
      v10 = *v8;
    printk(&unk_2226B, v10, "aw882xx_volume_put");
    if ( v7[154] == v9 )
    {
      return 0;
    }
    else
    {
      v13 = v7[155];
      v7[154] = v9;
      if ( (int)v13 <= v9 )
        v14 = (unsigned int)v9;
      else
        v14 = v13;
      aw882xx_dev_set_volume(*(_QWORD *)(v11 + 96), v14);
      return 1;
    }
  }
}
