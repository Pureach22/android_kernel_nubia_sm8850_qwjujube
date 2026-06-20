__int64 __fastcall msm_ioremap(__int64 a1, const char *a2)
{
  __int64 result; // x0

  if ( a2 )
  {
    if ( platform_get_resource_byname(a1, 512, a2) )
      goto LABEL_3;
    return -22;
  }
  if ( !platform_get_resource(a1, 512, 0) )
    return -22;
LABEL_3:
  result = devm_ioremap(a1 + 16);
  if ( !result )
  {
    dev_err(a1 + 16, "[%s:%d] failed to ioremap: %s\n", "msm_ioremap", 311, a2);
    return -12;
  }
  return result;
}
