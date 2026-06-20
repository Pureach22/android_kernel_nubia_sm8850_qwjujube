__int64 __fastcall aw_cali_svc_get_devs_cali_f0_q(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int list_head; // w0
  _QWORD *v9; // x8
  _QWORD *v10; // x26
  unsigned int v11; // w19
  __int64 v12; // x3
  __int64 *v13; // x8
  __int64 v14; // x1
  __int64 *v16; // x8
  __int64 v17; // x1
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  list_head = aw882xx_dev_get_list_head(v18);
  if ( list_head )
  {
    v16 = *(__int64 **)(a1 + 112);
    v11 = list_head;
    v17 = v16[14];
    if ( !v17 )
      v17 = *v16;
    printk(&unk_26C84, v17, "aw_cali_svc_get_devs_cali_f0_q");
  }
  else
  {
    v9 = (_QWORD *)v18[0];
    v10 = *(_QWORD **)v18[0];
    if ( *(_QWORD *)v18[0] == v18[0] )
    {
      v11 = 0;
    }
    else
    {
      v11 = 0;
      do
      {
        v12 = *((unsigned int *)v10 - 293);
        if ( (unsigned int)v12 >= a4 )
        {
          v13 = *(__int64 **)(a1 + 112);
          v14 = v13[14];
          if ( !v14 )
            v14 = *v13;
          printk(&unk_27BF5, v14, "aw_cali_svc_get_devs_cali_f0_q");
          v9 = (_QWORD *)v18[0];
        }
        else
        {
          ++v11;
          *(_DWORD *)(a2 + 4 * v12) = *((_DWORD *)v10 - 142);
          *(_DWORD *)(a3 + 4LL * *((unsigned int *)v10 - 293)) = *((_DWORD *)v10 - 141);
        }
        v10 = (_QWORD *)*v10;
      }
      while ( v10 != v9 );
    }
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
