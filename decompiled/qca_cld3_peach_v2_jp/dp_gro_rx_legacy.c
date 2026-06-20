__int64 __fastcall dp_gro_rx_legacy(_DWORD *a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 (__fastcall *v4)(__int64, __int64); // x9
  __int64 v8; // x1
  __int64 v9; // x0

  if ( a1[7] )
    return 11;
  v3 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_QWORD *)a1 + 1132LL) || *(_DWORD *)(v3 + 1128) )
    return 11;
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(v3 + 472);
  v8 = *(unsigned __int8 *)(v3 + 370);
  if ( *((_DWORD *)v4 - 1) != 332907827 )
    __break(0x8229u);
  v9 = v4(a2, v8);
  if ( v9 )
    return dp_gro_rx_bh_disable(a1, v9, a2);
  else
    return 16;
}
