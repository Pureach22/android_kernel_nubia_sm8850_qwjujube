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
    v3 = (void *)qword_16B78;
    if ( qword_16B78 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16B80;
  if ( dword_16B80 == a1 )
  {
    v3 = (void *)qword_16B90;
    if ( qword_16B90 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16B98;
  if ( dword_16B98 == a1 )
  {
    v3 = (void *)qword_16BA8;
    if ( qword_16BA8 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16BB0;
  if ( dword_16BB0 == a1 )
  {
    v3 = (void *)qword_16BC0;
    if ( qword_16BC0 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16BC8;
  if ( dword_16BC8 == a1 )
  {
    v3 = (void *)qword_16BD8;
    if ( qword_16BD8 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16BE0;
  if ( dword_16BE0 == a1 )
  {
    v3 = (void *)qword_16BF0;
    if ( qword_16BF0 == a2 )
      goto LABEL_21;
  }
  v2 = &dword_16BF8;
  if ( dword_16BF8 == a1 )
  {
    v3 = (void *)qword_16C08;
    if ( qword_16C08 == a2 )
      goto LABEL_21;
  }
  if ( (v2 = &dword_16C10, dword_16C10 == a1) && (v3 = (void *)qword_16C20, qword_16C20 == a2)
    || (v2 = &dword_16C28, v4 = dword_16C28 == a1, result = 16, v4) && (v3 = (void *)qword_16C38, qword_16C38 == a2) )
  {
LABEL_21:
    qdf_mem_set(v3, (unsigned int)v2[1], 0);
    result = 0;
    *((_BYTE *)v2 + 8) = 0;
  }
  return result;
}
