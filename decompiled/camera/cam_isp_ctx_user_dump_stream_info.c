_DWORD *__fastcall cam_isp_ctx_user_dump_stream_info(_DWORD *a1, _DWORD *a2)
{
  int v2; // w8

  *a2 = a1[8];
  a2[1] = a1[15];
  v2 = a1[16];
  a2[2] = v2;
  return a2 + 3;
}
