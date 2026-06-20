bool __fastcall qcom_scm_multi_call_allow(__int64 a1, char a2)
{
  return (a2 & 1) != 0 && *(_DWORD *)(*(_QWORD *)(a1 + 152) + 272LL) == 1;
}
