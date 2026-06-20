__int64 __fastcall extract_mlo_link_recfg_indication_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11,
        unsigned __int8 *a12)
{
  __int64 v13; // x21
  int v15; // w0
  __int64 v16; // x4
  __int64 v17; // x5
  int v18; // w8
  __int64 v19; // x6
  __int64 v20; // x7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w4
  unsigned int v38; // w8
  __int64 v39; // x9
  __int64 v40; // x20
  __int64 v42; // x20
  __int64 v43; // x20
  __int64 v44; // x21
  __int64 v45; // x21
  int v46; // w23
  _BYTE *v47; // x24
  unsigned int *v48; // x25
  __int64 v49; // x6
  __int64 v50; // x7
  int v51; // w10
  __int64 v52; // x5
  unsigned int v53; // w8
  int v54; // w8
  unsigned int v55; // w9
  unsigned int v56; // w11
  unsigned int v57; // w10
  unsigned int v58; // w12
  unsigned int v59; // w13
  __int64 v60; // x20
  __int64 v61; // x20
  unsigned int v62; // w8
  int v63; // w23
  _BYTE *v64; // x24
  __int64 v65; // x25
  __int64 v66; // x6
  __int64 v67; // x7
  int v68; // w9
  __int64 v69; // x5
  int v70; // w8
  int v71; // w10
  int v72; // w9
  int v73; // w11
  int v74; // w12
  __int64 v75; // [xsp+0h] [xbp-30h]
  __int64 v76; // [xsp+8h] [xbp-28h]

  if ( !a12 )
  {
    v40 = jiffies;
    if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: params is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_recfg_indication_event_tlv");
      extract_mlo_link_recfg_indication_event_tlv___last_ticks = v40;
      return 29;
    }
    return 29;
  }
  if ( !a10 )
  {
    v42 = jiffies;
    if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_87 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: buf is NULL",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_recfg_indication_event_tlv");
      extract_mlo_link_recfg_indication_event_tlv___last_ticks_87 = v42;
      return 29;
    }
    return 29;
  }
  v13 = *a10;
  if ( !*a10 )
  {
    v43 = jiffies;
    if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_88 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: fixed_param null",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_mlo_link_recfg_indication_event_tlv");
      extract_mlo_link_recfg_indication_event_tlv___last_ticks_88 = v43;
      return 4;
    }
    return 4;
  }
  *a12 = *(_DWORD *)(v13 + 4);
  *(_WORD *)(a12 + 1) = *(_DWORD *)(v13 + 8);
  a12[3] = *(_WORD *)(v13 + 10);
  a12[4] = *(_BYTE *)(v13 + 11);
  *(_WORD *)(a12 + 5) = *(_DWORD *)(v13 + 12);
  v15 = wmi_convert_fw_to_cm_trig_reason(*(unsigned int *)(v13 + 16));
  *((_DWORD *)a12 + 2) = v15;
  v16 = *a12;
  v17 = a12[1];
  v18 = *(_DWORD *)(v13 + 20);
  v19 = a12[2];
  v20 = a12[3];
  *((_DWORD *)a12 + 3) = v18;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev %d ap mld %02x:%02x:%02x:**:**:%02x fw reason %d (%d) result %d add num %d del num %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "extract_mlo_link_recfg_indication_event_tlv",
    v16,
    v17,
    v19,
    v20,
    a12[6],
    *(_DWORD *)(v13 + 16),
    v15,
    v18,
    *((_DWORD *)a10 + 6),
    *((_DWORD *)a10 + 10));
  v37 = *((_DWORD *)a10 + 6);
  if ( !v37 )
  {
    v38 = *((_DWORD *)a10 + 10);
    if ( !v38 )
    {
      v45 = jiffies;
      if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_91 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: add_num %d del_num %d invalid, max num %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "extract_mlo_link_recfg_indication_event_tlv",
          0,
          0,
          3);
        extract_mlo_link_recfg_indication_event_tlv___last_ticks_91 = v45;
      }
      return 4 * (unsigned int)(*((_DWORD *)a12 + 2) != 9);
    }
    if ( v38 <= 3 )
    {
      if ( !a10[4] )
        goto LABEL_34;
      LOBYTE(v53) = 0;
LABEL_39:
      a12[136] = v53;
      v62 = *((_DWORD *)a10 + 10);
      if ( v62 )
      {
        v63 = 0;
        v64 = a12 + 157;
        v65 = a10[4] + 8;
        do
        {
          v70 = *(_DWORD *)(v65 - 4);
          *(v64 - 12) = v70;
          v71 = *(_DWORD *)v65;
          *(v64 - 5) = *(_DWORD *)v65;
          v72 = *(_DWORD *)v65;
          *(v64 - 4) = BYTE1(*(_DWORD *)v65);
          v73 = *(_DWORD *)v65;
          *(v64 - 3) = BYTE2(*(_DWORD *)v65);
          *(v64 - 2) = *(_BYTE *)(v65 + 3);
          *(v64 - 1) = *(_DWORD *)(v65 + 4);
          v74 = *(_DWORD *)(v65 + 4);
          *v64 = BYTE1(v74);
          if ( v64 == (_BYTE *)&off_0 + 5 )
          {
            v67 = 0;
            v69 = 0;
            v66 = 0;
            v68 = 0;
          }
          else
          {
            v66 = BYTE1(v72);
            v67 = BYTE2(v73);
            v68 = BYTE1(v74);
            v69 = (unsigned __int8)v71;
          }
          v65 += 16;
          LODWORD(v75) = v68;
          qdf_trace_msg(
            0x31u,
            8u,
            "%s: del link %d ap link addr %02x:%02x:%02x:**:**:%02x",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "extract_mlo_link_recfg_indication_event_tlv",
            (unsigned __int8)v70,
            v69,
            v66,
            v67,
            v75);
          v62 = *((_DWORD *)a10 + 10);
          ++v63;
          v64 += 40;
        }
        while ( v62 > (unsigned __int8)v63 );
      }
      a12[264] = v62;
      return 0;
    }
