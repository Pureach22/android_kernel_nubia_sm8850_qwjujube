__int64 __fastcall _wma_handle_vdev_stop_rsp(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  __int64 *v11; // x20
  bool v12; // zf
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  __int64 v22; // x21
  int v23; // w8
  unsigned int bss_peer_mac; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // [xsp+0h] [xbp-10h] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"__wma_handle_vdev_stop_rsp", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v11 = context;
    WORD2(v42) = 0;
    LODWORD(v42) = 0;
    v12 = (unsigned int)cds_get_conparam() == 4;
    result = 0;
    if ( !v12 )
    {
      v22 = v11[65] + 488LL * *a1;
      v23 = *(unsigned __int8 *)(v22 + 210);
      *(_BYTE *)(v22 + 432) = 0;
      if ( v23 )
      {
        *(_BYTE *)(v22 + 210) = 0;
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Reset rmfEnabled for vdev %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "__wma_handle_vdev_stop_rsp",
          *a1,
          v42,
          v43);
      }
      if ( (*(_DWORD *)(*(_QWORD *)v22 + 16LL) & 0xFFFFFFFD) != 0 )
      {
        result = wma_delete_peer_on_vdev_stop(v11, *a1, v13, v14, v15, v16, v17, v18, v19, v20);
      }
      else
      {
        bss_peer_mac = wlan_vdev_get_bss_peer_mac(*(_QWORD *)v22, &v42, v13, v14, v15, v16, v17, v18, v19, v20);
        if ( bss_peer_mac )
        {
          v33 = bss_peer_mac;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Failed to get bssid, peer might have got deleted already",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "__wma_handle_vdev_stop_rsp");
          result = wlan_cm_bss_peer_delete_rsp(*(_QWORD *)v22, v33, v34, v35, v36, v37, v38, v39, v40, v41);
        }
        else
        {
          result = wlan_cm_bss_peer_delete_ind(
                     *(_QWORD *)v22,
                     (unsigned __int8 *)&v42,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     v31,
                     v32);
        }
      }
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
