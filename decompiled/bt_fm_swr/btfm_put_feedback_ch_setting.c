__int64 __fastcall btfm_put_feedback_ch_setting(__int64 a1, __int64 a2)
{
  btfm_feedback_ch_setting = *(_QWORD *)(a2 + 72);
  return 1;
}
