__int64 __fastcall dp_prealloc_get_consistent_mem_unaligned(
        __int64 a1,
        _QWORD *a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int *v11; // x19
  __int64 result; // x0
  __int64 v13; // x4
  __int64 v14; // x6

  v11 = g_dp_consistent_unaligned_allocs;
  if ( g_dp_consistent_unaligned_allocs[0] == a3 && dword_16A4C == a1 && qword_16A58 && (byte_16A50 & 1) == 0 )
  {
    v13 = 0;
LABEL_47:
    v14 = *((_QWORD *)v11 + 3);
    *((_BYTE *)v11 + 8) = 1;
    *a2 = v14;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: i %d: va unalign %pK pa unalign %pK size %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dp_prealloc_get_consistent_mem_unaligned",
      v13,
      *((_QWORD *)v11 + 2));
    return *((_QWORD *)v11 + 2);
  }
  v11 = &dword_16A68;
  if ( dword_16A68 == a3 && dword_16A6C == a1 && qword_16A78 && byte_16A70 != 1 )
  {
    v13 = 1;
    goto LABEL_47;
  }
  v11 = &dword_16A88;
  if ( dword_16A88 == a3 && dword_16A8C == a1 && qword_16A98 && byte_16A90 != 1 )
  {
    v13 = 2;
    goto LABEL_47;
  }
  v11 = &dword_16AA8;
  if ( dword_16AA8 == a3 && dword_16AAC == a1 && qword_16AB8 && byte_16AB0 != 1 )
  {
    v13 = 3;
    goto LABEL_47;
  }
  v11 = &dword_16AC8;
  if ( dword_16AC8 == a3 && dword_16ACC == a1 && qword_16AD8 && byte_16AD0 != 1 )
  {
    v13 = 4;
    goto LABEL_47;
  }
  v11 = &dword_16AE8;
  if ( dword_16AE8 == a3 && dword_16AEC == a1 && qword_16AF8 && byte_16AF0 != 1 )
  {
    v13 = 5;
    goto LABEL_47;
  }
  v11 = &dword_16B08;
  if ( dword_16B08 == a3 && dword_16B0C == a1 && qword_16B18 && byte_16B10 != 1 )
  {
    v13 = 6;
    goto LABEL_47;
  }
  v11 = &dword_16B28;
  if ( dword_16B28 == a3 && dword_16B2C == a1 && qword_16B38 && byte_16B30 != 1 )
  {
    v13 = 7;
    goto LABEL_47;
  }
  v11 = &dword_16B48;
  if ( dword_16B48 != a3 || dword_16B4C != a1 )
    return 0;
  result = 0;
  if ( qword_16B58 )
  {
    if ( byte_16B50 == 1 )
      return 0;
    v13 = 8;
    goto LABEL_47;
  }
  return result;
}
