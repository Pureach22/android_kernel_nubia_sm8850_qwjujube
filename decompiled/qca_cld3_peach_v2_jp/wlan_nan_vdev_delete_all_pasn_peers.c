__int64 __fastcall wlan_nan_vdev_delete_all_pasn_peers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v9; // w9
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_BYTE *)(a1 + 104);
  v20[0] = 0x400000000000LL;
  LOBYTE(v20[0]) = v9;
  result = tgt_vdev_mgr_peer_delete_all_send(a1, (__int64)v20, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
  {
    v19 = result;
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Send vdev delete all peers failed",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_nan_vdev_delete_all_pasn_peers");
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
