__int64 __fastcall dp_reo_status_ring_handler(__int64 a1, __int64 a2)
{
  char *v4; // x2
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w21
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  char v17; // w14
  __int64 v18; // x1
  __int64 v19; // x12
  unsigned int v20; // w10
  __int64 v22; // x22
  unsigned __int64 StatusReg; // x26
  __int64 v30; // x8
  unsigned int (*v31)(void); // x8
  __int64 v32; // x22
  __int64 v33; // x9
  __int64 v34; // x8
  _QWORD *v35; // x10
  _QWORD *v36; // x9
  _QWORD *v37; // x8
  __int64 v38; // x8
  __int64 v39; // x1
  _DWORD *v40; // x8
  __int64 v41; // x9
  __int64 v42; // x22
  char v43; // w12
  __int64 v44; // x25
  unsigned int v45; // w10
  _QWORD v48[13]; // [xsp+18h] [xbp-78h] BYREF
  int v49; // [xsp+80h] [xbp-10h]
  __int64 v50; // [xsp+88h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(char **)(a2 + 6592);
  v49 = 0;
  memset(v48, 0, sizeof(v48));
  v13 = 0;
  if ( !(unsigned int)dp_srng_access_start(a1, a2, v4) )
  {
    v14 = *(_QWORD *)(a2 + 6592);
    v15 = *(unsigned int *)(v14 + 120);
    if ( (_DWORD)v15 == *(_DWORD *)(v14 + 136) )
    {
      v13 = 0;
LABEL_45:
      dp_srng_access_end(a1, a2, *(char **)(a2 + 6592), v5, v6, v7, v8, v9, v10, v11, v12);
      goto LABEL_46;
    }
    v16 = *(_QWORD *)(v14 + 16);
    v17 = *(_BYTE *)(v14 + 78);
    v18 = v16 + 4 * v15;
    v19 = *(_QWORD *)(a2 + 1128);
    if ( *(_DWORD *)(v14 + 44) + (_DWORD)v15 == *(_DWORD *)(v14 + 36) )
      v20 = 0;
    else
      v20 = *(_DWORD *)(v14 + 44) + v15;
    *(_DWORD *)(v14 + 120) = v20;
    if ( (v17 & 4) != 0 )
    {
      _X21 = v16 + 4LL * v20;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(v19 + 8) + 40LL) + 844LL) & 0x40) == 0 )
      {
        v22 = v18;
        _dma_sync_single_for_cpu();
        v18 = v22;
      }
      __asm { PRFM            #0, [X21] }
    }
    v13 = 0;
    if ( !v18 )
      goto LABEL_45;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v30 = *(_QWORD *)(*(_QWORD *)(a2 + 1128) + 74392LL);
      if ( *(_QWORD *)(v30 + 1648) )
      {
        v31 = *(unsigned int (**)(void))(v30 + 1656);
        if ( *((_DWORD *)v31 - 1) != 1393895499 )
          __break(0x8228u);
        if ( !v31() )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(a2 + 13176);
            v32 = *(_QWORD *)(a2 + 13160);
            if ( v32 )
              goto LABEL_23;
          }
          else
          {
            raw_spin_lock_bh(a2 + 13176);
            *(_QWORD *)(a2 + 13184) |= 1uLL;
            v32 = *(_QWORD *)(a2 + 13160);
            if ( v32 )
            {
LABEL_23:
              while ( 1 )
              {
                v33 = *(_QWORD *)(v32 + 24);
                if ( !*(_WORD *)v32 )
                  break;
                v32 = *(_QWORD *)(v32 + 24);
                if ( !v33 )
                  goto LABEL_25;
              }
              v35 = (_QWORD *)(v33 + 32);
              _ZF = v33 == 0;
              v36 = (_QWORD *)(a2 + 13168);
              v37 = *(_QWORD **)(v32 + 32);
              if ( !_ZF )
                v36 = v35;
              *v36 = v37;
              *v37 = *(_QWORD *)(v32 + 24);
              *(_QWORD *)(v32 + 24) = 0;
              *(_QWORD *)(v32 + 32) = 0;
              v38 = *(_QWORD *)(a2 + 13184);
              if ( (v38 & 1) != 0 )
              {
                *(_QWORD *)(a2 + 13184) = v38 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(a2 + 13176);
              }
              else
              {
                raw_spin_unlock(a2 + 13176);
              }
              v39 = *(_QWORD *)(v32 + 8);
              v40 = *(_DWORD **)(v32 + 16);
              if ( *(v40 - 1) != -1114182658 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, __int64, _QWORD *))v40)(a2, v39, v48);
              _qdf_mem_free(v32);
              goto LABEL_34;
            }
          }
LABEL_25:
          v34 = *(_QWORD *)(a2 + 13184);
          if ( (v34 & 1) != 0 )
          {
            *(_QWORD *)(a2 + 13184) = v34 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a2 + 13176);
          }
          else
          {
            raw_spin_unlock(a2 + 13176);
          }
        }
      }
LABEL_34:
      v41 = *(_QWORD *)(a2 + 6592);
      ++v13;
      v42 = *(unsigned int *)(v41 + 120);
      if ( (_DWORD)v42 != *(_DWORD *)(v41 + 136) )
      {
        v43 = *(_BYTE *)(v41 + 78);
        v44 = *(_QWORD *)(v41 + 16);
        if ( *(_DWORD *)(v41 + 44) + (_DWORD)v42 == *(_DWORD *)(v41 + 36) )
          v45 = 0;
        else
          v45 = *(_DWORD *)(v41 + 44) + v42;
        *(_DWORD *)(v41 + 120) = v45;
        if ( (v43 & 4) != 0 )
        {
          _X27 = v44 + 4LL * v45;
          if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 40LL) + 844LL) & 0x40) == 0 )
            _dma_sync_single_for_cpu();
          __asm { PRFM            #0, [X27] }
        }
        if ( v44 + 4 * v42 )
          continue;
      }
      goto LABEL_45;
    }
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v13;
}
