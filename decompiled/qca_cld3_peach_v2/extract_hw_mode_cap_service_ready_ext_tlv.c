__int64 __fastcall extract_hw_mode_cap_service_ready_ext_tlv(__int64 a1, __int64 a2, unsigned __int8 a3, _DWORD *a4)
{
  __int64 v4; // x8
  unsigned int v5; // w8
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // x8

  if ( !a2 )
    return 4;
  v4 = *(_QWORD *)(a2 + 16);
  if ( !v4 )
    return 4;
  v5 = *(_DWORD *)(v4 + 4);
  if ( !v5 )
    return 4;
  result = 4;
  if ( v5 <= 4 )
  {
    v7 = *(_QWORD *)(a2 + 32);
    if ( v7 )
    {
      if ( v5 > a3 && v5 <= *(_DWORD *)(a2 + 40) )
      {
        v8 = 16LL * a3;
        *a4 = *(_DWORD *)(v7 + v8 + 4);
        a4[1] = *(_DWORD *)(*(_QWORD *)(a2 + 32) + v8 + 8);
        a4[2] = *(_DWORD *)(*(_QWORD *)(a2 + 32) + v8 + 12);
        return 0;
      }
    }
  }
  return result;
}
