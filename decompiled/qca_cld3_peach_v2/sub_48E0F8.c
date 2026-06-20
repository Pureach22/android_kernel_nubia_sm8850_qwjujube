__int64 __fastcall sub_48E0F8(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v3; // d11
  __int64 v4; // d24

  *(_QWORD *)(v2 + 472) = v3;
  *(_QWORD *)(v2 + 480) = v4;
  return sme_send_rate_update_ind(a1, a2);
}
