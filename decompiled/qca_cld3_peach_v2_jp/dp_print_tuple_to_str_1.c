__int64 __fastcall dp_print_tuple_to_str_1(__int64 a1, __int64 a2)
{
  unsigned __int16 v4; // w0
  unsigned __int16 v5; // w21
  __int16 v6; // w0
  __int16 v7; // w23
  __int16 v8; // w0
  unsigned __int16 v9; // w23
  __int16 v10; // w0

  scnprintf(a2, 256, "0x%x", *(_DWORD *)a1);
  v5 = v4;
  scnprintf(a2 + v4, 256 - v4, " 0x%x", *(_DWORD *)(a1 + 16));
  v7 = v6 + v5;
  scnprintf(a2 + (unsigned __int16)(v6 + v5), 256 - (unsigned __int16)(v6 + v5), " %u", *(unsigned __int16 *)(a1 + 32));
  v9 = v8 + v7;
  scnprintf(a2 + v9, 256 - v9, " %u", *(unsigned __int16 *)(a1 + 34));
  scnprintf(a2 + (unsigned __int16)(v10 + v9), 256 - (unsigned __int16)(v10 + v9), " %u", *(unsigned __int8 *)(a1 + 36));
  return a2;
}
