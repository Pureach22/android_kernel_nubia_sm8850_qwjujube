__int64 __fastcall dfunc_string(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  int v6; // w9

  tsv_timestamp_read(a1, a2, (const char *)&unk_8291);
  tsv_qtimer_read(a1, a2, " ");
  result = tsv_byte_array_read(a1, a2);
  v5 = *(_QWORD *)(a2 + 8);
  if ( *(_BYTE *)(v5 - 1) != 10 )
  {
    v6 = *(_DWORD *)(a2 + 16);
    if ( v6 )
    {
      *(_QWORD *)(a2 + 8) = ++v5;
      *(_DWORD *)(a2 + 16) = v6 - 1;
    }
    *(_BYTE *)(v5 - 1) = 10;
  }
  return result;
}
