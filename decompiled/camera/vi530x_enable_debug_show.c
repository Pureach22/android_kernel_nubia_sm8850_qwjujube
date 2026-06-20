__int64 __fastcall vi530x_enable_debug_show(__int64 a1, int a2, char *s)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
    return snprintf(s, 0x1000u, "%u\n", *(_DWORD *)(v3 + 228));
  else
    return -22;
}
