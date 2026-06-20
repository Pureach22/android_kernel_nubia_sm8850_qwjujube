__int64 __fastcall sme_start_bss(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  unsigned int v3; // w20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 result; // x0
  unsigned int v17; // w20

  if ( !a1 )
    return 16;
  v3 = a2;
  qdf_trace(52, 2u, a2, 0);
  if ( v3 <= 5 && (v15 = *(_QWORD *)(a1 + 17296)) != 0 && (*(_BYTE *)(v15 + 96LL * a2 + 1) & 1) != 0 )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      v17 = csr_bss_start(a1, v3, a3);
      qdf_mutex_release(a1 + 12848);
      return v17;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid sessionID: %d", v7, v8, v9, v10, v11, v12, v13, v14, "sme_start_bss", v3);
    return 4;
  }
  return result;
}
