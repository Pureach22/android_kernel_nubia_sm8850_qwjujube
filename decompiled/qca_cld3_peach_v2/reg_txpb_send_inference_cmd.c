__int64 __fastcall reg_txpb_send_inference_cmd(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  const char *v13; // x2
  const char *v14; // x3

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v13 = "%s: TPB: psoc is NULL";
    v14 = "reg_txpb_send_inference_cmd";
LABEL_9:
    qdf_trace_msg(0x51u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, v14);
    return 16;
  }
  v10 = *(_QWORD *)(v9 + 2128);
  if ( !v10 )
  {
    v13 = "%s: tx_ops is NULL";
    v14 = "reg_get_psoc_tx_ops";
    goto LABEL_9;
  }
  v11 = *(__int64 (**)(void))(v10 + 1096);
  if ( !v11 )
    return 0;
  if ( *((_DWORD *)v11 - 1) != 769093241 )
    __break(0x8228u);
  return v11();
}
