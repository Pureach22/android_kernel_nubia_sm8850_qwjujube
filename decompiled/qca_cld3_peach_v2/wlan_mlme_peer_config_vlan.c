__int64 __fastcall wlan_mlme_peer_config_vlan(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x19
  __int64 result; // x0
  __int64 v16; // [xsp+0h] [xbp-10h] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 216);
  v16 = 0;
  if ( v10 && (v11 = *(__int64 **)(v10 + 1240)) != nullptr && (v12 = *v11) != 0 )
  {
    qdf_mem_set(&v16, 8u, 0);
    BYTE6(v16) = *(_BYTE *)(a1 + 168);
    LOWORD(v16) = v16 | 0x82;
    result = wmi_send_peer_vlan_config(v12, a2, v16);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: unable to get wmi_handle",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlme_peer_config_vlan",
      v16,
      v17);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
