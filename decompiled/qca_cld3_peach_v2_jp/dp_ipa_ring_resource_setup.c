__int64 __fastcall dp_ipa_ring_resource_setup(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x21
  __int64 v5; // x25
  int v6; // w8
  __int64 v7; // x10
  int v8; // w9
  __int64 v9; // x12
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w9
  __int64 v29; // x8
  int v30; // w10
  __int64 v31; // x12
  _QWORD *v32; // x11
  __int64 v33; // x13
  __int64 v34; // x23
  int v35; // w8
  __int64 v36; // x10
  int v37; // w9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x6
  int v56; // w8
  int v57; // w8
  __int64 v58; // x10
  _QWORD *v59; // x9
  __int64 v60; // x11
  __int64 v61; // x4
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 v72; // x8
  _DWORD *v73; // x8
  int v74; // w0
  __int64 v75; // x8
  __int64 v77; // [xsp+0h] [xbp-90h]
  __int64 v78; // [xsp+8h] [xbp-88h]
  __int64 v79; // [xsp+8h] [xbp-88h]
  __int64 v80; // [xsp+10h] [xbp-80h]
  __int64 v81; // [xsp+10h] [xbp-80h]
  int v82; // [xsp+24h] [xbp-6Ch] BYREF
  __int64 v83; // [xsp+28h] [xbp-68h] BYREF
  __int64 v84; // [xsp+30h] [xbp-60h] BYREF
  __int64 v85; // [xsp+38h] [xbp-58h]
  __int64 v86; // [xsp+40h] [xbp-50h]
  __int64 v87; // [xsp+48h] [xbp-48h]
  __int64 v88; // [xsp+50h] [xbp-40h]
  __int64 v89; // [xsp+58h] [xbp-38h]
  __int64 v90; // [xsp+60h] [xbp-30h]
  __int64 v91; // [xsp+68h] [xbp-28h]
  __int64 v92; // [xsp+70h] [xbp-20h]
  __int64 v93; // [xsp+78h] [xbp-18h]
  __int64 v94; // [xsp+80h] [xbp-10h]
  __int64 v95; // [xsp+88h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 1128);
  v3 = *(_QWORD *)(a1 + 40);
  v93 = 0;
  v94 = 0;
  v91 = 0;
  v92 = 0;
  v89 = 0;
  v90 = 0;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v86 = 0;
  v83 = 0;
  v84 = 0;
  if ( (wlan_cfg_is_ipa_enabled(v3) & 1) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 7072);
    v5 = 9252;
    hal_get_srng_params((__int64)v2, v4, (__int64)&v84);
    v6 = v86;
    v7 = v85;
    v8 = v86 * HIDWORD(v91);
    *(_QWORD *)(a1 + 17984) = v84;
    v8 *= 4;
    *(_QWORD *)(a1 + 17992) = v7;
    *(_DWORD *)(a1 + 18000) = v8;
    v9 = *(_QWORD *)(v4 + 144);
    v10 = *(_QWORD *)(*v2 + 728LL);
    *(_QWORD *)(a1 + 18008) = v9 - v2[2] + v10;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: IPA TCL_DATA Ring addr_offset=%x, dev_base_paddr=%x, hp_paddr=%x paddr=%pK vaddr=%pK size= %u(%u bytes)",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_ipa_ring_resource_setup",
      v7,
      v6,
      v8);
    v19 = *(_QWORD *)(a1 + 7640);
    hal_get_srng_params((__int64)v2, v19, (__int64)&v84);
    v28 = v86;
    v29 = v85;
    v30 = 4 * v86 * HIDWORD(v91);
    *(_QWORD *)(a1 + 18024) = v84;
    *(_QWORD *)(a1 + 18032) = v29;
    *(_DWORD *)(a1 + 18040) = v30;
    if ( *(_DWORD *)(v19 + 116) )
    {
      v31 = 128;
      v32 = v2 + 9253;
      v33 = 9252;
    }
    else if ( (*(_DWORD *)(v19 + 76) & 0x80000000) != 0 )
    {
      v33 = 9254;
      v31 = 144;
      v32 = v2 + 9255;
    }
    else
    {
      v33 = 2;
      v31 = 144;
      v32 = (_QWORD *)(*v2 + 728LL);
    }
    *(_QWORD *)(a1 + 18056) = *v32 + *(_QWORD *)(v19 + v31) - v2[v33];
    *(_QWORD *)(a1 + 18048) = *(_QWORD *)(v19 + 144) - v2[2] + v10;
    LODWORD(v80) = v30;
    LODWORD(v78) = v28;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: IPA TX COMP Ring addr_offset=%x, dev_base_paddr=%x, ipa_wbm_tp_paddr=%x paddr=%pK vaddr=0%pK size= %u(%u bytes)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "dp_ipa_ring_resource_setup",
      v29,
      v78,
      v80);
    v34 = *(_QWORD *)(a1 + 5952);
    hal_get_srng_params((__int64)v2, v34, (__int64)&v84);
    v35 = v86;
    v36 = v85;
    v37 = v86 * HIDWORD(v91);
    *(_QWORD *)(a1 + 18080) = v84;
    v37 *= 4;
    *(_QWORD *)(a1 + 18088) = v36;
    *(_DWORD *)(a1 + 18096) = v37;
    *(_QWORD *)(a1 + 18104) = *(_QWORD *)(v34 + 144) - v2[2] + v10;
    LODWORD(v81) = v37;
    LODWORD(v79) = v35;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: IPA REO_DEST Ring addr_offset=%x, dev_base_paddr=%x, tp_paddr=%x paddr=%pK vaddr=%pK size= %u(%u bytes)",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "dp_ipa_ring_resource_setup",
      v36,
      v79,
      v81);
    v46 = *(_QWORD *)(a1 + 18488);
    hal_get_srng_params((__int64)v2, v46, (__int64)&v84);
    v55 = v85;
    v56 = v86 * HIDWORD(v91);
    *(_QWORD *)(a1 + 18112) = v84;
    v57 = 4 * v56;
    *(_QWORD *)(a1 + 18120) = v55;
    *(_DWORD *)(a1 + 18128) = v57;
    if ( *(_DWORD *)(v46 + 116) )
    {
      v58 = 128;
      v59 = v2 + 9253;
    }
    else if ( (*(_DWORD *)(v46 + 76) & 0x80000000) != 0 )
    {
      v5 = 9254;
      v58 = 144;
      v59 = v2 + 9255;
    }
    else
    {
      v5 = 2;
      v58 = 144;
      v59 = (_QWORD *)(*v2 + 728LL);
    }
    v60 = *(_QWORD *)(a1 + 24);
    v61 = *v59 + *(_QWORD *)(v46 + v58) - v2[v5];
    if ( *(_BYTE *)(v60 + 608) == 1 )
    {
      v62 = *(_QWORD *)(v60 + 616);
      if ( v62 )
      {
        v61 = iommu_iova_to_phys(v62, *v59 + *(_QWORD *)(v46 + v58) - v2[v5]);
        v57 = *(_DWORD *)(a1 + 18128);
      }
    }
    *(_QWORD *)(a1 + 18136) = v61;
    LODWORD(v77) = v57;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: IPA REFILL_BUF Ring hp_paddr=%x paddr=%pK vaddr=%pK size= %u(%u bytes)",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "dp_ipa_ring_resource_setup",
      v77);
    v71 = *(_QWORD *)(a1 + 1128);
    v83 = 0x606050403020101LL;
    if ( v71 && (v72 = *(_QWORD *)(v71 + 74392)) != 0 )
    {
      v73 = *(_DWORD **)(v72 + 80);
      if ( v73 )
      {
        if ( *(v73 - 1) != -236786424 )
          __break(0x8228u);
        v74 = ((__int64 (__fastcall *)(_QWORD, __int64 *))v73)(0, &v83);
        goto LABEL_23;
      }
    }
    else
    {
      qdf_trace_msg(
        0x46u,
        2u,
        "%s: hal handle is NULL",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "hal_gen_reo_remap_val");
    }
    v74 = 0;
LABEL_23:
    v75 = *(_QWORD *)(a1 + 1128);
    v82 = v74;
    hal_reo_read_write_ctrl_ix(v75, 0, &v82, nullptr, nullptr, nullptr);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
