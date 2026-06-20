__int64 __fastcall audpkt_chk_and_update_satellite_physical_addr(__int64 a1)
{
  __int16 v1; // w8
  __int64 result; // x0
  __int64 v4; // x0
  unsigned int v5; // w20
  unsigned int v6; // w19
  const void *v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_WORD *)(a1 + 36);
  v8[0] = 0;
  if ( (v1 & 0x1C1) != 0 )
  {
    result = 0;
  }
  else
  {
    v4 = *(unsigned int *)(a1 + 40);
    v7 = nullptr;
    result = msm_audio_get_phy_addr(v4, &v7, v8);
    if ( (result & 0x80000000) != 0 )
    {
      v6 = result;
      if ( (unsigned int)__ratelimit(
                           &audpkt_chk_and_update_satellite_physical_addr__rs,
                           "audpkt_chk_and_update_satellite_physical_addr") )
        printk(&unk_8612, "audpkt_chk_and_update_satellite_physical_addr");
      ipc_log_string(
        0,
        "[%s]: %s Get phy. address failed, ret %d\n",
        "audpkt_chk_and_update_satellite_physical_addr",
        "audpkt_chk_and_update_satellite_physical_addr",
        v6);
      result = v6;
    }
    else
    {
      if ( (audio_pkt_debug_mask & 1) != 0 )
      {
        v5 = result;
        ipc_log_string(
          0,
          "[%s]: %s physical address %pK",
          "audpkt_chk_and_update_satellite_physical_addr",
          "audpkt_chk_and_update_satellite_physical_addr",
          v7);
        result = v5;
      }
      *(_QWORD *)(a1 + 40) = v7;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
