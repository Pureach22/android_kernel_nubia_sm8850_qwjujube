__int64 __fastcall ucfg_p2p_set_noa(__int64 a1)
{
  __int64 (*v1)(void); // x8
  unsigned int v2; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 2128) + 184LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != -138336238 )
      __break(0x8228u);
    v2 = v1();
    qdf_trace_msg(0x4Eu, 8u, "%s: p2p set noa, status:%d", v3, v4, v5, v6, v7, v8, v9, v10, "ucfg_p2p_set_noa", v2);
  }
  else
  {
    return 4;
  }
  return v2;
}
