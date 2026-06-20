__int64 __fastcall dp_sim_write_dpcd_reg(__int64 a1, __int64 a2, int a3, int a4)
{
  int v9; // w24
  __int64 *v10; // x23
  unsigned int v11; // w27
  char v12; // w26
  __int64 *v13; // x8
  __int64 v14; // x0
  __int64 *v15; // x1

  if ( !a1 )
    return 4294967274LL;
  if ( (*(_DWORD *)(a1 + 16) & 0x80000000) == 0 )
    return 4294967274LL;
  mutex_lock(a1 + 80);
  if ( a3 )
  {
    v9 = 0;
    v10 = (__int64 *)(a1 + 2200);
    do
    {
      v11 = v9 + a4;
      v12 = *(_BYTE *)(a2 + v9);
      v13 = (__int64 *)(a1 + 2200);
      if ( (unsigned int)(v9 + a4) < 0x800 )
      {
        *(_BYTE *)(a1 + 152 + v11) = v12;
      }
      else
      {
        while ( 1 )
        {
          v13 = (__int64 *)*v13;
          if ( v13 == v10 )
            break;
          if ( *((_DWORD *)v13 + 4) == v11 )
          {
            *((_BYTE *)v13 + 20) = v12;
            goto LABEL_8;
          }
        }
        v14 = devm_kmalloc(*(_QWORD *)(a1 - 8), 24, 3520);
        if ( v14 )
        {
          v15 = *(__int64 **)(a1 + 2208);
          *(_DWORD *)(v14 + 16) = v11;
          *(_BYTE *)(v14 + 20) = v12;
          if ( (__int64 *)v14 == v10 || v15 == (__int64 *)v14 || (__int64 *)*v15 != v10 )
          {
            _list_add_valid_or_report();
          }
          else
          {
            *(_QWORD *)(a1 + 2208) = v14;
            *(_QWORD *)v14 = v10;
            *(_QWORD *)(v14 + 8) = v15;
            *v15 = v14;
          }
        }
      }
LABEL_8:
      ++v9;
    }
    while ( v9 != a3 );
  }
  mutex_unlock(a1 + 80);
  return 0;
}
