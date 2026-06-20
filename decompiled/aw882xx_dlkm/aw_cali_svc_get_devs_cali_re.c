__int64 __fastcall aw_cali_svc_get_devs_cali_re(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int list_head; // w0
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  __int64 result; // x0
  __int64 v10; // x3
  __int64 *v11; // x8
  unsigned int v12; // w19
  __int64 v13; // x1
  __int64 *v14; // x8
  __int64 v15; // x1
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  list_head = aw882xx_dev_get_list_head(v16);
  if ( list_head )
  {
    v11 = *(__int64 **)(a1 + 112);
    v12 = list_head;
    v13 = v11[14];
    if ( !v13 )
      v13 = *v11;
    printk(&unk_26C84, v13, "aw_cali_svc_get_devs_cali_re");
    result = v12;
  }
  else
  {
    v7 = (_QWORD *)v16[0];
    v8 = *(_QWORD **)v16[0];
    if ( *(_QWORD *)v16[0] == v16[0] )
    {
      result = 0;
    }
    else
    {
      LODWORD(result) = 0;
      while ( 1 )
      {
        v10 = *((unsigned int *)v8 - 293);
        if ( (unsigned int)v10 >= a3 )
          break;
        result = (unsigned int)(result + 1);
        *(_DWORD *)(a2 + 4 * v10) = *((_DWORD *)v8 - 143);
        v8 = (_QWORD *)*v8;
        if ( v8 == v7 )
          goto LABEL_8;
      }
      v14 = *(__int64 **)(a1 + 112);
      v15 = v14[14];
      if ( !v15 )
        v15 = *v14;
      printk(&unk_27BF5, v15, "aw_cali_svc_get_devs_cali_re");
      result = 4294967274LL;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
