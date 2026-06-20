__int64 __fastcall aw_reg_write_spin(__int64 a1, unsigned int a2, char a3)
{
  unsigned int list_head; // w0
  _QWORD *v7; // x23
  __int64 result; // x0
  _QWORD *v9; // x23
  __int64 v10; // x9
  __int64 v11; // x10
  int v12; // w8
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64); // x9
  __int64 v14; // x3
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x0
  unsigned int v18; // w0
  __int64 *v19; // x8
  unsigned int v20; // w19
  __int64 v21; // x1
  void *v22; // x0
  __int64 **v23; // x20
  __int64 *v24; // x8
  __int64 v25; // x1
  _QWORD *v26; // [xsp+0h] [xbp-30h] BYREF
  __int64 v27; // [xsp+8h] [xbp-28h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  __int64 v29; // [xsp+18h] [xbp-18h]
  int v30; // [xsp+20h] [xbp-10h]
  __int64 v31; // [xsp+28h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = nullptr;
  list_head = aw882xx_dev_get_list_head(&v26);
  if ( list_head )
  {
    v19 = *(__int64 **)(a1 + 112);
    v20 = list_head;
    v21 = v19[14];
    if ( !v21 )
      v21 = *v19;
    v22 = &unk_26C84;
LABEL_29:
    printk(v22, v21, "aw_reg_write_spin");
    result = v20;
    goto LABEL_20;
  }
  if ( g_spin_mode == 3 && (a3 & 1) != 0 )
  {
    v7 = v26;
    while ( 1 )
    {
      v7 = (_QWORD *)*v7;
      if ( v7 == v26 )
        break;
      result = aw882xx_dsp_set_mixer_en((__int64)(v7 - 153), 1);
      if ( (_DWORD)result )
        goto LABEL_20;
    }
  }
  usleep_range_state(100000, 100010, 2);
  v9 = (_QWORD *)*v26;
  if ( (_QWORD *)*v26 != v26 )
  {
    while ( 1 )
    {
      v10 = *(v9 - 36);
      v11 = *(v9 - 35);
      v12 = *((_DWORD *)v9 - 66);
      v29 = *(v9 - 34);
      v27 = v10;
      v28 = v11;
      v30 = v12;
      if ( a2 >= 4 )
        __break(0x5512u);
      v13 = (__int64 (__fastcall *)(__int64, __int64, __int64, __int64))*(v9 - 7);
      v14 = *((unsigned __int16 *)&v27 + a2 + 2);
      v15 = HIDWORD(v28);
      v16 = (unsigned int)v29;
      v17 = *(v9 - 138);
      if ( *((_DWORD *)v13 - 1) != 370515439 )
        __break(0x8229u);
      v18 = v13(v17, v15, v16, v14);
      if ( (v18 & 0x80000000) != 0 )
        break;
      if ( g_spin_mode == 3 && (a3 & 1) != 0 )
      {
        result = aw882xx_dsp_set_mixer_en(a1, 0);
        if ( (_DWORD)result )
          goto LABEL_20;
      }
      v9 = (_QWORD *)*v9;
      if ( v9 == v26 )
        goto LABEL_19;
    }
    v23 = (__int64 **)(v9 - 139);
    v20 = v18;
    v24 = (__int64 *)*(v9 - 139);
    v25 = v24[14];
    if ( !v25 )
      v25 = *v24;
    printk(&unk_258B8, v25, "aw_dev_set_channal_mode");
    v21 = (*v23)[14];
    if ( !v21 )
      v21 = **v23;
    v22 = &unk_26006;
    goto LABEL_29;
  }
LABEL_19:
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
