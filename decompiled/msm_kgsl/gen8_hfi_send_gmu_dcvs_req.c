__int64 __fastcall gen8_hfi_send_gmu_dcvs_req(__int64 a1)
{
  __int64 v1; // x24
  __int64 v3; // x21
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x8
  unsigned __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x9
  __int64 v13; // x11
  int v14; // w9
  _DWORD *v15; // x11
  __int64 v16; // x9
  _DWORD *v17; // x12
  _DWORD *v18; // x10
  __int64 v19; // x9
  _DWORD *v20; // x10
  __int64 v21; // x21
  __int64 v22; // x0
  int *v23; // x0
  __int64 v24; // x8
  __int64 v25; // x8
  int v26; // w9
  __int64 v27; // x8
  unsigned __int64 v28; // x9
  __int64 v29; // x11
  unsigned int v30; // w12
  __int64 v31; // x13
  unsigned __int64 StatusReg; // x25
  __int64 v33; // x26
  __int64 v34; // x0

  v3 = a1 + 11008;
  v4 = to_gen8_gmu(a1);
  if ( (*(_BYTE *)(v3 + 3224) & 1) != 0 )
    return 0;
  v6 = v4;
  v7 = to_gen8_gmu(a1);
  LODWORD(v8) = 3 * *(_DWORD *)(a1 + 10068) + 14;
  v9 = *(_QWORD *)(v7 + 1808);
  LODWORD(v10) = *(_DWORD *)(a1 + 10400) + v8 + 2;
  if ( v9 )
  {
    if ( (*(_BYTE *)v3 & 1) == 0 )
      goto LABEL_16;
    while ( 1 )
    {
      *(_QWORD *)(v9 + 4) = 0x700000000LL;
      v12 = *(_QWORD *)(v7 + 1808);
      *(_QWORD *)(v12 + 12) = 0x400000001LL;
      *(_DWORD *)(v12 + 20) = *(_DWORD *)(a1 + 10068) + 1;
      *(_DWORD *)(v12 + 24) = *(_DWORD *)(a1 + 10068) - *(_DWORD *)(a1 + 10052);
      *(_DWORD *)(v12 + 28) = *(_DWORD *)(a1 + 10380);
      *(_DWORD *)(v12 + 32) = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL);
      v13 = *(_QWORD *)(v7 + 1808);
      LODWORD(v12) = *(_DWORD *)(a1 + 10068) + 1;
      *(_QWORD *)(v13 + 40) = 3;
      *(_QWORD *)(v13 + 48) = 0;
      *(_DWORD *)(v13 + 36) = v12;
      v14 = *(_DWORD *)(a1 + 10068) - 1;
      if ( v14 >= 0 )
      {
        if ( (unsigned int)v14 > 0x1F )
          goto LABEL_40;
        v15 = (_DWORD *)(v13 + 64);
        v16 = 28LL * (unsigned int)v14;
        do
        {
          v17 = (_DWORD *)(a1 + 9156 + v16);
          v16 -= 28;
          *(v15 - 2) = *(v17 - 2);
          *(v15 - 1) = *(v17 - 1);
          *v15 = *v17;
          v15 += 3;
        }
        while ( v16 != -28 );
      }
      v18 = (_DWORD *)(*(_QWORD *)(v7 + 1808) + 4LL * (unsigned int)v8);
      *v18 = 1;
      v18[1] = *(_DWORD *)(a1 + 10400);
      if ( *(int *)(a1 + 10400) >= 1 )
      {
        v19 = 0;
        v20 = v18 + 2;
        do
        {
          v20[v19] = *(_DWORD *)(*(_QWORD *)(a1 + 10392) + 4 * v19);
          ++v19;
        }
        while ( v19 < *(int *)(a1 + 10400) );
      }
      *(_DWORD *)v9 = ((unsigned __int8)v10 << 8) | 0xF;
      *(_BYTE *)v3 = 0;
LABEL_16:
      v21 = *(_QWORD *)(v6 + 1808);
      result = gen8_hfi_send_feature_ctrl(a1, 0, 1, 3);
      if ( (_DWORD)result )
        return result;
      result = gen8_hfi_send_generic_req(a1, v21, 4 * (unsigned int)*(unsigned __int8 *)(v21 + 1));
      if ( (_DWORD)result )
        return result;
      v22 = to_gen8_gmu(a1);
      if ( *(_QWORD *)(v22 + 1816) || !*(_DWORD *)(a1 + 8456) )
        return gen8_hfi_send_generic_req(
                 a1,
                 *(_QWORD *)(v6 + 1816),
                 4 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v6 + 1816) + 1LL));
      v3 = v22;
      v8 = (unsigned int)(*(_DWORD *)(a1 + 8388) + 9);
      v10 = 4 * v8;
      v23 = (int *)_kmalloc_noprof(4 * v8, 3520);
      *(_QWORD *)(v3 + 1816) = v23;
      if ( !v23 )
        return 4294967284LL;
      if ( v10 >= 8 )
      {
        v23[1] = 0;
        if ( v10 != 8 )
        {
          v23[2] = 9;
          v24 = *(_QWORD *)(v3 + 1816);
          if ( (unsigned int)v8 <= 5 )
          {
            kfree(*(_QWORD *)(v3 + 1816));
            return 4294967284LL;
          }
          *(_QWORD *)(v24 + 12) = 0x100000001LL;
          *(_DWORD *)(v24 + 20) = 1;
          v25 = *(_QWORD *)(v3 + 1816);
          *(_DWORD *)(v25 + 24) = 1;
          v26 = *(_DWORD *)(a1 + 8388);
          *(_DWORD *)(v25 + 32) = 0;
          v27 = v25 + 32;
          *(_DWORD *)(v27 - 4) = v26 + 1;
          if ( !*(_DWORD *)(a1 + 8388) )
          {
LABEL_39:
            *v23 = ((unsigned __int8)v8 << 8) | 0xF;
            return gen8_hfi_send_generic_req(
                     a1,
                     *(_QWORD *)(v6 + 1816),
                     4 * (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(v6 + 1816) + 1LL));
          }
          v28 = 0;
          while ( v28 != 16 )
          {
            v30 = *(_DWORD *)(a1 + 8456 + 4 * v28);
            if ( v30 && (v31 = *(unsigned int *)(a1 + 10400), (_DWORD)v31) )
            {
              v29 = 0;
              while ( *(_DWORD *)(*(_QWORD *)(a1 + 10392) + 4 * v29) < v30 )
              {
                if ( v31 == ++v29 )
                {
                  LODWORD(v29) = *(_DWORD *)(a1 + 10400);
                  break;
                }
              }
            }
            else
            {
              LODWORD(v29) = 0;
            }
            ++v28;
            *(_DWORD *)(v27 + 4 * v28) = v29;
            if ( v28 >= *(unsigned int *)(a1 + 8388) )
              goto LABEL_39;
          }
LABEL_40:
          __break(0x5512u);
        }
      }
      __break(1u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v33 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &gen8_hwsched_build_dcvs_table__alloc_tag;
      v34 = _kmalloc_noprof(4LL * (unsigned int)v10, 3520);
      *(_QWORD *)(StatusReg + 80) = v33;
      *(_QWORD *)(v1 + 1808) = v34;
      if ( !v34 )
        return 4294967284LL;
LABEL_7:
      v7 = v1;
      *(_BYTE *)v3 = 1;
      v9 = *(_QWORD *)(v1 + 1808);
    }
  }
  v1 = v7;
  v11 = _kmalloc_noprof(4LL * (unsigned int)(*(_DWORD *)(a1 + 10400) + v8 + 2), 3520);
  *(_QWORD *)(v1 + 1808) = v11;
  if ( v11 )
    goto LABEL_7;
  return 4294967284LL;
}
