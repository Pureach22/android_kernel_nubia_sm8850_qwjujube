__int64 __fastcall aw_cali_misc_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x2
  _QWORD *v4; // x14
  _DWORD *v5; // x11
  _QWORD *v6; // x13
  __int64 v7; // x8
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  if ( (unsigned int)aw882xx_dev_get_list_head(v9) )
  {
    printk(&unk_288F5, "aw_cali_misc_open", v3);
    *(_QWORD *)(a2 + 32) = 0;
    result = 4294967274LL;
  }
  else
  {
    if ( *(_QWORD *)v9[0] == v9[0] )
      goto LABEL_11;
    v4 = *(_QWORD **)v9[0];
    do
    {
      v5 = (_DWORD *)v4 - 293;
      v6 = v4;
      if ( *((_DWORD *)v4 - 293) == g_dev_select )
        break;
      v4 = (_QWORD *)*v4;
    }
    while ( *v6 != v9[0] );
    if ( v6 == &qword_4C8 )
    {
LABEL_11:
      printk(&unk_28D7A, "aw_cali_misc_open", (unsigned int)g_dev_select);
      result = 4294967274LL;
    }
    else
    {
      v7 = *(_QWORD *)v9[0] - 1224LL;
      result = 0;
      if ( *v5 == g_dev_select )
        v7 = (__int64)(v6 - 153);
      *(_QWORD *)(a2 + 32) = v7;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
