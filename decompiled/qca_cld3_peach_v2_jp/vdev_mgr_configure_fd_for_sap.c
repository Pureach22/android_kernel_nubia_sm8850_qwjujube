__int64 __fastcall vdev_mgr_configure_fd_for_sap(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int16 *v2; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 result; // x0
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  int v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 504);
  v23 = 0;
  v22 = 0;
  v2 = *(unsigned __int16 **)(v1 + 40);
  if ( v2 && (wlan_reg_is_6ghz_chan_freq(*v2) & 1) != 0 && (!*(_DWORD *)(a1 + 440) || !*(_DWORD *)(a1 + 444)) )
  {
    v13 = *(_DWORD *)(*(_QWORD *)(a1 + 504) + 56LL);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: SAP FD enabled %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "vdev_mgr_configure_fd_for_sap",
      v13 >> 31);
    LOBYTE(v22) = *(_BYTE *)(*(_QWORD *)(a1 + 504) + 104LL);
    if ( (wlan_mlme_is_fd_disabled_in_6ghz_band() & 1) == 0 )
    {
      if ( (v13 & 0x80000000) != 0 )
      {
        HIDWORD(v22) = 20;
      }
      else if ( (*(_BYTE *)(*(_QWORD *)(a1 + 504) + 60LL) & 8) != 0 )
      {
        LOBYTE(v23) = 1;
        HIDWORD(v22) = 20;
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: SAP FD and 20TU Prb both are disabled",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "vdev_mgr_configure_fd_for_sap");
      }
    }
    result = tgt_vdev_mgr_fils_enable_send(a1, &v22);
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
