__int64 __fastcall sap_reassoc_mld_copy(
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
  int v10; // w8
  __int16 v11; // w9

  v10 = *(_DWORD *)(a1 + 352);
  v11 = *(_WORD *)(a1 + 356);
  *(_DWORD *)(a2 + 184) = v10;
  *(_WORD *)(a2 + 188) = v11;
  return qdf_trace_msg(
           0x39u,
           8u,
           "%s: reassoc_complete->staMld: %02x:%02x:%02x:**:**:%02x",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "sap_reassoc_mld_copy",
           (unsigned __int8)v10,
           BYTE1(v10),
           BYTE2(v10),
           HIBYTE(v11));
}
