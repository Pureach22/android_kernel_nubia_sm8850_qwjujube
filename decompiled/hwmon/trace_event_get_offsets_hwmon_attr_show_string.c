__int64 __fastcall trace_event_get_offsets_hwmon_attr_show_string(__int64 a1, const char *a2, const char *a3)
{
  const char *v4; // x0
  int v7; // w22
  int v8; // w24
  const char *v9; // x0
  int v10; // w9

  if ( a2 )
    v4 = a2;
  else
    v4 = "(null)";
  v7 = strlen(v4);
  v8 = v7 + 1;
  if ( a3 )
    v9 = a3;
  else
    v9 = "(null)";
  *(_QWORD *)(a1 + 8) = a2;
  *(_DWORD *)a1 = (v8 << 16) | 0x14;
  v10 = strlen(v9) + 1;
  *(_DWORD *)(a1 + 16) = (v7 + 21) | (v10 << 16);
  *(_QWORD *)(a1 + 24) = a3;
  return (unsigned int)(v10 + v8);
}
