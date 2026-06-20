__int64 __fastcall extract_reg_chan_list_update_event_tlv(
        __int64 a1,
        _DWORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int *v22; // x25
  __int64 v23; // x21
  __int64 v24; // x20
  unsigned int v25; // w23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x1
  __int64 (__fastcall *v35)(__int64, __int64); // x8
  __int64 v36; // x4
  __int64 v37; // x5
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned int *v70; // x24
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x8
  _DWORD *v81; // x9
  __int64 v82; // x11
  int v83; // t1
  _QWORD *v84; // x25
  __int64 v85; // x22
  __int64 v87; // x26
  __int64 v88; // x22
  unsigned __int16 *v89; // x8
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x8
  unsigned int *v100; // x9
  __int64 v101; // x11
  unsigned int v102; // w10
  _QWORD *v103; // x19
  __int64 v104; // x23
  __int64 v105; // x21
  unsigned __int16 *v106; // x8
  __int64 v107; // [xsp+0h] [xbp-20h]
  __int64 v108; // [xsp+8h] [xbp-18h]

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: processing regulatory channel list",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "extract_reg_chan_list_update_event_tlv");
  if ( a2 )
  {
    v22 = *(unsigned int **)a2;
    v23 = *(unsigned int *)(*(_QWORD *)a2 + 52LL);
    *(_DWORD *)(a3 + 48) = v23;
    v24 = v22[14];
    *(_DWORD *)(a3 + 52) = v24;
    if ( (unsigned int)v23 <= 0xA
      && (unsigned int)v24 <= 0xA
      && (unsigned int)(v24 + v23) <= 0xA
      && (_DWORD)v24 + (_DWORD)v23 == a2[6] )
    {
      qdf_mem_copy((void *)(a3 + 18), v22 + 3, 2u);
      *(_DWORD *)(a3 + 24) = v22[7];
      v25 = v22[8];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Target phybitmap: 0x%x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "convert_phybitmap_tlv",
        v25);
      *(_DWORD *)(a3 + 28) = v25 & 0x7F;
      *(_BYTE *)(a3 + 21) = 1;
      *(_BYTE *)(a3 + 12) = v22[4];
      v34 = v22[2];
      v35 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3704LL);
      if ( *((_DWORD *)v35 - 1) != -2112860426 )
        __break(0x8228u);
      *(_BYTE *)(a3 + 13) = v35(a1, v34);
      *(_WORD *)(a3 + 16) = v22[5];
      *(_WORD *)(a3 + 14) = v22[6];
      *(_DWORD *)(a3 + 8) = wmi_reg_status_to_reg_status(v22[1]);
      v36 = *(unsigned __int8 *)(a3 + 12);
      v37 = *(unsigned __int8 *)(a3 + 13);
      *(_DWORD *)(a3 + 32) = v22[9];
      *(_DWORD *)(a3 + 36) = v22[10];
      *(_DWORD *)(a3 + 40) = v22[11];
      *(_DWORD *)(a3 + 44) = v22[12];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: num_phys = %u and phy_id = %u",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "extract_reg_chan_list_update_event_tlv",
        v36,
        v37);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: cc %s dfs_region %d reg_dmn_pair %x BW: min_2g %d max_2g %d min_5g %d max_5g %d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "extract_reg_chan_list_update_event_tlv",
        a3 + 18,
        *(unsigned int *)(a3 + 24),
        *(unsigned __int16 *)(a3 + 14),
        *(unsigned int *)(a3 + 32),
        *(_DWORD *)(a3 + 36),
        *(_DWORD *)(a3 + 40),
        *(_DWORD *)(a3 + 44));
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: num_2g_reg_rules %d num_5g_reg_rules %d",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "extract_reg_chan_list_update_event_tlv",
        (unsigned int)v23,
        (unsigned int)v24);
      v70 = v22 + 16;
      if ( (_DWORD)v23 )
      {
        v71 = _qdf_mem_malloc(14 * v23, "create_reg_rules_from_wmi", 17314);
        if ( v71 )
        {
          v80 = 0;
          v81 = v22 + 19;
          do
          {
            v82 = v71 + v80;
            v80 += 14;
            *(_WORD *)v82 = *(v81 - 2);
            *(_WORD *)(v82 + 2) = *((_WORD *)v81 - 3);
            *(_WORD *)(v82 + 4) = *(v81 - 1);
            *(_BYTE *)(v82 + 6) = *((_WORD *)v81 - 1);
            *(_BYTE *)(v82 + 7) = *((_BYTE *)v81 - 1);
            v83 = *v81;
            v81 += 4;
            *(_WORD *)(v82 + 8) = v83;
          }
          while ( 14 * v23 != v80 );
          v70 += 4 * v23;
          *(_QWORD *)(a3 + 64) = v71;
          v84 = (_QWORD *)(a3 + 64);
        }
        else
        {
          v70 += 4 * v23;
          *(_QWORD *)(a3 + 64) = 0;
          v84 = (_QWORD *)(a3 + 64);
        }
        v87 = 0;
        v88 = 0;
        do
        {
          if ( !*v84 )
            break;
          v89 = (unsigned __int16 *)(*v84 + v87);
          LODWORD(v108) = v89[4];
          LODWORD(v107) = *((unsigned __int8 *)v89 + 7);
          qdf_trace_msg(
            0x31u,
            8u,
            "2 GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            (unsigned int)v88++,
            *v89,
            v89[1],
            v89[2],
            *((unsigned __int8 *)v89 + 6),
            v107,
            v108);
          v87 += 14;
        }
        while ( v23 != v88 );
      }
      else
      {
        *(_QWORD *)(a3 + 64) = 0;
        qdf_trace_msg(0x31u, 8u, "No 2ghz reg rule", v62, v63, v64, v65, v66, v67, v68, v69);
      }
      if ( (_DWORD)v24 )
      {
        v90 = _qdf_mem_malloc(14 * v24, "create_reg_rules_from_wmi", 17314);
        if ( v90 )
        {
          v99 = 0;
          v100 = v70 + 2;
          do
          {
            v101 = v90 + v99;
            v99 += 14;
            *(_WORD *)v101 = *(v100 - 1);
            *(_WORD *)(v101 + 2) = *((_WORD *)v100 - 1);
            *(_WORD *)(v101 + 4) = *v100;
            *(_BYTE *)(v101 + 6) = *((_WORD *)v100 + 1);
            *(_BYTE *)(v101 + 7) = *((_BYTE *)v100 + 3);
            v102 = v100[1];
            v100 += 4;
            *(_WORD *)(v101 + 8) = v102;
          }
          while ( 14 * v24 != v99 );
          *(_QWORD *)(a3 + 72) = v90;
          v103 = (_QWORD *)(a3 + 72);
        }
        else
        {
          *(_QWORD *)(a3 + 72) = 0;
          v103 = (_QWORD *)(a3 + 72);
        }
        v104 = 0;
        v105 = 0;
        do
        {
          if ( !*v103 )
            break;
          v106 = (unsigned __int16 *)(*v103 + v104);
          LODWORD(v108) = v106[4];
          LODWORD(v107) = *((unsigned __int8 *)v106 + 7);
          qdf_trace_msg(
            0x31u,
            8u,
            "5 GHz rule %u start freq %u end freq %u max_bw %u reg_power %u ant_gain %u flags %u",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            (unsigned int)v105++,
            *v106,
            v106[1],
            v106[2],
            *((unsigned __int8 *)v106 + 6),
            v107,
            v108);
          v104 += 14;
        }
        while ( v24 != v105 );
      }
      else
      {
        *(_QWORD *)(a3 + 72) = 0;
        qdf_trace_msg(0x31u, 8u, "No 5ghz reg rule", v72, v73, v74, v75, v76, v77, v78, v79);
      }
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: processed regulatory channel list",
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        "extract_reg_chan_list_update_event_tlv");
      return 0;
    }
    else
    {
      v85 = jiffies;
      if ( extract_reg_chan_list_update_event_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Invalid num_2g_reg_rules: %u, num_5g_reg_rules: %u",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "extract_reg_chan_list_update_event_tlv",
          (unsigned int)v23,
          (unsigned int)v24);
        extract_reg_chan_list_update_event_tlv___last_ticks = v85;
      }
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid channel list event buf",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "extract_reg_chan_list_update_event_tlv");
    return 16;
  }
}
