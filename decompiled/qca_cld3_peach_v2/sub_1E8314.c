__int64 __fastcall sub_1E8314(__int64 a1, __int64 a2, __int64 a3, double a4, float a5)
{
  __int64 v5; // x30
  int v6; // s26

  *(float *)(v5 - 100) = a5;
  *(_DWORD *)(v5 - 96) = v6;
  return cm_get_first_candidate_rsp(a1, a2, a3);
}
