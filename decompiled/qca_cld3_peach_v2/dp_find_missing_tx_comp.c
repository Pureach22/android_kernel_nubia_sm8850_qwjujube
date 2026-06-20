__int64 __fastcall dp_find_missing_tx_comp(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x23
  unsigned __int64 v10; // x20
  __int64 v11; // x22
  _QWORD *v12; // x21
  __int64 v13; // x1
  unsigned int v14; // w8
  unsigned int v15; // w9
  __int64 v16; // x10
  unsigned int v17; // w8
  unsigned int v18; // w9
  int v19; // w10
  __int64 v20; // x21
  __int64 v21; // x6
  __int64 v22; // x5
  __int64 i; // x20
  unsigned __int16 *v24; // x21
  int v25; // w24
  unsigned int v26; // w19
  unsigned int v27; // w27
  __int64 v28; // x22
  __int64 v29; // x8
  __int64 v30; // x28
  int v31; // w8
  __int64 v32; // x26
  __int64 v33; // x25
  __int64 v34; // x22
  unsigned int v35; // w26
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x22
  __int64 v46; // x22
  int v47; // w10
  __int64 v48; // x21
  __int64 v49; // x6
  __int64 v50; // x5

  v9 = result;
  if ( !*(_BYTE *)(result + 7201) )
  {
LABEL_17:
    for ( i = 0; i != 6; ++i )
    {
      v24 = (unsigned __int16 *)(v9 + 2304 + 296 * i);
      v25 = v24[28];
      if ( v24[28] && *((_DWORD *)v24 + 16) != 6 && *((_QWORD *)v24 + 4) )
      {
        v26 = v24[8];
        v27 = 0;
        do
        {
          v29 = *((_QWORD *)v24 + 4);
          if ( !v29 )
            break;
          v30 = *(_QWORD *)(v29 + 8LL * (unsigned __int16)(v27 / v26)) + (int)(v27 % v26 * *v24);
          v31 = *(_DWORD *)(v30 + 20);
          if ( v31 != -559038737 )
          {
            if ( v31 == -1412623820 )
            {
              v32 = *(_QWORD *)(v30 + 24);
              result = ktime_get_with_offset(0);
              if ( v32 )
              {
                v33 = jiffies;
                result = jiffies_to_msecs(jiffies - v32);
                if ( (unsigned int)result >> 5 >= 0x753 )
                {
                  v34 = jiffies;
                  if ( dp_tx_comp_delay_check___last_ticks_127 - jiffies + 125 < 0 )
                  {
                    v35 = jiffies_to_msecs(v32);
                    v36 = jiffies_to_msecs(v33);
                    result = qdf_trace_msg(
                               0x45u,
                               2u,
                               "%s: enqueued: %u ms, current : %u ms",
                               v37,
                               v38,
                               v39,
                               v40,
                               v41,
                               v42,
                               v43,
                               v44,
                               "dp_tx_comp_delay_check",
                               v35,
                               v36);
                    dp_tx_comp_delay_check___last_ticks_127 = v34;
                  }
                  v45 = jiffies;
                  if ( dp_find_missing_tx_comp___last_ticks - jiffies + 125 < 0 )
                  {
                    result = qdf_trace_msg(
                               0x45u,
                               2u,
                               "%s: Tx completion not rcvd for id: %u",
                               a2,
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               "dp_find_missing_tx_comp",
                               *(unsigned int *)(v30 + 36));
                    dp_find_missing_tx_comp___last_ticks = v45;
                  }
                  if ( *(unsigned __int8 *)(v30 + 48) == 255 )
                  {
                    *(_DWORD *)(v30 + 32) |= 0x2000u;
                    v46 = jiffies;
                    if ( dp_find_missing_tx_comp___last_ticks_63 - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x45u,
                        2u,
                        "%s: Freed tx_desc %u",
                        a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        "dp_find_missing_tx_comp",
                        *(unsigned int *)(v30 + 36));
                      dp_find_missing_tx_comp___last_ticks_63 = v46;
                    }
                    dp_tx_comp_free_buf(v9, v30, 0);
                    result = dp_tx_desc_release(v9, v30, (unsigned int)i);
                    if ( v9 )
                      ++*(_DWORD *)(v9 + 13620);
                  }
                }
              }
            }
            else
            {
              v28 = jiffies;
              if ( dp_find_missing_tx_comp___last_ticks_65 - jiffies + 125 < 0 )
              {
                result = qdf_trace_msg(
                           0x45u,
                           2u,
                           "%s: tx desc %u corrupted, flags: 0x%x",
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           "dp_find_missing_tx_comp",
                           *(unsigned int *)(v30 + 36),
                           *(unsigned int *)(v30 + 32));
                dp_find_missing_tx_comp___last_ticks_65 = v28;
              }
            }
          }
          ++v27;
        }
        while ( v25 != v27 );
      }
    }
    return result;
  }
  v10 = 0;
  v11 = 1;
  v12 = (_QWORD *)(result + 6800);
  while ( 1 )
  {
    result = dp_ipa_is_ring_ipa_tx(v9, (unsigned int)v10);
    if ( (result & 1) != 0 )
      goto LABEL_3;
    if ( v10 >= 5 )
    {
      __break(0x5512u);
      return dp_soc_attach_wifi3(result, v13);
    }
    v14 = *(_DWORD *)(*v12 + 120LL);
    v15 = **(_DWORD **)(*v12 + 128LL);
    if ( v14 != v15 )
      break;
    if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v9 + 40) + 776LL) + v11) != 15 )
    {
      v16 = v12[71];
      v17 = *(_DWORD *)(v16 + 120);
      v18 = **(_DWORD **)(v16 + 128);
      if ( v17 != v18 )
      {
        v19 = *(_DWORD *)(v16 + 116);
        v20 = jiffies;
        if ( dp_check_pending_tx___last_ticks_123 - jiffies + 125 < 0 )
        {
          if ( v19 )
            v21 = v17;
          else
            v21 = v18;
          if ( v19 )
            v22 = v18;
          else
            v22 = v17;
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: Pending transactions in TX comp Ring[%d] hp=0x%x, tp=0x%x",
                     a2,
                     a3,
                     a4,
                     a5,
                     a6,
                     a7,
                     a8,
                     a9,
                     "dp_check_pending_tx",
                     (unsigned int)v10,
                     v22,
                     v21);
          dp_check_pending_tx___last_ticks_123 = v20;
        }
        return result;
      }
    }
LABEL_3:
    ++v10;
    v12 += 10;
    v11 += 4;
    if ( v10 >= *(unsigned __int8 *)(v9 + 7201) )
      goto LABEL_17;
  }
  v47 = *(_DWORD *)(*v12 + 116LL);
  v48 = jiffies;
  if ( dp_check_pending_tx___last_ticks - jiffies + 125 < 0 )
  {
    if ( v47 )
      v49 = v14;
    else
      v49 = v15;
    if ( v47 )
      v50 = v15;
    else
      v50 = v14;
    result = qdf_trace_msg(
               0x45u,
               5u,
               "%s: Pending transactions in TCL DATA Ring[%d] hp=0x%x, tp=0x%x",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dp_check_pending_tx",
               (unsigned int)v10,
               v50,
               v49);
    dp_check_pending_tx___last_ticks = v48;
  }
  return result;
}
