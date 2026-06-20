__int64 __fastcall cvp_close(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = msm_cvp_close(*(_QWORD *)(a2 + 32));
  *(_QWORD *)(a2 + 32) = 0;
  return result;
}
