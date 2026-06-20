__int64 __fastcall ipa_ready_callback(__int64 a1)
{
  __int64 v1; // x9
  void *v2; // x11
  __int64 v3; // x9
  __int64 v4; // x11
  __int64 v5; // x12

  v1 = *(_QWORD *)(a1 + 16);
  v2 = *(void **)a1;
  qword_FB78 = *(_QWORD *)(a1 + 8);
  qword_FB80 = v1;
  ipa_ops = v2;
  v3 = *(_QWORD *)(a1 + 48);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(_QWORD *)(a1 + 32);
  qword_FB98 = *(_QWORD *)(a1 + 40);
  qword_FBA0 = v3;
  qword_FB88 = v4;
  qword_FB90 = v5;
  return complete_all(&wait_for_ipa_ready);
}
