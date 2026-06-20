__int64 __fastcall do_devfreq_resume(__int64 a1)
{
  devfreq_resume_device(*(_QWORD *)(a1 - 520));
  return devfreq_resume_device(*(_QWORD *)(a1 + 1016));
}
