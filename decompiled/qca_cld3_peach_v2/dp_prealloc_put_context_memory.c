__int64 __fastcall dp_prealloc_put_context_memory(int a1, __int64 a2)
{
  int *v2; // x19
  void *v3; // x8
  bool v4; // zf
  __int64 result; // x0

  if ( !a2 )
    return 16;
  v2 = &g_dp_context_allocs;
  if ( g_dp_context_allocs == a1 )
  {
    v3 = (void *)qword_17498;
    if ( qword_17498 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_174A0;
  if ( dword_174A0 == a1 )
  {
    v3 = (void *)qword_174B0;
    if ( qword_174B0 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_174B8;
  if ( dword_174B8 == a1 )
  {
    v3 = (void *)qword_174C8;
    if ( qword_174C8 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_174D0;
  if ( dword_174D0 == a1 )
  {
    v3 = (void *)qword_174E0;
    if ( qword_174E0 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_174E8;
  if ( dword_174E8 == a1 )
  {
    v3 = (void *)qword_174F8;
    if ( qword_174F8 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_17500;
  if ( dword_17500 == a1 )
  {
    v3 = (void *)qword_17510;
    if ( qword_17510 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_17518;
  if ( dword_17518 == a1 )
  {
    v3 = (void *)qword_17528;
    if ( qword_17528 == a2 )
      goto LABEL_21;
  }
  if ( (v2 = &dword_17530, dword_17530 == a1) && (v3 = (void *)qword_17540, qword_17540 == a2)
    || (v2 = &dword_17548, v4 = dword_17548 == a1, result = 16, v4) && (v3 = (void *)qword_17558, qword_17558 == a2) )
  {
LABEL_21:
    qdf_mem_set(v3, (unsigned int)v2[1], 0);
    result = 0;
    *((_BYTE *)v2 + 8) = 0;
  }
  return result;
}
