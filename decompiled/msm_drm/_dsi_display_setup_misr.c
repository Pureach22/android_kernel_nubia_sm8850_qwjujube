__int64 __fastcall dsi_display_setup_misr(__int64 result)
{
  __int64 v1; // x19

  if ( *(_DWORD *)(result + 160) )
  {
    v1 = result;
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_setup_misr)(
               *(_QWORD *)(result + 168),
               *(unsigned __int8 *)(v1 + 1344),
               *(unsigned int *)(v1 + 1348));
    if ( *(_DWORD *)(v1 + 160) >= 2u )
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_ctrl_setup_misr)(
               *(_QWORD *)(v1 + 216),
               *(unsigned __int8 *)(v1 + 1344),
               *(unsigned int *)(v1 + 1348));
  }
  return result;
}
