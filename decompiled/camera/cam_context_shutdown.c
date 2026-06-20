__int64 __fastcall cam_context_shutdown(__int64 a1)
{
  int v2; // w8
  int v3; // w9
  unsigned int v4; // w0
  unsigned int v5; // w20
  __int64 result; // x0
  unsigned int v7; // w8
  unsigned int v8; // w20
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 240);
  v9[0] = 0;
  if ( (unsigned int)(v2 - 2) > 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      2,
      "cam_context_shutdown",
      55,
      "dev %s context id %u state %d invalid to release hdl",
      (const char *)a1,
      *(_DWORD *)(a1 + 32),
      v2);
    result = 4294967274LL;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 60);
    LODWORD(v9[0]) = *(_DWORD *)(a1 + 56);
    HIDWORD(v9[0]) = v3;
    v4 = cam_context_handle_release_dev(a1, v9);
    if ( v4 )
    {
      v5 = v4;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "cam_context_shutdown",
        49,
        "context release failed for dev_name %s",
        (const char *)a1);
      result = v5;
    }
    else
    {
      cam_context_putref(a1);
      result = 0;
    }
  }
  v7 = *(_DWORD *)(a1 + 60);
  if ( v7 != -1 )
  {
    result = cam_destroy_device_hdl(v7);
    if ( (_DWORD)result )
    {
      v8 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "cam_context_shutdown",
        64,
        "destroy device hdl failed for node %s",
        (const char *)a1);
      result = v8;
    }
    else
    {
      *(_DWORD *)(a1 + 60) = -1;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
