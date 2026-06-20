__int64 __fastcall p2p_process_noa(
        __int64 **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int *v9; // x21
  __int64 v11; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w22
  __int64 v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x22
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w21
  unsigned int v52; // w0
  unsigned int v53; // w23
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 comp_private_obj; // x22
  void *v63; // x0
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v74; // [xsp+18h] [xbp-38h] BYREF
  __int64 v75; // [xsp+20h] [xbp-30h]
  __int64 v76; // [xsp+28h] [xbp-28h]
  __int64 v77; // [xsp+30h] [xbp-20h]
  __int64 v78; // [xsp+38h] [xbp-18h]
  __int64 v79; // [xsp+40h] [xbp-10h]
  __int64 v80; // [xsp+48h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v9 = (unsigned int *)a1[1];
    v11 = **a1;
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: psoc:%pK, index:%d, opps_ps:%d, ct_window:%d, num_desc:%d, vdev_id:%d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_noa",
      v11,
      *v9,
      v9[1],
      v9[2],
      v9[4],
      v9[3]);
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v11, v9[3], 15);
    if ( v12 )
    {
      v21 = *(_DWORD *)(v12 + 16);
      v22 = v12;
      qdf_trace_msg(0x4Eu, 8u, "%s: vdev mode:%d", v13, v14, v15, v16, v17, v18, v19, v20, "p2p_process_noa", v21);
      if ( v21 == 3 )
      {
        v78 = 0;
        v79 = 0;
        v76 = 0;
        v77 = 0;
        v74 = 0;
        v75 = 0;
        if ( v9 )
        {
          v31 = (_QWORD *)_qdf_mem_malloc(0x24u, "p2p_send_noa_to_pe", 431);
          if ( v31 )
          {
            v40 = (__int64)v31;
            v41 = *v31 & 0xFFFFFFFF00FFFFFFLL | (*v9 << 24);
            *v31 = v41;
            v42 = v41 & 0xFFFFFFFFFF7FFFFFLL | ((unsigned __int64)(v9[1] & 1) << 23);
            *v31 = v42;
            *v31 = v42 & 0xFFFFFFFFFF80FFFFLL | ((v9[2] & 0x7FLL) << 16);
            if ( v9[4] )
            {
              qdf_trace_msg(
                0x4Eu,
                8u,
                "%s: %d noa descriptors",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "p2p_send_noa_to_pe");
              *(_BYTE *)(v40 + 7) = v9[5];
              *(_DWORD *)(v40 + 8) = v9[6];
              *(_DWORD *)(v40 + 12) = v9[7];
              *(_DWORD *)(v40 + 16) = v9[8];
              if ( v9[4] >= 2 )
              {
                *(_BYTE *)(v40 + 23) = *((_BYTE *)v9 + 36);
                *(_DWORD *)(v40 + 24) = v9[10];
                *(_DWORD *)(v40 + 28) = v9[11];
                *(_DWORD *)(v40 + 32) = v9[12];
              }
            }
            else
            {
              qdf_trace_msg(
                0x4Eu,
                8u,
                "%s: Zero noa descriptors",
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                "p2p_send_noa_to_pe");
            }
            qdf_trace_msg(
              0x4Eu,
              8u,
              "%s: Sending P2P_NOA_ATTR_IND to pe",
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              "p2p_send_noa_to_pe");
            HIDWORD(v74) = 0;
            LOWORD(v74) = 4240;
            v75 = v40;
            v52 = scheduler_post_message_debug(
                    0x4Eu,
                    0x4Eu,
                    53,
                    (unsigned __int16 *)&v74,
                    0x1D7u,
                    (__int64)"p2p_send_noa_to_pe");
            if ( v52 )
            {
              v53 = v52;
              _qdf_mem_free(v40);
              qdf_trace_msg(
                0x4Eu,
                2u,
                "%s: post msg fail:%d",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "p2p_send_noa_to_pe",
                v53);
            }
          }
        }
        else
        {
          qdf_trace_msg(0x4Eu, 2u, "%s: noa info is null", v23, v24, v25, v26, v27, v28, v29, v30, "p2p_send_noa_to_pe");
        }
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v22, 5u);
        v63 = *(void **)(comp_private_obj + 8);
        if ( v63
          || (v63 = (void *)_qdf_mem_malloc(0x54u, "p2p_process_noa", 1674),
              (*(_QWORD *)(comp_private_obj + 8) = v63) != 0) )
        {
          qdf_mem_copy(v63, v9, 0x54u);
          v51 = 0;
        }
        else
        {
          v51 = 2;
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Eu,
          2u,
          "%s: invalid p2p vdev mode:%d",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "p2p_process_noa",
          v21);
        v51 = 4;
      }
      _qdf_mem_free((__int64)a1[1]);
      wlan_objmgr_vdev_release_ref(v22, 0xFu, v64, v65, v66, v67, v68, v69, v70, v71, v72);
    }
    else
    {
      qdf_trace_msg(0x4Eu, 2u, "%s: vdev obj is NULL", v13, v14, v15, v16, v17, v18, v19, v20, "p2p_process_noa");
      _qdf_mem_free((__int64)a1[1]);
      v51 = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x4Eu, 2u, "%s: invalid noa event", a2, a3, a4, a5, a6, a7, a8, a9, "p2p_process_noa");
    v51 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v51;
}
