__int64 __fastcall qcom_glink_native_start(_QWORD *a1)
{
  int v2; // w4
  __int64 v3; // x0
  unsigned int v4; // w20
  _QWORD *v5; // x21
  unsigned __int64 v6; // x0
  int v7; // w22
  __int64 v8; // x8
  _DWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *((_DWORD *)a1 + 52);
  v3 = a1[32];
  v10[0] = 0x10000;
  v10[1] = v2;
  ipc_log_string(v3, "[%s]: vers:%d features:%d\n", "qcom_glink_send_version", 1, v2);
  v4 = qcom_glink_tx(a1, v10, 8, 0, 0, 1);
  if ( v4 )
  {
    dev_err(*a1, "failed to send version: %d\n", v4);
    goto LABEL_9;
  }
  v5 = (_QWORD *)_kmalloc_cache_noprof(_stack_chk_fail, 3520, 992);
  if ( !v5 )
    goto LABEL_7;
  v6 = qcom_glink_alloc_channel(a1, "rpmsg_chrdev");
  v7 = v6;
  if ( v6 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(v6 + 104) = v5;
    v8 = *a1;
    v5[121] = v6;
    v5[12] = v8;
    v5[123] = &glink_device_ops;
    v5[101] = qcom_glink_device_release;
    if ( (unsigned int)rpmsg_register_device_override(v5, "rpmsg_ctrl") )
LABEL_7:
      dev_err(*a1, "failed to register chrdev\n");
  }
  else
  {
    kfree(v5);
    if ( v7 )
      goto LABEL_7;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v4;
}
