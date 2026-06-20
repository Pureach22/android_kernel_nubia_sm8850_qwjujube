__int64 __fastcall zte_lcd_reg_debug_func(__int64 a1)
{
  __int64 result; // x0

  result = strcmp(*(const char **)(a1 + 8), "primary");
  if ( !(_DWORD)result )
  {
    main_panel = a1;
    return create_sys_file();
  }
  return result;
}
