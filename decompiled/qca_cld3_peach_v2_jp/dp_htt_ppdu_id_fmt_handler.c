__int64 __fastcall dp_htt_ppdu_id_fmt_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w22
  unsigned int v12; // w19
  unsigned int v13; // w20
  __int64 result; // x0

  v10 = *(_DWORD *)(a2 + 8);
  v12 = (v10 >> 17) & 0x1F;
  v13 = (v10 >> 22) & 0x1F;
  result = qdf_trace_msg(
             0x45u,
             5u,
             "%s: link_id: valid %u bits %u offset %u",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "dp_htt_ppdu_id_fmt_handler",
             HIWORD(v10) & 1,
             v12,
             v13);
  if ( (v10 & 0x10000) != 0 )
  {
    *(_BYTE *)(a1 + 20089) = v13;
    *(_BYTE *)(a1 + 20090) = v12;
  }
  return result;
}
