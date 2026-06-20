__int64 __fastcall aw_cali_class_cali_re_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  int list_head; // w0
  __int64 v7; // x2
  __int64 v8; // x21
  int v10; // w21
  __int64 *v11; // x8
  __int64 v12; // x1
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  list_head = aw882xx_dev_get_list_head(v13);
  if ( list_head )
  {
    v10 = list_head;
    printk(&unk_288F5, "aw_cali_class_cali_re_store", v7);
    a4 = v10;
  }
  else
  {
    v8 = *(_QWORD *)v13[0];
    if ( (int)aw_cali_svc_set_devs_re_str(*(_QWORD *)v13[0] - 1224LL, a3) <= 0 )
    {
      v11 = *(__int64 **)(v8 - 1112);
      v12 = v11[14];
      if ( !v12 )
        v12 = *v11;
      printk(&unk_23797, v12, "aw_cali_class_cali_re_store");
      a4 = -1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
