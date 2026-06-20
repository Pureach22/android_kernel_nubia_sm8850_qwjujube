__int64 __fastcall sta_get_expected_throughput(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 v4; // x0
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x1
  __int64 v8; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 1616LL);
  if ( (*(_QWORD *)(a1 + 216) & 0x200000) != 0
    && (v2 = *(_QWORD *)(v1 + 2536)) != 0
    && (v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 104LL)) != nullptr )
  {
    v4 = *(_QWORD *)(a1 + 136);
    if ( *((_DWORD *)v3 - 1) != -1536295579 )
      __break(0x8228u);
    return v3(v4);
  }
  else
  {
    v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1 + 464) + 712LL);
    if ( v6 && *(_BYTE *)(a1 + 204) == 1 )
    {
      v7 = a1 + 2688;
      v8 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 1616LL);
      if ( *((_DWORD *)v6 - 1) != -960970475 )
        __break(0x8228u);
      return v6(v8, v7);
    }
    else
    {
      return 0;
    }
  }
}
