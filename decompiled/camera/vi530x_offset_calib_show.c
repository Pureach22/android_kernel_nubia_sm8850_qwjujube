__int64 __fastcall vi530x_offset_calib_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
    return (int)scnprintf(a3, 4096, "%d\n", *(__int16 *)(v3 + 42));
  else
    return -1;
}
