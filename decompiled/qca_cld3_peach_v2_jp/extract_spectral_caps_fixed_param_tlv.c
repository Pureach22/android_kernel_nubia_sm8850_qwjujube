__int64 __fastcall extract_spectral_caps_fixed_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  int v11; // w8
  int v12; // w9
  const char *v14; // x2

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *(_DWORD *)(a10 + 8);
      *a11 = v11;
      v12 = *(_DWORD *)(a10 + 24);
      a11[1] = v12;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: num_sscan_bw_caps:%u num_fft_size_caps:%u",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_spectral_caps_fixed_param_tlv",
        (unsigned __int8)v11,
        (unsigned __int8)v12);
      return 0;
    }
    v14 = "%s: event parameters is NULL";
  }
  else
  {
    v14 = "%s: param_buf is NULL";
  }
  qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_spectral_caps_fixed_param_tlv");
  return 29;
}
