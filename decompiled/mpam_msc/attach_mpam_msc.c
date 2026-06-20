__int64 __fastcall attach_mpam_msc(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w9
  void *v4; // x0
  _QWORD *v5; // x8

  v3 = -22;
  if ( !a2 || a3 != 2 )
    return v3;
  v4 = (void *)(a2 + 72);
  v5 = off_F8;
  if ( (_UNKNOWN **)(a2 + 72) != &qcom_mpam_list && off_F8 != v4 && *(_UNKNOWN ***)off_F8 == &qcom_mpam_list )
  {
    v3 = 0;
    off_F8 = (_UNKNOWN *)(a2 + 72);
    *(_QWORD *)(a2 + 72) = &qcom_mpam_list;
    *(_QWORD *)(a2 + 80) = v5;
    *v5 = v4;
    return v3;
  }
  _list_add_valid_or_report(v4, off_F8);
  return 0;
}
