__int64 __fastcall sub_64C068(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( (a5 & 0x10000000000LL) == 0 )
    JUMPOUT(0x647C90);
  return wmi_extract_twt_add_dialog_comp_event();
}
