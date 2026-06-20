__int64 __fastcall aw_cali_class_cali_f0_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int list_head; // w0
  __int64 v6; // x2
  int v8; // w20
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  list_head = aw882xx_dev_get_list_head(v9);
  if ( list_head )
  {
    v8 = list_head;
    printk(&unk_288F5, "aw_cali_class_cali_f0_store", v6);
    a4 = v8;
  }
  else
  {
    aw_cali_svc_cali_f0(*(_QWORD *)v9[0] - 1224LL, 0, 2);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
