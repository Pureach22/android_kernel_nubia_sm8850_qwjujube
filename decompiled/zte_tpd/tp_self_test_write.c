__int64 __fastcall tp_self_test_write(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  __int64 v5; // x1
  __int64 v6; // x2
  void (__fastcall *v7)(_QWORD); // x8
  __int64 v8; // x8

  v4 = tpd_cdev;
  if ( (unsigned int)tp_alloc_tp_firmware_data(0x100000) )
  {
    printk(&unk_35341, v5, v6);
    return -12;
  }
  else
  {
    v7 = *(void (__fastcall **)(_QWORD))(v4 + 3560);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != 1945898361 )
        __break(0x8228u);
      v7(v4);
    }
    v8 = tpd_cdev;
    **(_QWORD **)(tpd_cdev + 2720) = *(unsigned int *)(tpd_cdev + 1096);
    *(_DWORD *)(v8 + 1096) = 0;
  }
  return a3;
}
