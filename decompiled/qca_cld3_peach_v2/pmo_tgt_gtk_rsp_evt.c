__int64 __fastcall pmo_tgt_gtk_rsp_evt(
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
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  _QWORD *comp_private_obj; // x23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int vdev_bss_peer_mac_addr; // w19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x4
  void (__fastcall *v76)(__int64, unsigned __int8 *); // x8
  __int64 v77; // x0

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_gtk_rsp_evt");
  if ( a2 )
  {
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 10);
    if ( v20 )
    {
      v29 = v20;
      comp_private_obj = (_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(v20, 4u);
      vdev_bss_peer_mac_addr = pmo_get_vdev_bss_peer_mac_addr(v29, a2 + 64, v31, v32, v33, v34, v35, v36, v37, v38);
      if ( vdev_bss_peer_mac_addr )
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: cannot find peer mac address",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "pmo_tgt_gtk_rsp_evt");
LABEL_18:
        wlan_objmgr_vdev_release_ref(v29, 0xAu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
        goto LABEL_19;
      }
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 132);
        v66 = comp_private_obj[133];
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 132);
        v66 = comp_private_obj[133] | 1LL;
        comp_private_obj[133] = v66;
      }
      comp_private_obj[123] = *((_QWORD *)a2 + 2);
      if ( (v66 & 1) != 0 )
      {
        comp_private_obj[133] = v66 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(comp_private_obj + 132);
        v75 = comp_private_obj[125];
        if ( v75 )
          goto LABEL_13;
      }
      else
      {
        raw_spin_unlock(comp_private_obj + 132);
        v75 = comp_private_obj[125];
        if ( v75 )
        {
LABEL_13:
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: callback:%pK context:%pK psoc:%pK vdev_id:%d",
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            "pmo_tgt_gtk_rsp_evt",
            v75,
            comp_private_obj[126],
            a1,
            *a2);
          v76 = (void (__fastcall *)(__int64, unsigned __int8 *))comp_private_obj[125];
          v77 = comp_private_obj[126];
          if ( *((_DWORD *)v76 - 1) != -1831738236 )
            __break(0x8228u);
          v76(v77, a2);
          goto LABEL_18;
        }
      }
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: gtk rsp callback is null for vdev_id:%d psoc %pK",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "pmo_tgt_gtk_rsp_evt",
        *a2,
        a1);
      goto LABEL_18;
    }
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is null vdev_id:%d psoc:%pK",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "pmo_tgt_gtk_rsp_evt",
      *a2,
      a1);
    vdev_bss_peer_mac_addr = 29;
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: gtk rsp param is null", v12, v13, v14, v15, v16, v17, v18, v19, "pmo_tgt_gtk_rsp_evt");
    vdev_bss_peer_mac_addr = 29;
  }
LABEL_19:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v57, v58, v59, v60, v61, v62, v63, v64, "pmo_tgt_gtk_rsp_evt");
  return vdev_bss_peer_mac_addr;
}
