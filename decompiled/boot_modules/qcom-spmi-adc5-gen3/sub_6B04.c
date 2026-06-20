__int64 __fastcall sub_6B04(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  if ( (a6 & 0x10) != 0 )
    JUMPOUT(0x7528);
  return adc_tm_channel_measure_gen3();
}
