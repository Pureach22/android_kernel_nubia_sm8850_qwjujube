__int64 __fastcall qcom_register_dump_segments(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  unsigned int v3; // w8
  unsigned __int64 v5; // x21
  _DWORD *v6; // x22
  __int64 result; // x0

  v2 = *(_QWORD *)(a2 + 8);
  v3 = *(unsigned __int16 *)(v2 + 44);
  if ( *(_WORD *)(v2 + 44) )
  {
    v5 = 0;
    v6 = (_DWORD *)(v2 + 76);
    do
    {
      if ( *(v6 - 6) == 1 && (*v6 & 0x7000000) != 0x2000000 && *(v6 - 1) )
      {
        result = rproc_coredump_add_segment(a1, (unsigned int)*(v6 - 3));
        if ( (_DWORD)result )
          return result;
        v3 = *(unsigned __int16 *)(v2 + 44);
      }
      ++v5;
      v6 += 8;
    }
    while ( v5 < v3 );
  }
  return 0;
}
