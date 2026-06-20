__int64 __fastcall qdf_dp_trace_dump_all(
        unsigned int a1,
        unsigned int a2,
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w20
  int v29; // w22
  int v30; // w8
  __int64 result; // x0
  __int64 *v32; // x8
  __int64 v33; // x9
  __int64 v34; // x10
  __int64 v35; // x10
  __int64 v36; // x9
  __int64 v37; // x9
  __int64 v38; // x10
  __int64 v39; // x8
  __int64 v40; // x11
  _QWORD *v41; // t2
  unsigned int v42; // w8
  _DWORD *v43; // x8
  __int64 *v44; // x8
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x10
  __int64 v48; // x9
  __int64 v49; // x9
  __int64 v50; // x10
  __int64 v51; // x8
  __int64 v52; // x11
  _QWORD *v53; // t2
  __int64 v54; // [xsp+0h] [xbp-F0h]
  __int64 v55; // [xsp+90h] [xbp-60h] BYREF
  __int64 v56; // [xsp+98h] [xbp-58h]
  __int64 v57; // [xsp+A0h] [xbp-50h]
  __int64 v58; // [xsp+A8h] [xbp-48h]
  __int64 v59; // [xsp+B0h] [xbp-40h]
  __int64 v60; // [xsp+B8h] [xbp-38h]
  __int64 v61; // [xsp+C0h] [xbp-30h]
  __int64 v62; // [xsp+C8h] [xbp-28h]
  __int64 v63; // [xsp+D0h] [xbp-20h]
  __int64 v64; // [xsp+D8h] [xbp-18h]
  __int64 v65; // [xsp+E0h] [xbp-10h]
  __int64 v66; // [xsp+E8h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v55 = 0;
  if ( (byte_7F7658 & 1) != 0 )
  {
    qdf_trace_msg(
      0x38u,
      8u,
      "DPT: config - bitmap 0x%x verb %u #rec %u live_config %u thresh %u time_limit %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      (unsigned int)dword_7F764C,
      (unsigned __int8)byte_7F7656,
      (unsigned __int8)byte_7F7650,
      (unsigned __int8)byte_7F7659,
      (unsigned __int8)byte_7F7667,
      (unsigned __int16)word_7F7668);
    LODWORD(v54) = (unsigned __int16)word_7F7676;
    qdf_trace_msg(
      0x38u,
      8u,
      "STATS |DPT: tx %u rx %u icmp(%u %u) arp(%u %u) icmpv6(%u %u %u %u %u %u) dhcp(%u %u %u %u %u %u) eapol(%u %u %u %u %u)",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      (unsigned int)dword_7F766C,
      (unsigned int)dword_7F7670,
      (unsigned __int16)word_7F768E,
      (unsigned __int16)word_7F7690,
      (unsigned __int16)word_7F7674,
      v54,
      (unsigned __int16)word_7F7692,
      (unsigned __int16)word_7F7694,
      (unsigned __int16)word_7F7696,
      (unsigned __int16)word_7F7698,
      (unsigned __int16)word_7F769C,
      (unsigned __int16)word_7F769E,
      (unsigned __int16)word_7F7678,
      (unsigned __int16)word_7F767C,
      (unsigned __int16)word_7F767A,
      (unsigned __int16)word_7F767E,
      (unsigned __int16)word_7F7680,
      (unsigned __int16)word_7F7682,
      (unsigned __int16)word_7F7684,
      (unsigned __int16)word_7F7686,
      (unsigned __int16)word_7F7688,
      (unsigned __int16)word_7F768A,
      (unsigned __int16)word_7F768C,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66);
    qdf_trace_msg(
      0x38u,
      8u,
      "DPT: Total Records: %d, Head: %d, Tail: %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      (unsigned int)dword_7F7648,
      (unsigned int)g_qdf_dp_trace_data,
      HIDWORD(g_qdf_dp_trace_data));
    raw_spin_lock_bh(&l_dp_trace_lock);
    v28 = g_qdf_dp_trace_data;
    if ( (_DWORD)g_qdf_dp_trace_data != -1 )
    {
      v29 = HIDWORD(g_qdf_dp_trace_data);
      if ( a1 )
      {
        v30 = dword_7F7648;
        if ( dword_7F7648 >= a1 )
          v30 = a1;
        if ( HIDWORD(g_qdf_dp_trace_data) >= v30 - 1 )
        {
          v28 = HIDWORD(g_qdf_dp_trace_data) - v30 + 1;
        }
        else if ( v30 != 2000 )
        {
          v28 = HIDWORD(g_qdf_dp_trace_data) - v30 + 2001;
        }
      }
      if ( v28 >= 0x7D1 )
        goto LABEL_24;
      v32 = (__int64 *)((char *)&g_qdf_dp_trace_tbl + 88 * v28);
      v33 = v32[8];
      v34 = v32[9];
      v65 = v32[10];
      v63 = v33;
      v64 = v34;
      v35 = v32[5];
      v59 = v32[4];
      v60 = v35;
      v36 = v32[7];
      v61 = v32[6];
      v62 = v36;
      v38 = *v32;
      v37 = v32[1];
      v41 = v32 + 2;
      v39 = v32[2];
      v40 = v41[1];
      v55 = v38;
      v56 = v37;
      v57 = v39;
      v58 = v40;
      raw_spin_unlock_bh(&l_dp_trace_lock);
      v42 = (unsigned __int8)v56;
      if ( (unsigned __int8)v56 > 0x2Cu )
      {
LABEL_24:
        __break(0x5512u);
      }
      else
      {
        while ( v42 <= 0x2C )
        {
          v43 = (_DWORD *)qdf_dp_trace_cb_table[v42];
          if ( *(v43 - 1) != -1036641460 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64 *, _QWORD, _QWORD, _QWORD))v43)(&v55, v28, a2, 0);
          if ( v28 == v29 )
            goto LABEL_11;
          raw_spin_lock_bh(&l_dp_trace_lock);
          if ( v28 == 1999 )
            v28 = 0;
          else
            ++v28;
          if ( v28 <= 0x7D0 )
          {
            v44 = (__int64 *)((char *)&g_qdf_dp_trace_tbl + 88 * v28);
            v45 = v44[8];
            v46 = v44[9];
            v65 = v44[10];
            v63 = v45;
            v64 = v46;
            v47 = v44[5];
            v59 = v44[4];
            v60 = v47;
            v48 = v44[7];
            v61 = v44[6];
            v62 = v48;
            v50 = *v44;
            v49 = v44[1];
            v53 = v44 + 2;
            v51 = v44[2];
            v52 = v53[1];
            v55 = v50;
            v56 = v49;
            v57 = v51;
            v58 = v52;
            raw_spin_unlock_bh(&l_dp_trace_lock);
            v42 = (unsigned __int8)v56;
            if ( (unsigned __int8)v56 < 0x2Du )
              continue;
          }
          goto LABEL_24;
        }
      }
      __break(1u);
    }
    result = raw_spin_unlock_bh(&l_dp_trace_lock);
  }
  else
  {
    result = qdf_trace_msg(0x38u, 8u, "Tracing Disabled", a3, a4, a5, a6, a7, a8, a9, a10);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
