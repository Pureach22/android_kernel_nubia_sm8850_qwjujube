__int64 __fastcall btfm_get_feedback_ch_setting(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 72) = btfm_feedback_ch_setting;
  return 1;
}
