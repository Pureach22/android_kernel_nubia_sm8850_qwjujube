__int64 __fastcall rmnet_offload_flush_current_pkt(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  char v3; // w9
  __int64 *v5; // x1

  if ( *(unsigned __int16 *)(result + 52)
     + *(unsigned __int16 *)(result + 64)
     + (unsigned int)*(unsigned __int16 *)(result + 54) <= 0x10000 )
  {
    v2 = result;
    v3 = *(_BYTE *)(result + 67);
    result = *(_QWORD *)result;
    if ( (v3 & 1) == 0 )
      *(_DWORD *)(result + 52) = *(_DWORD *)(v2 + 60);
    v5 = *(__int64 **)(a2 + 8);
    if ( result == a2 || v5 == (__int64 *)result || *v5 != a2 )
    {
      return _list_add_valid_or_report(result, v5, a2);
    }
    else
    {
      *(_QWORD *)(a2 + 8) = result;
      *(_QWORD *)result = a2;
      *(_QWORD *)(result + 8) = v5;
      *v5 = result;
    }
  }
  return result;
}
