__int64 __fastcall get_last_cmd_buffer(unsigned int a1, _QWORD *a2)
{
  __int64 v2; // x8

  if ( a1 < 2 )
  {
    v2 = last_cmd_buf[a1];
    if ( v2 && *(_QWORD *)(v2 + 24) )
    {
      *a2 = v2;
      return 0;
    }
    _drm_err("invalid last cmd buf\n");
  }
  else
  {
    _drm_err("invalid dpu idx %d\n", a1);
  }
  return 4294967274LL;
}
