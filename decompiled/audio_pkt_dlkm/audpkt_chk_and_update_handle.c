__int64 __fastcall audpkt_chk_and_update_handle(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  unsigned int handle_from_phy_addr; // w19
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 32);
  v3 = *(unsigned int *)(a1 + 40);
  v6 = 0;
  handle_from_phy_addr = msm_audio_get_handle_from_phy_addr(&v6, v2, v3);
  if ( (handle_from_phy_addr & 0x80000000) != 0 )
  {
    if ( (unsigned int)__ratelimit(&audpkt_chk_and_update_handle__rs, "audpkt_chk_and_update_handle") )
      printk(&unk_8421, "audpkt_chk_and_update_handle");
    ipc_log_string(
      0,
      "[%s]: %s Get ion mem handle failed, ret %d\n",
      "audpkt_chk_and_update_handle",
      "audpkt_chk_and_update_handle",
      handle_from_phy_addr);
  }
  else
  {
    *(_QWORD *)(a1 + 32) = v6;
  }
  _ReadStatusReg(SP_EL0);
  return handle_from_phy_addr;
}
