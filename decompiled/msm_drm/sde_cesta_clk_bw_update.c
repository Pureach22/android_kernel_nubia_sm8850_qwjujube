__int64 __fastcall sde_cesta_clk_bw_update(__int64 a1, char *a2)
{
  __int64 v4; // x21
  int v5; // w8
  unsigned __int64 v6; // x9
  unsigned __int64 v7; // x10
  char v8; // w12
  int v9; // w11
  unsigned __int64 v10; // x14
  _QWORD *v11; // x16
  unsigned __int64 v12; // x15
  unsigned __int64 v13; // x13
  unsigned __int64 v14; // x16
  unsigned __int64 v15; // x13
  unsigned __int64 v16; // x14
  char v17; // w17
  int v18; // w15
  int v19; // w16
  char v20; // w9
  __int64 v22; // x1
  int v23; // w5
  char v24; // w9
  int v25; // w8
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x5
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x10
  __int64 v33; // x11
  int v34; // w4
  int v35; // w5

  if ( !a1 || !a2 || *(_DWORD *)(a1 + 4) )
    return printk(&unk_27EB6F, "sde_cesta_clk_bw_update");
  v4 = cesta_list_0;
  mutex_lock(cesta_list_0 + 800);
  if ( a2[41] != 1 )
  {
    if ( (*(_BYTE *)(a1 + 56) & 1) != 0 )
    {
      if ( !*a2 )
        goto LABEL_16;
    }
    else if ( (*a2 & 1) != 0 )
    {
      goto LABEL_16;
    }
    if ( *((_QWORD *)a2 + 3) == *(_QWORD *)(a1 + 80)
      && *((_QWORD *)a2 + 4) == *(_QWORD *)(a1 + 88)
      && *((_QWORD *)a2 + 1) == *(_QWORD *)(a1 + 64) )
    {
      if ( (*(_BYTE *)(a1 + 57) & 1) != 0 )
      {
        v5 = 1;
      }
      else
      {
        if ( (a2[40] & 1) == 0 )
        {
          *(_DWORD *)(a1 + 60) = 0;
          return mutex_unlock(v4 + 800);
        }
        v5 = 1;
      }
      goto LABEL_64;
    }
LABEL_16:
    v6 = *((_QWORD *)a2 + 4);
    v7 = *(_QWORD *)(a1 + 80);
    if ( *((_QWORD *)a2 + 3) > v6 )
      v6 = *((_QWORD *)a2 + 3);
    if ( v7 <= *(_QWORD *)(a1 + 88) )
      v7 = *(_QWORD *)(a1 + 88);
    if ( v6 <= v7 )
    {
      if ( v6 >= v7 )
      {
        v8 = 0;
        v9 = 0;
        v5 = 0;
      }
      else
      {
        v5 = 2;
        v8 = 1;
        v9 = 1;
      }
    }
    else
    {
      v8 = 0;
      v9 = 1;
      v5 = 1;
    }
    v10 = *((_QWORD *)a2 + 1);
    v11 = *(_QWORD **)(v4 + 784);
    v12 = v10;
    while ( v11 != (_QWORD *)(v4 + 784) )
    {
      if ( v11 - 13 != (_QWORD *)a1 && (*(_BYTE *)(v11 - 6) & 1) != 0 )
        v12 += *(v11 - 5);
      v11 = (_QWORD *)*v11;
    }
    if ( (a2[42] & 1) == 0 )
    {
      if ( *a2 )
      {
        v13 = *(unsigned int *)(v4 + 1144);
        if ( (_DWORD)v13 )
        {
          v14 = *(unsigned int *)(v4 + 1148);
          if ( (_DWORD)v14 )
            *((_QWORD *)a2 + 2) = 100 * (v12 / v13) / v14;
        }
      }
    }
    v15 = *((_QWORD *)a2 + 2);
    if ( v10 > v15 )
      v15 = v10;
    if ( *(_QWORD *)(a1 + 64) <= *(_QWORD *)(a1 + 72) )
      v16 = *(_QWORD *)(a1 + 72);
    else
      v16 = *(_QWORD *)(a1 + 64);
    if ( v15 <= v16 )
    {
      if ( v15 >= v16 )
      {
        v17 = 0;
        v18 = 0;
        v19 = 0;
        if ( !v5 )
        {
LABEL_64:
          *(_DWORD *)(a1 + 60) = v5;
          goto LABEL_65;
        }
      }
      else
      {
        v19 = 2;
        v17 = 1;
        v18 = 1;
        if ( v5 == 2 )
          goto LABEL_64;
      }
    }
    else
    {
      v17 = 0;
      v18 = 1;
      v19 = 1;
      if ( v5 == 1 )
        goto LABEL_64;
    }
    if ( v15 <= v16 )
      v8 = 0;
    if ( (v8 & 1) != 0 )
    {
      v5 = 3;
    }
    else
    {
      if ( v6 > v7 )
        v20 = v17;
      else
        v20 = 0;
      if ( (v20 & 1) != 0 )
      {
        v5 = 4;
      }
      else
      {
        if ( (v9 & v18 & 1) != 0 )
          goto LABEL_65;
        if ( v18 )
          v5 = v19;
      }
    }
    goto LABEL_64;
  }
  if ( (unsigned int)(*(_DWORD *)(a1 + 60) - 2) >= 3 )
    return mutex_unlock(v4 + 800);
LABEL_65:
  v22 = (unsigned __int8)a2[40];
  v23 = *(_DWORD *)(a1 + 4);
  *(_BYTE *)(a1 + 57) = v22;
  v24 = *a2;
  *(_BYTE *)(a1 + 56) = *a2;
  if ( v23 )
  {
    printk(&unk_27EB6F, "sde_cesta_clk_bw_update_helper");
    goto LABEL_76;
  }
  v25 = *(_DWORD *)(a1 + 60);
  if ( v25 == 1 || v25 == 2 && (v24 & 1) == 0 )
  {
    v26 = *((_QWORD *)a2 + 3);
    v27 = *((_QWORD *)a2 + 4);
    goto LABEL_73;
  }
  if ( (unsigned int)(v25 - 2) > 2 || (a2[41] & 1) == 0 )
  {
    if ( v25 != 3 )
    {
      if ( v25 != 4 )
        goto LABEL_76;
      v26 = *((_QWORD *)a2 + 3);
      v27 = *((_QWORD *)a2 + 4);
      v28 = *(_QWORD *)(a1 + 64);
      v29 = *(_QWORD *)(a1 + 72);
      goto LABEL_74;
    }
    v26 = *(_QWORD *)(a1 + 80);
    v27 = *(_QWORD *)(a1 + 88);
LABEL_73:
    v28 = *((_QWORD *)a2 + 1);
    v29 = *((_QWORD *)a2 + 2);
LABEL_74:
    v30 = a1;
    goto LABEL_75;
  }
  v26 = *(_QWORD *)(a1 + 80);
  v27 = *(_QWORD *)(a1 + 88);
  v28 = *(_QWORD *)(a1 + 64);
  v29 = *(_QWORD *)(a1 + 72);
  v30 = a1;
  *(_BYTE *)(a1 + 57) = 1;
  v22 = 1;
LABEL_75:
  ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64))sde_cesta_clk_bw_vote)(
    v30,
    v22,
    v26,
    v27,
    v28,
    v29);
LABEL_76:
  v31 = *((_QWORD *)a2 + 4);
  v32 = *((_QWORD *)a2 + 1);
  v33 = *((_QWORD *)a2 + 2);
  v34 = *(_DWORD *)a1;
  v35 = *(_DWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 80) = *((_QWORD *)a2 + 3);
  *(_QWORD *)(a1 + 88) = v31;
  *(_QWORD *)(a1 + 64) = v32;
  *(_QWORD *)(a1 + 72) = v33;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_cesta_clk_bw_update",
    604,
    -1,
    v34,
    v35,
    *(unsigned __int8 *)(a1 + 56),
    *(unsigned __int8 *)(a1 + 57),
    *(_DWORD *)(a1 + 60));
  return mutex_unlock(v4 + 800);
}
