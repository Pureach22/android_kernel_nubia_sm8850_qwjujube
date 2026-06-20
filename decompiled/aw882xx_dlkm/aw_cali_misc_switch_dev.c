__int64 __fastcall aw_cali_misc_switch_dev(__int64 a1, __int64 a2, char *s)
{
  __int64 result; // x0
  int v6; // w21
  __int64 *v7; // x8
  __int64 v8; // x1
  void *v9; // x0
  unsigned int list_head; // w0
  _QWORD *v11; // x8
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 *v14; // x8
  unsigned int v15; // w20
  __int64 v16; // x1
  __int64 *v17; // x8
  _QWORD *v18; // [xsp+8h] [xbp-48h] BYREF
  _QWORD v19[6]; // [xsp+10h] [xbp-40h] BYREF
  __int16 v20; // [xsp+40h] [xbp-10h]
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  v18 = nullptr;
  if ( sscanf(s, "dev_sel:%s", v19) < 1 )
    goto LABEL_2;
  if ( strnstr(v19, "pri_l", 5) )
  {
    v6 = 0;
  }
  else if ( strnstr(v19, "pri_r", 5) )
  {
    v6 = 1;
  }
  else if ( strnstr(v19, "sec_l", 5) )
  {
    v6 = 2;
  }
  else if ( strnstr(v19, "sec_r", 5) )
  {
    v6 = 3;
  }
  else if ( strnstr(v19, "tert_l", 6) )
  {
    v6 = 4;
  }
  else if ( strnstr(v19, "tert_r", 6) )
  {
    v6 = 5;
  }
  else
  {
    v6 = 6;
    if ( !strnstr(v19, "quat_l", 6) )
    {
      if ( !strnstr(v19, "quat_r", 6) )
      {
        v7 = *(__int64 **)(a2 + 112);
        v8 = v7[14];
        if ( !v8 )
          v8 = *v7;
        v9 = &unk_223C3;
LABEL_34:
        printk(v9, v8, "aw_cali_misc_switch_dev");
LABEL_2:
        result = 4294967274LL;
        goto LABEL_3;
      }
      v6 = 7;
    }
  }
  list_head = aw882xx_dev_get_list_head(&v18);
  if ( !list_head )
  {
    v11 = v18;
    while ( 1 )
    {
      v11 = (_QWORD *)*v11;
      if ( v11 == v18 )
        break;
      if ( *((_DWORD *)v11 - 293) == v6 )
      {
        *(_QWORD *)(a1 + 32) = v11 - 153;
        v12 = (__int64 *)*(v11 - 139);
        g_dev_select = v6;
        v13 = v12[14];
        if ( !v13 )
          v13 = *v12;
        printk(&unk_28D54, v13, "aw_cali_misc_switch_dev");
        result = 0;
        goto LABEL_3;
      }
    }
    v17 = *(__int64 **)(a2 + 112);
    v8 = v17[14];
    if ( !v8 )
      v8 = *v17;
    v9 = &unk_22FC1;
    goto LABEL_34;
  }
  v14 = *(__int64 **)(a2 + 112);
  v15 = list_head;
  v16 = v14[14];
  if ( !v16 )
    v16 = *v14;
  printk(&unk_26742, v16, "aw_cali_misc_switch_dev");
  result = v15;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
