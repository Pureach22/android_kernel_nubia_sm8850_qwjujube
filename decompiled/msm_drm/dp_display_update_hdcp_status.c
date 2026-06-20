__int64 __fastcall dp_display_update_hdcp_status(__int64 a1, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x9
  const char *v5; // x3
  __int64 v6; // x9
  const char *v7; // x4

  if ( (a2 & 1) != 0 )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 168) + 136LL) = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 168) + 140LL) = 0;
  }
  v2 = *(_QWORD *)(a1 + 192);
  *(_QWORD *)(v2 + 134) = 0;
  *(_QWORD *)(v2 + 126) = 0;
  *(_QWORD *)(v2 + 118) = 0;
  *(_QWORD *)(v2 + 110) = 0;
  *(_QWORD *)(v2 + 102) = 0;
  *(_QWORD *)(v2 + 94) = 0;
  *(_QWORD *)(v2 + 86) = 0;
  *(_QWORD *)(v2 + 78) = 0;
  *(_QWORD *)(v2 + 70) = 0;
  *(_QWORD *)(v2 + 62) = 0;
  *(_QWORD *)(v2 + 54) = 0;
  *(_QWORD *)(v2 + 46) = 0;
  *(_QWORD *)(v2 + 38) = 0;
  *(_QWORD *)(v2 + 30) = 0;
  *(_QWORD *)(v2 + 22) = 0;
  *(_QWORD *)(v2 + 14) = 0;
  v3 = *(_QWORD *)(a1 + 168);
  v4 = *(unsigned int *)(v3 + 140);
  if ( (unsigned int)v4 > 2 )
    v5 = "???";
  else
    v5 = off_283770[v4];
  v6 = *(unsigned int *)(v3 + 136);
  if ( (unsigned int)v6 > 3 )
    v7 = "???";
  else
    v7 = off_283788[v6];
  return snprintf((char *)(*(_QWORD *)(a1 + 192) + 14LL), 0x80u, "%s: %s\ncaps: %d\n", v5, v7, *(_DWORD *)(a1 + 240));
}
