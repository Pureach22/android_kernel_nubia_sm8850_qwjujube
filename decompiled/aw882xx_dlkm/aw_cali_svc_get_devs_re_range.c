__int64 __fastcall aw_cali_svc_get_devs_re_range(__int64 a1, __int64 a2)
{
  unsigned int list_head; // w0
  _QWORD *v5; // x9
  _QWORD *v6; // x8
  __int64 result; // x0
  __int64 v8; // x3
  __int64 *v9; // x8
  unsigned int v10; // w19
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  list_head = aw882xx_dev_get_list_head(v14);
  if ( list_head )
  {
    v9 = *(__int64 **)(a1 + 112);
    v10 = list_head;
    v11 = v9[14];
    if ( !v11 )
      v11 = *v9;
    printk(&unk_26C84, v11, "aw_cali_svc_get_devs_re_range");
    result = v10;
  }
  else
  {
    v5 = (_QWORD *)v14[0];
    v6 = *(_QWORD **)v14[0];
    if ( *(_QWORD *)v14[0] == v14[0] )
    {
      result = 0;
    }
    else
    {
      LODWORD(result) = 0;
      while ( 1 )
      {
        v8 = *((unsigned int *)v6 - 293);
        if ( (unsigned int)v8 > 7 )
          break;
        result = (unsigned int)(result + 1);
        *(_DWORD *)(a2 + 8 * v8) = *((_DWORD *)v6 - 290);
        *(_DWORD *)(a2 + 4LL * ((2 * *((_DWORD *)v6 - 293)) | 1u)) = *((_DWORD *)v6 - 291);
        v6 = (_QWORD *)*v6;
        if ( v6 == v5 )
          goto LABEL_8;
      }
      v12 = (__int64 *)*(v6 - 139);
      v13 = v12[14];
      if ( !v13 )
        v13 = *v12;
      printk(&unk_27BF5, v13, "aw_cali_svc_get_devs_re_range");
      result = 4294967274LL;
    }
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
