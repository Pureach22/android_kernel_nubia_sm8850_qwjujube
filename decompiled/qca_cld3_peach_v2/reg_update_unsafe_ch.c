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
  __int64 v17; // x28
  __int64 v18; // x25
  __int64 v19; // x23
  __int64 v20; // x22
  const char *v21; // x2
  unsigned int *v22; // x21
  unsigned __int8 v23; // w27
  unsigned __int8 v24; // w26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int *v33; // x10
  __int64 v34; // x8
  unsigned int *v35; // x11
  unsigned int v36; // t1
  unsigned int v37; // w11
  int v38; // w9
  __int64 v39; // x12
  unsigned int v40; // t1
  bool v41; // cc
  int v42; // w11
  int v43; // w10
  unsigned int v44; // w10
  unsigned int v45; // w10
  __int64 v46; // x12
  __int64 v47; // x9
  __int16 v48; // w14
  __int64 v49; // x8
  __int16 v50; // w13
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x11
  int v54; // w13
  unsigned __int64 v55; // x21
  __int64 result; // x0
  __int64 v57; // [xsp+0h] [xbp-10h]
  __int64 v58; // [xsp+8h] [xbp-8h]

  psoc_obj = reg_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v21 = "%s: reg psoc private obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v21, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v57);
  }
  v13 = psoc_obj;
  pdev_obj = reg_get_pdev_obj(a2);
  if ( !pdev_obj )
  {
    v21 = "%s: reg pdev priv obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v21, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v57);
  }
  v15 = pdev_obj;
  if ( *(_BYTE *)(v13 + 91680) )
  {
    v16 = reg_get_psoc_obj(a1);
    if ( v16 )
    {
      v17 = v16 + 90112;
      v57 = v15;
      v58 = v16;
      if ( *(_DWORD *)(v16 + 92404) )
      {
        v18 = 0;
        v19 = v16 + 92408;
        v20 = v16 + 91686;
        while ( *(unsigned __int16 *)(v17 + 1572) < 0x66u )
        {
          if ( v18 == 43 )
          {
LABEL_49:
            __break(0x5512u);
            JUMPOUT(0xFFFFFFFFFC9B4C84LL);
          }
          v22 = (unsigned int *)(v19 + 16 * v18);
          v23 = reg_freq_to_chan(a2, *v22);
          v24 = reg_freq_to_chan(a2, v22[1]);
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: start: freq %d, ch %d, end: freq %d, ch %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "reg_process_ch_avoid_freq",
            *v22,
            v23,
            v22[1],
            v24);
          if ( v23 && v24 )
          {
            v33 = (unsigned int *)channel_map;
            v34 = 0;
            v35 = (unsigned int *)channel_map;
            do
            {
              v36 = *v35;
              v35 += 3;
              if ( v36 >= *v22 )
                break;
              ++v34;
            }
            while ( v34 != 102 );
            v37 = v22[1];
            v38 = 0;
            v39 = 0;
            while ( 1 )
            {
              v40 = *v33;
              v33 += 3;
              v41 = v40 > v37;
              if ( v40 >= v37 )
                break;
              --v39;
              ++v38;
              if ( v39 == -102 )
                goto LABEL_10;
            }
            if ( v41 )
              v42 = -1;
            else
              v42 = 0;
            if ( v41 )
              v43 = -1;
            else
              v43 = 0;
            if ( (unsigned int)v34 <= 0x65 )
            {
              v44 = v43 - v39;
              if ( v44 <= 0x65 && (unsigned int)v34 <= v44 )
              {
                v45 = *(unsigned __int16 *)(v17 + 1572);
                v46 = (unsigned int)v34;
                v47 = (unsigned int)(v42 + v38);
                v48 = v34 - v45;
                v49 = 3LL * (unsigned int)v34;
                if ( v45 <= 0x66 )
                  v50 = 102;
                else
                  v50 = *(_WORD *)(v17 + 1572);
                v51 = 4 * v49;
                v52 = v47 - v46 + 1;
                v53 = (unsigned __int16)(v48 + v50) - v46;
                while ( 1 )
                {
                  v54 = *(_DWORD *)(channel_map + v51);
                  *(_WORD *)(v17 + 1572) = v45 + 1;
                  if ( !v53 )
                    goto LABEL_49;
                  *(_WORD *)(v20 + 2LL * (unsigned __int16)v45) = v54;
                  if ( (unsigned __int16)(v45 + 1) >= 0x66u )
                    break;
                  --v52;
                  --v53;
                  v51 += 12;
                  LOWORD(v45) = v45 + 1;
                  if ( !v52 )
                    goto LABEL_10;
                }
                qdf_trace_msg(
                  0x51u,
                  3u,
                  "%s: LTECoex unsafe ch list full",
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  v12,
                  "reg_process_ch_avoid_freq");
              }
            }
          }
LABEL_10:
          if ( ++v18 >= (unsigned __int64)*(unsigned int *)(v17 + 2292) )
            goto LABEL_41;
        }
        qdf_trace_msg(
          0x51u,
          3u,
          "%s: LTE Coex unsafe channel list full",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "reg_process_ch_avoid_freq");
      }
LABEL_41:
      v15 = v57;
      if ( *(_WORD *)(v17 + 1572) )
      {
        v55 = 0;
        do
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: Unsafe freq %d",
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            "reg_process_ch_avoid_freq",
            *(unsigned __int16 *)(v58 + 91686 + 2 * v55),
            v57);
          if ( v55 > 0x64 )
            break;
          ++v55;
        }
        while ( v55 < *(unsigned __int16 *)(v17 + 1572) );
      }
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg psoc private obj is NULL",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "reg_process_ch_avoid_freq");
      *(_BYTE *)(v13 + 91680) = 0;
    }
  }
  reg_compute_pdev_current_chan_list(v15, v5, v6, v7, v8, v9, v10, v11, v12);
  result = reg_send_scheduler_msg_nb(a1, a2);
  if ( (_DWORD)result )
  {
    v21 = "%s: channel change msg schedule failed";
    return qdf_trace_msg(0x51u, 2u, v21, v5, v6, v7, v8, v9, v10, v11, v12, "reg_update_unsafe_ch", v57);
  }
  return result;
}
