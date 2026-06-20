__int64 __fastcall mhi_set_mhi_state(__int64 a1, int a2)
{
  __int64 v3; // x21
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v7; // x20
  const char *v8; // x3
  __int64 v9; // x20
  const char *v10; // x0

  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_QWORD *)(a1 + 32);
  if ( a2 )
  {
    result = mhi_write_reg_field(a1, v4, 0x38u);
    if ( !(_DWORD)result )
      return result;
  }
  else
  {
    result = mhi_write_reg_field(a1, v4, 0x38u);
    if ( !(_DWORD)result )
      return result;
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 16) + 192LL);
  if ( a2 <= 3 )
  {
    if ( a2 <= 1 )
    {
      if ( !a2 )
      {
        v8 = "RESET";
        goto LABEL_26;
      }
      if ( a2 == 1 )
      {
        v8 = "READY";
        goto LABEL_26;
      }
LABEL_25:
      v8 = "Unknown state";
      goto LABEL_26;
    }
    if ( a2 == 2 )
      v8 = "M0";
    else
      v8 = "M1";
  }
  else
  {
    if ( a2 > 5 )
    {
      switch ( a2 )
      {
        case 6:
          v8 = "M3_FAST";
          goto LABEL_26;
        case 7:
          v8 = "BHI";
          goto LABEL_26;
        case 255:
          v8 = "SYS ERROR";
          goto LABEL_26;
      }
      goto LABEL_25;
    }
    if ( a2 == 4 )
      v8 = "M2";
    else
      v8 = "M3";
  }
LABEL_26:
  result = dev_err(v3 + 40, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", v8);
  if ( v7 )
  {
    if ( *(_DWORD *)(v7 + 24) <= 2u )
    {
      v9 = *(_QWORD *)(v7 + 32);
      v10 = (const char *)mhi_state_str_0((unsigned int)a2);
      return ipc_log_string(v9, "[E][%s] Failed to set MHI state to: %s\n", "mhi_set_mhi_state", v10);
    }
  }
  return result;
}
