__int64 __fastcall aw_class_re_range_show(__int64 a1, __int64 a2, char *a3)
{
  int list_head; // w0
  __int64 v5; // x2
  __int64 v6; // x21
  int devs_re_range; // w0
  int v8; // w20
  int v9; // w0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 result; // x0
  int v14; // w20
  __int64 *v15; // x8
  __int64 v16; // x1
  __int64 *v17; // [xsp+0h] [xbp-50h] BYREF
  __int64 v18; // [xsp+8h] [xbp-48h] BYREF
  __int64 v19; // [xsp+10h] [xbp-40h]
  __int64 v20; // [xsp+18h] [xbp-38h]
  __int64 v21; // [xsp+20h] [xbp-30h]
  __int64 v22; // [xsp+28h] [xbp-28h]
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = nullptr;
  v18 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v19 = 0;
  printk(&unk_24BEA, "aw_class_re_range_show", a3);
  list_head = aw882xx_dev_get_list_head(&v17);
  if ( list_head < 0 )
  {
    v14 = list_head;
    printk(&unk_288F5, "aw_class_re_range_show", v5);
    result = v14;
    goto LABEL_13;
  }
  v6 = *v17;
  devs_re_range = aw_cali_svc_get_devs_re_range(*v17 - 1224, &v18);
  if ( devs_re_range < 1 )
  {
    v15 = *(__int64 **)(v6 - 1112);
    v16 = v15[14];
    if ( !v16 )
      v16 = *v15;
    printk(&unk_26CE5, v16, "aw_class_re_range_show");
    result = -22;
    goto LABEL_13;
  }
  v8 = devs_re_range;
  v9 = snprintf(a3, 0x1000u, "%s:re_min:%d mOhms re_max:%d mOhms ", "pri_l", v18, HIDWORD(v18));
  v10 = v9;
  if ( v8 == 1
    || (v10 = v9
            + (__int64)snprintf(&a3[v9], 4096LL - v9, "%s:re_min:%d mOhms re_max:%d mOhms ", "pri_r", v19, HIDWORD(v19)),
        v8 == 2)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "sec_l", v20, HIDWORD(v20)), v8 == 3)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "sec_r", v21, HIDWORD(v21)), v8 == 4)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "tert_l", v22, HIDWORD(v22)),
        v8 == 5)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "tert_r", v23, HIDWORD(v23)),
        v8 == 6)
    || (v10 += snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "quat_l", v24, HIDWORD(v24)),
        v8 == 7) )
  {
LABEL_12:
    result = v10 + snprintf(&a3[v10], 4096 - v10, "\n");
LABEL_13:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v11 = snprintf(&a3[v10], 4096 - v10, "%s:re_min:%d mOhms re_max:%d mOhms ", "quat_r", v25, HIDWORD(v25));
  if ( v8 == 8 )
  {
    v10 += (int)v11;
    goto LABEL_12;
  }
  __break(0x5512u);
  return aw_cali_svc_get_devs_re_range(v11, v12);
}
