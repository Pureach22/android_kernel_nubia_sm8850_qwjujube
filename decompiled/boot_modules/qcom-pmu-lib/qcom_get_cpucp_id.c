unsigned __int64 qcom_get_cpucp_id()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v2; // x19

  v0 = ((__int64 (*)(void))get_event)();
  if ( v0 < 0xFFFFFFFFFFFFF001LL )
    return *(unsigned int *)(v0 + 36);
  v2 = v0;
  printk(&unk_8E1E);
  return v2;
}
