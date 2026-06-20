__int64 __fastcall microdump_modem_ssr_notifier_nb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x0
  __int64 v4; // x2
  unsigned __int64 v5; // x0
  __int64 v6; // x2
  _QWORD v8[2]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v9; // [xsp+18h] [xbp-68h] BYREF
  __int64 v10; // [xsp+20h] [xbp-60h] BYREF
  __int64 v11; // [xsp+28h] [xbp-58h] BYREF
  _QWORD *v12; // [xsp+30h] [xbp-50h]
  __int64 v13; // [xsp+38h] [xbp-48h]
  unsigned __int64 v14; // [xsp+40h] [xbp-40h]
  __int64 v15; // [xsp+48h] [xbp-38h]
  __int64 v16; // [xsp+50h] [xbp-30h] BYREF
  _QWORD *v17; // [xsp+58h] [xbp-28h]
  __int64 v18; // [xsp+60h] [xbp-20h]
  unsigned __int64 v19; // [xsp+68h] [xbp-18h]
  __int64 v20; // [xsp+70h] [xbp-10h]
  __int64 v21; // [xsp+78h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 2 && *(_BYTE *)(a3 + 8) == 1 )
  {
    v9 = 0;
    v10 = 0;
    v8[0] = v8;
    v8[1] = v8;
    v11 = 0;
    v12 = nullptr;
    v13 = 0;
    v14 = 0;
    v15 = 0;
    v16 = 0;
    v17 = nullptr;
    v18 = 0;
    v19 = 0;
    v20 = 0;
    v3 = qcom_smem_get(1, 611, &v9);
    if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
    {
      v4 = v8[0];
      v14 = v3;
      v15 = v9;
      if ( (__int64 *)v8[0] == &v11 || *(_QWORD **)(v8[0] + 8LL) != v8 )
      {
        _list_add_valid_or_report(&v11, v8);
      }
      else
      {
        *(_QWORD *)(v8[0] + 8LL) = &v11;
        v11 = v4;
        v12 = v8;
        v8[0] = &v11;
      }
      v5 = qcom_smem_get(0xFFFFFFFFLL, 421, &v10);
      if ( v5 )
      {
        if ( v5 >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_6718, "microdump_crash_collection");
        }
        else
        {
          v6 = v8[0];
          v19 = v5;
          v20 = v10;
          if ( *(_QWORD **)(v8[0] + 8LL) != v8 || (__int64 *)v8[0] == &v16 )
          {
            _list_add_valid_or_report(&v16, v8);
          }
          else
          {
            *(_QWORD *)(v8[0] + 8LL) = &v16;
            v16 = v6;
            v17 = v8;
            v8[0] = &v16;
          }
          if ( enable_microdump )
          {
            start_qcomdump = 1;
            if ( (unsigned int)qcom_dump(v8, *(_QWORD *)drv) )
              printk(&unk_67F6, "microdump_crash_collection");
            start_qcomdump = 0;
          }
          else
          {
            printk(&unk_678E, "microdump_crash_collection");
          }
        }
      }
      else
      {
        printk(&unk_6777, "microdump_crash_collection");
      }
    }
    else
    {
      printk(&unk_68D3, "microdump_crash_collection");
    }
  }
  _ReadStatusReg(SP_EL0);
  return 1;
}
