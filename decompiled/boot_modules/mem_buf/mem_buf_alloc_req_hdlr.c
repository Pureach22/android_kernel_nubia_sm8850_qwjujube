__int64 __fastcall mem_buf_alloc_req_hdlr(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  _QWORD *v7; // x22
  __int64 v8; // x0
  __int64 v9; // x1

  if ( (mem_buf_capability & 1) != 0 )
  {
    v6 = result;
    result = _kmalloc_cache_noprof(dup_gh_sgl_desc, 3264, 56, a4);
    v7 = (_QWORD *)result;
    if ( result )
    {
      v8 = kmemdup_noprof(a2, a3, 3264);
      if ( v8 )
      {
        *v7 = v6;
        v7[1] = v8;
        v7[3] = 0xFFFFFFFE00000LL;
        v7[2] = a3;
        v7[4] = v7 + 4;
        v7[5] = v7 + 4;
        v9 = mem_buf_wq;
        v7[6] = &mem_buf_alloc_req_work;
        return queue_work_on(32, v9, v7 + 3);
      }
      else
      {
        return kfree(v7);
      }
    }
  }
  return result;
}
