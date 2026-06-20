__int64 __fastcall microdump_probe(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x19
  unsigned __int64 v4; // x0

  v2 = (_QWORD *)_kmalloc_cache_noprof(_stack_chk_fail, 3520, 40);
  drv = (__int64)v2;
  if ( !v2 )
    return 4294967284LL;
  *v2 = a1 + 16;
  v3 = v2;
  v2[2] = microdump_modem_ssr_notifier_nb;
  v4 = qcom_register_ssr_notifier("mpss", v2 + 2);
  v3[1] = v4;
  if ( v4 < 0xFFFFFFFFFFFFF001LL )
    return 0;
  printk(&unk_6878, v4);
  printk(&unk_689F, "microdump_probe");
  printk(&unk_682B, "microdump_probe");
  kfree(drv);
  drv = 0;
  return 4294967274LL;
}
