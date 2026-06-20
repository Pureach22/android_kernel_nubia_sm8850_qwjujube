__int64 __fastcall cam_context_init(
        __int64 a1,
        const char *a2,
        __int64 a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8,
        int a9)
{
  size_t v17; // x0
  unsigned __int64 v18; // x2
  _QWORD *v19; // x9
  int v20; // w10
  __int64 v21; // x11
  __int64 v22; // x8
  _QWORD *v23; // x12
  _QWORD *v24; // x1
  _QWORD *v25; // x0
  __int64 result; // x0
  __int64 v29; // x0

  if ( !a1 || !a6 || !a7 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_init",
      728,
      "Invalid input parameters");
    return 4294967274LL;
  }
  memset((void *)a1, 0, 0x228u);
  *(_DWORD *)(a1 + 64) = -1;
  *(_QWORD *)(a1 + 56) = -1;
  *(_QWORD *)(a1 + 40) = a1 + 40;
  *(_QWORD *)(a1 + 48) = a1 + 40;
  _mutex_init(a1 + 72, "&ctx->ctx_mutex", &cam_context_init___key);
  _mutex_init(a1 + 416, "&ctx->sync_mutex", &cam_context_init___key_51);
  *(_DWORD *)(a1 + 120) = 0;
  v17 = strnlen(a2, 0x14u);
  if ( v17 == -1 )
  {
    _fortify_panic(2, -1, 0);
LABEL_26:
    v29 = _fortify_panic(7, 20, v18);
    return cam_context_handle_hw_event(v29);
  }
  if ( v17 == 20 )
    v18 = 20;
  else
    v18 = v17 + 1;
  if ( v18 >= 0x15 )
    goto LABEL_26;
  sized_strscpy(a1, a2);
  *(_QWORD *)(a1 + 24) = a3;
  *(_QWORD *)(a1 + 224) = a5;
  *(_QWORD *)(a1 + 232) = cam_context_handle_hw_event;
  v19 = (_QWORD *)(a1 + 176);
  *(_DWORD *)(a1 + 32) = a4;
  *(_DWORD *)(a1 + 464) = 0;
  *(_QWORD *)(a1 + 208) = a6;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 128) = a1 + 128;
  *(_QWORD *)(a1 + 136) = a1 + 128;
  *(_QWORD *)(a1 + 160) = a1 + 160;
  *(_QWORD *)(a1 + 168) = a1 + 160;
  *(_QWORD *)(a1 + 144) = a1 + 144;
  *(_QWORD *)(a1 + 152) = a1 + 144;
  *(_QWORD *)(a1 + 176) = a1 + 176;
  *(_QWORD *)(a1 + 184) = a1 + 176;
  *(_QWORD *)(a1 + 192) = a7;
  *(_DWORD *)(a1 + 200) = a8;
  if ( a8 )
  {
    v20 = 0;
    do
    {
      v21 = v20;
      v22 = 144LL * v20;
      v23 = (_QWORD *)(*(_QWORD *)(a1 + 192) + v22);
      *v23 = v23;
      v23[1] = v23;
      v24 = *(_QWORD **)(a1 + 184);
      v25 = (_QWORD *)(*(_QWORD *)(a1 + 192) + v22);
      if ( v25 != v19 && v24 != v25 && *v24 == (_QWORD)v19 )
      {
        *(_QWORD *)(a1 + 184) = v25;
        *v25 = v19;
        v25[1] = v24;
        *v24 = v25;
      }
      else
      {
        _list_add_valid_or_report(v25);
      }
      *(_QWORD *)(*(_QWORD *)(a1 + 192) + 144 * v21 + 104) = a1;
      *(_DWORD *)(*(_QWORD *)(a1 + 192) + 144 * v21 + 92) = v20++;
    }
    while ( a8 != v20 );
  }
  result = 0;
  *(_QWORD *)(a1 + 248) = 0;
  *(_QWORD *)(a1 + 256) = 0;
  *(_DWORD *)(a1 + 240) = 1;
  *(_DWORD *)(a1 + 512) = a9;
  return result;
}
