__int64 __fastcall cam_context_handle_acquire_dev(__int64 a1, __int64 a2)
{
  unsigned int v4; // w7
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  int v6; // w0
  const char *v7; // x5
  __int64 v8; // x4
  unsigned int v10; // w20
  _QWORD *v11; // x9
  unsigned int v12; // w10
  int v13; // w11
  _QWORD *v14; // x8
  _QWORD *v15; // x1
  _QWORD *v16; // x0

  if ( !*(_QWORD *)(a1 + 248) )
  {
    v7 = "Context is not ready";
    v8 = 388;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_acquire_dev",
      v8,
      v7);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v7 = "Invalid acquire device command payload";
    v8 = 393;
    goto LABEL_9;
  }
  mutex_lock(a1 + 72);
  v4 = *(_DWORD *)(a1 + 240);
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * v4);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -1263047823 )
      __break(0x8228u);
    v6 = v5(a1, a2);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_acquire_dev",
      403,
      "No acquire device in dev %d, state %d",
      *(_DWORD *)(a2 + 8),
      v4);
    v6 = -71;
  }
  v10 = v6;
  *(_QWORD *)(a1 + 128) = a1 + 128;
  *(_QWORD *)(a1 + 136) = a1 + 128;
  *(_QWORD *)(a1 + 160) = a1 + 160;
  *(_QWORD *)(a1 + 168) = a1 + 160;
  v11 = (_QWORD *)(a1 + 176);
  *(_QWORD *)(a1 + 144) = a1 + 144;
  *(_QWORD *)(a1 + 152) = a1 + 144;
  *(_QWORD *)(a1 + 176) = a1 + 176;
  *(_QWORD *)(a1 + 184) = a1 + 176;
  if ( *(_DWORD *)(a1 + 200) )
  {
    v12 = 0;
    v13 = 144;
    do
    {
      v14 = (_QWORD *)(*(_QWORD *)(a1 + 192) + (int)v12 * (__int64)v13);
      *v14 = v14;
      v14[1] = v14;
      v15 = *(_QWORD **)(a1 + 184);
      v16 = (_QWORD *)(*(_QWORD *)(a1 + 192) + (int)v12 * (__int64)v13);
      if ( v16 != v11 && v15 != v16 && *v15 == (_QWORD)v11 )
      {
        *(_QWORD *)(a1 + 184) = v16;
        *v16 = v11;
        v16[1] = v15;
        *v15 = v16;
      }
      else
      {
        _list_add_valid_or_report(v16);
      }
      ++v12;
    }
    while ( v12 < *(_DWORD *)(a1 + 200) );
  }
  mutex_unlock(a1 + 72);
  return v10;
}
