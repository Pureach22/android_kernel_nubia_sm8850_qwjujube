__int64 __fastcall aw_cali_class_re_show(__int64 a1, __int64 a2, char *a3)
{
  int list_head; // w0
  __int64 v5; // x2
  __int64 v6; // x21
  int devs_cali_re; // w0
  int v8; // w20
  int v9; // w0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // w20
  __int64 *v14; // x8
  __int64 v15; // x1
  __int64 *v16; // [xsp+0h] [xbp-30h] BYREF
  __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  __int64 v18; // [xsp+10h] [xbp-20h]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = nullptr;
  v17 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  list_head = aw882xx_dev_get_list_head(&v16);
  if ( list_head )
  {
    v13 = list_head;
    printk(&unk_288F5, "aw_cali_class_re_show", v5);
    result = v13;
    goto LABEL_13;
  }
  v6 = *v16;
  devs_cali_re = aw_cali_svc_get_devs_cali_re(*v16 - 1224, (__int64)&v17, 8u);
  if ( devs_cali_re < 1 )
  {
    v14 = *(__int64 **)(v6 - 1112);
    v15 = v14[14];
    if ( !v15 )
      v15 = *v14;
    printk(&unk_2621A, v15, "aw_cali_class_re_show");
    result = 0;
    goto LABEL_13;
  }
  v8 = devs_cali_re;
  v9 = snprintf(a3, 0x1000u, "%s:%d mOhms", "pri_l", v17);
  v10 = v9;
  if ( v8 == 1
    || (v10 = v9 + (__int64)snprintf(&a3[v9], 4096LL - v9, "%s:%d mOhms", "pri_r", HIDWORD(v17)), v8 == 2)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "sec_l", v18), v8 == 3)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "sec_r", HIDWORD(v18)), v8 == 4)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "tert_l", v19), v8 == 5)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "tert_r", HIDWORD(v19)), v8 == 6)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "quat_l", v20), v8 == 7) )
  {
LABEL_12:
    result = v10 + snprintf(&a3[v10], 4096 - v10, "\n");
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = snprintf(&a3[v10], 4096 - v10, "%s:%d mOhms", "quat_r", HIDWORD(v20));
  if ( v8 == 8 )
  {
    v10 += (int)v11;
    goto LABEL_12;
  }
  __break(0x5512u);
  return aw_cali_class_f0_show(v11);
}
