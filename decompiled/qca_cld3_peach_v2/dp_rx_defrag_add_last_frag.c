__int64 __fastcall dp_rx_defrag_add_last_frag(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int16 *v14; // x27
  int v15; // w26
  __int64 v18; // x25
  _QWORD *v20; // x23
  unsigned int v21; // w24
  __int64 v22; // x0
  __int64 (__fastcall *v23)(_QWORD); // x8
  int v24; // w0
  unsigned int v25; // w9
  unsigned int v26; // w24
  unsigned int v27; // w8
  __int64 result; // x0
  int v29; // w9
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w9
  int v39; // w10
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x21
  _QWORD *v73; // x0
  _QWORD *v74; // x19
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x21
  _QWORD *v100; // x0
  _QWORD *v101; // x19
  unsigned __int16 *v102; // x19
  __int64 v103; // x0
  _QWORD *v104; // x19
  __int64 v105; // t1
  unsigned __int16 *v106; // x19
  __int64 v107; // x0
  __int64 v108; // t1
  char v109[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v110; // [xsp+8h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0x12u || (v109[0] = 0, a3 == 17) )
    __break(0x5512u);
  v14 = a2 + 88;
  v15 = a3;
  v18 = (__int64)&a2[60 * a3 + 88];
  v20 = *(_QWORD **)(v18 + 48);
  if ( !v20 )
  {
    if ( is_dp_verbose_debug_enabled == 1 )
    {
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: peer id:%d drop rx frame!",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "dp_rx_defrag_add_last_frag",
        a2[4]);
      if ( !a1 )
      {
LABEL_13:
        if ( !a5 )
        {
LABEL_19:
          result = 45;
          goto LABEL_49;
        }
LABEL_14:
        _qdf_nbuf_free(a5);
        result = 45;
        goto LABEL_49;
      }
    }
    else if ( !a1 )
    {
      goto LABEL_13;
    }
    ++*(_DWORD *)(a1 + 13760);
    goto LABEL_13;
  }
  if ( *v20 )
  {
    v21 = a4;
    if ( *(_DWORD *)(v18 + 40) != a4 )
    {
      dp_rx_reorder_flush_frag((__int64)a2, a3, a6, a7, a8, a9, a10, a11, a12, a13);
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: No list found for TID %d Seq# %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "dp_rx_defrag_add_last_frag",
        a3,
        v21);
      if ( !a5 )
        goto LABEL_19;
      goto LABEL_14;
    }
  }
  v22 = *(_QWORD *)(a5 + 224);
  v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1272LL);
  if ( *((_DWORD *)v23 - 1) != 855462014 )
    __break(0x8228u);
  v24 = v23(v22);
  v25 = *(_DWORD *)(a5 + 112);
  v26 = v24 + *(unsigned __int16 *)(a1 + 1138);
  v27 = v26 - v25;
  if ( v26 < v25 )
  {
    skb_trim(a5, v26);
    goto LABEL_25;
  }
  if ( *(_DWORD *)(a5 + 116) )
  {
    v27 = v26 - v25;
    if ( v26 != v25 )
    {
      v29 = 0;
      goto LABEL_22;
    }
  }
  else
  {
    v39 = *(_DWORD *)(a5 + 208);
    v38 = *(_DWORD *)(a5 + 212);
    if ( v38 - v39 < v27 )
    {
      v29 = v39 - v38;
LABEL_22:
      if ( (unsigned int)pskb_expand_head(a5, 0, v29 + v27, 2080) )
        dev_kfree_skb_any_reason(a5, 1);
    }
  }
  skb_put(a5, v26 - *(_DWORD *)(a5 + 112));
LABEL_25:
  if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, _QWORD *, _QWORD *, __int64, char *))dp_rx_defrag_fraglist_insert)(
                       a2,
                       a3,
                       v20,
                       v20 + 1,
                       a5,
                       v109) )
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "%s Fragment insert failed",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "dp_rx_defrag_add_last_frag");
    result = 45;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 13200) )
      dp_rx_defrag_waitlist_remove(a2, a3, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( v109[0] )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int16 *, _QWORD, _QWORD))dp_rx_defrag)(a2, a3, *v20) )
      {
        qdf_trace_msg(
          0x3Fu,
          2u,
          "%s Fragment processing failed",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "dp_rx_defrag_add_last_frag");
        dp_rx_return_head_frag_desc((__int64)a2, a3, v56, v57, v58, v59, v60, v61, v62, v63);
        v72 = *(_QWORD *)(v18 + 48);
        if ( v72 )
        {
          v73 = *(_QWORD **)v72;
          if ( *(_QWORD *)v72 )
          {
            do
            {
              v74 = (_QWORD *)*v73;
              _qdf_nbuf_free((__int64)v73);
              v73 = v74;
            }
            while ( v74 );
          }
          *(_QWORD *)v72 = 0;
          *(_QWORD *)(v72 + 8) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Cleanup self peer %pK and TID %u",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "dp_rx_defrag_cleanup",
            a2,
            a3);
        }
        v102 = &v14[60 * v15];
        v105 = *((_QWORD *)v102 + 3);
        v104 = v102 + 12;
        v103 = v105;
        if ( v105 )
          _qdf_mem_free(v103);
        *(_DWORD *)(v18 + 104) = 0;
        result = 45;
      }
      else
      {
        dp_rx_defrag_reo_reinject(a2, a3, *v20);
        *v20 = 0;
        v20[1] = 0;
        qdf_trace_msg(
          0x3Fu,
          4u,
          "%s: Frag seq successfully reinjected",
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          "dp_rx_defrag_add_last_frag");
        v99 = *(_QWORD *)(v18 + 48);
        if ( v99 )
        {
          v100 = *(_QWORD **)v99;
          if ( *(_QWORD *)v99 )
          {
            do
            {
              v101 = (_QWORD *)*v100;
              _qdf_nbuf_free((__int64)v100);
              v100 = v101;
            }
            while ( v101 );
          }
          *(_QWORD *)v99 = 0;
          *(_QWORD *)(v99 + 8) = 0;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: Cleanup self peer %pK and TID %u",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            "dp_rx_defrag_cleanup",
            a2,
            a3);
        }
        v106 = &v14[60 * v15];
        v108 = *((_QWORD *)v106 + 3);
        v104 = v106 + 12;
        v107 = v108;
        if ( v108 )
          _qdf_mem_free(v107);
        result = 0;
        *(_DWORD *)(v18 + 104) = 0;
      }
      *v104 = 0;
      v104[1] = 0;
      v104[2] = 0;
    }
    else
    {
      *(_DWORD *)(v18 + 104) = *(_DWORD *)(a1 + 13176) + jiffies_to_msecs(jiffies);
      dp_rx_defrag_waitlist_add(a2, a3, v75, v76, v77, v78, v79, v80, v81, v82);
      result = 0;
    }
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
