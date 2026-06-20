__int64 __fastcall dp_get_peer_param(__int64 a1, int a2, __int64 a3, int a4, _WORD *a5)
{
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 *v18; // x8
  __int64 v19; // x8
  __int64 v20; // x9
  unsigned int v21; // w19
  _DWORD *v22; // x8
  __int64 v23; // x20

  v9 = dp_peer_find_hash_find(a1, a3);
  if ( v9 )
    goto LABEL_22;
  v22 = *(_DWORD **)(a1 + 1536);
  if ( v22 )
  {
    if ( *(v22 - 1) != 69695039 )
      __break(0x8228u);
    v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v22)(a1, a3, 0, 7, 255);
    if ( v9 )
    {
LABEL_22:
      if ( *(_DWORD *)(v9 + 408) == 1 && (v18 = *(__int64 **)(v9 + 416)) != nullptr )
      {
        v19 = *v18;
        if ( v19 )
          goto LABEL_5;
      }
      else
      {
        v19 = *(_QWORD *)v9;
        if ( *(_QWORD *)v9 )
        {
LABEL_5:
          if ( a4 == 7 )
          {
            v20 = 16;
          }
          else
          {
            if ( a4 != 8 )
            {
LABEL_17:
              v21 = 0;
              goto LABEL_18;
            }
            v20 = 32;
          }
          v23 = v9;
          *a5 = *(_WORD *)(v9 + 16);
          qdf_mem_copy(a5 + 4, (const void *)(v19 + v20), 0x10u);
          v9 = v23;
          goto LABEL_17;
        }
      }
      v21 = 16;
LABEL_18:
      dp_peer_unref_delete(v9, 7u, v10, v11, v12, v13, v14, v15, v16, v17);
      return v21;
    }
  }
  return 4;
}
