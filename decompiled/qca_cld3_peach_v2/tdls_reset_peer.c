__int64 __fastcall tdls_reset_peer(
        __int64 *a1,
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
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 comp_private_obj; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x21
  _QWORD *peer; // x0
  __int64 v26; // x19
  __int64 result; // x0
  const char *v28; // x2
  const char *v29; // x2
  char v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v30[0] = 0;
  if ( !v10 )
  {
    v28 = "%s: NULL vdev";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)(v10 + 216);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v28 = "%s: can't get psoc";
LABEL_13:
    qdf_trace_msg(0, 2u, v28, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_14;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_14:
    v29 = "%s: NULL psoc object";
LABEL_15:
    qdf_trace_msg(0, 2u, v29, v16, v17, v18, v19, v20, v21, v22, v23, "tdls_reset_peer");
    result = 16;
    goto LABEL_16;
  }
  v24 = (_DWORD *)comp_private_obj;
  peer = tdls_find_peer((__int64)a1, a2);
  if ( !peer )
  {
    v29 = "%s: NULL tdls peer";
    goto LABEL_15;
  }
  v26 = (__int64)peer;
  if ( (*((_BYTE *)peer + 489) & 1) == 0 )
  {
    tdls_fill_pref_off_chan_info((__int64)a1, v24, (__int64)peer, v16, v17, v18, v19, v20, v21, v22, v23);
    *(_BYTE *)(v26 + 490) = tdls_get_opclass_from_bandwidth(
                              *a1,
                              *(unsigned int *)(v26 + 492),
                              *(_BYTE *)(v26 + 496),
                              v30);
  }
  if ( *(_BYTE *)(v26 + 672) == 1 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x: destroy  idle timer ",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "tdls_reset_peer",
      *(unsigned __int8 *)(v26 + 24),
      *(unsigned __int8 *)(v26 + 25),
      *(unsigned __int8 *)(v26 + 26),
      *(unsigned __int8 *)(v26 + 29));
    qdf_mc_timer_stop(v26 + 504);
    qdf_mc_timer_destroy(v26 + 504);
    *(_BYTE *)(v26 + 672) = 0;
  }
  tdls_set_peer_link_status(v26, 0, 0xFFFFFFFF, v16, v17, v18, v19, v20, v21, v22, v23);
  result = 0;
  *(_BYTE *)(v26 + 30) = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
