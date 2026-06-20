__int64 __fastcall lim_util_get_type_subtype(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  _BYTE *v23; // x19
  unsigned int v24; // w8
  _QWORD v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  if ( a1 )
  {
    v13 = wma_ds_peek_rx_packet_info(a1, v25);
    if ( v13 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed extract cds packet. status %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_util_get_type_subtype",
        v13);
      result = 16;
    }
    else
    {
      v23 = *(_BYTE **)(v25[0] + 16LL);
      v24 = (*(unsigned __int16 *)v23 >> 2) & 3;
      if ( v24 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Not a management packet type %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_util_get_type_subtype",
          v24);
        result = 4;
      }
      else
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RxBd: %pK mHdr: %pK Type: %d Subtype: %d SizeFC: %zu",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "lim_util_get_type_subtype",
          2);
        result = 0;
        *a2 = (*v23 >> 2) & 3;
        *a3 = *v23 >> 4;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: NULL packet received", a4, a5, a6, a7, a8, a9, a10, a11, "lim_util_get_type_subtype");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
