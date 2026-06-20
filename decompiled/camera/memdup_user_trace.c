__int64 __fastcall memdup_user_trace(int a1, size_t a2, const char *a3, unsigned int a4)
{
  __int64 v6; // x0
  __int64 v7; // x19

  v6 = cam_mem_trace_alloc(a2, 0x102CC0u, 0, a3, a4);
  if ( !v6 )
    return -12;
  v7 = v6;
  if ( a2 >> 31 )
  {
    __break(0x800u);
    goto LABEL_4;
  }
  _check_object_size(v6, a2, 0);
  if ( inline_copy_from_user_0(v7, a1, a2) )
  {
LABEL_4:
    kfree(v7);
    return -14;
  }
  return v7;
}
