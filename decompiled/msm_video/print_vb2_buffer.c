__int64 __fastcall print_vb2_buffer(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  const char *v4; // x4
  __int64 v5; // x2

  v3 = *(_DWORD *)(a3 + 12);
  if ( (unsigned int)(v3 - 9) >= 2 )
  {
    if ( v3 == 14 )
    {
      if ( !a2 )
        return result;
    }
    else if ( !a2 || v3 != 13 )
    {
      return result;
    }
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v4 = "OUTPUT_META";
      v5 = a2 + 340;
      return printk(&unk_93AFD, "err ", v5, result, v4);
    }
  }
  else if ( a2 && (msm_vidc_debug & 1) != 0 )
  {
    if ( v3 == 10 )
      v4 = "INPUT";
    else
      v4 = "OUTPUT";
    v5 = a2 + 340;
    return printk(&unk_93AFD, "err ", v5, result, v4);
  }
  return result;
}
