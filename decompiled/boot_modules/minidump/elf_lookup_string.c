__int64 __fastcall elf_lookup_string(__int64 a1, int a2)
{
  __int64 v2; // x8
  bool v3; // zf
  __int64 v4; // x8

  v2 = *(unsigned __int16 *)(a1 + 62);
  if ( *(_WORD *)(a1 + 62) )
    v2 = a1 + *(_QWORD *)(*(_QWORD *)(a1 + 40) + a1 + (v2 << 6) + 24);
  v3 = qword_10040 < (unsigned __int64)a2 || v2 == 0;
  v4 = v2 + a2;
  if ( v3 )
    return 0;
  else
    return v4;
}
