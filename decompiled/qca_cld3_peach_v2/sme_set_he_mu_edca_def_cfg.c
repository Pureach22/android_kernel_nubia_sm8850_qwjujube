__int64 __fastcall sme_set_he_mu_edca_def_cfg(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x20
  __int64 result; // x0
  char v12; // w8
  char v13; // w11
  char v14; // w8
  char v15; // w9

  v10 = a1 + 20480;
  result = qdf_trace_msg(
             0x34u,
             8u,
             "%s: Set MU EDCA params to default",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "sme_set_he_mu_edca_def_cfg");
  v12 = *(_BYTE *)(v10 + 1273);
  *(_WORD *)(a1 + 21755) = 255;
  v13 = *(_BYTE *)(v10 + 1278);
  *(_BYTE *)(v10 + 1274) = -1;
  *(_BYTE *)(v10 + 1273) = v12 & 0x90;
  v14 = *(_BYTE *)(v10 + 1283);
  *(_BYTE *)(v10 + 1279) = -1;
  v15 = *(_BYTE *)(v10 + 1288);
  *(_BYTE *)(v10 + 1278) = v13 & 0x90 | 0x20;
  *(_WORD *)(v10 + 1280) = 255;
  *(_BYTE *)(v10 + 1283) = v14 & 0x90 | 0x40;
  *(_WORD *)(a1 + 21765) = 255;
  *(_BYTE *)(v10 + 1284) = -1;
  *(_BYTE *)(v10 + 1288) = v15 & 0x90 | 0x60;
  *(_BYTE *)(v10 + 1289) = -1;
  *(_WORD *)(v10 + 1290) = 255;
  return result;
}
