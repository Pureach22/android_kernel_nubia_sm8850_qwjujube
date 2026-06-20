__int64 __fastcall dp_vdev_attach_be(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  char bank_profile; // w0
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x0
  __int64 v9; // x1

  if ( *(_DWORD *)(a2 + 32) == 4 )
    return 0;
  v3 = a2 + 45056;
  *(_BYTE *)(a2 + 46249) = 0;
  bank_profile = dp_tx_get_bank_profile(a1, a2);
  *(_BYTE *)(v3 + 1192) = bank_profile;
  *(_BYTE *)(a2 + 63) = bank_profile;
  if ( bank_profile == -1 )
    return 5;
  if ( *(_DWORD *)(a2 + 32) == 3 )
  {
    v7 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 8) + 152LL);
    if ( v7 )
    {
      v8 = *(_QWORD *)(a1 + 16);
      v9 = *(unsigned __int8 *)(a2 + 59);
      if ( *((_DWORD *)v7 - 1) != 2075239756 )
        __break(0x8228u);
      v7(v8, v9, 5000);
    }
  }
  return 0;
}
