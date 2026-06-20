__int64 __fastcall msm_lpi_logging_enable_put(__int64 a1, __int64 a2)
{
  lpi_pcm_logging_enable = *(_QWORD *)(a2 + 72) != 0;
  audio_prm_set_lpi_logging_status();
  return 0;
}
