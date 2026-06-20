__int64 __fastcall sub_7028F0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a5 & 0x10000000000LL) == 0 )
    JUMPOUT(0x6FE518);
  return wmi_extract_twt_add_dialog_comp_event();
}
