__int64 __fastcall aw_cali_svc_set_devs_re_str(__int64 a1, const char *a2)
{
  unsigned int list_head; // w0
  int v5; // w0
  _QWORD *v6; // x8
  _QWORD *v7; // x20
  unsigned int v8; // w19
  __int64 v9; // x9
  __int64 *v11; // x8
  __int64 v12; // x1
  __int64 *v13; // x8
  __int64 v14; // x1
  _QWORD *v15; // [xsp+10h] [xbp-30h] BYREF
  __int64 v16; // [xsp+18h] [xbp-28h] BYREF
  __int64 v17; // [xsp+20h] [xbp-20h] BYREF
  __int64 v18; // [xsp+28h] [xbp-18h] BYREF
  __int64 v19; // [xsp+30h] [xbp-10h] BYREF
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = nullptr;
  v16 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  list_head = aw882xx_dev_get_list_head(&v15);
  if ( list_head )
  {
    v11 = *(__int64 **)(a1 + 112);
    v8 = list_head;
    v12 = v11[14];
    if ( !v12 )
      v12 = *v11;
    printk(&unk_26C84, v12, "aw_cali_svc_set_devs_re_str");
  }
  else
  {
    v5 = sscanf(
           a2,
           "pri_l:%d pri_r:%d sec_l:%d sec_r:%d tert_l:%d tert_r:%d quat_l:%d quat_r:%d",
           &v16,
           (char *)&v16 + 4,
           &v17,
           (char *)&v17 + 4,
           &v18,
           (char *)&v18 + 4,
           &v19,
           (char *)&v19 + 4);
    if ( v5 <= 0 )
    {
      v13 = *(__int64 **)(a1 + 112);
      v8 = v5;
      v14 = v13[14];
      if ( !v14 )
        v14 = *v13;
      printk(&unk_251F9, v14, "aw_cali_svc_set_devs_re_str");
    }
    else
    {
      v6 = v15;
      v7 = (_QWORD *)*v15;
      if ( (_QWORD *)*v15 == v15 )
      {
        v8 = 0;
      }
      else
      {
        v8 = 0;
        do
        {
          v9 = *((unsigned int *)v7 - 293);
          if ( (unsigned int)v9 <= 7 )
          {
            aw_cali_store_cali_re((__int64)(v7 - 153), *((_DWORD *)&v16 + v9));
            v6 = v15;
            ++v8;
          }
          v7 = (_QWORD *)*v7;
        }
        while ( v7 != v6 );
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
