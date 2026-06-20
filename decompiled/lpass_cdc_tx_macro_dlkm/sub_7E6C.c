__int64 __fastcall sub_7E6C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  if ( (a7 & 0x20000000000000LL) == 0 )
    JUMPOUT(0xD1D0);
  return _lpass_cdc_tx_macro_mclk_enable();
}
