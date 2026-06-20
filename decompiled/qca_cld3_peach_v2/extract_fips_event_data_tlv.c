__int64 __fastcall extract_fips_event_data_tlv(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int *v3; // x8
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64); // x9
  int v8; // w8

  v3 = *(unsigned int **)a2;
  if ( *(_DWORD *)(*(_QWORD *)a2 + 12LL) > *(_DWORD *)(a2 + 24) )
    return 16;
  *(_QWORD *)(a3 + 16) = *(_QWORD *)(a2 + 16);
  *(_DWORD *)(a3 + 8) = v3[3];
  *(_DWORD *)(a3 + 4) = v3[2];
  v6 = v3[1];
  v7 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3688LL);
  if ( *((_DWORD *)v7 - 1) != -2112860426 )
    __break(0x8229u);
  v8 = v7(a1, v6);
  *(_DWORD *)a3 = v8;
  return 0;
}
