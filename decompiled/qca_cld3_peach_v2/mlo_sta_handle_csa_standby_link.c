__int64 __fastcall mlo_sta_handle_csa_standby_link(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x23
  __int64 v13; // x19
  __int64 v14; // x26
  __int64 ap_link_by_link_id; // x0
  __int64 v20; // x4
  __int64 v21; // x20
  const char *v22; // x2
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w10
  int v33; // w11
  int v34; // w12
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int (__fastcall *v51)(__int64, __int64 *); // x8
  const char *v52; // x2
  __int64 v53; // [xsp+28h] [xbp-38h]
  __int64 v54; // [xsp+30h] [xbp-30h] BYREF
  __int64 v55; // [xsp+38h] [xbp-28h]
  __int64 v56; // [xsp+40h] [xbp-20h]
  __int64 v57; // [xsp+48h] [xbp-18h]
  __int64 v58; // [xsp+50h] [xbp-10h]
  __int64 v59; // [xsp+58h] [xbp-8h]

  v59 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v57 = 0;
  v58 = 0;
  v55 = 0;
  v56 = 0;
  v54 = 0;
  if ( !a1 )
  {
    v22 = "%s: invalid mlo_dev_ctx";
LABEL_11:
    qdf_trace_msg(0x8Fu, 2u, v22, a5, a6, a7, a8, a9, a10, a11, a12, "mlo_sta_handle_csa_standby_link");
    goto LABEL_12;
  }
  v12 = *(_QWORD *)(a4 + 216);
  if ( !v12 )
  {
    v22 = "%s: null pdev";
    goto LABEL_11;
  }
  v13 = *(_QWORD *)(v12 + 80);
  if ( !v13 )
  {
    v22 = "%s: null psoc";
    goto LABEL_11;
  }
  v14 = *(_QWORD *)(v13 + 2128);
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(a1, (unsigned __int8)a2);
  if ( !ap_link_by_link_id )
  {
    v22 = "%s: link info null";
    goto LABEL_11;
  }
  v20 = *(unsigned __int8 *)(ap_link_by_link_id + 12);
  v21 = ap_link_by_link_id;
  if ( (_DWORD)v20 == 255 )
  {
    mlo_mgr_update_csa_link_info(v12, a1, a3, a2);
    result = mlo_mgr_standby_link_csa_notify(v21 + 24);
    if ( (_DWORD)result )
      goto LABEL_13;
    LOBYTE(v54) = *(_BYTE *)(v21 + 6);
    v57 = _qdf_mem_malloc(0x28u, "mlo_sta_handle_csa_standby_link", 2565);
    if ( !v57 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: no mem allocated",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "mlo_sta_handle_csa_standby_link");
      result = 2;
      goto LABEL_13;
    }
    wlan_vdev_get_bss_peer_mld_mac(a4, (char *)&v54 + 1, v24, v25, v26, v27, v28, v29, v30, v31);
    LOBYTE(v58) = 0;
    *(_WORD *)v57 = **(_WORD **)(v21 + 32);
    v32 = SBYTE2(v54);
    v33 = SBYTE3(v54);
    v34 = SBYTE6(v54);
    *(_DWORD *)(v57 + 16) = *(_DWORD *)(*(_QWORD *)(v21 + 32) + 16LL);
    *(_DWORD *)(v57 + 20) = *(_DWORD *)(*(_QWORD *)(v21 + 32) + 20LL);
    *(_DWORD *)(v57 + 28) = *(_DWORD *)(*(_QWORD *)(v21 + 32) + 28LL);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link id %d chan freq %d cfreq1 %d cfreq2 %d host phymode %d ap mld mac %02x:%02x:%02x:**:**:%02x",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "mlo_sta_handle_csa_standby_link",
      *(unsigned __int8 *)(v21 + 6),
      **(unsigned __int16 **)(v21 + 32),
      *(unsigned int *)(*(_QWORD *)(v21 + 32) + 16LL),
      *(unsigned int *)(*(_QWORD *)(v21 + 32) + 20LL),
      *(_DWORD *)(*(_QWORD *)(v21 + 32) + 28LL),
      SBYTE1(v54),
      v32,
      v33,
      v34,
      v53,
      v54,
      v55,
      v56);
    v51 = *(unsigned int (__fastcall **)(__int64, __int64 *))(v14 + 2016);
    if ( v51 )
    {
      if ( *((_DWORD *)v51 - 1) != -82738735 )
        __break(0x8228u);
      if ( !v51(v13, &v54) )
      {
        _qdf_mem_free(v57);
        result = 0;
        goto LABEL_13;
      }
      v52 = "%s: failed to send link set bss request command to FW";
    }
    else
    {
      v52 = "%s: handler is not registered";
    }
    qdf_trace_msg(0x8Fu, 2u, v52, v43, v44, v45, v46, v47, v48, v49, v50, "mlo_sta_handle_csa_standby_link");
    _qdf_mem_free(v57);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: vdev id %d link id %d ",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlo_sta_handle_csa_standby_link",
      v20,
      (unsigned __int8)a2);
  }
LABEL_12:
  result = 29;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
