__int64 __fastcall cam_subdev_probe(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x0
  _QWORD *v10; // x21
  unsigned int v11; // w20

  result = 4294967274LL;
  if ( a1 && a2 && a3 )
  {
    if ( mem_trace_en == 1 )
    {
      v9 = cam_mem_trace_alloc(344, 0xCC0u, 0, "cam_subdev_probe", 0x9Cu);
      if ( !v9 )
        return 4294967284LL;
    }
    else
    {
      v9 = _kvmalloc_node_noprof(344, 0, 3520, 0xFFFFFFFFLL);
      if ( !v9 )
        return 4294967284LL;
    }
    *(_QWORD *)(a1 + 408) = a3;
    *(_QWORD *)(a1 + 392) = &cam_subdev_ops;
    v10 = (_QWORD *)v9;
    *(_QWORD *)(a1 + 424) = v9;
    *(_QWORD *)a1 = a2;
    *(_DWORD *)(a1 + 416) = 12;
    *(_DWORD *)(a1 + 432) = a4;
    result = cam_register_subdev(a1);
    if ( (_DWORD)result )
    {
      v11 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "cam_subdev_probe",
        172,
        "cam_register_subdev() failed for dev: %s",
        *(const char **)(a1 + 408));
      if ( (mem_trace_en & 1) != 0 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      return v11;
    }
    else
    {
      *(_QWORD *)(*(_QWORD *)a1 + 168LL) = a1;
    }
  }
  return result;
}
