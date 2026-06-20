__int64 __fastcall qcom_rproc_shutdown_request_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  char v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v5 = kstrtobool(a3, v7);
  if ( v5 )
  {
    a4 = v5;
  }
  else
  {
    qcom_device_shutdown_in_progress = v7[0];
    printk(&unk_8491);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
