__int64 __fastcall sub_6CAD5C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 _X6)
{
  __asm { LDTR            Q3, [X6,#-0x96] }
  return wmi_extract_mlo_link_state_switch_evt(a1, a2, a3, a4);
}
