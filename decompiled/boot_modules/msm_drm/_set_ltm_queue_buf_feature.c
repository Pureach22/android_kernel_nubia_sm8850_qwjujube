__int64 __fastcall set_ltm_queue_buf_feature(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x25
  __int64 result; // x0
  _QWORD *v7; // x20
  unsigned int disp_op; // w0
  _DWORD *v9; // x23
  int v10; // w8
  unsigned int v11; // w21
  int v12; // w24
  _QWORD **v13; // x11
  __int64 v14; // x10
  char v15; // w26
  char v16; // w8
  _QWORD **v17; // x9
  __int64 v18; // x12
  __int64 v19; // x13
  __int64 v20; // x14
  _QWORD *i; // x14
  int v22; // w16
  __int64 v23; // x14
  _QWORD *v24; // x1
  _QWORD *v25; // x0
  __int64 v26; // x0
  void (*v27)(void); // x8
  __int64 v28; // x0
  void (*v29)(void); // x8
  __int64 v30; // x0
  void (*v31)(void); // x8
  __int64 v32; // x0
  void (*v33)(void); // x8
  __int64 v34; // x0
  void (*v35)(void); // x8
  __int64 v36; // x0
  void (*v37)(void); // x8
  __int64 v38; // x0
  void (*v39)(void); // x8
  __int64 v40; // x0
  void (*v41)(void); // x8
  int v42; // w1

  result = 4294967274LL;
  if ( !a1 || !a3 )
    return result;
  v7 = a2;
  if ( (*(_BYTE *)(a2[4] + 384LL) & 1) != 0 )
    return 0;
  mutex_lock(a3 + 7704);
  if ( !v7 )
  {
    _drm_err("invalid parameters sde_crtc %pK cfg %pK\n", (const void *)a3, nullptr);
    goto LABEL_112;
  }
  disp_op = sde_crtc_get_disp_op(a3);
  v9 = (_DWORD *)*v7;
  if ( !*v7 )
  {
    _drm_err("invalid parameters payload %pK\n", nullptr);
    goto LABEL_112;
  }
  v10 = *(_DWORD *)(a3 + 2192);
  v11 = disp_op;
  if ( v10 )
  {
    if ( (unsigned int)(v10 - 9) < 0xFFFFFFF8 )
      goto LABEL_99;
    v12 = *(_QWORD *)(a3 + 2216) != 0;
    if ( v10 != 1 )
    {
      if ( *(_QWORD *)(a3 + 2264) )
        ++v12;
      if ( v10 != 2 )
      {
        if ( *(_QWORD *)(a3 + 2312) )
          ++v12;
        if ( v10 != 3 )
        {
          if ( *(_QWORD *)(a3 + 2360) )
            ++v12;
          if ( v10 != 4 )
          {
            if ( *(_QWORD *)(a3 + 2408) )
              ++v12;
            if ( v10 != 5 )
            {
              if ( *(_QWORD *)(a3 + 2456) )
                ++v12;
              if ( v10 != 6 )
              {
                if ( *(_QWORD *)(a3 + 2504) )
                  ++v12;
                if ( v10 != 7 && *(_QWORD *)(a3 + 2552) )
                  ++v12;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v12 = 0;
  }
  v3 = 7752;
  v7 = (_QWORD *)raw_spin_lock_irqsave(a3 + 7752);
  if ( !*(_DWORD *)(a3 + 7592) )
  {
LABEL_100:
    raw_spin_unlock_irqrestore(a3 + v3, v7);
    _drm_err("LTM buffers are not allocated\n");
    goto LABEL_112;
  }
  v13 = *(_QWORD ***)(a3 + 7640);
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = (_QWORD **)(a3 + 7640);
  v18 = a3 + 7600;
  v19 = 17792;
  do
  {
    v20 = *(_QWORD *)(v18 + 8 * v14);
    if ( v20 && *v9 == *(_DWORD *)(v20 + 24) )
    {
      *(_DWORD *)(*(_QWORD *)(v20 + 40) + *(unsigned int *)(v20 + 28) + v19) = 0;
      for ( i = *v17; i != v17; v16 |= v22 == *v9 )
      {
        v22 = *((_DWORD *)i - 6);
        i = (_QWORD *)*i;
      }
      if ( (v16 & 1) != 0 )
      {
        v16 = 1;
LABEL_36:
        v15 = 1;
        goto LABEL_37;
      }
      v23 = *(_QWORD *)(v18 + 8 * v14);
      v24 = *(_QWORD **)(a3 + 7648);
      v25 = (_QWORD *)(v23 + 48);
      if ( (_QWORD **)(v23 + 48) == v17 || v25 == v24 || (_QWORD **)*v24 != v17 )
      {
        _list_add_valid_or_report(v25, v24);
        v16 = 0;
        goto LABEL_36;
      }
      v16 = 0;
      v15 = 1;
      *(_QWORD *)(a3 + 7648) = v25;
      *(_QWORD *)(v23 + 48) = v17;
      *(_QWORD *)(v23 + 56) = v24;
      *v24 = v25;
    }
LABEL_37:
    ++v14;
  }
  while ( v14 != 5 );
  if ( ((v13 == v17) & (unsigned __int8)v15) != 1 || !v12 )
    goto LABEL_110;
  v26 = *(_QWORD *)(a3 + 2216);
  if ( !v26 )
  {
    v42 = 0;
LABEL_109:
    _drm_err("invalid dspp for mixer %d\n", v42);
    goto LABEL_110;
  }
  if ( v11 > 2 )
    goto LABEL_99;
  v27 = *(void (**)(void))(v26 + 8LL * v11 + 688);
  if ( v27 )
  {
    if ( *((_DWORD *)v27 - 1) != -1971146212 )
      __break(0x8228u);
    v27();
  }
  if ( v12 == 1 )
    goto LABEL_110;
  v28 = *(_QWORD *)(a3 + 2264);
  if ( !v28 )
  {
    v42 = 1;
    goto LABEL_109;
  }
  v29 = *(void (**)(void))(v28 + 8LL * v11 + 688);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != -1971146212 )
      __break(0x8228u);
    v29();
  }
  if ( v12 == 2 )
    goto LABEL_110;
  v30 = *(_QWORD *)(a3 + 2312);
  if ( !v30 )
  {
    v42 = 2;
    goto LABEL_109;
  }
  v31 = *(void (**)(void))(v30 + 8LL * v11 + 688);
  if ( v31 )
  {
    if ( *((_DWORD *)v31 - 1) != -1971146212 )
      __break(0x8228u);
    v31();
  }
  if ( v12 == 3 )
    goto LABEL_110;
  v32 = *(_QWORD *)(a3 + 2360);
  if ( !v32 )
  {
    v42 = 3;
    goto LABEL_109;
  }
  v33 = *(void (**)(void))(v32 + 8LL * v11 + 688);
  if ( v33 )
  {
    if ( *((_DWORD *)v33 - 1) != -1971146212 )
      __break(0x8228u);
    v33();
  }
  if ( v12 == 4 )
    goto LABEL_110;
  v34 = *(_QWORD *)(a3 + 2408);
  if ( !v34 )
  {
    v42 = 4;
    goto LABEL_109;
  }
  v35 = *(void (**)(void))(v34 + 8LL * v11 + 688);
  if ( v35 )
  {
    if ( *((_DWORD *)v35 - 1) != -1971146212 )
      __break(0x8228u);
    v35();
  }
  if ( v12 == 5 )
    goto LABEL_110;
  v36 = *(_QWORD *)(a3 + 2456);
  if ( !v36 )
  {
    v42 = 5;
    goto LABEL_109;
  }
  v37 = *(void (**)(void))(v36 + 8LL * v11 + 688);
  if ( v37 )
  {
    if ( *((_DWORD *)v37 - 1) != -1971146212 )
      __break(0x8228u);
    v37();
  }
  if ( v12 == 6 )
    goto LABEL_110;
  v38 = *(_QWORD *)(a3 + 2504);
  if ( !v38 )
  {
    v42 = 6;
    goto LABEL_109;
  }
  v39 = *(void (**)(void))(v38 + 8LL * v11 + 688);
  if ( v39 )
  {
    if ( *((_DWORD *)v39 - 1) != -1971146212 )
      __break(0x8228u);
    v39();
  }
  if ( v12 == 7 )
    goto LABEL_110;
  v40 = *(_QWORD *)(a3 + 2552);
  if ( !v40 )
  {
    v42 = 7;
    goto LABEL_109;
  }
  v41 = *(void (**)(void))(v40 + 8LL * v11 + 688);
  if ( v41 )
  {
    if ( *((_DWORD *)v41 - 1) != -1971146212 )
      __break(0x8228u);
    v41();
  }
  if ( v12 != 8 )
  {
LABEL_99:
    __break(0x5512u);
    goto LABEL_100;
  }
LABEL_110:
  raw_spin_unlock_irqrestore(a3 + 7752, v7);
  if ( (v15 & 1) == 0 )
    _drm_err("failed to found a matching buffer fd %d", *v9);
LABEL_112:
  mutex_unlock(a3 + 7704);
  return 0;
}
