__int64 __fastcall dp_tx_adjust_flow_pool_state(__int64 result, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v4; // x20
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64, __int64); // x8
  void (__fastcall *v7)(__int64, __int64, __int64); // x8
  __int64 v8; // x0
  void (__fastcall *v9)(__int64, __int64, __int64); // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x0

  v2 = *(unsigned __int16 *)(a2 + 60);
  if ( v2 <= *(unsigned __int16 *)(a2 + 72) )
  {
    v4 = result;
    if ( v2 <= *(unsigned __int16 *)(a2 + 74) )
    {
      if ( v2 <= *(unsigned __int16 *)(a2 + 76) )
      {
        if ( v2 <= *(unsigned __int16 *)(a2 + 78) )
        {
          v5 = *(unsigned __int8 *)(a2 + 58);
          *(_DWORD *)(a2 + 64) = 1;
          v6 = *(void (__fastcall **)(__int64, __int64, __int64))(v4 + 12872);
          if ( *((_DWORD *)v6 - 1) != 694643930 )
            __break(0x8228u);
          v6(v5, 11, 12);
        }
        else
        {
          *(_DWORD *)(a2 + 64) = 4;
        }
        v7 = *(void (__fastcall **)(__int64, __int64, __int64))(v4 + 12872);
        v8 = *(unsigned __int8 *)(a2 + 58);
        if ( *((_DWORD *)v7 - 1) != 694643930 )
          __break(0x8228u);
        v7(v8, 13, 11);
      }
      else
      {
        *(_DWORD *)(a2 + 64) = 3;
      }
      v9 = *(void (__fastcall **)(__int64, __int64, __int64))(v4 + 12872);
      v10 = *(unsigned __int8 *)(a2 + 58);
      if ( *((_DWORD *)v9 - 1) != 694643930 )
        __break(0x8228u);
      v9(v10, 15, 10);
    }
    else
    {
      *(_DWORD *)(a2 + 64) = 2;
    }
    v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v4 + 12872);
    v12 = *(unsigned __int8 *)(a2 + 58);
    if ( *((_DWORD *)v11 - 1) != 694643930 )
      __break(0x8228u);
    return v11(v12, 16, 9);
  }
  else
  {
    *(_DWORD *)(a2 + 64) = 0;
  }
  return result;
}
