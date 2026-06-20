unsigned __int64 __fastcall get_si_object_from_u_handle(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 result; // x0
  __int64 inited; // x20
  unsigned __int64 v7; // x0
  __int64 v8; // x0
  const char *v9; // x4
  unsigned __int64 v10; // x22
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x2
  __int64 v13; // x21

  v2 = *a1;
  if ( *a1 == -1 )
  {
    result = 0;
  }
  else
  {
    if ( v2 > -2 )
    {
      v7 = dma_buf_get((unsigned int)v2);
      if ( v7 <= 0xFFFFFFFFFFFFF000LL )
      {
        v10 = v7;
        v11 = cb_object_alloc(a1[1]);
        if ( v11 <= 0xFFFFFFFFFFFFF000LL )
        {
          v12 = v11;
          *(_QWORD *)(v11 + 96) = v2;
        }
        else
        {
          v12 = 0;
        }
        inited = init_si_mem_object_user(v10, mem_object_release, v12);
        ((void (*)(void))get_si_object)();
        dma_buf_put(v10);
        if ( inited )
        {
          result = 0;
          goto LABEL_18;
        }
      }
      else
      {
        v8 = fget((unsigned int)v2);
        if ( v8 )
        {
          if ( *(_UNKNOWN ***)(v8 + 16) == &qtee_fops )
          {
            inited = *(_QWORD *)(v8 + 32);
            v13 = v8;
            get_si_object(inited);
            fput(v13);
            result = 0;
            goto LABEL_18;
          }
          fput(v8);
        }
      }
      inited = 0;
      result = 4294967274LL;
      goto LABEL_18;
    }
    result = cb_object_alloc(a1[1]);
    inited = result;
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v9 = *(const char **)(result + 104);
      *(_QWORD *)(result + 96) = v2;
      init_si_object_user(result, 2, &cbo_sio_ops, "cbo-%s%d", v9, v2);
      get_si_object(inited);
      result = 0;
      goto LABEL_18;
    }
    result = (unsigned int)result;
  }
  inited = 0;
LABEL_18:
  *(_QWORD *)(a2 + 8) = inited;
  return result;
}
