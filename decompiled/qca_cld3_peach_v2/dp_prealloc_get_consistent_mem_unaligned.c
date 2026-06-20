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
  if ( g_dp_consistent_unaligned_allocs[0] == a3 && dword_1736C == a1 && qword_17378 && (byte_17370 & 1) == 0 )
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
  v11 = &dword_17388;
  if ( dword_17388 == a3 && dword_1738C == a1 && qword_17398 && byte_17390 != 1 )
  {
    v13 = 1;
    goto LABEL_47;
  }
  v11 = &dword_173A8;
  if ( dword_173A8 == a3 && dword_173AC == a1 && qword_173B8 && byte_173B0 != 1 )
  {
    v13 = 2;
    goto LABEL_47;
  }
  v11 = &dword_173C8;
  if ( dword_173C8 == a3 && dword_173CC == a1 && qword_173D8 && byte_173D0 != 1 )
  {
    v13 = 3;
    goto LABEL_47;
  }
  v11 = &dword_173E8;
  if ( dword_173E8 == a3 && dword_173EC == a1 && qword_173F8 && byte_173F0 != 1 )
  {
    v13 = 4;
    goto LABEL_47;
  }
  v11 = &dword_17408;
  if ( dword_17408 == a3 && dword_1740C == a1 && qword_17418 && byte_17410 != 1 )
  {
    v13 = 5;
    goto LABEL_47;
  }
  v11 = &dword_17428;
  if ( dword_17428 == a3 && dword_1742C == a1 && qword_17438 && byte_17430 != 1 )
  {
    v13 = 6;
    goto LABEL_47;
  }
  v11 = &dword_17448;
  if ( dword_17448 == a3 && dword_1744C == a1 && qword_17458 && byte_17450 != 1 )
  {
    v13 = 7;
    goto LABEL_47;
  }
  v11 = &dword_17468;
  if ( dword_17468 != a3 || dword_1746C != a1 )
    return 0;
  result = 0;
  if ( qword_17478 )
  {
    if ( byte_17470 == 1 )
      return 0;
    v13 = 8;
    goto LABEL_47;
  }
  return result;
}
