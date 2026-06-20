__int64 __fastcall dp_tx_mon_update_channel_freq(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  unsigned __int8 *v4; // x19
  __int64 v5; // x22
  __int64 (__fastcall *v6)(__int64, __int64); // x9
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 (__fastcall *v9)(__int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x1

  if ( a2 )
  {
    v2 = *(_QWORD *)(a2 + 8);
    v4 = (unsigned __int8 *)result;
    v5 = result + 94208;
    v6 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 136);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a2 + 16);
      v8 = *v4;
      if ( *((_DWORD *)v6 - 1) != 1873570910 )
        __break(0x8229u);
      result = v6(v7, v8);
      *(_BYTE *)(v5 + 1656) = result;
      v2 = *(_QWORD *)(a2 + 8);
    }
    v9 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 144);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a2 + 16);
      v11 = *v4;
      if ( *((_DWORD *)v9 - 1) != 1873570910 )
        __break(0x8228u);
      result = v9(v10, v11);
      *(_BYTE *)(v5 + 1657) = result;
    }
  }
  return result;
}
