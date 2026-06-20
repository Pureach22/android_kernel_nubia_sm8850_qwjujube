__int64 __fastcall sme_get_cfg_valid_channels(
        __int64 a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _QWORD *v21; // x22
  __int64 v22; // x0
  __int64 v23; // x21
  unsigned int cfg_valid_channels; // w22
  unsigned __int64 v25; // x8

  context = _cds_get_context(52, (__int64)"sme_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v21 = context;
    v22 = _qdf_mem_malloc(0x190u, "sme_get_cfg_valid_channels", 6103);
    if ( v22 )
    {
      v23 = v22;
      cfg_valid_channels = csr_get_cfg_valid_channels(v21, v22, a2);
      if ( *a2 )
      {
        v25 = 0;
        do
        {
          *(_DWORD *)(a1 + 4 * v25) = *(_DWORD *)(v23 + 4 * v25);
          ++v25;
        }
        while ( v25 < (unsigned int)*a2 );
      }
      _qdf_mem_free(v23);
      return cfg_valid_channels;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid MAC context",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "sme_get_cfg_valid_channels");
    return 16;
  }
}
