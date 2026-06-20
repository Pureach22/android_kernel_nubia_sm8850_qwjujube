__int64 __fastcall hdd_tx_latency_enable(
        __int64 a1,
        int a2,
        char a3,
        __int16 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v15; // w8
  int v16; // w23
  _WORD *v17; // x25
  unsigned int v18; // w8
  unsigned int v19; // w0
  int v20; // w8
  __int64 v21; // x8
  __int64 result; // x0
  __int64 v23; // x4
  __int64 v24; // x20
  __int64 v25; // x20
  __int64 v26; // x20
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x20
  __int64 v30; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h] BYREF
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  __int64 v36; // [xsp+38h] [xbp-18h]
  __int64 v37; // [xsp+40h] [xbp-10h]
  __int64 v38; // [xsp+48h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = *a4;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v16 = (unsigned __int16)(v15 - 4);
  v30 = 0;
  v31 = 0;
  if ( (unsigned int)v16 >= 4 )
  {
    v17 = a4 + 2;
    do
    {
      v18 = (unsigned __int16)*v17;
      if ( v18 < 4 || v16 < v18 )
        break;
      v19 = _nla_parse(&v33, 4, v17 + 2, (unsigned __int16)(*v17 - 4), &tx_latency_bucket_policy, 31, 0);
      if ( v19 )
      {
        v24 = jiffies;
        if ( hdd_tx_latency_enable___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Attribute parse failed, ret %d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "hdd_tx_latency_enable",
            v19);
          hdd_tx_latency_enable___last_ticks = v24;
        }
        goto LABEL_32;
      }
      if ( !v34 )
      {
        v25 = jiffies;
        if ( hdd_tx_latency_enable___last_ticks_383 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Missing bucket type attribute",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "hdd_tx_latency_enable");
          hdd_tx_latency_enable___last_ticks_383 = v25;
        }
        goto LABEL_32;
      }
      if ( !v35 )
      {
        v26 = jiffies;
        if ( hdd_tx_latency_enable___last_ticks_385 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Missing bucket granularity attribute",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "hdd_tx_latency_enable");
          hdd_tx_latency_enable___last_ticks_385 = v26;
        }
        goto LABEL_32;
      }
      if ( *(unsigned __int8 *)(v34 + 4) >= 4u )
      {
        v27 = jiffies;
        if ( hdd_tx_latency_enable___last_ticks_387 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid bucket type %u",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "hdd_tx_latency_enable");
          hdd_tx_latency_enable___last_ticks_387 = v27;
        }
        goto LABEL_32;
      }
      v20 = *(_DWORD *)(v35 + 4);
      *((_DWORD *)&v31 + *(unsigned __int8 *)(v34 + 4)) = v20;
      if ( !v20 )
      {
        v28 = jiffies;
        if ( hdd_tx_latency_enable___last_ticks_389 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid granularity for type %d",
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            "hdd_tx_latency_enable");
          hdd_tx_latency_enable___last_ticks_389 = v28;
        }
        goto LABEL_32;
      }
      v21 = ((unsigned __int16)*v17 + 3) & 0x1FFFC;
      v16 -= v21;
      v17 = (_WORD *)((char *)v17 + v21);
    }
    while ( v16 > 3 );
  }
  if ( (_DWORD)v31 )
  {
    if ( HIDWORD(v31) )
    {
      if ( (_DWORD)v32 )
      {
        if ( HIDWORD(v32) )
        {
          LOBYTE(v30) = 1;
          BYTE1(v30) = a3 & 1;
          HIDWORD(v30) = a2;
          result = hdd_tx_latency_set(a1, &v30);
          goto LABEL_33;
        }
        v23 = 3;
      }
      else
      {
        v23 = 2;
      }
    }
    else
    {
      v23 = 1;
    }
  }
  else
  {
    v23 = 0;
  }
  v29 = jiffies;
  if ( hdd_tx_latency_enable___last_ticks_391 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid granularity for type %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_tx_latency_enable",
      v23);
    hdd_tx_latency_enable___last_ticks_391 = v29;
  }
LABEL_32:
  result = 4294967274LL;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
