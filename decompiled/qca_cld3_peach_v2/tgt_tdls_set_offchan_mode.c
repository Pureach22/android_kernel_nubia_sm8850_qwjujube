__int64 __fastcall tgt_tdls_set_offchan_mode(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x8

  v2 = *(_QWORD *)(a1 + 2128);
  if ( v2 == -1336 )
    return 0;
  v3 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 1352);
  if ( !v3 )
    return 0;
  if ( *((_DWORD *)v3 - 1) != -906760798 )
    __break(0x8228u);
  return v3(a1, a2);
}
