__int64 __fastcall edid_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v5; // w19
  int v6; // w20
  int v7; // w0

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(unsigned __int16 *)(v3 + 3204);
  v6 = *(unsigned __int16 *)(v3 + 3214);
  v7 = drm_mode_vrefresh(v3 + 3200);
  return (int)scnprintf(a3, 4096, "%dx%d@%d\n", v5, v6, v7);
}
