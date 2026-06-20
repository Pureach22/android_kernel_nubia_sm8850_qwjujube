__int64 __fastcall ml_nlink_clr_emlsr_mode_disable_req(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 v5; // x8
  unsigned int v6; // w19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  v3 = *(_QWORD *)(a2 + 1360);
  if ( v3 && *(_QWORD *)(v3 + 2224) )
  {
    qdf_mutex_acquire(v3 + 1656);
    v5 = *(_QWORD *)(v3 + 2224);
    v6 = *(_DWORD *)(v5 + 1448);
    *(_DWORD *)(v5 + 1448) = v6 & ~a3;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: clr disable_req to 0x%x from 0x%x by req 0x%x",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "ml_nlink_clr_emlsr_mode_disable_req");
    qdf_mutex_release(v3 + 1656);
  }
  else
  {
    return 0;
  }
  return v6;
}
