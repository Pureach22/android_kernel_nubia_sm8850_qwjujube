__int64 __fastcall dp_rx_mon_stitch_mpdu(__int64 a1, __int64 *a2)
{
  __int64 v2; // x23
  int v3; // w8
  __int64 v4; // x19
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 i; // x21
  int v19; // w24
  __int64 v20; // x0
  _QWORD *v21; // x8
  int v22; // w9
  _QWORD *j; // x10
  __int64 v24; // x12
  bool v25; // zf
  int v26; // w11
  __int64 *v27; // x11
  __int64 *v28; // x13
  int v29; // w8
  int v30; // w9
  __int64 v31; // x0
  __int64 v32; // x1
  int v33; // w8
  __int64 v34; // x24
  int v35; // w8
  __int64 *v36; // x0
  __int64 *v37; // x9
  __int64 v38; // x8

  v2 = a1 + 0x4000;
  v3 = *(_DWORD *)(a1 + 18448);
  if ( !v3 )
    return 0;
  v4 = *(_QWORD *)(a1 + 18432);
  if ( !v4 )
  {
    v9 = skb_copy(0, 2080);
    if ( v9 )
    {
      i = v9;
      v19 = 0;
      goto LABEL_30;
    }
    goto LABEL_41;
  }
  v7 = *(_QWORD *)(a1 + 18440);
  *(_DWORD *)(a1 + 18448) = v3 - 1;
  if ( v4 == v7 )
  {
    v8 = 0;
    *(_QWORD *)(a1 + 18440) = 0;
  }
  else
  {
    v8 = *(_QWORD *)v4;
  }
  *(_QWORD *)(a1 + 18432) = v8;
  *(_QWORD *)v4 = 0;
  v20 = skb_copy(v4, 2080);
  if ( !v20 )
  {
LABEL_41:
    v34 = jiffies;
    if ( dp_rx_mon_stitch_mpdu___last_ticks - jiffies + 125 < 0 )
    {
      if ( (*(_BYTE *)(v4 + 68) & 4) != 0 )
        v35 = *(unsigned __int16 *)(v4 + 66);
      else
        v35 = 0;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: nbuf copy failed len: %zu Q1: %d Q2: %d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "dp_rx_mon_stitch_mpdu",
        (unsigned int)(*(_DWORD *)(v4 + 112) + v35),
        *(unsigned int *)(v2 + 2064),
        *(unsigned int *)(v2 + 2088));
      dp_rx_mon_stitch_mpdu___last_ticks = v34;
    }
    if ( v4 )
    {
      _qdf_nbuf_free(v4);
      v36 = *(__int64 **)(a1 + 18432);
      for ( i = 0; v36 != a2 && v36; i = 0 )
      {
        v37 = *(__int64 **)(a1 + 18440);
        --*(_DWORD *)(v2 + 2064);
        if ( v36 == v37 )
        {
          v38 = 0;
          *(_QWORD *)(a1 + 18440) = 0;
        }
        else
        {
          v38 = *v36;
        }
        *(_QWORD *)(a1 + 18432) = v38;
        *v36 = 0;
        _qdf_nbuf_free((__int64)v36);
        v36 = *(__int64 **)(a1 + 18432);
      }
      return i;
    }
    return 0;
  }
  i = v20;
  v19 = 0;
  v21 = nullptr;
  v22 = 1;
  for ( j = (_QWORD *)v4; ; j = v27 )
  {
    if ( v22 )
      v25 = j == (_QWORD *)v4;
    else
      v25 = 1;
    if ( !v25 )
      v21 = j;
    if ( j != (_QWORD *)v4 )
      v22 = 0;
    if ( !v22 )
    {
      if ( (*((_BYTE *)j + 68) & 4) != 0 )
        v26 = *((unsigned __int16 *)j + 33);
      else
        v26 = 0;
      v19 += v26 + *((_DWORD *)j + 28);
    }
    v27 = *(__int64 **)(a1 + 18432);
    if ( v27 == a2 )
      break;
    if ( !v27 )
    {
      *j = 0;
      break;
    }
    v28 = *(__int64 **)(a1 + 18440);
    --*(_DWORD *)(v2 + 2064);
    if ( v27 == v28 )
    {
      v24 = 0;
      *(_QWORD *)(a1 + 18440) = 0;
    }
    else
    {
      v24 = *v27;
    }
    *(_QWORD *)(a1 + 18432) = v24;
    *v27 = 0;
    *j = v27;
  }
  if ( v21 )
    goto LABEL_39;
LABEL_30:
  if ( (*(_BYTE *)(i + 68) & 4) != 0 )
    v29 = *(unsigned __int16 *)(i + 66);
  else
    v29 = 0;
  v30 = *(_DWORD *)(i + 112);
  if ( (unsigned int)(v30 + v29) > 0xFF )
  {
LABEL_38:
    v21 = nullptr;
LABEL_39:
    *(_QWORD *)(*(_QWORD *)(i + 216) + *(unsigned int *)(i + 212) + 8LL) = v21;
    v33 = *(_DWORD *)(i + 116) + v19;
    *(_DWORD *)(i + 112) += v19;
    *(_DWORD *)(i + 116) = v33;
    if ( v4 )
      _qdf_nbuf_free(v4);
    return i;
  }
  v31 = skb_trim(i, (unsigned int)(v30 - 4));
  if ( *(unsigned __int8 *)(v2 + 233) < 0x26uLL )
  {
    if ( (unsigned __int8)(*(_BYTE *)(a1 + 344LL * *(unsigned __int8 *)(v2 + 233) + 3970) - 4) <= 7u
      && ((0xF7u >> (*(_BYTE *)(a1 + 344LL * *(unsigned __int8 *)(v2 + 233) + 3970) - 4)) & 1) != 0 )
    {
      skb_trim(
        i,
        (unsigned int)(*(_DWORD *)(i + 112)
                     + dword_A30170[(unsigned __int8)(*(_BYTE *)(a1 + 344LL * *(unsigned __int8 *)(v2 + 233) + 3970) - 4)]));
    }
    goto LABEL_38;
  }
  __break(0x5512u);
  return dp_rx_mon_send_mpdu(v31, v32);
}
