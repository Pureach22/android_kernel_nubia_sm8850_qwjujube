__int64 __fastcall fastrpc_buf_free(__int64 a1, char a2)
{
  __int64 v3; // x20
  _QWORD *v5; // x20
  unsigned __int64 v6; // x8
  __int64 v7; // x9
  unsigned __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x2
  _QWORD *v11; // x1

  if ( *(_BYTE *)(a1 + 152) == 1 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    raw_spin_lock(v3 + 320);
    *(_BYTE *)(a1 + 152) = 0;
    return raw_spin_unlock(v3 + 320);
  }
  if ( (a2 & 1) != 0 )
  {
    if ( !(*(_QWORD *)(a1 + 72) >> 23) )
    {
      v3 = *(_QWORD *)(a1 + 16);
      raw_spin_lock(v3 + 320);
      if ( *(_DWORD *)(v3 + 272) < 0x21u )
      {
        v10 = v3 + 80;
        v11 = *(_QWORD **)(v3 + 88);
        if ( v3 + 80 == a1 || v11 == (_QWORD *)a1 || *v11 != v10 )
        {
          _list_add_valid_or_report(a1, v11, v10);
        }
        else
        {
          *(_QWORD *)(v3 + 88) = a1;
          *(_QWORD *)a1 = v10;
          *(_QWORD *)(a1 + 8) = v11;
          *v11 = a1;
        }
        ++*(_DWORD *)(v3 + 272);
        *(_DWORD *)(a1 + 56) = -1;
        return raw_spin_unlock(v3 + 320);
      }
      raw_spin_unlock(v3 + 320);
    }
    if ( *(_DWORD *)(a1 + 56) == 4 )
      goto LABEL_11;
    v5 = *(_QWORD **)(a1 + 40);
    mutex_lock(v5 + 2);
    if ( *v5 )
    {
      v8 = *(_QWORD *)(a1 + 72);
      v9 = 4095;
      if ( v8 > 0x200000 )
        v9 = 0x1FFFFF;
      if ( v8 > 0x40000000 )
        v9 = 0x3FFFFFFF;
      v5[12] -= (v9 + v8) & ~v9;
LABEL_24:
      _fastrpc_dma_buf_free(a1);
      kfree(a1);
    }
  }
  else
  {
    if ( *(_DWORD *)(a1 + 56) == 4 )
    {
LABEL_11:
      _fastrpc_dma_buf_free(a1);
      return kfree(a1);
    }
    v5 = *(_QWORD **)(a1 + 40);
    mutex_lock(v5 + 2);
    if ( *v5 )
    {
      v6 = *(_QWORD *)(a1 + 72);
      v7 = 4095;
      if ( v6 > 0x200000 )
        v7 = 0x1FFFFF;
      if ( v6 > 0x40000000 )
        v7 = 0x3FFFFFFF;
      v5[12] -= (v7 + v6) & ~v7;
      goto LABEL_24;
    }
  }
  return mutex_unlock(v5 + 2);
}
