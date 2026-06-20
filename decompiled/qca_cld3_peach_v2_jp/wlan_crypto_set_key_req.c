__int64 __fastcall wlan_crypto_set_key_req(
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
  __int64 v11; // x8
  __int64 (*v12)(void); // x8

  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 || (v11 = *(_QWORD *)(v10 + 2128)) == 0 )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_set_key_req");
    return 16;
  }
  v12 = *(__int64 (**)(void))(v11 + 736);
  if ( !v12 )
    return 16;
  if ( *((_DWORD *)v12 - 1) != 687961826 )
    __break(0x8228u);
  return v12();
}
