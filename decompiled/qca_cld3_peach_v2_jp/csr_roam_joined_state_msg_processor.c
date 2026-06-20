__int64 __fastcall csr_roam_joined_state_msg_processor(
        _QWORD *a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  __int64 v13; // x0
  unsigned __int16 v14; // w9
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  __int64 v24; // x0
  __int64 v25; // x21
  int opmode_from_vdev_id; // w0
  int v27; // w23
  char v28; // w9
  char v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x10
  __int64 v39; // x11
  __int64 v40; // x12
  __int64 v41; // x11
  __int64 v42; // x8
  __int64 v43; // x10
  __int64 v44; // x9
  int v45; // w8
  __int64 v46; // x8
  _DWORD *v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 result; // x0
  int v59; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v60; // [xsp+4h] [xbp-Ch]
  unsigned __int8 v61; // [xsp+6h] [xbp-Ah]
  __int64 v62; // [xsp+8h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  if ( v12 == 5262 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Invoke SAE callback",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "csr_roam_joined_state_msg_processor");
    result = csr_sae_callback(a1, (__int64)a2, v50, v51, v52, v53, v54, v55, v56, v57);
  }
  else
  {
    if ( v12 == 5158 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: ASSOCIATION confirmation can be given to upper layer ",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "csr_roam_joined_state_msg_processor");
      v13 = a1[2695];
      v14 = a2[8];
      v59 = *((_DWORD *)a2 + 3);
      v60 = v14;
      v61 = 6;
      wlan_objmgr_pdev_iterate_obj_list(
        v13,
        2,
        (void (__fastcall *)(__int64, __int64, __int64))csr_get_vdev_id_from_bssid,
        (__int64)&v59,
        0,
        0xBu);
      if ( v61 <= 5u )
        v23 = v61;
      else
        v23 = 0;
      if ( a1[2153] + 96LL * v23 )
      {
        v24 = _qdf_mem_malloc(0x180u, "csr_roam_joined_state_msg_processor", 3337);
        if ( v24 )
        {
          v25 = v24;
          opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(a1[2695], v23);
          *(_DWORD *)(v25 + 32) = 0;
          v27 = opmode_from_vdev_id;
          *(_BYTE *)(v25 + 41) = *((_BYTE *)a2 + 24);
          v28 = *((_BYTE *)a2 + 28);
          *(_QWORD *)(v25 + 48) = a2 + 15;
          *(_BYTE *)(v25 + 43) = v28;
          v29 = *((_BYTE *)a2 + 288);
          *(_QWORD *)(v25 + 64) = a2 + 145;
          *(_BYTE *)(v25 + 56) = v29;
          *(_BYTE *)(v25 + 72) = *((_BYTE *)a2 + 548);
          *(_QWORD *)(v25 + 80) = a2 + 275;
          qdf_mem_copy((void *)(v25 + 23), a2 + 9, 6u);
          qdf_mem_copy((void *)(v25 + 17), a2 + 6, 6u);
          *(_BYTE *)(v25 + 96) = *((_BYTE *)a2 + 26) != 0;
          *(_BYTE *)(v25 + 136) = *((_BYTE *)a2 + 2601);
          qdf_mem_copy((void *)(v25 + 140), a2 + 1302, 0x28u);
          *(_BYTE *)(v25 + 274) = *((_BYTE *)a2 + 2645);
          *(_BYTE *)(v25 + 275) = *((_BYTE *)a2 + 2646);
          *(_BYTE *)(v25 + 276) = *((_BYTE *)a2 + 2647);
          *(_BYTE *)(v25 + 277) = *((_BYTE *)a2 + 2656);
          *(_DWORD *)(v25 + 280) = *((_DWORD *)a2 + 662);
          *(_DWORD *)(v25 + 284) = *((_DWORD *)a2 + 663);
          *(_BYTE *)(v25 + 288) = *((_BYTE *)a2 + 2657);
          *(_BYTE *)(v25 + 289) = *((_BYTE *)a2 + 2658);
          *(_BYTE *)(v25 + 291) = *((_BYTE *)a2 + 2659);
          *(_BYTE *)(v25 + 290) = *((_BYTE *)a2 + 2660);
          *(_BYTE *)(v25 + 292) = *((_BYTE *)a2 + 2661);
          *(_BYTE *)(v25 + 293) = *((_BYTE *)a2 + 2662);
          *(_BYTE *)(v25 + 294) = *((_BYTE *)a2 + 2663);
          *(_DWORD *)(v25 + 296) = *((_DWORD *)a2 + 666);
          *(_BYTE *)(v25 + 300) = *((_BYTE *)a2 + 2668);
          if ( *((_BYTE *)a2 + 2688) )
          {
            v38 = *((_QWORD *)a2 + 338);
            v39 = *((_QWORD *)a2 + 336);
            v40 = *((_QWORD *)a2 + 337);
            *(_QWORD *)(v25 + 220) = *((_QWORD *)a2 + 339);
            *(_QWORD *)(v25 + 212) = v38;
            *(_QWORD *)(v25 + 204) = v40;
            *(_QWORD *)(v25 + 196) = v39;
            v41 = *((_QWORD *)a2 + 340);
            v42 = *((_QWORD *)a2 + 341);
            v43 = *((_QWORD *)a2 + 342);
            *(_DWORD *)(v25 + 252) = *((_DWORD *)a2 + 686);
            *(_QWORD *)(v25 + 228) = v41;
            *(_QWORD *)(v25 + 244) = v43;
            *(_QWORD *)(v25 + 236) = v42;
          }
          if ( *((_BYTE *)a2 + 2748) )
          {
            v44 = *(_QWORD *)(a2 + 1378);
            *(_QWORD *)(v25 + 256) = *(_QWORD *)(a2 + 1374);
            *(_QWORD *)(v25 + 264) = v44;
          }
          *(_WORD *)(v25 + 316) = a2[1382];
          *(_BYTE *)(v25 + 272) = *((_BYTE *)a2 + 2766);
          *(_BYTE *)(v25 + 273) = *((_BYTE *)a2 + 2767);
          if ( (v27 & 0xFFFFFFFD) == 1 )
          {
            v45 = *((_DWORD *)a2 + 668);
            if ( v45 )
            {
              *(_DWORD *)(v25 + 112) = v45;
              *(_QWORD *)(v25 + 120) = *((_QWORD *)a2 + 335);
            }
            *(_DWORD *)(a1[2153] + 96LL * v23 + 4) = 4;
            *(_BYTE *)(v25 + 16) = *((_BYTE *)a2 + 2600) != 0;
            *(_BYTE *)(v25 + 376) = *((_BYTE *)a2 + 2768);
            *(_BYTE *)(v25 + 377) = *((_BYTE *)a2 + 2769);
            *(_WORD *)(v25 + 378) = a2[1385];
            if ( a1 && (v46 = a1[2153]) != 0 && (*(_BYTE *)(v46 + 96LL * v23 + 1) & 1) != 0 )
            {
              wlan_get_operation_chan_freq_vdev_id(a1[2695], v23);
              v47 = (_DWORD *)a1[2746];
              if ( v47 )
              {
                v48 = a1[2694];
                if ( *(v47 - 1) != 1469140685 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64))v47)(v48, v23, v25, 18, 11);
                v49 = *((_QWORD *)a2 + 335);
                if ( !v49 )
                  goto LABEL_31;
                goto LABEL_30;
              }
            }
            else
            {
              qdf_trace_msg(
                0x34u,
                2u,
                "%s: Session ID: %d is not valid",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "csr_roam_call_callback",
                v23);
            }
          }
          v49 = *((_QWORD *)a2 + 335);
          if ( !v49 )
          {
LABEL_31:
            result = v25;
LABEL_32:
            result = _qdf_mem_free(result);
            goto LABEL_33;
          }
LABEL_30:
          _qdf_mem_free(v49);
          goto LABEL_31;
        }
      }
      else
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: session %d not found",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "csr_roam_joined_state_msg_processor",
          v23);
      }
      result = *((_QWORD *)a2 + 335);
      if ( !result )
        goto LABEL_33;
      goto LABEL_32;
    }
    result = csr_roam_check_for_link_status_change((__int64)a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
