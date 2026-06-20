__int64 __fastcall index_show(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // x20
  void (__fastcall *v5)(__int64, __int64); // x8
  int v6; // w3

  v3 = *(_QWORD *)(a1 + 152);
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v3 + 1312) + 288LL);
  if ( *((_DWORD *)v5 - 1) != -746885483 )
    __break(0x8228u);
  v5(v3 - 168, 1);
  v6 = *(unsigned __int8 *)(v3 - 138);
  *(_DWORD *)(v3 - 100) = v6;
  return snprintf(a3, 0x1000u, "index = %d\n", v6);
}
