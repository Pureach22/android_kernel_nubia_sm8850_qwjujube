__int64 __fastcall aw_cali_svc_get_devs_cali_f0(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int list_head; // w0
  _QWORD *v7; // x8
  _QWORD *v8; // x25
  unsigned int v9; // w19
  __int64 v10; // x3
  __int64 *v11; // x8
  __int64 v12; // x1
  __int64 *v14; // x8
  __int64 v15; // x1
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  list_head = aw882xx_dev_get_list_head(v16);
  if ( list_head )
  {
    v14 = *(__int64 **)(a1 + 112);
    v9 = list_head;
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    printk(&unk_26C84, v15, "aw_cali_svc_get_devs_cali_f0");
  }
  else
  {
    v7 = (_QWORD *)v16[0];
    v8 = *(_QWORD **)v16[0];
    if ( *(_QWORD *)v16[0] == v16[0] )
    {
      v9 = 0;
    }
    else
    {
      v9 = 0;
      do
      {
        v10 = *((unsigned int *)v8 - 293);
        if ( (unsigned int)v10 >= a3 )
        {
          v11 = *(__int64 **)(a1 + 112);
          v12 = v11[14];
          if ( !v12 )
            v12 = *v11;
          printk(&unk_27BF5, v12, "aw_cali_svc_get_devs_cali_f0");
          v7 = (_QWORD *)v16[0];
        }
        else
        {
          ++v9;
          *(_DWORD *)(a2 + 4 * v10) = *((_DWORD *)v8 - 142);
        }
        v8 = (_QWORD *)*v8;
      }
      while ( v8 != v7 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