LABEL_19:
    v44 = jiffies;
    if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_93 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: add_num %d del_num %d exceed max num %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "extract_mlo_link_recfg_indication_event_tlv");
      extract_mlo_link_recfg_indication_event_tlv___last_ticks_93 = v44;
      return 4;
    }
    return 4;
  }
  if ( v37 > 3 )
    goto LABEL_19;
  v38 = *((_DWORD *)a10 + 10);
  if ( v38 >= 4 )
    goto LABEL_19;
  v39 = a10[2];
  if ( v39 )
  {
    if ( v38 )
    {
      if ( !a10[4] )
      {
LABEL_34:
        v60 = jiffies;
        if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_97 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: del_num %d but link_del_param null",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "extract_mlo_link_recfg_indication_event_tlv",
            v38);
          extract_mlo_link_recfg_indication_event_tlv___last_ticks_97 = v60;
          return 4;
        }
        return 4;
      }
      v39 = a10[2];
    }
    v46 = 0;
    v47 = a12 + 29;
    v48 = (unsigned int *)(v39 + 8);
    do
    {
      v54 = *(v48 - 1);
      *(v47 - 12) = v54;
      v55 = v48[2];
      *(v47 - 13) = v55;
      v56 = *v48;
      *(v47 - 5) = *v48;
      v57 = *v48;
      *(v47 - 4) = BYTE1(*v48);
      v58 = *v48;
      *(v47 - 3) = BYTE2(*v48);
      *(v47 - 2) = *((_BYTE *)v48 + 3);
      *(v47 - 1) = v48[1];
      v59 = v48[1];
      *v47 = BYTE1(v59);
      if ( v47 == (_BYTE *)&off_0 + 5 )
      {
        v50 = 0;
        v52 = 0;
        v49 = 0;
        v51 = 0;
      }
      else
      {
        v49 = BYTE1(v57);
        v50 = BYTE2(v58);
        v51 = BYTE1(v59);
        v52 = (unsigned __int8)v56;
      }
      v48 += 5;
      LODWORD(v76) = (unsigned __int8)v55;
      LODWORD(v75) = v51;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: add link %d ap link addr %02x:%02x:%02x:**:**:%02x vdev %d",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "extract_mlo_link_recfg_indication_event_tlv",
        (unsigned __int8)v54,
        v52,
        v49,
        v50,
        v75,
        v76);
      v53 = *((_DWORD *)a10 + 6);
      ++v46;
      v47 += 40;
    }
    while ( v53 > (unsigned __int8)v46 );
    goto LABEL_39;
  }
  v61 = jiffies;
  if ( extract_mlo_link_recfg_indication_event_tlv___last_ticks_95 - jiffies + 125 >= 0 )
    return 4;
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: add_num %d but link_add_param null",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "extract_mlo_link_recfg_indication_event_tlv");
  extract_mlo_link_recfg_indication_event_tlv___last_ticks_95 = v61;
  return 4;
}
