__int64 __fastcall stm_console_link(__int64 a1)
{
  __int64 v1; // x0

  *(_QWORD *)(a1 + 48) = *(_QWORD *)"stm_console";
  v1 = a1 + 48;
  *(_DWORD *)(v1 + 8) = 6646895;
  *(_QWORD *)(v1 + 16) = stm_console_write;
  *(_WORD *)(v1 + 72) = 5;
  register_console();
  return 0;
}
