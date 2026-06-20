__int64 __fastcall syna_cdev_remove(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v4; // x20
  _QWORD **v5; // x21
  _QWORD *v6; // x8
  __int64 v7; // x9
  __int64 v8; // x0
  int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x20
  __int64 result; // x0
  __int64 v14; // x2

  if ( !a1 )
    return printk(&unk_31F53, "syna_cdev_remove", a3);
  mutex_lock(&qword_316D0);
  v4 = *(_QWORD **)(a1 + 1272);
  v5 = (_QWORD **)(a1 + 1272);
  if ( v4 != (_QWORD *)(a1 + 1272) )
  {
    do
    {
      v6 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v6 == v4 && (v7 = *v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        *(_QWORD *)(v7 + 8) = v6;
        *v6 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      v8 = v4[2];
      *v4 = 0xDEAD000000000100LL;
      v4[1] = 0xDEAD000000000122LL;
      kfree(v8);
      kfree(v4);
      v9 = *(_DWORD *)(a1 + 1264);
      if ( v9 )
        *(_DWORD *)(a1 + 1264) = v9 - 1;
      v4 = *v5;
    }
    while ( *v5 != v5 );
  }
  v10 = mutex_unlock(&qword_316D0);
  v11 = *(_QWORD *)(a1 + 912);
  *(_DWORD *)(a1 + 900) = 0;
  if ( v11 )
  {
    device_destroy(*(_QWORD *)(a1 + 904), *(unsigned int *)(a1 + 896));
    class_destroy(*(_QWORD *)(a1 + 904));
    cdev_del(a1 + 760);
    v10 = unregister_chrdev_region(*(unsigned int *)(a1 + 896), 1);
  }
  if ( (_BYTE)qword_31698 )
    v10 = printk(&unk_34845, "syna_tcm_buf_release", (unsigned __int8)qword_31698);
  v12 = qword_31658;
  result = syna_request_managed_device(v10);
  if ( result )
  {
    if ( v12 )
      result = devm_kfree(result, v12);
  }
  else
  {
    result = printk(&unk_3BE43, "syna_pal_mem_free", v14);
  }
  *(_QWORD *)(a1 + 904) = 0;
  qword_31660 = 0;
  LOBYTE(qword_31698) = 0;
  *(_QWORD *)(a1 + 912) = 0;
  g_cdev_data = 0;
  return result;
}
