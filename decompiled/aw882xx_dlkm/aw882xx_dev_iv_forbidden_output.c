__int64 __fastcall aw882xx_dev_iv_forbidden_output(__int64 result, char a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w8
  unsigned int v4; // w8
  __int64 v5; // x10
  _DWORD *v6; // x11
  __int64 v7; // x2
  __int64 v8; // x3
  char v9; // w19
  __int64 v10; // x20
  __int64 v11; // x0
  __int64 *v12; // x9
  __int64 v13; // x1
  __int64 v14; // x10
  _DWORD *v15; // x11
  __int64 v16; // x2
  __int64 v17; // x3
  char v18; // w19
  __int64 v19; // x20
  __int64 v20; // x0
  __int64 *v21; // x9
  __int64 v22; // x1
  __int64 v23; // x10
  _DWORD *v24; // x11
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 *v29; // x9
  __int64 v30; // x1

  v2 = *(_DWORD *)(result + 1048);
  if ( v2 != 255 )
  {
    v5 = 1056;
    if ( (a2 & 1) == 0 )
      v5 = 1060;
    v6 = *(_DWORD **)(result + 1168);
    v7 = *(unsigned int *)(result + 1052);
    v8 = *(unsigned int *)(result + v5);
    v9 = a2;
    v10 = result;
    v11 = *(_QWORD *)(result + 120);
    if ( *(v6 - 1) != 370515439 )
      __break(0x822Bu);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v6)(v11, v2, v7, v8);
    v12 = *(__int64 **)(v10 + 112);
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    printk(&unk_25B06, v13, "aw_dev_switch");
    result = v10;
    a2 = v9;
  }
  v3 = *(_DWORD *)(result + 1072);
  if ( v3 != 255 )
  {
    v14 = 1080;
    if ( (a2 & 1) == 0 )
      v14 = 1084;
    v15 = *(_DWORD **)(result + 1168);
    v16 = *(unsigned int *)(result + 1076);
    v17 = *(unsigned int *)(result + v14);
    v18 = a2;
    v19 = result;
    v20 = *(_QWORD *)(result + 120);
    if ( *(v15 - 1) != 370515439 )
      __break(0x822Bu);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v15)(v20, v3, v16, v17);
    v21 = *(__int64 **)(v19 + 112);
    v22 = v21[14];
    if ( !v22 )
      v22 = *v21;
    printk(&unk_25B06, v22, "aw_dev_switch");
    result = v19;
    a2 = v18;
  }
  v4 = *(_DWORD *)(result + 1096);
  if ( v4 != 255 )
  {
    v23 = 1104;
    if ( (a2 & 1) == 0 )
      v23 = 1108;
    v24 = *(_DWORD **)(result + 1168);
    v25 = *(unsigned int *)(result + 1100);
    v26 = *(unsigned int *)(result + v23);
    v27 = result;
    v28 = *(_QWORD *)(result + 120);
    if ( *(v24 - 1) != 370515439 )
      __break(0x822Bu);
    ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v24)(v28, v4, v25, v26);
    v29 = *(__int64 **)(v27 + 112);
    v30 = v29[14];
    if ( !v30 )
      v30 = *v29;
    return printk(&unk_25B06, v30, "aw_dev_switch");
  }
  return result;
}
