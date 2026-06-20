__int64 __fastcall reg_txpb_send_dma_addr(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 (__fastcall *v14)(__int64, __int64); // x8
  const char *v16; // x2
  const char *v17; // x3

  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v16 = "%s: TPB: psoc is NULL";
    v17 = "reg_txpb_send_dma_addr";
LABEL_9:
    qdf_trace_msg(0x51u, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, v17);
    return 16;
  }
  v11 = *(_QWORD *)(v10 + 2128);
  if ( !v11 )
  {
    v16 = "%s: tx_ops is NULL";
    v17 = "reg_get_psoc_tx_ops";
    goto LABEL_9;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: TPB: in reg_txpb_send_dma_addr",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "reg_txpb_send_dma_addr");
  v14 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 1088);
  if ( !v14 )
    return 0;
  if ( *((_DWORD *)v14 - 1) != 260228319 )
    __break(0x8228u);
  return v14(a1, a2);
}
