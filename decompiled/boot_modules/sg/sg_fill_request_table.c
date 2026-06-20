__int64 __fastcall sg_fill_request_table(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 *v3; // x21
  unsigned __int64 v5; // x22
  int v6; // w8
  unsigned int v7; // w8
  bool v8; // cf

  v2 = result + 144;
  v3 = *(__int64 **)(result + 144);
  if ( v3 != (__int64 *)(result + 144) )
  {
    v5 = 0;
    do
    {
      *(_BYTE *)a2 = *((_BYTE *)v3 + 243) + 1;
      *(_BYTE *)(a2 + 3) = *((_WORD *)v3 + 62) & *((_BYTE *)v3 + 121) & *((_WORD *)v3 + 63);
      if ( *((_BYTE *)v3 + 243) )
      {
        v6 = *((_DWORD *)v3 + 33);
      }
      else
      {
        result = jiffies_to_msecs(jiffies);
        v7 = *((_DWORD *)v3 + 33);
        v8 = (unsigned int)result >= v7;
        v6 = result - v7;
        if ( !v8 )
          v6 = 0;
      }
      *(_DWORD *)(a2 + 16) = v6;
      *(_BYTE *)(a2 + 1) = *((_BYTE *)v3 + 241);
      *(_BYTE *)(a2 + 2) = *((_BYTE *)v3 + 242);
      *(_DWORD *)(a2 + 4) = *((_DWORD *)v3 + 26);
      *(_QWORD *)(a2 + 8) = v3[14];
      v3 = (__int64 *)*v3;
      if ( v3 == (__int64 *)v2 )
        break;
      v8 = v5++ >= 0xF;
      a2 += 24;
    }
    while ( !v8 );
  }
  return result;
}
