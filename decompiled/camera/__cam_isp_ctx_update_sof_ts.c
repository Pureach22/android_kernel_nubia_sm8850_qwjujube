__int64 *__fastcall _cam_isp_ctx_update_sof_ts(__int64 *result, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x11
  _QWORD *v5; // x12
  unsigned __int64 v6; // x9
  __int64 v7; // x11
  char v8; // w10
  __int64 v9; // x6

  v3 = *result;
  v4 = *result + 128;
  result[5707] = jiffies;
  v5 = (_QWORD *)v4;
  while ( 1 )
  {
    v5 = (_QWORD *)*v5;
    if ( v5 == (_QWORD *)v4 )
      break;
    v6 = v5[3];
    if ( v6 > result[4666] )
      goto LABEL_8;
  }
  v7 = *(_QWORD *)(v3 + 160);
  v6 = 0;
  if ( v7 != v3 + 160 && v7 )
    v6 = *(_QWORD *)(v7 + 24);
LABEL_8:
  result[4663] = a2;
  result[4664] = a3;
  v8 = debug_mdl;
  v9 = result[1] + 1;
  result[1] = v9;
  if ( (v8 & 8) != 0 && !debug_priority )
    return (__int64 *)((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        v8 & 8,
                        4,
                        "__cam_isp_ctx_update_sof_ts",
                        1225,
                        "Frame id: %llu, SOF qtimer timestamp: [%llu:%09llu], boot timestamp: [%llu:%09llu], ctx %u, requ"
                        "est id: %llu, link: 0x%x",
                        v9,
                        a2 / 0x3B9ACA00,
                        a2 % 0x3B9ACA00,
                        a3 / 0x3B9ACA00,
                        a3 % 0x3B9ACA00,
                        *(_DWORD *)(v3 + 32),
                        v6,
                        *(_DWORD *)(v3 + 64));
  return result;
}
