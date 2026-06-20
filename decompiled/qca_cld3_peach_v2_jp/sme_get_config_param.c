__int64 __fastcall sme_get_config_param(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned int config_param; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w20

  qdf_trace(52, 0x14u, 255, 0);
  result = qdf_mutex_acquire(a1 + 12776);
  if ( !(_DWORD)result )
  {
    config_param = csr_get_config_param(a1, a2);
    if ( config_param )
    {
      v14 = config_param;
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: csr_get_config_param failed",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "sme_get_config_param");
    }
    else
    {
      v14 = 0;
    }
    qdf_mutex_release(a1 + 12776);
    return v14;
  }
  return result;
}
