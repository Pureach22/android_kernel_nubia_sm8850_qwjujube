__int64 __fastcall os_if_dp_fill_txrx_stats(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_17;
  v14[0] = *(_QWORD *)a2;
  if ( !(unsigned int)nla_put_64bit(a1, 1, 8, v14, 229) )
  {
    LODWORD(v14[0]) = *(_DWORD *)(a2 + 8);
    if ( (unsigned int)nla_put(a1, 2, 4, v14) )
    {
      v12 = "%s: STC: pkts put failed";
      goto LABEL_16;
    }
    LODWORD(v14[0]) = *(_DWORD *)(a2 + 12);
    if ( (unsigned int)nla_put(a1, 3, 4, v14) )
    {
      v12 = "%s: STC: pkt_size_min put failed";
      goto LABEL_16;
    }
    LODWORD(v14[0]) = *(_DWORD *)(a2 + 16);
    if ( (unsigned int)nla_put(a1, 4, 4, v14) )
    {
      v12 = "%s: STC: pkt_size_max put failed";
      goto LABEL_16;
    }
    v14[0] = *(_QWORD *)(a2 + 24) / 0x3E8uLL;
    if ( (unsigned int)nla_put_64bit(a1, 5, 8, v14, 229) )
    {
      v12 = "%s: STC: pkt_iat_min put failed";
      goto LABEL_16;
    }
    v14[0] = *(_QWORD *)(a2 + 32) / 0x3E8uLL;
    if ( (unsigned int)nla_put_64bit(a1, 6, 8, v14, 229) )
    {
      v12 = "%s: STC: pkt_iat_max put failed";
      goto LABEL_16;
    }
    v14[0] = *(_QWORD *)(a2 + 40) / 0x3E8uLL;
    if ( (unsigned int)nla_put_64bit(a1, 7, 8, v14, 229) )
    {
      v12 = "%s: STC: pkt_iat_sum put failed";
      goto LABEL_16;
    }
LABEL_17:
    result = 72;
    goto LABEL_18;
  }
  v12 = "%s: STC: bytes put failed";
LABEL_16:
  qdf_trace_msg(0x48u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "os_if_dp_fill_txrx_stats");
  result = 4294967274LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
