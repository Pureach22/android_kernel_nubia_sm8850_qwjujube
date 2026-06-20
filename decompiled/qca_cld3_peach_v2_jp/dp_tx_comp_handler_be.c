__int64 __fastcall dp_tx_comp_handler_be(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w8
  unsigned int v19; // w9
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w21
  __int64 v24; // x24
  __int64 v25; // x27
  _QWORD *v26; // x8
  unsigned int i; // w25
  __int64 v28; // x19
  int v29; // w8
  char v30; // w12
  __int64 v31; // x10
  __int64 v32; // x23
  unsigned int v33; // w9
  unsigned int *v39; // x19
  _DWORD *v40; // x1
  __int64 v41; // x26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  int v114; // w8
  char v115; // w9
  int v116; // w4
  __int64 v117; // x8
  __int64 v118; // x19
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x0
  _QWORD *v128; // x8
  __int64 v129; // x0
  __int64 v130; // x19
  __int64 v131; // x0
  int v133; // [xsp+4h] [xbp-4Ch]
  __int64 v134; // [xsp+8h] [xbp-48h]
  unsigned int v135; // [xsp+10h] [xbp-40h]
  _QWORD *v136; // [xsp+18h] [xbp-38h]
  _QWORD *v137; // [xsp+20h] [xbp-30h]
  unsigned int v138; // [xsp+2Ch] [xbp-24h]
  _QWORD v139[2]; // [xsp+30h] [xbp-20h] BYREF
  int v140; // [xsp+40h] [xbp-10h]
  __int64 v141; // [xsp+48h] [xbp-8h]

  v141 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned int)dp_srng_access_start(a1, a2, a3) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: HAL RING Access Failed -- %pK",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_tx_comp_handler_be",
      a3);
    v23 = 0;
LABEL_65:
    _ReadStatusReg(SP_EL0);
    return v23;
  }
  v18 = *(_DWORD *)(a3 + 120);
  v19 = *(_DWORD *)(a3 + 136);
  _CF = v19 >= v18;
  v21 = v19 - v18;
  if ( !_CF )
    v21 += *(_DWORD *)(a3 + 36);
  v22 = v21 / *(_DWORD *)(a3 + 44);
  if ( v22 >= a5 )
    v22 = a5;
  if ( !v22 )
  {
    v131 = dp_srng_access_end(a1, a2, a3);
    v138 = 0;
    v23 = 0;
    v24 = 0;
    v137 = nullptr;
    if ( !a2 )
      goto LABEL_63;
    goto LABEL_61;
  }
  v134 = a1;
  v135 = a4;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v133 = 0;
  v138 = 0;
  v136 = nullptr;
  v137 = nullptr;
