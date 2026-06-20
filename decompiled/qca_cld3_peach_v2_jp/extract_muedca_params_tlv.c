__int64 __fastcall extract_muedca_params_tlv(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v11; // x20
  __int64 (*v13)(void); // x8
  int v14; // w8

  if ( a2 )
  {
    v11 = (_DWORD *)*a2;
    v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3712LL);
    if ( *((_DWORD *)v13 - 1) != -2112860426 )
      __break(0x8228u);
    v14 = v13();
    *(_DWORD *)a3 = v14;
    *(_BYTE *)(a3 + 12) = v11[2];
    *(_BYTE *)(a3 + 4) = v11[6];
    *(_BYTE *)(a3 + 8) = v11[10];
    *(_BYTE *)(a3 + 20) = v11[14];
    *(_BYTE *)(a3 + 13) = v11[3];
    *(_BYTE *)(a3 + 5) = v11[7];
    *(_BYTE *)(a3 + 9) = v11[11];
    *(_BYTE *)(a3 + 21) = v11[15];
    *(_BYTE *)(a3 + 14) = v11[4];
    *(_BYTE *)(a3 + 6) = v11[8];
    *(_BYTE *)(a3 + 10) = v11[12];
    *(_BYTE *)(a3 + 22) = v11[16];
    *(_BYTE *)(a3 + 15) = v11[5];
    *(_BYTE *)(a3 + 7) = v11[9];
    *(_BYTE *)(a3 + 11) = v11[13];
    *(_BYTE *)(a3 + 23) = v11[17];
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid muedca evt buffer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_muedca_params_tlv");
    return 4;
  }
}
