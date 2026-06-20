__int64 __fastcall dp_mst_sim_clear_esi(__int64 result, __int64 a2)
{
  unsigned __int64 v3; // x22
  char v4; // w8
  __int64 v5; // x20
  int v6; // w21
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x9

  v3 = (unsigned int)(*(_DWORD *)a2 - 8194);
  if ( *(_QWORD *)(a2 + 16) - v3 > 0xF )
  {
    v4 = 1;
LABEL_11:
    *(_BYTE *)(a2 + 5) = v4;
    return result;
  }
  v5 = result;
  v6 = *(unsigned __int8 *)(result + 781);
  v7 = mutex_lock(result + 688);
  if ( !*(_QWORD *)(a2 + 16) )
  {
LABEL_8:
    if ( v6 != *(unsigned __int8 *)(v5 + 781) )
      complete(v5 + 736);
    result = mutex_unlock(v5 + 688);
    v4 = 0;
    goto LABEL_11;
  }
  v8 = 0;
  v9 = 16 - v3;
  if ( v3 > 0x10 )
    v9 = 0;
  while ( v9 != v8 )
  {
    *(_BYTE *)(v3 + v5 + 780 + v8) &= ~*(_BYTE *)(*(_QWORD *)(a2 + 8) + v8);
    if ( (unsigned __int64)++v8 >= *(_QWORD *)(a2 + 16) )
      goto LABEL_8;
  }
  __break(0x5512u);
  return dp_mst_sim_reset(v7);
}