LABEL_12:
  for ( i = 1 - v22; i != 1; ++i )
  {
    v28 = *(unsigned int *)(a3 + 120);
    if ( (_DWORD)v28 == *(_DWORD *)(a3 + 136) )
      break;
    v29 = *(_DWORD *)(a3 + 44);
    v30 = *(_BYTE *)(a3 + 78);
    v31 = *(_QWORD *)(a2 + 1128);
    v32 = *(_QWORD *)(a3 + 16);
    if ( v29 + (_DWORD)v28 == *(_DWORD *)(a3 + 36) )
      v33 = 0;
    else
      v33 = v29 + v28;
    *(_DWORD *)(a3 + 120) = v33;
    if ( (v30 & 4) != 0 )
    {
      _X26 = v32 + 4LL * v33;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v31 + 8) + 40LL) + 844LL) & 0x40) == 0 )
        _dma_sync_single_for_cpu();
      __asm { PRFM            #0, [X26] }
    }
    v39 = (unsigned int *)(v32 + 4 * v28);
    if ( !v39 )
      break;
    v40 = v39 + 2;
    if ( (v39[2] & 0x40000000) != 0 )
    {
      v41 = *(_QWORD *)v39;
      if ( !*(_QWORD *)v39 )
        goto LABEL_24;
    }
    else
    {
      v41 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 22552) + 24LL * (v39[1] >> 21))
                      + (((unsigned __int64)v39[1] >> 9) & 0xFF8));
      if ( !v41 )
      {
LABEL_24:
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: unable to retrieve tx_desc!",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_tx_comp_handler_be");
        qdf_trace_msg(0x3Fu, 1u, "Current tx completion descriptor is", v42, v43, v44, v45, v46, v47, v48, v49);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v50, v51, v52, v53, v54, v55, v56, v57, *v39);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v58, v59, v60, v61, v62, v63, v64, v65, v39[1]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v66, v67, v68, v69, v70, v71, v72, v73, v39[2]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v74, v75, v76, v77, v78, v79, v80, v81, v39[3]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v82, v83, v84, v85, v86, v87, v88, v89, v39[4]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v90, v91, v92, v93, v94, v95, v96, v97, v39[5]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v98, v99, v100, v101, v102, v103, v104, v105, v39[6]);
        qdf_trace_msg(0x3Fu, 1u, "DWORD[i] = 0x%x", v106, v107, v108, v109, v110, v111, v112, v113, v39[7]);
        if ( a2 )
          ++*(_DWORD *)(a2 + 13496);
        continue;
      }
    }
    v114 = v39[2] & 7;
    v115 = *(_BYTE *)(v41 + 64) & 0xE3;
    *(_WORD *)(v41 + 50) = v39[7];
    *(_BYTE *)(v41 + 64) = v115 | (4 * v114);
    if ( v114 == 3 )
    {
      v140 = 0;
      v139[0] = 0;
      v139[1] = 0;
      qdf_mem_copy(v139, v40, 0x14u);
      hal_tx_comp_desc_sync_wrapper((int)v39);
      if ( !*(_QWORD *)(v41 + 56) )
        dp_tx_dump_tx_desc(v41);
      dp_tx_process_htt_completion_be(
        a2,
        v41,
        (unsigned int *)v139,
        v135,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126);
      goto LABEL_11;
    }
    v116 = *(_DWORD *)(v41 + 32);
    *(_BYTE *)(v41 + 49) = (*v40 >> 13) & 0xF;
    if ( (v116 & 0x30004) != 0 )
      goto LABEL_48;
    if ( !v116 && *(unsigned __int8 *)(v41 + 48) == 255 )
    {
      v118 = jiffies;
      if ( dp_tx_comp_handler_be___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x87u,
          5u,
          "%s: Descriptor freed in vdev_detach %d",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "dp_tx_comp_handler_be",
          *(unsigned int *)(v41 + 36));
        dp_tx_comp_handler_be___last_ticks = v118;
      }
      if ( a2 )
        ++*(_DWORD *)(a2 + 13532);
      dp_tx_desc_check_corruption(v41);
    }
    else
    {
      v117 = *(_QWORD *)(v41 + 56);
      if ( v117 )
      {
        if ( *(_BYTE *)(v117 + 16) == 1 )
        {
          v130 = jiffies;
          if ( dp_tx_comp_handler_be___last_ticks_29 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x87u,
              5u,
              "%s: pdev in down state %d",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              "dp_tx_comp_handler_be",
              *(unsigned int *)(v41 + 36));
            v116 = *(_DWORD *)(v41 + 32);
            dp_tx_comp_handler_be___last_ticks_29 = v130;
          }
          *(_DWORD *)(v41 + 32) = v116 | 0x1000;
          dp_tx_comp_free_buf(a2, v41, 0);
          dp_tx_desc_release(a2, v41, *(unsigned __int8 *)(v41 + 67));
        }
        else
        {
          if ( (~v116 & 0x220) != 0 )
          {
            qdf_trace_msg(
              0x87u,
              1u,
              "%s: Txdesc invalid, flgs = %x,id = %d",
              v10,
              v11,
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              "dp_tx_comp_handler_be");
            v129 = printk(
                     &unk_9BB309,
                     "0",
                     "dp_tx_comp_handler_be",
                     "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/be/dp_be_tx.c");
            dump_stack(v129);
          }
          hal_tx_comp_desc_sync_wrapper((int)v39);
          v116 = *(_DWORD *)(v41 + 32);
          ++v133;
LABEL_48:
          if ( (v116 & 0x30000) != 0 )
          {
            v127 = *(_QWORD *)(v41 + 8);
            if ( v127 )
              _qdf_nbuf_free(v127);
            v128 = v137;
            v137 = (_QWORD *)v41;
            if ( !v24 )
            {
              v24 = v41;
              v128 = (_QWORD *)v41;
            }
            *v128 = v41;
            *(_BYTE *)(v41 + 48) = -1;
            *(_DWORD *)(v41 + 32) = 0;
            *(_QWORD *)v41 = 0;
            *(_QWORD *)(v41 + 8) = 0;
            ++v138;
          }
          else
          {
            v26 = v136;
            v136 = (_QWORD *)v41;
            if ( !v25 )
            {
              v25 = v41;
              v26 = (_QWORD *)v41;
            }
            *v26 = v41;
            *(_QWORD *)v41 = 0;
          }
        }
LABEL_11:
        ++v23;
        v22 = -i;
        if ( !i )
          break;
        goto LABEL_12;
      }
      qdf_trace_msg(
        0x87u,
        3u,
        "%s: The pdev is NULL in TX desc, ignored.",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "dp_tx_comp_handler_be");
      dp_tx_dump_tx_desc(v41);
      if ( a2 )
        ++*(_DWORD *)(a2 + 13532);
    }
  }
  v131 = dp_srng_access_end(v134, a2, a3);
  if ( !v25 )
  {
    a4 = v135;
    if ( a2 )
      goto LABEL_61;
LABEL_63:
    if ( v24 )
      dp_tx_comp_process_desc_list_fast(a2, v24, v137, a4, v138);
    goto LABEL_65;
  }
  a4 = v135;
  v131 = dp_tx_comp_process_desc_list(a2, v25, v135);
  if ( !a2 )
    goto LABEL_63;
LABEL_61:
  if ( (unsigned __int8)a4 < 5u )
  {
    *(_DWORD *)(a2 + 4LL * (unsigned __int8)a4 + 13544) += v23;
    goto LABEL_63;
  }
  __break(0x5512u);
  return dp_tx_dump_tx_desc(v131);
}
