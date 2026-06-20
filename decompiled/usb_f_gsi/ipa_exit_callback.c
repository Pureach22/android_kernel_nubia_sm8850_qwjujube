void ipa_exit_callback()
{
  qword_FB98 = 0;
  qword_FBA0 = 0;
  qword_FB88 = 0;
  qword_FB90 = 0;
  qword_FB78 = 0;
  qword_FB80 = 0;
  ipa_ops = nullptr;
  wait_for_ipa_ready = 0;
}
