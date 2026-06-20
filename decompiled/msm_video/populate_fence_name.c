__int64 __fastcall populate_fence_name(__int64 a1, __int64 a2, char a3)
{
  const char *v3; // x3
  const char *v4; // x4
  const char *v5; // x6

  if ( (a3 & 1) != 0 )
    v3 = (const char *)(a1 + 340);
  else
    v3 = (const char *)&unk_84D69;
  if ( (a3 & 1) != 0 )
    v4 = (const char *)&unk_95828;
  else
    v4 = (const char *)&unk_84D69;
  if ( *(_QWORD *)(a2 + 176) )
    v5 = (const char *)&unk_88630;
  else
    v5 = (const char *)&unk_823BB;
  return snprintf(
           (char *)(a2 + 16),
           0x80u,
           "%s%sfence: %s: %s: fd %3d id %10llu mid %5llu f.no %5llu",
           v3,
           v4,
           *(const char **)(a2 + 272),
           v5,
           *(_DWORD *)(a2 + 152),
           *(_QWORD *)(a2 + 160),
           *(_QWORD *)(a2 + 160) & 0x7FFFFFFFLL,
           *(_QWORD *)(a2 + 168));
}
