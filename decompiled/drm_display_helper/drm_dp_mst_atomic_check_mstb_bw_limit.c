__int64 __fastcall drm_dp_mst_atomic_check_mstb_bw_limit(_QWORD *a1, __int64 a2, __int64 **a3)
{
  _QWORD *v3; // x8
  _QWORD *v4; // x25
  __int64 v8; // x9
  _QWORD *v9; // x9
  const void **v10; // x5
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x1
  __int64 *v14; // x21
  __int64 *v15; // x26
  __int64 *v16; // t1
  int v17; // w27
  int v18; // w24
  __int64 *v19; // x22
  int v20; // w7
  _QWORD *v21; // x8
  __int64 v22; // x8
  __int64 v23; // x1
  __int64 v25; // x1
  __int64 v26; // x8
  __int64 v27; // x1

  v4 = (_QWORD *)(a2 + 56);
  v3 = *(_QWORD **)(a2 + 56);
  if ( v3 == (_QWORD *)(a2 + 56) )
    return 0;
  while ( !*((_DWORD *)v3 - 4) )
  {
LABEL_3:
    v3 = (_QWORD *)*v3;
    if ( v3 == v4 )
      return 0;
  }
  v8 = *(v3 - 4);
  while ( 1 )
  {
    v9 = *(_QWORD **)(v8 + 1616);
    if ( !v9 )
      goto LABEL_3;
    if ( v9 == a1 )
      break;
    v8 = v9[7];
    if ( !v8 )
      goto LABEL_3;
  }
  v10 = (const void **)a1[7];
  v11 = *(_QWORD *)(a1[8] + 104LL);
  if ( v10 )
  {
    v12 = v11 ? *(_QWORD *)(v11 + 8) : 0LL;
    _drm_dev_dbg(0, v12, 4, "[MSTB:%p] [MST PORT:%p] Checking bandwidth limits on [MSTB:%p]\n", v10[202], v10, a1);
  }
  else
  {
    v13 = v11 ? *(_QWORD *)(v11 + 8) : 0LL;
    _drm_dev_dbg(0, v13, 4, "[MSTB:%p] Checking bandwidth limits\n", a1);
  }
  v16 = (__int64 *)a1[5];
  v14 = a1 + 5;
  v15 = v16;
  if ( v16 == v14 )
    return 0;
  v17 = 0;
  while ( 1 )
  {
    if ( !*((_BYTE *)v15 - 12) )
      goto LABEL_21;
    v19 = v15 - 3;
    if ( *((_BYTE *)v15 - 12) != 2 || (*((_BYTE *)v15 - 14) & 1) == 0 )
    {
      v21 = v4;
      while ( 1 )
      {
        v21 = (_QWORD *)*v21;
        if ( v21 == v4 )
          break;
        if ( (__int64 *)*(v21 - 4) == v19 )
        {
          if ( v21 == (_QWORD *)&unk_20 )
            break;
          v20 = *((unsigned __int16 *)v15 - 3);
          if ( *((_WORD *)v15 - 3) )
          {
            v18 = *((_DWORD *)v21 - 4);
            goto LABEL_34;
          }
          v26 = *(_QWORD *)(v15[201] + 104);
          if ( v26 )
            v27 = *(_QWORD *)(v26 + 8);
          else
            v27 = 0;
          _drm_dev_dbg(
            0,
            v27,
            4,
            "[MSTB:%p] [MST PORT:%p] no BW available for the port\n",
            (const void *)v15[199],
            v15 - 3);
          v18 = -22;
          goto LABEL_51;
        }
      }
LABEL_21:
      v18 = 0;
      goto LABEL_22;
    }
    v18 = drm_dp_mst_atomic_check_mstb_bw_limit(v15[2], a2, a3);
    if ( v18 >= 1 )
      break;
LABEL_39:
    if ( v18 < 0 )
      return (unsigned int)v18;
LABEL_22:
    v15 = (__int64 *)*v15;
    v17 += v18;
    v18 = v17;
    if ( v15 == v14 )
      return (unsigned int)v18;
  }
  v20 = *((unsigned __int16 *)v15 - 3);
LABEL_34:
  v22 = *(_QWORD *)(v15[201] + 104);
  if ( v18 <= v20 )
  {
    if ( v22 )
      v23 = *(_QWORD *)(v22 + 8);
    else
      v23 = 0;
    _drm_dev_dbg(
      0,
      v23,
      4,
      "[MSTB:%p] [MST PORT:%p] uses %d out of %d PBN\n",
      (const void *)v15[199],
      v15 - 3,
      v18,
      v20);
    goto LABEL_39;
  }
  if ( v22 )
    v25 = *(_QWORD *)(v22 + 8);
  else
    v25 = 0;
  _drm_dev_dbg(
    0,
    v25,
    4,
    "[MSTB:%p] [MST PORT:%p] required PBN of %d exceeds port limit of %d\n",
    (const void *)v15[199],
    v15 - 3,
    v18,
    v20);
  v18 = -28;
LABEL_51:
  *a3 = v19;
  return (unsigned int)v18;
}
