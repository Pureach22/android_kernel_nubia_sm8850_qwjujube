__int64 __fastcall wcd9378_mbhc_request_micbias(__int64 a1, unsigned int a2, int a3)
{
  return wcd9378_micbias_control(a1, a2, a3, 0);
}
