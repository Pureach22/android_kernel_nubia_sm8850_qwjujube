__int64 __fastcall ucfg_p2p_set_ps(
        __int64 a1,
        unsigned int *a2,
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
  unsigned int v20; // w21
  unsigned int *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  __int64 v39; // x27
  __int64 comp_private_obj; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w9
  unsigned int *v50; // x8
  const char *v51; // x2
  unsigned int v52; // w1
  __int64 result; // x0
  __int64 v54; // x8
  __int64 v55; // x9
  __int64 v56; // x8
  __int64 v57; // x10
  __int64 v58; // x9
  _DWORD *v59; // x8
  unsigned int v60; // w19
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  _QWORD v69[4]; // [xsp+30h] [xbp-30h] BYREF
  unsigned int v70; // [xsp+50h] [xbp-10h]
  __int64 v71; // [xsp+58h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: soc:%pK, vdev_id:%d, opp_ps:%d, ct_window:%d, count:%d, interval:%d, duration:%d, start:%d, single noa duration:"
    "%d, ps_selection:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "ucfg_p2p_set_ps",
    a1,
    *a2,
    a2[1],
    a2[2],
    a2[3],
    a2[5],
    a2[4],
    a2[8],
    a2[6],
    a2[7]);
  if ( a1 )
  {
    v20 = 0;
    while ( 1 )
    {
      v38 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v20, 15);
      if ( v38 )
      {
        v39 = v38;
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v38, 5u);
        v49 = *(_DWORD *)(v39 + 16);
        v50 = (unsigned int *)comp_private_obj;
        if ( comp_private_obj && v49 == 3 )
        {
          if ( !*(_WORD *)(comp_private_obj + 18)
            || (v50 = (unsigned int *)*(unsigned __int8 *)(comp_private_obj + 16), ((unsigned __int8)v50 & 1) != 0) )
          {
            wlan_objmgr_vdev_release_ref(v39, 0xFu, v50, v41, v42, v43, v44, v45, v46, v47, v48);
            v54 = *(_QWORD *)a2;
            v55 = *((_QWORD *)a2 + 1);
            v70 = a2[8];
            v69[0] = v54;
            v69[1] = v55;
            v56 = *((_QWORD *)a2 + 2);
            v57 = *((_QWORD *)a2 + 3);
            v58 = *(_QWORD *)(a1 + 2128);
            LODWORD(v69[0]) = v20;
            v69[2] = v56;
            v69[3] = v57;
            v59 = *(_DWORD **)(v58 + 144);
            if ( v59 )
            {
              if ( *(v59 - 1) != -25712771 )
                __break(0x8228u);
              v60 = ((__int64 (__fastcall *)(__int64, _QWORD *))v59)(a1, v69);
              qdf_trace_msg(
                0x4Eu,
                8u,
                "%s: p2p set ps vdev %d, status:%d",
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                "ucfg_p2p_set_ps",
                v20,
                v60);
              result = v60;
            }
            else
            {
              result = 16;
            }
            goto LABEL_15;
          }
          qdf_trace_msg(
            0x4Eu,
            8u,
            "%s: non_p2p_peer_count: %u, noa_status: %d",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "is_p2p_ps_allowed");
        }
        else
        {
          qdf_trace_msg(
            0x4Eu,
            2u,
            "%s: p2p_vdev_obj:%pK is_p2pgo:%u",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "is_p2p_ps_allowed",
            comp_private_obj,
            v49 == 3);
        }
        wlan_objmgr_vdev_release_ref(v39, 0xFu, v21, v22, v23, v24, v25, v26, v27, v28, v29);
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: skip p2p set ps vdev %d, NoA is disabled as legacy STA is connected to GO.",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "ucfg_p2p_set_ps",
          v20);
      }
      if ( ++v20 == 6 )
      {
        v51 = "%s: No GO found!";
        v52 = 8;
        goto LABEL_14;
      }
    }
  }
  v51 = "%s: psoc context passed is NULL";
  v52 = 2;
LABEL_14:
  qdf_trace_msg(0x4Eu, v52, v51, v12, v13, v14, v15, v16, v17, v18, v19, "ucfg_p2p_set_ps");
  result = 4;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
