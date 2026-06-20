__int64 __fastcall kgsl_snapshot_save_frozen_objs(__int64 a1)
{
  unsigned __int64 v1; // x20
  _QWORD *v2; // x25
  _QWORD *v4; // x21
  _QWORD *v5; // x23
  _QWORD *v6; // x25
  __int64 v7; // x8
  _QWORD *v8; // x22
  __int64 v9; // x26
  __int64 v10; // x27
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  __int64 v13; // x0
  _QWORD *v14; // x8
  unsigned __int64 v15; // x9
  size_t v16; // x1
  __int64 v17; // x21
  _QWORD *v18; // x28
  unsigned __int64 v19; // x26
  __int64 v20; // x8
  _QWORD *v21; // x22
  __int64 v22; // x27
  size_t v23; // x24
  __int64 v24; // x8
  void (__fastcall *v25)(_QWORD); // x8
  unsigned __int64 v26; // x27
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 (*v29)(void); // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x11
  __int64 v33; // x12
  unsigned __int64 v34; // x10
  bool v35; // w13
  unsigned __int64 v36; // x11
  __int64 v37; // x12
  bool v38; // w13
  __int64 v39; // x8
  __int64 v40; // x9
  void (__fastcall *v41)(_QWORD); // x9
  __int64 v42; // x2
  unsigned __int64 StatusReg; // x22
  __int64 v45; // x23
  __int64 v46; // [xsp+8h] [xbp-8h]

  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 88) + 13192LL) & 1) == 0 )
  {
    v5 = (_QWORD *)(a1 - 16);
    v4 = *(_QWORD **)(a1 - 16);
    if ( v4 != (_QWORD *)(a1 - 16) )
    {
      v1 = a1 - 160;
      do
      {
        v6 = (_QWORD *)*v4;
        v8 = v4 - 1;
        v7 = *(v4 - 1);
        if ( *(int *)(v7 + 8) >= 1 )
        {
          v9 = 0;
          v10 = 0;
          do
          {
            kgsl_snapshot_get_object(
              a1 - 160,
              *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v7 + v9 + 24) + 256LL),
              *(_QWORD *)(*(_QWORD *)v7 + v9),
              *(_QWORD *)(*(_QWORD *)v7 + v9 + 8),
              *(_DWORD *)(*(_QWORD *)v7 + v9 + 16));
            v7 = *v8;
            ++v10;
            v9 += 32;
          }
          while ( v10 < *(int *)(*v8 + 8LL) );
        }
        v11 = (_QWORD *)v4[1];
        if ( (_QWORD *)*v11 == v4 && (v12 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
        {
          v12[1] = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v4);
        }
        v13 = *(v4 - 1);
        *v4 = 0xDEAD000000000100LL;
        v4[1] = 0xDEAD000000000122LL;
        adreno_ib_destroy_obj_list(v13);
        kfree(v4 - 1);
        v4 = v6;
      }
      while ( v6 != v5 );
    }
    v2 = (_QWORD *)(a1 - 32);
    v14 = *(_QWORD **)(a1 - 32);
    if ( v14 != (_QWORD *)(a1 - 32) )
    {
      v1 = 0;
      do
      {
        v15 = (*(v14 - 4) + 3LL) & 0xFFFFFFFFFFFFFFFCLL;
        *(v14 - 4) = v15;
        v14 = (_QWORD *)*v14;
        v1 += v15 + 36;
      }
      while ( v14 != v2 );
      if ( v1 )
      {
        v17 = vmalloc_noprof(v1);
        while ( 1 )
        {
          v18 = *(_QWORD **)(a1 - 32);
          *(_QWORD *)(a1 - 48) = v17;
          *(_QWORD *)(a1 - 40) = 0;
          if ( v18 == v2 )
            goto LABEL_86;
          v19 = 0;
          v46 = 0;
          while ( 1 )
          {
            v21 = (_QWORD *)*v18;
            if ( !*(_QWORD *)(a1 - 48) )
              goto LABEL_22;
            v22 = *(v18 - 1);
            v23 = *(v18 - 4);
            v24 = *(_QWORD *)(v22 + 72);
            if ( v24 )
            {
              v25 = *(void (__fastcall **)(_QWORD))(v24 + 24);
              if ( v25 )
              {
                if ( *((_DWORD *)v25 - 1) != -441828660 )
                  __break(0x8228u);
                v25(v22 + 8);
              }
            }
            if ( *(_QWORD *)(v22 + 16) )
              break;
            dev_err(**(_QWORD **)(a1 + 88), "snapshot: failed to map GPU object\n");
            v20 = 0;
LABEL_21:
            v19 += v20;
            v17 += v20;
            v46 += v20;
            *(_QWORD *)(a1 - 40) += v20;
LABEL_22:
            kgsl_snapshot_put_object(v18 - 5);
            v18 = v21;
            if ( v21 == v2 )
              goto LABEL_86;
          }
          if ( (v19 & 0x8000000000000000LL) == 0 && v1 >= v19 && v1 - v19 >= 2 )
          {
            *(_WORD *)v17 = -21555;
            if ( ((v19 + 2) & 0x8000000000000000LL) == 0 && v1 >= v19 + 2 && v1 - (v19 + 2) >= 2 )
            {
              v26 = v19 + 4;
              *(_WORD *)(v17 + 2) = 2818;
              if ( ((v19 + 4) & 0x8000000000000000LL) == 0 && v1 >= v19 + 4 && v1 - (v19 + 4) >= 4 )
              {
                *(_DWORD *)(v17 + 4) = v23 + 36;
                if ( ((v19 + 28) & 0x8000000000000000LL) == 0 && v1 >= v19 + 28 && v1 - (v19 + 28) >= 8 )
                {
                  *(_QWORD *)(v17 + 28) = v23 >> 2;
                  if ( ((v19 + 12) & 0x8000000000000000LL) == 0 && v1 >= v19 + 12 && v1 - (v19 + 12) >= 8 )
                  {
                    *(_QWORD *)(v17 + 12) = *(v18 - 5);
                    v27 = *(_QWORD *)(*(_QWORD *)(*(v18 - 1) + 256LL) + 64LL);
                    if ( v27 )
                    {
                      v28 = *(_QWORD *)(v27 + 96);
                      if ( v28 && (v29 = *(__int64 (**)(void))(v28 + 48)) != nullptr )
                      {
                        if ( *((_DWORD *)v29 - 1) != 1831526433 )
                          __break(0x8228u);
                        v27 = v29();
                      }
                      else
                      {
                        v27 = 0;
                      }
                    }
                    if ( ((v19 + 20) & 0x8000000000000000LL) == 0 && v1 >= v19 + 20 && v1 - (v19 + 20) >= 8 )
                    {
                      *(_QWORD *)(v17 + 20) = v27;
                      if ( ((v19 + 8) & 0x8000000000000000LL) == 0 && v1 >= v19 + 8 && v1 - (v19 + 8) >= 4 )
                      {
                        *(_DWORD *)(v17 + 8) = *((_DWORD *)v18 - 4);
                        v30 = *(v18 - 5);
                        v31 = *(v18 - 4);
                        v32 = *(_QWORD *)(a1 - 160);
                        v33 = *(unsigned int *)(a1 - 136);
                        v34 = ~v30;
                        v35 = __CFADD__(v32, v33);
                        if ( v31 <= v34 && !v35 && v31 + v30 > v32 && v32 + v33 > v30 )
                        {
                          *(_BYTE *)(a1 - 124) = 1;
                          v30 = *(v18 - 5);
                          v31 = *(v18 - 4);
                          v34 = ~v30;
                        }
                        v36 = *(_QWORD *)(a1 - 152);
                        v37 = *(unsigned int *)(a1 - 132);
                        v38 = __CFADD__(v36, v37);
                        if ( v31 <= v34 && !v38 && v30 + v31 > v36 && v36 + v37 > v30 )
                          *(_BYTE *)(a1 - 123) = 1;
                        if ( v1 >= v46 + 36 )
                          v16 = v1 - (v46 + 36);
                        else
                          v16 = 0;
                        if ( v16 < v23 )
                          goto LABEL_96;
                        memcpy((void *)(v17 + 36), (const void *)(*(_QWORD *)(*(v18 - 1) + 16LL) + *(v18 - 3)), v23);
                        v39 = *(v18 - 1);
                        v40 = *(_QWORD *)(v39 + 72);
                        if ( v40 )
                        {
                          v41 = *(void (__fastcall **)(_QWORD))(v40 + 32);
                          if ( v41 )
                          {
                            if ( *((_DWORD *)v41 - 1) != 1555154090 )
                              __break(0x8229u);
                            v41(v39 + 8);
                          }
                        }
                        if ( v1 >= v26 && v1 - v26 >= 4 )
                          break;
                      }
                    }
                  }
                }
              }
            }
          }
          __break(1u);
LABEL_96:
          _fortify_panic(17, v16, v23);
LABEL_97:
          __break(0x800u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v45 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &kgsl_snapshot_save_frozen_objs__alloc_tag;
          v17 = vmalloc_noprof(v1);
          *(_QWORD *)(StatusReg + 80) = v45;
        }
        v20 = *(unsigned int *)(v17 + 4);
        goto LABEL_21;
      }
    }
LABEL_86:
    kgsl_process_private_put(*(unsigned int **)(a1 + 64));
    v42 = *(_QWORD *)(a1 - 160);
    *(_QWORD *)(a1 + 64) = 0;
    if ( v42 && (*(_BYTE *)(a1 - 124) & 1) == 0 )
    {
      dev_err(**(_QWORD **)(a1 + 88), "snapshot: Active IB1:%016llx not dumped\n");
    }
    else if ( *(_QWORD *)(a1 - 152) && (*(_BYTE *)(a1 - 123) & 1) == 0 )
    {
      dev_err(**(_QWORD **)(a1 + 88), "snapshot: Active IB2:%016llx not dumped\n");
    }
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 88) + 11301LL) & 1) == 0 && *(_BYTE *)(*(_QWORD *)(a1 + 88) + 11300LL) == 1 )
    goto LABEL_97;
  return complete_all(a1 + 32);
}
