__int64 __fastcall csr_rel_wm_status_cng_cmd(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int8 v15; // w19
  __int64 v16; // x0
  __int64 active_cmd; // x0
  __int64 result; // x0
  const char *sme_msg_string; // x5
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x7
  int v29; // w8
  int v30; // w9
  int v31; // w10
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h] BYREF
  __int64 v34; // [xsp+28h] [xbp-8h]

  v15 = a2;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 21552);
  WORD2(v33) = 0;
  LODWORD(v33) = 0;
  active_cmd = wlan_serialization_get_active_cmd(v16, a2, 5u, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( active_cmd && csr_peer_mac_match_cmd(active_cmd, 1, (__int64)a3, (__int64)&v33) )
  {
    result = csr_roam_wm_status_change_complete(a1, v15);
  }
  else
  {
    sme_msg_string = mac_trace_get_sme_msg_string(a4);
    if ( a3 )
    {
      v28 = *a3;
      v29 = a3[1];
      v30 = a3[2];
      v31 = a3[5];
    }
    else
    {
      v30 = 0;
      v28 = 0;
      v29 = 0;
      v31 = 0;
    }
    result = qdf_trace_msg(
               0x34u,
               4u,
               "%s: Vdev %d, rsp %s(%d) for peer %02x:%02x:%02x:**:**:%02x , cmd not found",
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               "csr_rel_wm_status_cng_cmd",
               v15,
               sme_msg_string,
               a4,
               v28,
               v29,
               v30,
               v31,
               v32,
               v33,
               v34);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
