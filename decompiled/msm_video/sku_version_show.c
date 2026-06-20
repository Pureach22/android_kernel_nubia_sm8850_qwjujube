__int64 __fastcall sku_version_show(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8

  if ( result )
  {
    if ( *(_QWORD *)(result + 136) )
    {
      v3 = *(_QWORD *)(result + 152);
      if ( v3 && (v4 = *(_QWORD *)(v3 + 3912)) != 0 )
      {
        return (int)scnprintf(a3, 4096, "%d", *(_DWORD *)(v4 + 324));
      }
      else
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_807F4, "err ", 0xFFFFFFFFLL, "codec", "sku_version_show");
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
