__int64 __fastcall sde_rm_inc_resource_info(__int64 result, __int64 a2, __int64 a3)
{
  int v3; // w8
  __int64 v4; // x8
  _QWORD *v5; // x0
  _QWORD *i; // x9
  _QWORD *v7; // t1
  unsigned __int64 v14; // x14
  __int64 v15; // x13
  __int64 v16; // x14
  unsigned __int64 v17; // x12
  unsigned __int64 v18; // x13
  __int64 v19; // x12

  v3 = *(_DWORD *)(a3 + 32);
  if ( v3 > 9 )
  {
    if ( v3 == 10 )
    {
      ++*(_DWORD *)(a2 + 8);
    }
    else if ( v3 == 11 )
    {
      ++*(_DWORD *)(a2 + 12);
    }
  }
  else if ( v3 == 2 )
  {
    v4 = *(_QWORD *)(*(_QWORD *)(a3 + 40) + 40LL);
    if ( (*(_BYTE *)(v4 + 72) & 1) == 0 )
    {
      ++*(_DWORD *)(a2 + 4);
      v7 = *(_QWORD **)(result + 56);
      v5 = (_QWORD *)(result + 56);
      for ( i = v7; i != v5; i = (_QWORD *)*i )
      {
        v15 = i[2];
        if ( v15 )
        {
          v16 = *(_QWORD *)(a3 + 16);
          if ( !v16 || *(_DWORD *)(v15 + 20) != *(_DWORD *)(v16 + 20) )
            continue;
        }
        if ( ((*(_QWORD *)(*(_QWORD *)(i[5] + 40LL)
                         + (((unsigned __int64)*(unsigned int *)(v4 + 16) >> 3) & 0x1FFFFFF8)
                         + 80) >> *(_DWORD *)(v4 + 16))
            & 1) != 0 )
        {
          v17 = *(unsigned int *)(v4 + 68);
          v18 = v17 >> 6;
          v19 = 1LL << v17;
          _X13 = (unsigned __int64 *)(a2 + 32 + 8 * v18);
          __asm { PRFM            #0x11, [X13] }
          do
            v14 = __ldxr(_X13);
          while ( __stxr(v14 | v19, _X13) );
        }
      }
      result = _sw_hweight64(*(_QWORD *)(a2 + 32));
      *(_DWORD *)(a2 + 20) = result;
    }
  }
  else if ( v3 == 5 )
  {
    ++*(_DWORD *)(a2 + 16);
  }
  return result;
}
