__int64 sender_probe_handler()
{
  unsigned __int64 v0; // x0
  unsigned int csf_version; // w0
  __int64 (__fastcall *v2)(__int64, _DWORD *, __int64); // x0
  void (*v3)(); // x1
  unsigned int dev; // w19
  void *v6; // x0
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v7[1] = 0;
  v0 = gh_msgq_register(266);
  msgq_hdl = v0;
  if ( v0 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev = v0;
    printk(&unk_7AD3, "sender_probe_handler");
    goto LABEL_9;
  }
  csf_version = smmu_proxy_get_csf_version(v7);
  if ( csf_version )
  {
    dev = csf_version;
    v6 = &unk_773B;
LABEL_13:
    printk(v6, "sender_probe_handler");
LABEL_16:
    gh_msgq_unregister(msgq_hdl);
    goto LABEL_9;
  }
  if ( v7[0] == 2 )
  {
    v2 = nullptr;
    v3 = nullptr;
  }
  else
  {
    if ( v7[0] != 0x500000002LL )
    {
      printk(&unk_7857, "sender_probe_handler");
      dev = 0;
      goto LABEL_16;
    }
    v2 = smmu_proxy_map;
    v3 = smmu_proxy_unmap_nop;
  }
  dev = qti_smmu_proxy_register_callbacks(v2, v3);
  if ( dev )
  {
    v6 = &unk_767F;
    goto LABEL_13;
  }
  dev = smmu_proxy_create_dev((__int64)&smmu_proxy_dev_fops);
  if ( dev )
  {
    printk(&unk_7940, "sender_probe_handler");
    qti_smmu_proxy_register_callbacks(0, 0);
    goto LABEL_16;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return dev;
}
