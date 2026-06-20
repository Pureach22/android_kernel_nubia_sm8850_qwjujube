__int64 __fastcall hw_fence_debug_dump_table(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x8
  unsigned int v4; // w20
  __int64 v5; // x23
  unsigned __int64 v6; // x21
  unsigned int v7; // w22
  __int64 v8; // x9
  _QWORD v9[5]; // [xsp+8h] [xbp-38h] BYREF
  __int16 v10; // [xsp+30h] [xbp-10h]
  __int64 v11; // [xsp+38h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a2 + 80);
  if ( (_DWORD)v2 )
  {
    v4 = result;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = *(_QWORD *)(a2 + 64);
      if ( *(_DWORD *)(v8 + v5) )
      {
        v10 = 0;
        memset(v9, 0, sizeof(v9));
        result = dump_fence_helper(v4, (unsigned int *)(v8 + v5), (__int64)v9, v6, v7);
        v2 = *(unsigned int *)(a2 + 80);
        ++v7;
      }
      ++v6;
      v5 += 128;
    }
    while ( v6 < v2 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
