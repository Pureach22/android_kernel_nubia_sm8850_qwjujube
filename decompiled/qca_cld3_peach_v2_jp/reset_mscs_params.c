__int64 __fastcall reset_mscs_params(
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
  __int64 result; // x0

  result = mlme_set_is_mscs_req_sent(*(_QWORD *)(a1 + 32), 0, a2, a3, a4, a5, a6, a7, a8, a9);
  *(_DWORD *)(a1 + 4408) = 0;
  return result;
}
