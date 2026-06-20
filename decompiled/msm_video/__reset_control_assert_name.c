__int64 __fastcall _reset_control_assert_name(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x21
  __int64 result; // x0
  unsigned int v7; // w19

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v2 + 80);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 88);
  if ( v4 >= v5 )
  {
LABEL_4:
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_7FD11, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_assert_name");
    return 4294967274LL;
  }
  else
  {
    while ( strcmp(*(const char **)(v4 + 8), s2) )
    {
      v4 += 24LL;
      if ( v4 >= v5 )
        goto LABEL_4;
    }
    result = reset_control_assert(*(_QWORD *)v4);
    if ( (_DWORD)result )
    {
      if ( (msm_vidc_debug & 1) != 0 )
      {
        v7 = result;
        printk(&unk_901E6, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_assert_name");
        return v7;
      }
    }
    else
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_93ED9, "high", 0xFFFFFFFFLL, "codec", "__reset_control_assert_name");
      return 0;
    }
  }
  return result;
}
