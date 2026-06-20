__int64 __fastcall dp_tx_rx_collect_connectivity_stats_info(
        __int64 result,
        __int64 a2,
        int a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  __int64 v14; // x21
  int v15; // w8
  unsigned int v16; // w8
  const char *v17; // x2
  bool v19; // w8
  __int64 v20; // x0
  int v21; // w23
  bool v22; // w8
  __int64 v23; // x0
  int v24; // w23
  int v25; // w8
  unsigned int v26; // w8
  bool is_icmp_pkt; // w8
  __int64 v28; // x0
  int v29; // w22
  bool is_ipv4_tcp_pkt; // w8
  __int64 v31; // x0
  int v32; // w22
  __int16 v33; // w8
  int v34; // w23
  __int16 v35; // w8
  __int16 v36; // w8

  v12 = *(_QWORD *)(a2 + 32);
  if ( (*(_DWORD *)(v12 + 3076) & ~*(_DWORD *)(*(_QWORD *)v12 + 1196LL)) == 0 )
    return result;
  v14 = result;
  if ( a3 <= 3 )
  {
    if ( a3 )
    {
      if ( a3 == 1 )
      {
        is_icmp_pkt = _qdf_nbuf_data_is_icmp_pkt(*(_QWORD *)(result + 224));
        v28 = *(_QWORD *)(v14 + 224);
        if ( is_icmp_pkt )
        {
          result = _qdf_nbuf_data_is_icmpv4_rsp(v28);
          if ( (result & 1) == 0 )
            return result;
          v29 = *(_DWORD *)(v12 + 3352);
          result = _qdf_nbuf_get_icmpv4_src_ip(*(_QWORD *)(v14 + 224));
          if ( v29 != (_DWORD)result )
            return result;
          v17 = "%s: ICMPv4 resp packet";
          ++*(_WORD *)(v12 + 2786);
          *a4 = 4;
        }
        else
        {
          is_ipv4_tcp_pkt = _qdf_nbuf_data_is_ipv4_tcp_pkt(v28);
          v31 = *(_QWORD *)(v14 + 224);
          if ( is_ipv4_tcp_pkt )
          {
            result = _qdf_nbuf_data_is_tcp_syn_ack(v31);
            if ( (result & 1) == 0 )
              return result;
            v32 = *(_DWORD *)(v12 + 3348);
            result = _qdf_nbuf_data_get_tcp_src_port(*(_QWORD *)(v14 + 224));
            if ( v32 != (unsigned __int16)result )
              return result;
            v33 = *(_WORD *)(v12 + 2760);
            v17 = "%s: TCP Syn ack packet";
            *(_BYTE *)(v12 + 2782) = 1;
            *(_WORD *)(v12 + 2760) = v33 + 1;
            *a4 = 7;
          }
          else
          {
            result = _qdf_nbuf_data_is_ipv4_udp_pkt(v31);
            if ( (result & 1) == 0 )
              return result;
            result = _qdf_nbuf_data_is_dns_response(*(_QWORD *)(v14 + 224));
            if ( (result & 1) == 0 )
              return result;
            result = dp_tx_rx_is_dns_domain_name_match(v14, v12);
            if ( (result & 1) == 0 )
              return result;
            v17 = "%s: DNS resp packet";
            ++*(_WORD *)(v12 + 2742);
            *a4 = 2;
          }
        }
      }
      else
      {
        if ( a3 != 2 )
          return result;
        v16 = (unsigned __int8)*a4;
        if ( v16 > 5 )
        {
          if ( v16 == 6 )
          {
            v17 = "%s: TCP syn packet dropped";
            ++*(_WORD *)(v12 + 2762);
          }
          else
          {
            if ( v16 != 8 )
              return result;
            v17 = "%s: TCP ack packet dropped";
            ++*(_WORD *)(v12 + 2764);
          }
        }
        else if ( v16 == 2 )
        {
          v17 = "%s: DNS query packet dropped";
          ++*(_WORD *)(v12 + 2744);
        }
        else
        {
          if ( v16 != 4 )
            return result;
          v17 = "%s: ICMPv4 Req packet dropped";
          ++*(_WORD *)(v12 + 2788);
        }
      }
      return qdf_trace_msg(
               0x45u,
               5u,
               v17,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "dp_tx_rx_collect_connectivity_stats_info");
    }
  }
  else
  {
    if ( a3 <= 5 )
    {
      if ( a3 == 4 )
      {
        v25 = (unsigned __int8)*a4;
        switch ( v25 )
        {
          case 2:
            ++*(_WORD *)(v12 + 2746);
            break;
          case 7:
            ++*(_WORD *)(v12 + 2766);
            break;
          case 4:
            ++*(_WORD *)(v12 + 2790);
            break;
        }
      }
      else
      {
        v15 = (unsigned __int8)*a4;
        switch ( v15 )
        {
          case 2:
            ++*(_WORD *)(v12 + 2748);
            break;
          case 7:
            ++*(_WORD *)(v12 + 2768);
            break;
          case 4:
            ++*(_WORD *)(v12 + 2792);
            break;
        }
      }
      return result;
    }
    if ( a3 == 7 )
    {
      v26 = (unsigned __int8)*a4;
      if ( v26 > 5 )
      {
        if ( v26 == 6 )
        {
          ++*(_WORD *)(v12 + 2778);
        }
        else if ( v26 == 8 )
        {
          ++*(_WORD *)(v12 + 2780);
        }
      }
      else if ( v26 == 2 )
      {
        ++*(_WORD *)(v12 + 2754);
      }
      else if ( v26 == 4 )
      {
        ++*(_WORD *)(v12 + 2800);
      }
      return result;
    }
    if ( a3 != 6 )
      return result;
  }
  v19 = _qdf_nbuf_data_is_icmp_pkt(*(_QWORD *)(result + 224));
  v20 = *(_QWORD *)(v14 + 224);
  if ( v19 )
  {
    result = _qdf_nbuf_data_is_icmpv4_req(v20);
    if ( (result & 1) == 0 )
      return result;
    v21 = *(_DWORD *)(v12 + 3352);
    result = _qdf_nbuf_get_icmpv4_tgt_ip(*(_QWORD *)(v14 + 224));
    if ( v21 != (_DWORD)result )
      return result;
    *a4 = 4;
    if ( a3 )
    {
      ++*(_WORD *)(v12 + 2794);
      return result;
    }
    v17 = "%s: ICMPv4 Req packet";
    ++*(_WORD *)(v12 + 2784);
    return qdf_trace_msg(0x45u, 5u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "dp_tx_rx_collect_connectivity_stats_info");
  }
  v22 = _qdf_nbuf_data_is_ipv4_tcp_pkt(v20);
  v23 = *(_QWORD *)(v14 + 224);
  if ( !v22 )
  {
    result = _qdf_nbuf_data_is_ipv4_udp_pkt(v23);
    if ( (result & 1) == 0 )
      return result;
    result = _qdf_nbuf_data_is_dns_query(*(_QWORD *)(v14 + 224));
    if ( (result & 1) == 0 )
      return result;
    result = dp_tx_rx_is_dns_domain_name_match(v14, v12);
    if ( (result & 1) == 0 )
      return result;
    *a4 = 2;
    if ( a3 )
    {
      ++*(_WORD *)(v12 + 2750);
      return result;
    }
    v17 = "%s: DNS query packet";
    ++*(_WORD *)(v12 + 2740);
    return qdf_trace_msg(0x45u, 5u, v17, a5, a6, a7, a8, a9, a10, a11, a12, "dp_tx_rx_collect_connectivity_stats_info");
  }
  result = _qdf_nbuf_data_is_tcp_syn(v23);
  if ( (result & 1) != 0 )
  {
    v24 = *(_DWORD *)(v12 + 3348);
    result = _qdf_nbuf_data_get_tcp_dst_port(*(_QWORD *)(v14 + 224));
    if ( v24 == (unsigned __int16)result )
    {
      *a4 = 6;
      if ( a3 )
      {
        ++*(_WORD *)(v12 + 2770);
        return result;
      }
      v17 = "%s: TCP Syn packet";
      ++*(_WORD *)(v12 + 2756);
      return qdf_trace_msg(
               0x45u,
               5u,
               v17,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "dp_tx_rx_collect_connectivity_stats_info");
    }
  }
  if ( (*(_BYTE *)(v12 + 2782) & 1) != 0 || *(_BYTE *)(v12 + 2783) == 1 )
  {
    result = _qdf_nbuf_data_is_tcp_ack(*(_QWORD *)(v14 + 224));
    if ( (result & 1) != 0 )
    {
      v34 = *(_DWORD *)(v12 + 3348);
      result = _qdf_nbuf_data_get_tcp_dst_port(*(_QWORD *)(v14 + 224));
      if ( v34 == (unsigned __int16)result )
      {
        *a4 = 8;
        if ( a3 != 6 )
        {
          if ( *(_BYTE *)(v12 + 2782) != 1 )
            return result;
          v35 = *(_WORD *)(v12 + 2758);
          v17 = "%s: TCP Ack packet";
          *(_WORD *)(v12 + 2782) = 256;
          *(_WORD *)(v12 + 2758) = v35 + 1;
          return qdf_trace_msg(
                   0x45u,
                   5u,
                   v17,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "dp_tx_rx_collect_connectivity_stats_info");
        }
        if ( *(_BYTE *)(v12 + 2783) == 1 )
        {
          v36 = *(_WORD *)(v12 + 2772);
          *(_BYTE *)(v12 + 2783) = 0;
          *(_WORD *)(v12 + 2772) = v36 + 1;
        }
      }
    }
  }
  return result;
}
