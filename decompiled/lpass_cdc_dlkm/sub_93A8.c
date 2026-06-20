__int64 __fastcall sub_93A8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  if ( (a7 & 0x20000000000000LL) == 0 )
    JUMPOUT(0xE70C);
  return lpass_cdc_register_event_listener();
}
