__int64 __fastcall wlan_hdd_mlo_update(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x9
  int v11; // w8
  _QWORD *v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  char v30; // w9
  char v31; // w10
  __int64 v32; // x8
  char is_mlo_vdev; // w0
  __int64 result; // x0
  const char *v35; // x2
  __int64 v36; // [xsp+0h] [xbp-10h] BYREF
  __int64 v37; // [xsp+8h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v11 = *((_DWORD *)a1 + 80);
  BYTE4(v36) = 0;
  LOBYTE(v36) = 0;
  v12 = *(_QWORD **)(v10 + 24);
  if ( v11 != 0x4000 && v11 != 0x2000 )
    goto LABEL_8;
  wlan_hdd_get_mlo_link_id(a1[304], (char *)&v36 + 4, &v36);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: MLO SAP vdev id %d, link id %d total link %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_hdd_mlo_update",
    *((unsigned __int8 *)a1 + 8),
    BYTE4(v36),
    (unsigned __int8)v36);
  if ( (_BYTE)v36 )
  {
    v29 = *(_QWORD *)(a1[4] + 1360);
    if ( v29 )
    {
      if ( *(_QWORD *)(v29 + 2232) )
      {
        if ( (mlo_ap_vdev_attach() & 1) == 0 )
        {
          v35 = "%s: MLO SAP attach fails";
          goto LABEL_16;
        }
        v30 = BYTE4(v36);
        v31 = v36;
        *((_BYTE *)a1 + 2149) = 1;
        *((_BYTE *)a1 + 2150) = v30;
        *((_BYTE *)a1 + 2151) = v31;
LABEL_8:
        v32 = a1[4];
        if ( *(_DWORD *)(v32 + 16) == 1 )
        {
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(a1[4], a2, a3, a4, a5, a6, a7, a8, a9);
          v32 = a1[4];
        }
        else
        {
          is_mlo_vdev = 0;
        }
        if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))policy_mgr_is_mlo_sap_concurrency_allowed)(
                *v12,
                is_mlo_vdev & 1,
                *(unsigned __int8 *)(v32 + 168))
            & 1) != 0 )
        {
          result = 0;
          goto LABEL_17;
        }
        v35 = "%s: MLO SAP concurrency check fails";
LABEL_16:
        qdf_trace_msg(0x33u, 2u, v35, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_mlo_update", v36, v37);
        result = 4;
        goto LABEL_17;
      }
    }
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: start 11be AP without mlo",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wlan_hdd_mlo_update",
    v36,
    v37);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
