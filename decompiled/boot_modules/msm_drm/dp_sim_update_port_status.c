__int64 __fastcall dp_sim_update_port_status(__int64 a1, unsigned int a2, int a3)
{
  __int64 v7; // x8
  char v8; // w10
  unsigned int v9; // w19

  if ( !a1 || (*(_DWORD *)(a1 + 16) & 0x80000000) == 0 )
    return 4294967274LL;
  mutex_lock(a1 + 80);
  if ( (a2 & 0x80000000) != 0 )
  {
    v9 = -22;
  }
  else
  {
    v7 = a1;
    if ( *(_DWORD *)(a1 + 2252) <= a2 )
    {
      v9 = -22;
      goto LABEL_13;
    }
    if ( a3 == 1 )
      v8 = 3;
    else
      v8 = 0;
    *(_BYTE *)(*(_QWORD *)(a1 + 2240) + 48LL * a2 + 3) = v8;
    v9 = dp_mst_sim_update(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 + 2252), *(_QWORD *)(a1 + 2240));
  }
  v7 = a1;
LABEL_13:
  mutex_unlock(v7 + 80);
  return v9;
}
