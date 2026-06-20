__int64 __fastcall _reset_control_release_name(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x21
  void *v7; // x0

  v2 = *(_QWORD *)(a1 + 3904);
  v4 = *(_QWORD *)(v2 + 80);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 88);
  if ( v4 >= v5 )
  {
LABEL_4:
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v7 = &unk_8C43D;
      goto LABEL_13;
    }
    return 0;
  }
  while ( strcmp(*(const char **)(v4 + 8), s2) )
  {
    v4 += 24LL;
    if ( v4 >= v5 )
      goto LABEL_4;
  }
  if ( (*(_BYTE *)(v4 + 16) & 1) != 0 )
  {
    reset_control_release(*(_QWORD *)v4);
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v7 = &unk_7FCD1;
LABEL_13:
      printk(v7, "high", 0xFFFFFFFFLL, "codec", "__reset_control_release_name");
      return 0;
    }
    return 0;
  }
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_970B4, "err ", 0xFFFFFFFFLL, "codec", "__reset_control_release_name");
  return 4294967274LL;
}
