__int64 __fastcall dsi_parser_get(__int64 a1)
{
  __int64 result; // x0

  if ( a1 )
  {
    result = devm_kmalloc(a1, 72, 3520);
    if ( result )
    {
      *(_QWORD *)(result + 24) = a1;
      strcpy((char *)(result + 40), "dsi_prop");
    }
    else
    {
      return -12;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid data\n");
    return -22;
  }
  return result;
}
