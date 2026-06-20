__int64 __fastcall epcs_update_ac_value(
        __int64 a1,
        unsigned __int8 *a2,
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
  char v11; // w13
  char v12; // w10
  unsigned int v13; // w9
  char v14; // w10
  unsigned int v15; // w11
  char v16; // w10
  __int64 v17; // x7
  unsigned int v18; // w10
  unsigned __int8 v19; // w13

  v10 = *a2;
  v11 = *(_BYTE *)(a1 + 1);
  v12 = v10 & 0x80 | *(_BYTE *)a1 & 0x7F;
  *(_BYTE *)a1 = v12;
  v13 = *a2;
  v14 = v12 & 0x9F | v13 & 0x60;
  *(_BYTE *)a1 = v14;
  v15 = *a2;
  v16 = v14 & 0xEF | v15 & 0x10;
  *(_BYTE *)a1 = v16;
  v17 = *a2 & 0xF;
  *(_BYTE *)a1 = v16 & 0xF0 | *a2 & 0xF;
  v18 = a2[1];
  *(_BYTE *)(a1 + 1) = a2[1] & 0xF0 | v11 & 0xF;
  v19 = a2[1];
  *(_BYTE *)(a1 + 1) = v18 & 0xF0 | v19 & 0xF;
  *(_WORD *)(a1 + 2) = *((_WORD *)a2 + 1);
  return qdf_trace_msg(
           0x68u,
           8u,
           "%s: edca rsvd %d, aci %d, acm %d, aifsn %d, cwmax %d, cwmin %d",
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           "epcs_update_ac_value",
           v10 >> 7,
           (v13 >> 5) & 3,
           (v15 >> 4) & 1,
           v17,
           v18 >> 4,
           v19 & 0xF);
}
