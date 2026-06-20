__int64 __fastcall qcom_sys_heap_alloc_largest_available(
        __int64 a1,
        unsigned __int64 a2,
        unsigned int a3,
        unsigned __int8 a4)
{
  __int64 v8; // x25
  unsigned int v9; // w8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 result; // x0
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x19

  v8 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v9 = *(_DWORD *)&orders[4 * v8];
    if ( v9 > a3 || 4096LL << v9 > a2 )
      goto LABEL_2;
    v10 = raw_spin_lock_irqsave(*(_QWORD *)(a1 + 8 * v8) + 64LL);
    v11 = *(_DWORD **)(a1 + 8 * v8);
    v12 = v10;
    if ( *v11 || v11[1] )
      v13 = dynamic_page_pool_remove(*(_QWORD *)(a1 + 8 * v8), *v11 != 0);
    else
      v13 = 0;
    raw_spin_unlock_irqrestore(*(_QWORD *)(a1 + 8 * v8) + 64LL, v12);
    if ( v13 || (a4 & 1) != 0 )
      break;
    result = _alloc_pages_noprof(
               *(unsigned int *)(*(_QWORD *)(a1 + 8 * v8) + 68LL),
               *(unsigned int *)(*(_QWORD *)(a1 + 8 * v8) + 72LL),
               0,
               0);
    if ( result )
      goto LABEL_17;
LABEL_2:
    if ( ++v8 == 3 )
      return 0;
  }
  if ( ((v13 == 0) & a4) != 0 )
    result = -95;
  else
    result = v13;
LABEL_17:
  v15 = *(_QWORD *)(a1 + 8 * v8);
  v16 = *(_DWORD *)(v15 + 72);
  if ( v16 )
  {
    if ( *(_DWORD *)(v15 + 8) < (int)(0x2800uLL >> v16) )
    {
      v17 = result;
      wake_up_process(*(_QWORD *)(v15 + 56));
      return v17;
    }
  }
  return result;
}
