__int64 __fastcall _cam_isp_ctx_print_fcg_tracker(__int64 result)
{
  _QWORD ***v1; // x8
  _QWORD **v2; // x10
  _QWORD **v3; // x9
  int v4; // w8
  _QWORD *v5; // x11
  int v6; // w9
  int v7; // w10

  v2 = (_QWORD **)(result + 16);
  v1 = *(_QWORD ****)(result + 16);
  if ( v1 == (_QWORD ***)(result + 16) )
  {
    v4 = 0;
    goto LABEL_7;
  }
  v3 = *v1;
  v4 = *((_DWORD *)v1 - 2);
  if ( v3 == v2 )
  {
LABEL_7:
    v6 = 0;
    goto LABEL_8;
  }
  v5 = *v3;
  v6 = *((_DWORD *)v3 - 2);
  if ( v5 == v2 )
  {
LABEL_8:
    v7 = 0;
    goto LABEL_9;
  }
  if ( (_QWORD **)*v5 != v2 )
  {
    __break(0x5512u);
    return list_rotate_left(result);
  }
  v7 = *((_DWORD *)v5 - 2);
LABEL_9:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "__cam_isp_ctx_print_fcg_tracker",
             5782,
             "FCG tracker num_skipped: %u, sum_skipped: %u, skipped list: [%u, %u, %u]",
             *(_DWORD *)(result + 8),
             *(_DWORD *)(result + 12),
             v4,
             v6,
             v7);
  return result;
}
