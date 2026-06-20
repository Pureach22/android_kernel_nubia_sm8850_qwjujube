__int64 __fastcall print_vidc_buffer(__int64 result, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  const char *v9; // x8
  const char *v10; // [xsp+90h] [xbp-20h]

  if ( a3 && a2 && a5 )
  {
    v5 = *(_QWORD *)(a5 + 88);
    if ( v5 && (v6 = *(_QWORD *)(v5 + 8)) != 0 && *(_QWORD *)(v6 + 40) )
    {
      if ( !a4 )
        return result;
    }
    else if ( !a4 )
    {
      return result;
    }
    if ( (msm_vidc_debug & (unsigned int)result) != 0 )
    {
      v7 = *(unsigned int *)(a5 + 24);
      if ( (unsigned int)v7 <= 0xF )
        v9 = buf_type_name_arr[v7];
      else
        v9 = "UNKNOWN BUF";
      v10 = v9;
      buf_region_name(*(_DWORD *)(a5 + 28));
      return printk(&unk_9477F, a2, a4 + 340, a3, v10);
    }
  }
  return result;
}
