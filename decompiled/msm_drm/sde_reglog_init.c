__int64 sde_reglog_init()
{
  __int64 result; // x0

  result = vzalloc_noprof(24624);
  if ( !result )
    return -12;
  *(_QWORD *)(result + 24600) = 0;
  *(_QWORD *)(result + 24584) = 0;
  *(_DWORD *)(result + 24612) = 1;
  return result;
}
