__int64 __fastcall msm_lpi_logging_enable_get(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 72) = (unsigned __int8)lpi_pcm_logging_enable;
  return 0;
}
