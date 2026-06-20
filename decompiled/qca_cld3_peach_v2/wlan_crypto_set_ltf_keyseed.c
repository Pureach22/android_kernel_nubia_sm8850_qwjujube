__int64 __fastcall wlan_crypto_set_ltf_keyseed(
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

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v10 = *(__int64 (**)(void))(v9 + 752);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -1117362197 )
        __break(0x8228u);
      return v10();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_crypto_set_ltf_keyseed");
    return 4;
  }
}
