__int64 __fastcall mem_used_max_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  _QWORD *v6; // x20
  int v7; // w8
  __int64 result; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 - 224);
  v9[0] = 0;
  v6 = *(_QWORD **)(v5 + 88);
  v7 = kstrtoull(a3, 10, v9);
  result = -22;
  if ( !v7 && !v9[0] )
  {
    down_read(v6 + 4);
    if ( v6[27] )
      v6[21] = zs_get_total_pages(v6[1]);
    up_read(v6 + 4);
    result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
