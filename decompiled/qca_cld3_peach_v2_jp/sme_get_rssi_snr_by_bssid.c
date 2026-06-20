__int64 __fastcall sme_get_rssi_snr_by_bssid(__int64 a1, const void *a2, _BYTE *a3, _BYTE *a4)
{
  unsigned int rssi_snr_by_bssid; // w19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x5
  __int64 v17; // x6
  int v19; // [xsp+0h] [xbp-10h] BYREF
  __int16 v20; // [xsp+4h] [xbp-Ch]
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v19 = 0;
  qdf_mem_copy(&v19, a2, 6u);
  rssi_snr_by_bssid = cm_get_rssi_snr_by_bssid(*(_QWORD *)(a1 + 21560), &v19, a3, a4);
  if ( !a4 )
  {
    v16 = 0;
    if ( a3 )
      goto LABEL_3;
LABEL_5:
    v17 = 0;
    goto LABEL_6;
  }
  v16 = (unsigned int)(char)*a4;
  if ( !a3 )
    goto LABEL_5;
LABEL_3:
  v17 = (unsigned int)(char)*a3;
LABEL_6:
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: status %d snr: %d, rssi: %d",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "sme_get_rssi_snr_by_bssid",
    rssi_snr_by_bssid,
    v16,
    v17);
  _ReadStatusReg(SP_EL0);
  return rssi_snr_by_bssid;
}
