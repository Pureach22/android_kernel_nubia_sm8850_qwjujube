__int64 rmnet_ctl_probe()
{
  __int64 v0; // x1
  __int64 v1; // x2

  qword_6AE8 = 0;
  qword_6AF0 = 0;
  qword_6AD8 = 0;
  qword_6AE0 = 0;
  qword_6AC8 = 0;
  qword_6AD0 = 0;
  ctl_ipa_dev = (__int64)rmnet_ctl_send_ipa;
  rmnet_ctl_endpoint_setdev();
  return printk(&unk_69C3, v0, v1);
}
