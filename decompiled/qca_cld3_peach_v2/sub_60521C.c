__int64 __fastcall sub_60521C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, double a5)
{
  *(double *)(a4 + 57) = a5;
  return extract_nan_msg_tlv(a1, a2, a3, a4 + 57);
}
