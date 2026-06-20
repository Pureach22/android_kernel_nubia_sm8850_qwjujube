__int64 __fastcall _dp_ipa_handle_buf_smmu_mapping(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v8; // x0
  int hdl; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  unsigned __int8 v19; // w23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x4
  __int64 v30; // x27
  __int64 v31; // x8
  __int64 v32; // x9
  __int64 v33; // x8
  __int64 v34; // x9
  __int64 v35; // x25
  __int64 v36; // x0
  __int64 v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w22
  __int64 v47; // x0
  unsigned __int64 v48; // x8
  unsigned int v49; // w21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int64 v58; // x9
  unsigned int v59; // w21
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x0
  __int64 v69; // x0
  unsigned int v70; // w19
  __int64 v71; // x0
  unsigned int v78; // w8
  unsigned int v79; // w8
  unsigned int v82; // w8
  unsigned int v83; // w8
  _QWORD v84[2]; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v85; // [xsp+18h] [xbp-18h]
  __int64 v86; // [xsp+20h] [xbp-10h]
  __int64 v87; // [xsp+28h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 16);
  v86 = 0;
  hdl = wlan_ipa_get_hdl(v8, 0);
  if ( hdl == 255 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: IPA handle is invalid",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__dp_ipa_handle_buf_smmu_mapping");
    result = 4;
    goto LABEL_32;
  }
  v19 = hdl;
  if ( (_qdf_is_pp_nbuf(a2) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 20750) & 1) != 0 )
    {
      v28 = (*(_QWORD *)(a2 + 40) - *(_QWORD *)(a1 + 20728)) >> 12;
      v29 = v28 >> *(_WORD *)(a1 + 20748);
      if ( (unsigned int)v29 > *(unsigned __int16 *)(a1 + 20690) )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Invalid page idx %u",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_ipa_skip_pp_nbuf_smmu_map");
        goto LABEL_11;
      }
      v31 = *(_QWORD *)(*(_QWORD *)(a1 + 20704) + 8LL * (unsigned int)v29);
      v32 = 4LL * (*(_DWORD *)(a1 + 20744) & (unsigned int)v28);
      if ( (a4 & 1) != 0 )
      {
        _X9 = (unsigned int *)(v31 + v32);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v78 = __ldxr(_X9);
          v79 = v78 + 1;
        }
        while ( __stlxr(v79, _X9) );
        __dmb(0xBu);
        if ( v79 == 1 )
          goto LABEL_11;
LABEL_34:
        result = 0;
        goto LABEL_32;
      }
      _X9 = (unsigned int *)(v31 + v32);
      __asm { PRFM            #0x11, [X9] }
      do
      {
        v82 = __ldxr(_X9);
        v83 = v82 - 1;
      }
      while ( __stlxr(v83, _X9) );
      __dmb(0xBu);
      if ( v83 )
        goto LABEL_34;
    }
    else
    {
      v30 = jiffies;
      if ( dp_ipa_skip_pp_nbuf_smmu_map___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Unexpected!!, ipa ref counters not initialized",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "dp_ipa_skip_pp_nbuf_smmu_map");
        dp_ipa_skip_pp_nbuf_smmu_map___last_ticks = v30;
      }
    }
  }
LABEL_11:
  v33 = *(_QWORD *)(a1 + 24);
  v34 = 80;
  if ( (*(_BYTE *)(a2 + 68) & 4) == 0 )
    v34 = 40;
  v35 = *(_QWORD *)(a2 + v34);
  v36 = v35;
  if ( *(_BYTE *)(v33 + 608) == 1 )
  {
    v37 = *(_QWORD *)(v33 + 616);
    v36 = *(_QWORD *)(a2 + v34);
    if ( v37 )
      v36 = iommu_iova_to_phys(v37, *(_QWORD *)(a2 + v34));
  }
  v84[0] = v36;
  v84[1] = v35;
  v85 = a3;
  if ( (a4 & 1) != 0 )
  {
    if ( !v36 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Assert PA is zero. nbuf %pK ipa_smmu_map_caller %d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "__dp_ipa_handle_buf_smmu_mapping",
        a2,
        *(_DWORD *)(a2 + 48) >> 26);
      if ( !v84[0] )
      {
        v68 = printk(
                &unk_9BB309,
                "mem_map_table.pa",
                "__dp_ipa_handle_buf_smmu_mapping",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
        dump_stack(v68);
      }
    }
    result = qdf_nbuf_smmu_map_debug(a2, v19, 1u, (__int64)v84);
    if ( !(_DWORD)result )
      goto LABEL_23;
    goto LABEL_21;
  }
  result = qdf_nbuf_smmu_unmap_debug(a2, v19, 1u, (__int64)v84);
  if ( (_DWORD)result )
  {
LABEL_21:
    v46 = result;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Assert return of map/unmap.nbuf %pK ipa_smmu_map_caller %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "__dp_ipa_handle_buf_smmu_mapping",
      a2,
      *(_DWORD *)(a2 + 48) >> 26);
    v47 = printk(
            &unk_9BB309,
            "!ret",
            "__dp_ipa_handle_buf_smmu_mapping",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
    dump_stack(v47);
    result = v46;
  }
LABEL_23:
  v48 = (int)v86;
  if ( (a4 & 1) != 0 )
  {
    if ( (_DWORD)v86 )
    {
      v49 = result;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Assert mem_map_table result for map.",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__dp_ipa_handle_buf_smmu_mapping");
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf %pK ipa_smmu_map_caller %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "__dp_ipa_handle_buf_smmu_mapping",
        a2,
        *(_DWORD *)(a2 + 48) >> 26);
      if ( (_DWORD)v86 )
      {
        v69 = printk(
                &unk_9BB309,
                "!mem_map_table.result",
                "__dp_ipa_handle_buf_smmu_mapping",
                "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
        dump_stack(v69);
      }
      result = v49;
    }
  }
  else
  {
    v58 = v85;
    if ( v85 > (int)v86 )
    {
      v59 = result;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Assert mem_map_table result for unmap.",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "__dp_ipa_handle_buf_smmu_mapping");
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf %pK ipa_smmu_map_caller %d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "__dp_ipa_handle_buf_smmu_mapping",
        a2,
        *(_DWORD *)(a2 + 48) >> 26);
      v48 = (int)v86;
      v58 = v85;
      result = v59;
    }
    if ( v58 > v48 )
    {
      v70 = result;
      v71 = printk(
              &unk_9BB309,
              "mem_map_table.result >= mem_map_table.size",
              "__dp_ipa_handle_buf_smmu_mapping",
              "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_ipa.c");
      dump_stack(v71);
      result = v70;
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
