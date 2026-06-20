__int64 __fastcall cfg_ini_buf_cb(__int64 result, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  int v4; // w19

  if ( a2 && result && a3 && !*(_QWORD *)(result + 32536) )
  {
    v3 = result;
    v4 = a2;
    result = _qdf_mem_malloc(a3, "cfg_ini_buf_cb", 444);
    *(_QWORD *)(v3 + 32536) = result;
    if ( result )
      return qdf_mem_copy(result, v4, a3);
  }
  return result;
}
