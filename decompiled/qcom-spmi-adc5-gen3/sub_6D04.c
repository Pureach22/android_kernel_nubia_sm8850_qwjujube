__int64 __fastcall sub_6D04(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  if ( (a6 & 0x10) != 0 )
    JUMPOUT(0x7728);
  return adc_tm_disable_chan_meas_gen3();
}
