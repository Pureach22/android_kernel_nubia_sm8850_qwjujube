__int64 __fastcall re_range_show(__int64 a1, int a2, char *s)
{
  __int64 v4; // x8
  int v5; // w19
  __int64 v6; // x22

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL);
  v5 = *(_DWORD *)(v4 + 60);
  v6 = snprintf(s, 0x1000u, "re_min value: [%d] mOhms\n", *(_DWORD *)(v4 + 64));
  return v6 + snprintf(&s[v6], 4096 - v6, "re_max value: [%d] mOhms\n", v5);
}
