__int64 __fastcall wcd_mbhc_get_button_mask(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w0

  v1 = *(_QWORD *)(a1 + 120);
  v2 = *(_QWORD *)(a1 + 216);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v1 + 136);
  if ( *((_DWORD *)v3 - 1) != -725583242 )
    __break(0x8228u);
  v4 = v3(v2);
  if ( v4 > 5 )
    return 0;
  else
    return dword_E6E8[v4];
}
