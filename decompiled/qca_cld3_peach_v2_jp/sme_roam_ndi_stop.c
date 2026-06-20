__int64 __fastcall sme_roam_ndi_stop(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x8
  __int64 result; // x0
  unsigned int v15; // w20

  v2 = (unsigned __int8)a2;
  qdf_trace(52, 0xFu, (unsigned __int8)a2, 0);
  if ( a1
    && v2 <= 5
    && (v13 = *(_QWORD *)(a1 + 17224)) != 0
    && (*(_BYTE *)(v13 + 96LL * (unsigned __int8)a2 + 1) & 1) != 0 )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      v15 = csr_roam_ndi_stop(a1, a2);
      qdf_mutex_release(a1 + 12776);
      return v15;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 8u, "%s: Invalid sessionID: %d", v5, v6, v7, v8, v9, v10, v11, v12, "sme_roam_ndi_stop", v2);
    return 4;
  }
  return result;
}
