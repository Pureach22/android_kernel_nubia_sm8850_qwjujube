__int64 sde_evtlog_init()
{
  __int64 result; // x0

  result = vzalloc_noprof(786496);
  if ( !result )
    return -12;
  *(_DWORD *)(result + 786476) = 0;
  *(_DWORD *)(result + 786444) = 0;
  *(_QWORD *)(result + 786452) = 0x20000000BLL;
  *(_QWORD *)(result + 786480) = result + 786480;
  *(_QWORD *)(result + 786488) = result + 786480;
  return result;
}
