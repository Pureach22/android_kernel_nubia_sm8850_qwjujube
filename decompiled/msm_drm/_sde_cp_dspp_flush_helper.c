__int64 __fastcall sde_cp_dspp_flush_helper(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x1
  int v6; // w9
  unsigned int v7; // w21
  unsigned int v8; // w8
  unsigned int v9; // w22
  __int64 v10; // x26
  __int64 v11; // x27
  __int64 (__fastcall *v12)(__int64, __int64, __int64, __int64); // x8
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x2
  __int64 v16; // x25
  __int64 v17; // x28
  __int64 v18; // x23
  _DWORD *v19; // x8
  __int64 v20; // x0
  int v21; // w8
  __int64 *v22; // x9
  __int64 v23; // x1
  __int64 v24; // x0
  __int64 v25; // x10
  void (__fastcall *v26)(__int64, __int64, __int64); // x24
  unsigned int (*v27)(void); // x8
  __int64 v28; // x1
  __int64 v29; // [xsp+8h] [xbp-18h] BYREF
  int v30; // [xsp+10h] [xbp-10h] BYREF
  int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h] BYREF

  if ( !a1 || a2 >= 0x34 )
    return printk(&unk_27E0CF, "_sde_cp_dspp_flush_helper");
  result = sde_crtc_get_disp_op(a1);
  v6 = *(_DWORD *)(a1 + 2192);
  v7 = result;
  if ( v6 )
  {
    if ( (unsigned int)(v6 - 9) < 0xFFFFFFF8 )
    {
LABEL_75:
      __break(0x5512u);
      __break(1u);
      return sde_cp_ad_set_prop(result, v5);
    }
    v8 = *(_QWORD *)(a1 + 2216) != 0;
    if ( v6 != 1 )
    {
      if ( *(_QWORD *)(a1 + 2264) )
        ++v8;
      if ( v6 != 2 )
      {
        if ( *(_QWORD *)(a1 + 2312) )
          ++v8;
        if ( v6 != 3 )
        {
          if ( *(_QWORD *)(a1 + 2360) )
            ++v8;
          if ( v6 != 4 )
          {
            if ( *(_QWORD *)(a1 + 2408) )
              ++v8;
            if ( v6 != 5 )
            {
              if ( *(_QWORD *)(a1 + 2456) )
                ++v8;
              if ( v6 != 6 )
              {
                if ( *(_QWORD *)(a1 + 2504) )
                  ++v8;
                if ( v6 != 7 && *(_QWORD *)(a1 + 2552) )
                  ++v8;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v8 = 0;
  }
  v32 = 0;
  v9 = dspp_feature_to_sub_blk_tbl[a2];
  v31 = 0;
  v30 = 0;
  v29 = 0;
  if ( v8 )
  {
    v10 = 0;
    v11 = 48LL * v8;
    do
    {
      if ( v10 == 384 )
        goto LABEL_75;
      v16 = *(_QWORD *)(a1 + v10 + 2208);
      if ( v16 )
      {
        v17 = *(_QWORD *)(a1 + v10 + 2216);
        if ( v17 )
        {
          if ( v7 > 2 )
            goto LABEL_75;
          v18 = v16 + 1144;
          v19 = *(_DWORD **)(v16 + 1144 + 8LL * v7);
          if ( v19 )
          {
            if ( a2 != 33 )
            {
              v23 = *(unsigned int *)(v17 + 64);
              v24 = *(_QWORD *)(a1 + v10 + 2208);
              if ( *(v19 - 1) != -399206746 )
                __break(0x8228u);
              result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v19)(v24, v23, v9, 1);
              if ( a2 != 49 )
                goto LABEL_35;
              v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v18 + 8LL * v7);
              v13 = *(unsigned int *)(v17 + 64);
              v14 = v16;
              v15 = 23;
              goto LABEL_32;
            }
            if ( *(_BYTE *)(v17 + 80) == 1 )
            {
              v20 = *(unsigned int *)(v17 + 1496);
              *(_BYTE *)(v17 + 80) = 0;
              result = sde_reg_dma_get_ops(v20);
              if ( !result )
              {
                printk(&unk_221363, "_flush_sb_dma_hw");
                goto LABEL_31;
              }
              v21 = *(_DWORD *)(v16 + 64);
              if ( HIDWORD(v32) != v21 )
              {
                if ( HIDWORD(v32) )
                {
                  if ( (_DWORD)v32 == v21 )
                    goto LABEL_31;
                  if ( (_DWORD)v32 )
                  {
                    if ( v31 == v21 )
                      goto LABEL_31;
                    if ( v31 )
                    {
                      if ( v30 == v21 )
                        goto LABEL_31;
                      if ( v30 )
                      {
                        if ( HIDWORD(v29) == v21 )
                          goto LABEL_31;
                        if ( HIDWORD(v29) )
                        {
                          if ( v21 && !(_DWORD)v29 )
                          {
                            v22 = &v29;
                            goto LABEL_66;
                          }
                          goto LABEL_31;
                        }
                        v22 = (__int64 *)((char *)&v29 + 4);
                      }
                      else
                      {
                        v22 = (__int64 *)&v30;
                      }
                    }
                    else
                    {
                      v22 = (__int64 *)&v31;
                    }
                  }
                  else
                  {
                    v22 = &v32;
                  }
                }
                else
                {
                  v22 = (__int64 *)((char *)&v32 + 4);
                }
LABEL_66:
                v25 = *(unsigned int *)(v16 + 28);
                *(_DWORD *)v22 = v21;
                if ( (unsigned int)v25 >= 3 )
                  goto LABEL_75;
                v26 = *(void (__fastcall **)(__int64, __int64, __int64))(result + 8 * v25 + 96);
                if ( v26 )
                {
                  v27 = *(unsigned int (**)(void))(result + 128);
                  if ( *((_DWORD *)v27 - 1) != -1162562360 )
                    __break(0x8228u);
                  v28 = v27();
                  if ( *((_DWORD *)v26 - 1) != 112044836 )
                    __break(0x8238u);
                  v26(v16, v28, 1);
                }
              }
LABEL_31:
              v12 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v18 + 8LL * v7);
              v13 = *(unsigned int *)(v17 + 64);
              v14 = v16;
              v15 = v9;
LABEL_32:
              if ( *((_DWORD *)v12 - 1) != -399206746 )
                __break(0x8228u);
              result = v12(v14, v13, v15, 1);
            }
          }
        }
      }
LABEL_35:
      v10 += 48;
    }
    while ( v11 != v10 );
  }
  return result;
}
