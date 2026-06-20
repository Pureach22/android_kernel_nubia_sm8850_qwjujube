__int64 __fastcall fastrpc_buf_alloc(__int64 a1, __int64 a2, unsigned __int64 a3, unsigned int a4, _QWORD *a5)
{
  unsigned __int64 v10; // x24
  __int64 v11; // x8
  unsigned __int64 v12; // x25
  char v13; // w10
  _QWORD *v14; // x9
  _QWORD *v15; // x24
  unsigned __int64 v16; // x10
  __int64 result; // x0
  _QWORD *v18; // x8
  __int64 v19; // x9

  raw_spin_lock(a1 + 320);
  if ( a3 <= 0x1000 && !a4 )
  {
    v10 = *(unsigned int *)(a1 + 276);
    if ( (_DWORD)v10 )
    {
      v11 = *(_QWORD *)(a1 + 192);
      if ( *(_BYTE *)(v11 + 152) != 1 )
      {
        *(_BYTE *)(v11 + 152) = 1;
        *a5 = v11;
        raw_spin_unlock(a1 + 320);
        return 0;
      }
      v12 = 0;
      while ( v10 - 1 != v12 )
      {
        v13 = *(_BYTE *)(v11 + 376);
        v11 += 224;
        ++v12;
        if ( (v13 & 1) == 0 )
        {
          *(_BYTE *)(v11 + 152) = 1;
          *a5 = v11;
          raw_spin_unlock(a1 + 320);
          if ( v12 >= v10 )
            goto LABEL_11;
          return 0;
        }
      }
    }
  }
  raw_spin_unlock(a1 + 320);
LABEL_11:
  if ( a4 - 3 >= 2 )
  {
    raw_spin_lock(a1 + 320);
    v14 = *(_QWORD **)(a1 + 80);
    if ( v14 != (_QWORD *)(a1 + 80) )
    {
      v15 = nullptr;
      do
      {
        v16 = v14[9];
        if ( v16 >= a3 && (!v15 || v15[9] > v16) )
          v15 = v14;
        v14 = (_QWORD *)*v14;
      }
      while ( v14 != (_QWORD *)(a1 + 80) );
      if ( v15 )
      {
        v18 = (_QWORD *)v15[1];
        if ( (_QWORD *)*v18 == v15 && (v19 = *v15, *(_QWORD **)(*v15 + 8LL) == v15) )
        {
          *(_QWORD *)(v19 + 8) = v18;
          *v18 = v19;
        }
        else
        {
          _list_del_entry_valid_or_report(v15);
        }
        *v15 = v15;
        v15[1] = v15;
        --*(_DWORD *)(a1 + 272);
        raw_spin_unlock(a1 + 320);
        *((_DWORD *)v15 + 14) = a4;
        *a5 = v15;
        return 0;
      }
    }
    raw_spin_unlock(a1 + 320);
  }
  result = _fastrpc_buf_alloc(a1, a2, **(unsigned int **)(a1 + 128), a3, a5, a4);
  if ( (_DWORD)result == -12 )
  {
    fastrpc_buf_list_free(a1, (_QWORD **)(a1 + 80), 1);
    return _fastrpc_buf_alloc(a1, a2, **(unsigned int **)(a1 + 128), a3, a5, a4);
  }
  return result;
}
