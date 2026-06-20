__int64 __fastcall loop_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  unsigned int v8; // w20
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x9
  int v13; // w10
  _QWORD *v14; // x8
  __int64 v15; // x2
  _QWORD *v16; // x1
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 152);
  v18[0] = 0;
  mutex_lock(v7 + 24);
  if ( (unsigned int)kstrtoull(a3, 16, v18) )
  {
    a4 = -22;
  }
  else if ( *(_DWORD *)(v7 + 328) <= (unsigned int)*(unsigned __int8 *)(v7 + 332) )
  {
    dev_err(a1, "Select link list to program using curr_list\n");
    a4 = -22;
  }
  else
  {
    v8 = v18[0];
    v9 = _kmalloc_cache_noprof(strcmp, 3520, 56);
    if ( v9 )
    {
      if ( v8 >= 0xFF )
        v10 = 255;
      else
        v10 = v8;
      *(_DWORD *)(v9 + 16) = v10;
      v11 = *(_QWORD *)(v7 + 320);
      v12 = *(unsigned __int8 *)(v7 + 332);
      v13 = *(_DWORD *)(v11 + 4 * v12);
      *(_DWORD *)(v11 + 4 * v12) = v13 + 1;
      v14 = (_QWORD *)(v9 + 40);
      *(_DWORD *)(v9 + 12) = v13;
      *(_DWORD *)(v9 + 32) = 1;
      *(_QWORD *)(v9 + 40) = v9 + 40;
      *(_QWORD *)(v9 + 48) = v9 + 40;
      v15 = *(_QWORD *)(v7 + 312) + 16LL * *(unsigned __int8 *)(v7 + 332);
      v16 = *(_QWORD **)(v15 + 8);
      if ( v9 + 40 == v15 || v16 == v14 || *v16 != v15 )
      {
        _list_add_valid_or_report(v9 + 40, v16);
      }
      else
      {
        *(_QWORD *)(v15 + 8) = v14;
        *(_QWORD *)(v9 + 40) = v15;
        *(_QWORD *)(v9 + 48) = v16;
        *v16 = v14;
      }
    }
    else
    {
      a4 = -12;
    }
  }
  mutex_unlock(v7 + 24);
  _ReadStatusReg(SP_EL0);
  return a4;
}
