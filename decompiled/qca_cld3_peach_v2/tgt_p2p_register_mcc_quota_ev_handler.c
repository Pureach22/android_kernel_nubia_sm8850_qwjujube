__int64 __fastcall tgt_p2p_register_mcc_quota_ev_handler(
        __int64 a1,
        char a2,
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
  __int64 (*v11)(void); // x8
  char v12; // w19
  unsigned int v13; // w0
  unsigned int v14; // w19

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v11 = *(__int64 (**)(void))(v10 + 248);
    if ( v11 )
    {
      v12 = a2;
      if ( *((_DWORD *)v11 - 1) != -132374536 )
        __break(0x8228u);
      v13 = v11();
      a2 = v12;
      v14 = v13;
    }
    else
    {
      v14 = 16;
    }
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: register %d mcc quota event, status:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_p2p_register_mcc_quota_ev_handler",
      a2 & 1,
      v14);
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: invalid lmac if tx ops",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_p2p_register_mcc_quota_ev_handler");
    return 16;
  }
  return v14;
}
