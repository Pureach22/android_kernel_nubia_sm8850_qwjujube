__int64 __fastcall cam_sync_handle_merge(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  __int64 v4; // x0
  _QWORD *v5; // x19
  size_t v6; // x20
  int v7; // w21
  unsigned int v8; // w0
  unsigned int v9; // w20
  __int64 v10; // x20
  __int64 v11; // x21
  __int64 v12; // x8
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) != 16 )
    goto LABEL_6;
  v1 = *(_QWORD *)(a1 + 16);
  if ( !v1 )
    goto LABEL_6;
  v13 = 0;
  v14[0] = 0;
  if ( inline_copy_from_user_2((int)&v13, v1, 0x10u) )
  {
    result = 4294967282LL;
    goto LABEL_7;
  }
  if ( LODWORD(v14[0]) > 0x7FF )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  v4 = 4LL * LODWORD(v14[0]);
  if ( mem_trace_en == 1 )
  {
    v5 = (_QWORD *)cam_mem_trace_alloc(v4, 0x820u, 0, "cam_sync_handle_merge", 0x2FAu);
    if ( v5 )
      goto LABEL_10;
LABEL_16:
    result = 4294967284LL;
    goto LABEL_7;
  }
  v5 = (_QWORD *)_kvmalloc_node_noprof((unsigned int)v4, 0, 2336, 0xFFFFFFFFLL);
  if ( !v5 )
    goto LABEL_16;
LABEL_10:
  if ( LODWORD(v14[0]) >> 29 )
  {
    __break(0x800u);
    goto LABEL_12;
  }
  v6 = 4LL * LODWORD(v14[0]);
  v7 = v13;
  _check_object_size(v5, v6, 0);
  if ( inline_copy_from_user_2((int)v5, v7, v6) )
    goto LABEL_12;
  v8 = cam_sync_merge((__int64)v5, v14[0], (_DWORD *)v14 + 1);
  if ( !v8 )
  {
    v10 = *(unsigned int *)(a1 + 4);
    if ( (unsigned int)v10 >= 0x11 )
    {
      _copy_overflow(16, *(unsigned int *)(a1 + 4));
      goto LABEL_12;
    }
    v11 = *(_QWORD *)(a1 + 16);
    _check_object_size(&v13, *(unsigned int *)(a1 + 4), 1);
    v12 = inline_copy_to_user_1(v11, &v13, v10);
    v8 = 0;
    if ( v12 )
    {
LABEL_12:
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v5, 0);
      else
        kvfree(v5);
      result = 4294967282LL;
      goto LABEL_7;
    }
  }
  v9 = v8;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  result = v9;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
