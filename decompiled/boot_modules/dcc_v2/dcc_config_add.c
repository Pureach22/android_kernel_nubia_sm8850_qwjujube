__int64 __fastcall dcc_config_add(__int64 a1, unsigned int a2, unsigned int a3, int a4)
{
  __int64 v8; // x8
  _QWORD *v9; // x9
  __int64 v10; // x9
  unsigned int v11; // w23
  unsigned int v12; // w22
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w10
  int v17; // w10
  _QWORD *v18; // x8
  __int64 v19; // x2
  _QWORD *v20; // x1
  __int64 v21; // x9
  unsigned int v22; // w10
  int v23; // w8
  int v24; // w11
  int v25; // w8

  mutex_lock(a1 + 24);
  v8 = *(unsigned __int8 *)(a1 + 332);
  if ( *(_DWORD *)(a1 + 328) <= (unsigned int)v8 )
  {
    dev_err(*(_QWORD *)(a1 + 16), "Select link list to program using curr_list\n");
    goto LABEL_30;
  }
  if ( !a3 || a3 > *(_DWORD *)(a1 + 80) >> 3 )
  {
    dev_err(*(_QWORD *)(a1 + 16), "DCC: Invalid length\n");
LABEL_30:
    a3 = -22;
    goto LABEL_31;
  }
  v9 = (_QWORD *)(*(_QWORD *)(a1 + 312) + 16 * v8);
  if ( (_QWORD *)*v9 == v9
    || (v10 = v9[1], *(_DWORD *)(v10 - 8))
    || (v11 = *(_DWORD *)(v10 - 40), v22 = *(_DWORD *)(v10 - 36) + v11, v22 > a2)
    || v22 + 1020 < a2 )
  {
    v11 = a2 & 0xFFFFFFF0;
  }
  else
  {
    v23 = *(_DWORD *)(v10 - 32);
    if ( v22 + 4 * v23 == a2 )
    {
      v24 = v23 + a3;
      if ( v23 + a3 >= 0x7F )
        v25 = 127;
      else
        v25 = v23 + a3;
      a3 = v24 - v25;
      *(_DWORD *)(v10 - 32) = v25;
      if ( v24 == v25 )
        goto LABEL_31;
      a2 = v22 + 4 * v25;
    }
  }
  v12 = a2 - v11;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v13 = _kmalloc_cache_noprof(strcmp, 3520, 56);
    if ( !v13 )
      break;
    v14 = *(_QWORD *)(a1 + 320);
    v15 = *(unsigned __int8 *)(a1 + 332);
    if ( a3 >= 0x7F )
      v16 = 127;
    else
      v16 = a3;
    *(_DWORD *)v13 = v11;
    *(_DWORD *)(v13 + 4) = v12;
    *(_DWORD *)(v13 + 8) = v16;
    v17 = *(_DWORD *)(v14 + 4 * v15);
    *(_DWORD *)(v14 + 4 * v15) = v17 + 1;
    v18 = (_QWORD *)(v13 + 40);
    *(_DWORD *)(v13 + 12) = v17;
    *(_DWORD *)(v13 + 32) = 0;
    *(_BYTE *)(v13 + 28) = a4 != 0;
    *(_QWORD *)(v13 + 40) = v13 + 40;
    *(_QWORD *)(v13 + 48) = v13 + 40;
    v19 = *(_QWORD *)(a1 + 312) + 16LL * *(unsigned __int8 *)(a1 + 332);
    v20 = *(_QWORD **)(v19 + 8);
    if ( v13 + 40 == v19 || v20 == v18 || *v20 != v19 )
    {
      _list_add_valid_or_report(v13 + 40, v20);
      v13 = v21;
    }
    else
    {
      *(_QWORD *)(v19 + 8) = v18;
      *(_QWORD *)(v13 + 40) = v19;
      *(_QWORD *)(v13 + 48) = v20;
      *v20 = v18;
    }
    v12 += 508;
    a3 -= *(_DWORD *)(v13 + 8);
    if ( !a3 )
      goto LABEL_31;
  }
  a3 = -12;
LABEL_31:
  mutex_unlock(a1 + 24);
  return a3;
}
