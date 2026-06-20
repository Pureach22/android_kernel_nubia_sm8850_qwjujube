__int64 __fastcall lim_print_ht_cap(
        __int64 result,
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
  unsigned int v10; // w8

  if ( *(_BYTE *)(result + 155) )
  {
    if ( *(_BYTE *)(a2 + 3160) )
    {
      v10 = *(unsigned __int16 *)(a2 + 3161);
      return qdf_trace_msg(
               0x35u,
               8u,
               "%s: AdvCodingCap:%d ChaWidthSet:%d PowerSave:%d greenField:%d shortGI20:%d shortGI40:%d txSTBC:%d rxSTBC:"
               "%d delayBA:%d maxAMSDUsize:%d DSSS/CCK:%d  PSMP:%d stbcCntl:%d lsigTXProt:%d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "lim_print_ht_cap",
               v10 & 1,
               (v10 >> 1) & 1,
               (v10 >> 2) & 3,
               (v10 >> 4) & 1,
               (v10 >> 5) & 1,
               (v10 >> 6) & 1,
               (v10 >> 7) & 1,
               (v10 >> 8) & 3,
               (v10 >> 10) & 1,
               (v10 >> 11) & 1,
               (v10 >> 12) & 1,
               (v10 >> 13) & 1,
               (v10 >> 14) & 1,
               v10 >> 15);
    }
  }
  return result;
}
