__int64 __fastcall lim_process_switch_channel_join_mlo(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // w8
  __int64 v12; // x0
  int v14; // w4
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  _WORD *v33; // x22
  unsigned int v34; // w21
  unsigned int v35; // w8
  __int64 v36; // x0
  unsigned int v37; // w22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 result; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int mlie; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  double updated; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x3
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
  unsigned int bvmlie_primary_linkid; // w0
  char v91; // w10
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  _BYTE v100[4]; // [xsp+8h] [xbp-68h] BYREF
  _BYTE v101[4]; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v102; // [xsp+10h] [xbp-60h] BYREF
  __int64 v103; // [xsp+18h] [xbp-58h] BYREF
  __int64 v104; // [xsp+20h] [xbp-50h] BYREF
  __int64 v105; // [xsp+28h] [xbp-48h] BYREF
  __int64 v106; // [xsp+30h] [xbp-40h]
  __int64 v107; // [xsp+38h] [xbp-38h]
  __int64 v108; // [xsp+40h] [xbp-30h] BYREF
  __int64 v109; // [xsp+48h] [xbp-28h]
  __int64 v110; // [xsp+50h] [xbp-20h] BYREF
  char *v111; // [xsp+58h] [xbp-18h]
  int v112; // [xsp+60h] [xbp-10h] BYREF
  __int16 v113; // [xsp+64h] [xbp-Ch]
  __int64 v114; // [xsp+68h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a1 + 10696);
  v110 = 0;
  v111 = nullptr;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v103 = 0;
  v104 = 0;
  v102 = 0;
  v101[0] = 0;
  v113 = 0;
  v112 = 0;
  v100[0] = 0;
  if ( !v11 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: MLO: vdev:%d num_partner_links is 0",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_switch_channel_join_mlo",
      *(unsigned __int8 *)(a1 + 10));
    goto LABEL_8;
  }
  v12 = *(_QWORD *)(a1 + 16);
  LODWORD(v110) = 0;
  mlo_get_assoc_rsp(v12, &v110);
  if ( !(_DWORD)v110 )
  {
LABEL_8:
    result = 4;
    goto LABEL_24;
  }
  v105 = 0;
  qdf_mem_copy(&v112, (const void *)(a1 + 30), 6u);
  BYTE6(v105) = *(_BYTE *)(a1 + 8);
  qdf_trace(53, 0xAu, 0, 1005);
  lim_process_mlm_join_cnf(a2, (__int64)&v105);
  v14 = v110 + 24;
  *(_DWORD *)(a1 + 80) = 5;
  LODWORD(v110) = v14;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: MLO:assoc rsp len + hdr %d ",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "lim_process_switch_channel_join_mlo");
  v23 = _qdf_mem_malloc((unsigned int)v110, "lim_process_switch_channel_join_mlo", 2863);
  v109 = v23;
  if ( v23 )
  {
    v32 = *(_QWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 72) = 10;
    v33 = (_WORD *)v23;
    v34 = *(unsigned __int8 *)(v32 + 93);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: MLO: Generate and process assoc rsp for link vdev %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "lim_process_switch_channel_join_mlo",
      *(unsigned __int8 *)(v32 + 93));
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 16) + 67LL) & 2) == 0 )
    {
LABEL_5:
      v35 = util_gen_link_assoc_rsp((int)v111, (int)v110 - 24, 0, v34, v112, (int)v33, v110, (__int64)&v108);
      v36 = *(_QWORD *)(a1 + 16);
      if ( v35 )
      {
        v37 = v35;
        mlo_free_cache_link_assoc_rsp(v36, v34);
LABEL_22:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: MLO vdev %d link %d vdev assoc rsp generation failed",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_process_switch_channel_join_mlo",
          *(unsigned __int8 *)(a1 + 10),
          v34);
        v91 = *(_BYTE *)(a1 + 8);
        LODWORD(v104) = 500;
        WORD2(v104) = 1;
        BYTE6(v104) = v91;
        qdf_trace(53, 0xAu, 0, 1010);
        lim_process_mlm_assoc_cnf(a2, (unsigned int *)&v104, v92, v93, v94, v95, v96, v97, v98, v99);
        goto LABEL_23;
      }
      updated = mlo_update_cache_link_assoc_rsp(v36, v34, &v108);
LABEL_15:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: MLO vdev %d: process assoc rsp for link %d",
        updated,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        "lim_process_switch_channel_join_mlo",
        *(unsigned __int8 *)(a1 + 10),
        v34);
      mgmt_txrx_frame_hex_dump(v109, v108, 0, v73, v74, v75, v76, v77, v78, v79, v80, v81);
      lim_process_assoc_rsp_frame(a2, v109, v108, 0, a1, v82, v83, v84, v85, v86, v87, v88, v89);
      v37 = 0;
LABEL_23:
      _qdf_mem_free(v109);
      result = v37;
      goto LABEL_24;
    }
    if ( !(unsigned int)mlo_get_cache_link_assoc_rsp() )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: found link id %d in cached link assoc rsp, len %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "lim_process_switch_channel_join_mlo",
        v34,
        (unsigned int)v106);
      _qdf_mem_free((__int64)v33);
      v109 = v107;
      LODWORD(v108) = v106;
      goto LABEL_15;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: no found link id %d in cached link assoc rsp",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "lim_process_switch_channel_join_mlo",
      v34);
    mlie = util_find_mlie(v111 + 6, (unsigned int)(v110 - 30), &v103, &v102);
    if ( mlie )
    {
      v37 = mlie;
      v64 = "%s: ML IE not found";
    }
    else
    {
      bvmlie_primary_linkid = util_get_bvmlie_primary_linkid(v103, v102, v101, v100);
      if ( !bvmlie_primary_linkid && (v101[0] & 1) != 0 )
      {
        if ( v100[0] == v34 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Skip assoc rsp gen for link %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "lim_process_switch_channel_join_mlo",
            v34);
          qdf_ether_addr_copy(v33 + 8, (_WORD *)(a1 + 24));
          qdf_ether_addr_copy(v33 + 5, (_WORD *)(a1 + 24));
          qdf_ether_addr_copy(v33 + 2, &v112);
          *v33 = 16;
          LODWORD(v108) = v110;
          qdf_mem_copy(v33 + 12, v111, (unsigned int)(v110 - 24));
          goto LABEL_15;
        }
        goto LABEL_5;
      }
      v37 = bvmlie_primary_linkid;
      v64 = "%s: Assoc link ID not found";
    }
    qdf_trace_msg(0x35u, 8u, v64, v56, v57, v58, v59, v60, v61, v62, v63, "lim_process_switch_channel_join_mlo");
    goto LABEL_22;
  }
  result = 2;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
