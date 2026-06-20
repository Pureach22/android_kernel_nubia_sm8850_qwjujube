__int64 __fastcall dsi_ctrl_toggle_error_interrupt_status(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x8
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 v7; // x8

  if ( (a2 & 1) == 0 )
  {
    v6 = *(unsigned int *)(result + 1608);
    if ( (unsigned int)v6 < 3 )
    {
      v3 = *(__int64 (__fastcall **)(__int64, __int64))(result + 8 * v6 + 936);
      if ( !v3 )
        return result;
      v4 = result + 96;
      v5 = 0;
      goto LABEL_11;
    }
    goto LABEL_18;
  }
  if ( *(_DWORD *)(result + 2440) != 1 || (*(_BYTE *)(result + 2542) & 1) != 0 || (*(_BYTE *)(result + 2541) & 1) != 0 )
  {
    v2 = *(unsigned int *)(result + 1608);
    if ( (unsigned int)v2 <= 2 )
    {
      v3 = *(__int64 (__fastcall **)(__int64, __int64))(result + 8 * v2 + 936);
      if ( !v3 )
        return result;
      v4 = result + 96;
      v5 = 16711904;
      goto LABEL_11;
    }
LABEL_18:
    __break(0x5512u);
    return dsi_ctrl_buffer_init();
  }
  v7 = *(unsigned int *)(result + 1608);
  if ( (unsigned int)v7 > 2 )
    goto LABEL_18;
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(result + 8 * v7 + 936);
  if ( !v3 )
    return result;
  v4 = result + 96;
  v5 = 16711840;
LABEL_11:
  if ( *((_DWORD *)v3 - 1) != 2055766805 )
    __break(0x8228u);
  return v3(v4, v5);
}
