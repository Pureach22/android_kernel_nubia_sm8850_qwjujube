__int64 hvc_gh_console_init()
{
  __int64 result; // x0
  int v1; // w21
  int i; // w22

  if ( (unsigned int)hvc_instantiate(1196317000, 0, gh_hv_ops) )
  {
    result = hvc_instantiate(1196317000, 1, gh_hv_ops);
    if ( (_DWORD)result )
      return result;
    v1 = 2;
  }
  else
  {
    v1 = 1;
  }
  for ( i = 0; i != 4; ++i )
  {
    result = hvc_instantiate((unsigned int)(i + 1196317001), (unsigned int)(v1 + i), gh_hv_ops);
    if ( (_DWORD)result )
      break;
  }
  return result;
}
