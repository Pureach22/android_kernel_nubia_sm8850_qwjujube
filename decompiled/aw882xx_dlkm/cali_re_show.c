__int64 __fastcall cali_re_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v4; // x8
  __int64 v5; // x21
  int devs_cali_re; // w0
  int v7; // w20
  int v8; // w0
  __int64 v9; // x21
  __int64 v10; // x0
  __int64 result; // x0
  __int64 *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+10h] [xbp-20h]
  __int64 v17; // [xsp+18h] [xbp-18h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v5 = *(_QWORD *)(v4 + 96);
  if ( (aw_cali_svc_cali_re(v5, 0, 1) & 0x80000000) != 0 )
  {
    result = 19;
    strcpy(a3, "cali Re cmd failed\n");
    goto LABEL_14;
  }
  devs_cali_re = aw_cali_svc_get_devs_cali_re(v5, (__int64)&v15, 8u);
  if ( devs_cali_re < 1 )
  {
    v12 = *(__int64 **)(v5 + 112);
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    printk(&unk_27409, v13, "cali_re_show");
    result = 14;
    strcpy(a3, "get re failed\n");
    goto LABEL_14;
  }
  v7 = devs_cali_re;
  v8 = snprintf(a3, 0x1000u, "%s:%d mOhms ", "pri_l", v15);
  v9 = v8;
  if ( v7 == 1
    || (v9 = v8 + (__int64)snprintf(&a3[v8], 4096LL - v8, "%s:%d mOhms ", "pri_r", HIDWORD(v15)), v7 == 2)
    || (v9 += snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "sec_l", v16), v7 == 3)
    || (v9 += snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "sec_r", HIDWORD(v16)), v7 == 4)
    || (v9 += snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "tert_l", v17), v7 == 5)
    || (v9 += snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "tert_r", HIDWORD(v17)), v7 == 6)
    || (v9 += snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "quat_l", v18), v7 == 7) )
  {
LABEL_12:
    result = v9 + snprintf(&a3[v9], 4096 - v9, "\n");
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v10 = snprintf(&a3[v9], 4096 - v9, "%s:%d mOhms ", "quat_r", HIDWORD(v18));
  if ( v7 == 8 )
  {
    v9 += (int)v10;
    goto LABEL_12;
  }
  __break(0x5512u);
  v14 = MEMORY[0x711BD28](v10);
  return cali_re_store(v14);
}
