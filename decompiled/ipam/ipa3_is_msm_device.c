__int64 ipa3_is_msm_device()
{
  unsigned int v0; // w8
  unsigned int v1; // w8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8

  v0 = *(_DWORD *)(ipa3_ctx + 32240) - 10;
  if ( v0 >= 0xF )
  {
    v3 = printk(&unk_3EFFA4, "ipa3_is_msm_device");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d unknown HW type %d\n", "ipa3_is_msm_device", 13712, *(_DWORD *)(ipa3_ctx + 32240));
        v4 = ipa3_ctx;
      }
      v6 = v4 + 32240;
      v3 = *(_QWORD *)(v6 + 1920);
      if ( v3 )
        v3 = ipc_log_string(v3, "ipa %s:%d unknown HW type %d\n", "ipa3_is_msm_device", 13712, *(_DWORD *)v6);
    }
    ((void (__fastcall *)(__int64))ipa_assert)(v3);
    LOBYTE(v1) = 0;
  }
  else
  {
    v1 = 0x776Au >> v0;
  }
  return v1 & 1;
}
