__int64 __fastcall sub_400024(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, double a6)
{
  __int64 v6; // x22
  __int64 v7; // d11

  *(double *)(v6 + 104) = a6;
  *(_QWORD *)(v6 + 112) = v7;
  return dot11f_pack_probe_request(a1, a2, a3, a4, a5);
}
