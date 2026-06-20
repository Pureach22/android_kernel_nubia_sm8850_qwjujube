__int64 __fastcall fq_adjust_removal(__int64 result, _DWORD *a2, __int64 a3)
{
  __int64 v3; // x10
  int v4; // w8
  int v5; // w12
  int v6; // w11
  int v7; // w9
  int v8; // w8
  _QWORD *v9; // x8
  __int64 *v10; // x9
  __int64 v11; // x11

  v3 = *(_QWORD *)a2;
  v4 = *(_DWORD *)(a3 + 112);
  v5 = *(_DWORD *)(a3 + 232);
  v6 = *(_DWORD *)(*(_QWORD *)a2 + 108LL) - 1;
  *(_DWORD *)(v3 + 104) = *(_DWORD *)(*(_QWORD *)a2 + 104LL) - v4;
  *(_DWORD *)(v3 + 108) = v6;
  a2[12] -= v4;
  v7 = *(_DWORD *)(result + 48) - v5;
  --*(_DWORD *)(result + 56);
  *(_DWORD *)(result + 48) = v7;
  if ( !a2[12] )
  {
    if ( (_DWORD *)(v3 + 48) == a2 )
    {
      v9 = *(_QWORD **)(v3 + 40);
      v10 = (__int64 *)(v3 + 32);
      if ( *v9 == v3 + 32 && (v11 = *v10, *(__int64 **)(*v10 + 8) == v10) )
      {
        *(_QWORD *)(v11 + 8) = v9;
        *v9 = v11;
      }
      else
      {
        result = _list_del_entry_valid_or_report(v3 + 32);
      }
      *(_QWORD *)(v3 + 32) = v3 + 32;
      *(_QWORD *)(v3 + 40) = v10;
    }
    else
    {
      v8 = -1227133513 * (((__int64)a2 - *(_QWORD *)result) >> 3);
      *(_QWORD *)(*(_QWORD *)(result + 8) + (((unsigned __int64)v8 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) &= ~(1LL << v8);
    }
  }
  return result;
}
