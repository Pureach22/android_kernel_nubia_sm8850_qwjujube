__int64 __fastcall drm_dp_dsc_sink_line_buf_depth(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_BYTE *)(a1 + 5) & 0xF;
  if ( (unsigned int)v1 > 8 )
    return 0;
  else
    return byte_1D668[v1];
}
