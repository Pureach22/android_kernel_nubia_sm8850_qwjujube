__int64 __fastcall smem_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8

  v2 = mailbox;
  v3 = a1 + 16;
  dev = v3;
  if ( !mailbox )
  {
    v2 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 16);
    v3 = dev;
    mailbox = v2;
  }
  *(_QWORD *)mailbox = qcom_smem_state_get(v3, "smem-mailbox-smp2p-out", v2 + 8);
  if ( *(_QWORD *)mailbox >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_72FA);
    return 1;
  }
  else
  {
    read_client_info_map();
    return 0;
  }
}
