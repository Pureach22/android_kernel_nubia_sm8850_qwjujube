__int64 __fastcall lim_set_stads_rtt_cap(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w8
  char v11; // w9

  *(_BYTE *)(a1 + 656) = 0;
  v10 = *a2;
  *(_BYTE *)(a1 + 656) = (*a2 & 0x800000) != 0;
  v11 = (*((_BYTE *)a2 + 8) >> 6) & 2 | ((v10 & 0x800000) != 0);
  *(_BYTE *)(a1 + 656) = v11;
  *(_BYTE *)(a1 + 656) = (*((unsigned __int16 *)a2 + 4) << 25 >> 31) & 3 | v11;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: ExtCap present, timingMeas: %d Initiator: %d Responder: %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "lim_set_stads_rtt_cap",
           ((unsigned int)*a2 >> 23) & 1,
           (*((unsigned __int16 *)a2 + 4) >> 7) & 1,
           (*((unsigned __int16 *)a2 + 4) >> 6) & 1);
}
