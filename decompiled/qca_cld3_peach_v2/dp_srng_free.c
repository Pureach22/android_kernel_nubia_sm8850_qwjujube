__int64 __fastcall dp_srng_free(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x9
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x1

  if ( *(_DWORD *)(a2 + 40) && *(_QWORD *)(a2 + 8) )
  {
    if ( *(_BYTE *)(a2 + 44) )
    {
      result = _qdf_mem_free(*(_QWORD *)(a2 + 8));
    }
    else if ( *(_BYTE *)(a2 + 76) )
    {
      v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(result + 8) + 240LL);
      if ( v11 )
      {
        v12 = *(_QWORD *)(a2 + 24);
        v13 = *(unsigned int *)(a2 + 40);
        v14 = *(_QWORD *)(a2 + 8);
        if ( *((_DWORD *)v11 - 1) != -1361934022 )
          __break(0x8229u);
        result = v11(v13, v14, v12);
      }
      else
      {
        result = qdf_trace_msg(
                   0x45u,
                   3u,
                   "%s: dp_prealloc_put_consistent is null!",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "dp_srng_mem_free_consistent");
      }
    }
    else
    {
      result = _qdf_mem_free_consistent(
                 *(_QWORD *)(result + 24),
                 *(_QWORD *)(*(_QWORD *)(result + 24) + 40LL),
                 *(_DWORD *)(a2 + 40));
    }
    *(_DWORD *)(a2 + 40) = 0;
    *(_QWORD *)(a2 + 8) = 0;
  }
  *(_QWORD *)a2 = 0;
  return result;
}
