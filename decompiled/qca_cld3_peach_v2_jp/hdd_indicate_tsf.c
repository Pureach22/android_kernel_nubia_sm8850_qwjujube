__int64 __fastcall hdd_indicate_tsf(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x8
  unsigned int v12; // w20
  int v13; // w20
  const char *v14; // x2
  const char *v16; // x2
  __int64 *v18; // x8
  __int64 v19; // x9
  __int64 v20; // x20

  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: invalid pointer", a3, a4, a5, a6, a7, a8, a9, a10, "__hdd_indicate_tsf");
    return 4294967274LL;
  }
  a2[1] = 0;
  a2[2] = 0;
  *a2 = 0;
  v11 = *(_QWORD *)(a1 + 24);
  if ( !v11 )
  {
    v16 = "%s: invalid hdd context";
LABEL_11:
    qdf_trace_msg(0x33u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_tsf_is_initialized");
    goto LABEL_12;
  }
  if ( !*(_DWORD *)(v11 + 3232) )
  {
    v16 = "%s: TSF is not initialized";
    goto LABEL_11;
  }
  v12 = *(_DWORD *)(a1 + 40) & 0xFFFFFFFD;
  if ( (*(_QWORD *)(*(_QWORD *)(a1 + 52824) + 4416LL) & 2) != 0 || v12 != 1 )
  {
    if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52824)) && !v12 )
    {
      v13 = 1;
      v14 = "%s: failed to cap tsf, not connect with ap";
      goto LABEL_16;
    }
    *(_DWORD *)a2 = 0;
    v18 = (__int64 *)(a1 + 39360);
    v19 = *(_QWORD *)(a1 + 39368);
    if ( v19 )
    {
      a2[1] = v19;
      a2[2] = *v18 / 0x3E8uLL;
      return 0;
    }
    v20 = *v18;
    qdf_trace_msg(0x33u, 4u, "%s: TSF value not received", a3, a4, a5, a6, a7, a8, a9, a10, "__hdd_indicate_tsf");
    if ( v20 )
    {
      *(_DWORD *)a2 = 2;
      return 4294967181LL;
    }
LABEL_12:
    *(_DWORD *)a2 = 8;
    return 4294967274LL;
  }
  v13 = 7;
  v14 = "%s: Soft AP / P2p GO not beaconing";
LABEL_16:
  qdf_trace_msg(0x33u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_tsf_check_conn_state");
  *(_DWORD *)a2 = v13;
  return 0xFFFFFFFFLL;
}
