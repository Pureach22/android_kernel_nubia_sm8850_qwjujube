__int64 __fastcall speed_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v5; // x9
  unsigned int *v6; // x8
  const char *v7; // x0

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(_QWORD *)(v3 + 40);
  if ( v5 )
    v6 = (unsigned int *)(*(_QWORD *)(v5 + 168) + 1232LL);
  else
    v6 = (unsigned int *)(v3 + 1128);
  v7 = (const char *)usb_speed_string(*v6);
  return (int)scnprintf(a3, 4096, "%s\n", v7);
}
