__int64 init_module()
{
  __int64 v0; // x1
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v3; // [xsp+10h] [xbp-10h]
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)s = 0;
  v3 = 0;
  debug_dent = debugfs_create_dir("qcrypto", 0);
  if ( (unsigned __int64)debug_dent <= 0xFFFFFFFFFFFFF000LL )
  {
    snprintf(s, 0xFu, "stats-%d", 1);
    debug_qcrypto = 0;
    if ( !debugfs_create_file(s, 420, debug_dent) )
      debugfs_remove(debug_dent);
  }
  qword_10838 = (__int64)&qword_10838;
  qword_10840 = (__int64)&qword_10838;
  qword_10870 = (__int64)&qword_10870;
  qword_10878 = (__int64)&qword_10870;
  qword_108E0 = 0;
  dword_10834 = 0;
  _mutex_init(&unk_10888, "&pcp->engine_lock", &qcrypto_init___key);
  qword_108F0 = alloc_workqueue("qcrypto_seq_response_wq", 56, 1);
  if ( qword_108F0 )
  {
    qword_108F8 = 0xFFFFFFFE00000LL;
    qword_10900 = (__int64)&qword_10900;
    qword_10908 = (__int64)&qword_10900;
    qword_10910 = (__int64)seq_response;
    dword_10880 = 0;
    qword_108B8 = 0;
    qword_10930 = 0;
    dword_1091C = 1;
    crypto_init_queue(&unk_108C0, 768);
    result = _platform_driver_register(_qcrypto, &_this_module);
  }
  else
  {
    printk(&unk_12461, v0);
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
