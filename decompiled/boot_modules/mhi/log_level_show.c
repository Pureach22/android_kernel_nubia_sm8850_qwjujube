__int64 __fastcall log_level_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x8
  const char *v5; // x3

  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 - 24) + 16LL) + 192LL);
  if ( !v3 )
    return -5;
  v4 = *(unsigned int *)(v3 + 24);
  if ( (unsigned int)v4 <= 4 )
    v5 = mhi_log_level_str[v4];
  else
    v5 = "Mask all";
  return (int)scnprintf(a3, 4096, "IPC log level begins from: %s\n", v5);
}
