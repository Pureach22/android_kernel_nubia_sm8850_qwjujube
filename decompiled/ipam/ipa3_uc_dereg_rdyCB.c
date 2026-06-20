__int64 ipa3_uc_dereg_rdyCB()
{
  __int64 v1; // x8

  v1 = ipa3_ctx + 43160;
  *(_QWORD *)(ipa3_ctx + 43160) = 0;
  *(_QWORD *)(v1 + 8) = 0;
  return 0;
}
