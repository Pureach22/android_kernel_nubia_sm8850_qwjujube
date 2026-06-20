__int64 __fastcall glink_pkt_release_device(__int64 a1)
{
  unsigned __int64 StatusReg; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    glink_pkt_ilctxt,
    "[%s]: for %s by %s:%d ref_cnt[%d]\n",
    "glink_pkt_release_device",
    *(const char **)(a1 + 1512),
    (const char *)(StatusReg + 2320),
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(a1 + 1128));
  ida_free(&glink_pkt_minor_ida, *(_DWORD *)(a1 + 760) & 0xFFFFF);
  cdev_del(a1 + 912);
  return kfree(a1);
}
