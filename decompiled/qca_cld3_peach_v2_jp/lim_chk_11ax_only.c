__int64 __fastcall lim_chk_11ax_only(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  if ( *(_DWORD *)(a3 + 88) != 1 || *(_BYTE *)(a3 + 154) != 11 || *(_BYTE *)(a4 + 3372) )
    return 1;
  lim_send_assoc_rsp_mgmt_frame(a1, 10, 1, a2, a5, 0, a3, 0, a4 + 3608);
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: SOFTAP was in 11AX only mode, reject",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "lim_chk_11ax_only");
  return 0;
}
