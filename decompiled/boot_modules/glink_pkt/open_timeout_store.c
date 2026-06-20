__int64 __fastcall open_timeout_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  mutex_lock(a1 + 1048);
  if ( (unsigned int)kstrtoll(a3, 0, v8) )
  {
    mutex_unlock(a1 + 1048);
    if ( (unsigned int)__ratelimit(&open_timeout_store__rs, "open_timeout_store") )
      printk(
        "%s[%s]: unable to convert string to int for /dev/%s\n",
        byte_9300,
        "open_timeout_store",
        *(const char **)(a1 + 1504));
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: unable to convert string to int for /dev/%s\n",
      (const char *)&unk_90F5,
      "open_timeout_store",
      *(const char **)(a1 + 1504));
    a4 = -22;
  }
  else
  {
    *(_DWORD *)(a1 + 1528) = v8[0];
    mutex_unlock(a1 + 1048);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
