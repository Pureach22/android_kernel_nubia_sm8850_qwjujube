__int64 __fastcall csr_ll_insert_entry(
        __int64 result,
        __int64 *a2,
        _QWORD *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x9
  __int64 v24; // x8
  int v25; // w9
  __int64 v26; // x19

  if ( !result )
    return qdf_trace_msg(
             0x34u,
             2u,
             "%s: Error!! pList is Null",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "csr_ll_insert_entry");
  if ( *(_DWORD *)(result + 84) == -1582119721 )
  {
    if ( (a4 & 1) != 0 )
    {
      v12 = result;
      result = qdf_mutex_acquire(result + 16);
      if ( a2 )
      {
        v23 = *a2;
        *(_QWORD *)(v23 + 8) = a3;
        *a2 = (__int64)a3;
        *a3 = v23;
        a3[1] = a2;
      }
      else
      {
        result = qdf_trace_msg(
                   0x34u,
                   2u,
                   "%s: Error!! pEntry is Null",
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   v20,
                   v21,
                   v22,
                   "csr_list_insert_entry");
      }
      v25 = *(_DWORD *)(v12 + 84);
      ++*(_DWORD *)(v12 + 80);
      if ( v25 == -1582119721 )
        return qdf_mutex_release(v12 + 16);
    }
    else
    {
      if ( a2 )
      {
        v24 = *a2;
        *(_QWORD *)(v24 + 8) = a3;
        *a2 = (__int64)a3;
        *a3 = v24;
        a3[1] = a2;
      }
      else
      {
        v26 = result;
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Error!! pEntry is Null",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "csr_list_insert_entry");
        result = v26;
      }
      ++*(_DWORD *)(result + 80);
    }
  }
  return result;
}
