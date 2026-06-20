__int64 __fastcall reg_update_unsafe_ch(__int64 a1, __int64 a2)
{
  __int64 psoc_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x23
  __int64 pdev_obj; // x0
  __int64 v15; // x25
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x28
  __int64 v26; // x25
  __int64 v27; // x23
  __int64 v28; // x22
  const char *v29; // x2
  unsigned int *v30; // x21
  unsigned __int8 v31; // w27
  unsigned __int8 v32; // w26
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int *v41; // x10
  __int64 v42; // x8
  unsigned int *v43; // x11
  unsigned int v44; // t1
  unsigned int v45; // w11
  int v46; // w9
  __int64 v47; // x12
  unsigned int v48; // t1
  bool v49; // cc
  int v50; // w11
  int v51; // w10
  unsigned int v52; // w10
  unsigned int v53; // w10
  __int64 v54; // x12
  __int64 v55; // x9
  __int16 v56; // w14
  __int64 v57; // x8
  __int16 v58; // w13
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x11
  int v62; // w13
  unsigned __int64 v63; // x21
  __int64 result; // x0
  __int64 v65; // [xsp+0h] [xbp-10h]
  __int64 v66; // [xsp+8h] [xbp-8h]

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v29 = "%s: reg psoc private obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v29, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v65);
  }
  v13 = psoc_obj;
  pdev_obj = reg_get_pdev_obj(a2);
  if ( !pdev_obj )
  {
    v29 = "%s: reg pdev priv obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v29, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v65);
  }
  v15 = pdev_obj;
  if ( *(_BYTE *)(v13 + 91680) )
  {
    v16 = reg_get_psoc_obj(a1);
    if ( v16 )
    {
      v25 = v16 + 90112;
      v65 = v15;
      v66 = v16;
      if ( *(_DWORD *)(v16 + 92404) )
      {
        v26 = 0;
        v27 = v16 + 92408;
        v28 = v16 + 91686;
        while ( *(unsigned __int16 *)(v25 + 1572) < 0x66u )
        {
          if ( v26 == 43 )
          {
LABEL_49:
            __break(0x5512u);
            JUMPOUT(0xFFFFFFFFFC998C20LL);
          }
          v30 = (unsigned int *)(v27 + 16 * v26);
          v31 = reg_freq_to_chan(a2, *v30);
          v32 = reg_freq_to_chan(a2, v30[1]);
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: start: freq %d, ch %d, end: freq %d, ch %d",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "reg_process_ch_avoid_freq",
            *v30,
            v31,
            v30[1],
            v32);
          if ( v31 && v32 )
          {
            v41 = (unsigned int *)channel_map;
            v42 = 0;
            v43 = (unsigned int *)channel_map;
            do
            {
              v44 = *v43;
              v43 += 3;
              if ( v44 >= *v30 )
                break;
              ++v42;
            }
            while ( v42 != 102 );
            v45 = v30[1];
            v46 = 0;
            v47 = 0;
            while ( 1 )
            {
              v48 = *v41;
              v41 += 3;
              v49 = v48 > v45;
              if ( v48 >= v45 )
                break;
              --v47;
              ++v46;
              if ( v47 == -102 )
                goto LABEL_10;
            }
            if ( v49 )
              v50 = -1;
            else
              v50 = 0;
            if ( v49 )
              v51 = -1;
            else
              v51 = 0;
            if ( (unsigned int)v42 <= 0x65 )
            {
              v52 = v51 - v47;
              if ( v52 <= 0x65 && (unsigned int)v42 <= v52 )
              {
                v53 = *(unsigned __int16 *)(v25 + 1572);
                v54 = (unsigned int)v42;
                v55 = (unsigned int)(v50 + v46);
                v56 = v42 - v53;
                v57 = 3LL * (unsigned int)v42;
                if ( v53 <= 0x66 )
                  v58 = 102;
                else
                  v58 = *(_WORD *)(v25 + 1572);
                v59 = 4 * v57;
                v60 = v55 - v54 + 1;
                v61 = (unsigned __int16)(v56 + v58) - v54;
                while ( 1 )
                {
                  v62 = *(_DWORD *)(channel_map + v59);
                  *(_WORD *)(v25 + 1572) = v53 + 1;
                  if ( !v61 )
                    goto LABEL_49;
                  *(_WORD *)(v28 + 2LL * (unsigned __int16)v53) = v62;
                  if ( (unsigned __int16)(v53 + 1) >= 0x66u )
                    break;
                  --v60;
                  --v61;
                  v59 += 12;
                  LOWORD(v53) = v53 + 1;
                  if ( !v60 )
                    goto LABEL_10;
                }
                qdf_trace_msg(
                  0x51u,
                  3u,
                  "%s: LTECoex unsafe ch list full",
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  "reg_process_ch_avoid_freq");
              }
            }
          }
LABEL_10:
          if ( ++v26 >= (unsigned __int64)*(unsigned int *)(v25 + 2292) )
            goto LABEL_41;
        }
        qdf_trace_msg(
          0x51u,
          3u,
          "%s: LTE Coex unsafe channel list full",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "reg_process_ch_avoid_freq");
      }
LABEL_41:
      v15 = v65;
      if ( *(_WORD *)(v25 + 1572) )
      {
        v63 = 0;
        do
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Unsafe freq %d",
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            "reg_process_ch_avoid_freq",
            *(unsigned __int16 *)(v66 + 91686 + 2 * v63),
            v65);
          if ( v63 > 0x64 )
            break;
          ++v63;
        }
        while ( v63 < *(unsigned __int16 *)(v25 + 1572) );
      }
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg psoc private obj is NULL",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "reg_process_ch_avoid_freq");
      *(_BYTE *)(v13 + 91680) = 0;
    }
  }
  reg_compute_pdev_current_chan_list(v15);
  result = reg_send_scheduler_msg_nb(a1, a2);
  if ( (_DWORD)result )
  {
    v29 = "%s: channel change msg schedule failed";
    return qdf_trace_msg(0x51u, 2u, v29, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v65);
  }
  return result;
}
