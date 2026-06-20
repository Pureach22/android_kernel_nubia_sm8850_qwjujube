__int64 __fastcall tgt_tdls_set_fw_state(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64); // x8

  if ( *(_QWORD *)(a1 + 2128) == -1336 )
    return 0;
  v2 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 2128) + 1336LL);
  if ( !v2 )
    return 0;
  if ( *((_DWORD *)v2 - 1) != 1211776033 )
    __break(0x8228u);
  return v2(a1, a2);
}
