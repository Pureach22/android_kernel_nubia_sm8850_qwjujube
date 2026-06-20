__int64 __fastcall fastrpc_pack_root_sharedpage(__int64 result, __int64 a2, _DWORD *a3)
{
  unsigned __int64 v3; // x20
  size_t v4; // x21
  __int64 v5; // x19
  _QWORD *v6; // x22
  __int64 v9; // x22

  v3 = *(_QWORD *)(result + 608);
  if ( v3 )
  {
    v4 = *(unsigned int *)(result + 616);
    v5 = result;
    if ( (_DWORD)v4 )
    {
      v6 = *(_QWORD **)(result + 136);
      if ( (unsigned int)fastrpc_buf_alloc(
                           result,
                           (__int64)v6,
                           *(unsigned int *)(result + 616),
                           3u,
                           (_QWORD *)(result + 176)) )
      {
        return dev_err(*v6, "failed to allocate buffer\n");
      }
      else if ( (v4 & 0x80000000) != 0 )
      {
        __break(0x800u);
        result = *(_QWORD *)(v5 + 176);
        if ( result )
          goto LABEL_7;
      }
      else
      {
        v9 = *(_QWORD *)(*(_QWORD *)(v5 + 176) + 48LL);
        _check_object_size(v9, v4, 0);
        result = inline_copy_from_user(v9, v3, v4);
        if ( result )
        {
          result = *(_QWORD *)(v5 + 176);
          if ( result )
          {
LABEL_7:
            result = fastrpc_buf_free(result, 0);
            *(_QWORD *)(v5 + 176) = 0;
          }
        }
        else
        {
          *a3 = 4;
          *(_QWORD *)(a2 + 48) = *(_QWORD *)(*(_QWORD *)(v5 + 176) + 64LL);
          *(_QWORD *)(a2 + 56) = *(_QWORD *)(*(_QWORD *)(v5 + 176) + 72LL);
        }
      }
    }
  }
  return result;
}
