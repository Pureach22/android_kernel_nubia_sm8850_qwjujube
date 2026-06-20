__int64 __fastcall wlan_mlo_link_disable_request_handler(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x19
  unsigned int *v22; // x8
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  const char *v33; // x2
  _BYTE v34[12]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_13;
  v34[0] = 0;
  if ( !a2 )
  {
    v33 = "%s: event params is null";
LABEL_12:
    qdf_trace_msg(0x99u, 2u, v33, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_mlo_link_disable_request_handler");
LABEL_13:
    result = 29;
    goto LABEL_14;
  }
  if ( !(*(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2)) )
  {
    v33 = "%s: mld mac addr in event params is null";
    goto LABEL_12;
  }
  if ( !*((_DWORD *)a2 + 2) )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: Link id bitmap is 0, no action frame to be sent",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlo_link_disable_request_handler");
    result = 0;
    goto LABEL_14;
  }
  if ( (wlan_get_connected_vdev_by_mld_addr(a1, (__int64)a2, v34) & 1) == 0 )
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Not connected to peer MLD %02x:%02x:%02x:**:**:%02x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_mlo_link_disable_request_handler",
      *a2,
      a2[1],
      a2[2],
      a2[5]);
    result = 16;
    goto LABEL_14;
  }
  v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v34[0], 90);
  if ( !v20 )
  {
    v33 = "%s: vdev is null";
    goto LABEL_12;
  }
  v21 = v20;
  v23 = wlan_populate_link_disable_t2lm_frame(v20, a2);
  if ( v23 )
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: Failed to handle link disable",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_mlo_link_disable_request_handler");
  wlan_objmgr_vdev_release_ref(v21, 0x5Au, v22, v24, v25, v26, v27, v28, v29, v30, v31);
  result = v23;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
