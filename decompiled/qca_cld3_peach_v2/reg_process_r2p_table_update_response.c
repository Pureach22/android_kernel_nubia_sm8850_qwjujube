__int64 __fastcall reg_process_r2p_table_update_response(
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
  __int64 (*v10)(void); // x8

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x51u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "reg_get_psoc_tx_ops");
    return 16;
  }
  v10 = *(__int64 (**)(void))(v9 + 1064);
  if ( !v10 )
    return 16;
  if ( *((_DWORD *)v10 - 1) != 787953853 )
    __break(0x8228u);
  return v10();
}
