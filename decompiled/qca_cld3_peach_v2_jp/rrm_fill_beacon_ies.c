__int64 __fastcall rrm_fill_beacon_ies(
        _DWORD *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        char a4,
        unsigned __int8 a5,
        unsigned __int8 *a6,
        unsigned __int8 a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned __int16 *a17)
{
  _DWORD *v18; // x22
  unsigned __int8 v20; // w24
  char v22; // w27
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w8
  __int16 v34; // w9
  unsigned int v35; // w24
  unsigned __int16 v36; // w25
  unsigned __int8 *v37; // x26
  __int64 v38; // x8
  __int64 v39; // x4
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x24
  __int64 v49; // x28
  unsigned __int16 v50; // w27
  int v51; // w8
  __int64 v52; // x10
  unsigned __int8 *v53; // x11
  unsigned __int8 *v54; // x12
  bool v55; // zf
  int v56; // w9
  int v57; // t1
  int v58; // w5
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v68; // [xsp+Ch] [xbp-14h]
  __int64 v69; // [xsp+10h] [xbp-10h]
  int v70; // [xsp+1Ch] [xbp-4h]

  if ( a1 && a2 )
  {
    v18 = a1;
    if ( a6 )
      v20 = a7;
    else
      v20 = 0;
    if ( a3 )
      v22 = a4;
    else
      v22 = 0;
    qdf_trace_msg(0x35u, 2u, "%s: extn_eids_count %d", a9, a10, a11, a12, a13, a14, a15, a16, "rrm_fill_beacon_ies", a7);
    v33 = *a17;
    v34 = v33 - 102;
    if ( (unsigned __int16)(v33 - 102) >= (unsigned int)(unsigned __int16)a8 )
    {
      v36 = v34 - a8;
      *a2 = 0;
      if ( !(_WORD)a8 )
      {
        *v18 = *((_DWORD *)a17 + 2);
        *a2 += 4;
        v18[1] = *((_DWORD *)a17 + 3);
        *a2 += 4;
        *((_WORD *)v18 + 4) = a17[8];
        *a2 += 2;
        *((_WORD *)v18 + 5) = a17[9];
        v18 += 3;
        *a2 += 2;
      }
      if ( (unsigned __int16)(v34 - a8) >= 2u )
      {
        v68 = v33 - 102;
        v70 = a5;
        v37 = (unsigned __int8 *)a17 + (unsigned __int16)a8 + 104;
        if ( ((v20 + v22) & 0xFE) != 0 )
          v38 = (unsigned __int8)(v20 + v22);
        else
          v38 = 1;
        v69 = v38;
        while ( 1 )
        {
          v48 = v37[1];
          v49 = v48 + 2;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: EID = %d, len = %d total = %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "rrm_fill_beacon_ies",
            *v37,
            v48,
            (unsigned int)(v48 + 2));
          if ( *v37 == 255 && v37[2] )
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Extended EID = %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "rrm_fill_beacon_ies");
          v50 = v36;
          if ( !(_DWORD)v48 || (unsigned int)v49 > v36 )
            break;
          if ( a3 )
          {
            v51 = *v37;
            v52 = v69;
            v53 = a6;
            v54 = a3;
            if ( a6 )
              v55 = v51 == v70;
            else
              v55 = 0;
            v56 = v55;
            while ( 1 )
            {
              v57 = *v54++;
              if ( v51 == v57 || v56 && v37[2] == *v53 )
                break;
              --v52;
              ++v53;
              if ( !v52 )
                goto LABEL_20;
            }
          }
          v58 = *a2;
          if ( (unsigned int)(v49 + v58) <= 0xD6 )
          {
            qdf_mem_copy(v18, v37, (unsigned int)v49);
            v39 = (unsigned __int8)(*a2 + v49);
            v18 = (_DWORD *)((char *)v18 + v49);
            *a2 += v49;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: ies_filled_len:%d last_filled_ie_len:%d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "rrm_fill_beacon_ies",
              v39,
              (unsigned int)v49);
          }
          else
          {
            if ( (_WORD)a8 )
              v35 = v68 - a8 - v58;
            else
              v35 = v68 - a8 - v58 + 12;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: rem_len %d ies added %d",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "rrm_fill_beacon_ies",
              (unsigned __int16)v35);
            if ( (_WORD)v35 )
              goto LABEL_45;
          }
LABEL_20:
          v36 -= v49;
          v37 += (unsigned int)v49;
          if ( (unsigned __int16)(v50 - v49) <= 1u )
            goto LABEL_44;
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: RRM: Invalid IE len:%d exp_len:%d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "rrm_fill_beacon_ies",
          (unsigned int)v49,
          v36);
      }
LABEL_44:
      v35 = 0;
LABEL_45:
      _qdf_mem_free(0);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Total length of Ies added = %d rem_len %d",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "rrm_fill_beacon_ies",
        *a2,
        (unsigned __int16)v35);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid start offset %d Bcn IE len %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "rrm_fill_beacon_ies",
        (unsigned __int16)a8);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid parameters", a9, a10, a11, a12, a13, a14, a15, a16, "rrm_fill_beacon_ies");
    return 0;
  }
  return v35;
}
