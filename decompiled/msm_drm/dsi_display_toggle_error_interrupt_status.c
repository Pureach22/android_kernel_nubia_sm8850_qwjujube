__int64 __fastcall dsi_display_toggle_error_interrupt_status(__int64 result, char a2)
{
  unsigned int v2; // w8
  __int64 v3; // x20

  v2 = *(_DWORD *)(result + 160);
  if ( v2 )
  {
    v3 = result;
    result = *(_QWORD *)(result + 168);
    if ( result )
    {
      result = dsi_ctrl_toggle_error_interrupt_status(result, a2 & 1);
      v2 = *(_DWORD *)(v3 + 160);
    }
    if ( v2 >= 2 )
    {
      result = *(_QWORD *)(v3 + 216);
      if ( result )
        return dsi_ctrl_toggle_error_interrupt_status(result, a2 & 1);
    }
  }
  return result;
}
