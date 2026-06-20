__int64 __fastcall dcc_rd_mod_wr_add(__int64 a1, int a2, int a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x9
  __int64 v9; // x8
  int v10; // w10
  _QWORD *v11; // x8
  __int64 v12; // x2
  _QWORD *v13; // x1
  unsigned int v14; // w20

  mutex_lock(a1 + 24);
  v6 = *(unsigned __int8 *)(a1 + 332);
  if ( *(_DWORD *)(a1 + 328) <= (unsigned int)v6 )
  {
    dev_err(*(_QWORD *)(a1 + 16), "Select link list to program using curr_list\n");
    v14 = -22;
  }
  else if ( *(_QWORD *)(*(_QWORD *)(a1 + 312) + 16 * v6) == *(_QWORD *)(a1 + 312) + 16 * v6 )
  {
    dev_err(*(_QWORD *)(a1 + 16), "DCC: No read address programmed\n");
    v14 = -1;
  }
  else
  {
    v7 = _kmalloc_cache_noprof(strcmp, 3520, 56);
    if ( v7 )
    {
      v8 = *(unsigned __int8 *)(a1 + 332);
      *(_DWORD *)(v7 + 20) = a3;
      *(_DWORD *)(v7 + 24) = a2;
      *(_DWORD *)(v7 + 32) = 2;
      v9 = *(_QWORD *)(a1 + 320);
      v10 = *(_DWORD *)(v9 + 4 * v8);
      *(_DWORD *)(v9 + 4 * v8) = v10 + 1;
      v11 = (_QWORD *)(v7 + 40);
      *(_DWORD *)(v7 + 12) = v10;
      *(_QWORD *)(v7 + 40) = v7 + 40;
      *(_QWORD *)(v7 + 48) = v7 + 40;
      v12 = *(_QWORD *)(a1 + 312) + 16LL * *(unsigned __int8 *)(a1 + 332);
      v13 = *(_QWORD **)(v12 + 8);
      if ( v7 + 40 == v12 || v13 == v11 || *v13 != v12 )
      {
        _list_add_valid_or_report(v7 + 40, v13);
        v14 = 0;
      }
      else
      {
        v14 = 0;
        *(_QWORD *)(v12 + 8) = v11;
        *(_QWORD *)(v7 + 40) = v12;
        *(_QWORD *)(v7 + 48) = v13;
        *v13 = v11;
      }
    }
    else
    {
      v14 = -12;
    }
  }
  mutex_unlock(a1 + 24);
  return v14;
}
