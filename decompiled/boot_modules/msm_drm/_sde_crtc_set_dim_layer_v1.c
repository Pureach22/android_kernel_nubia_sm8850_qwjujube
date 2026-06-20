__int64 __fastcall sde_crtc_set_dim_layer_v1(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x24
  __int64 result; // x0
  __int64 v7; // x20
  __int64 v8; // x21
  unsigned __int16 *v9; // x25
  char *v10; // x26
  int v11; // w5
  __int64 v12; // x8
  unsigned __int16 v13; // w11
  int v14; // w10
  int v15; // w13
  __int16 v16; // w9
  unsigned __int16 v17; // w12
  __int16 v18; // w10
  unsigned __int16 v19; // w9
  int v20; // w11
  int v21; // w6
  void *v22; // x0
  unsigned __int64 v29; // x9
  _QWORD v30[28]; // [xsp+20h] [xbp-F0h] BYREF
  int v31; // [xsp+100h] [xbp-10h]
  __int64 v32; // [xsp+108h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  memset(v30, 0, sizeof(v30));
  if ( a3 )
  {
    if ( a1 && *(_QWORD *)a1 && (v4 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    {
      v5 = *(_QWORD *)(v4 + 8);
      if ( v5 )
      {
        if ( *(_QWORD *)(v5 + 152) )
        {
          result = inline_copy_from_user_2((int)v30, a3, 0xE4u);
          if ( result )
          {
            result = printk(&unk_23F02C, "_sde_crtc_set_dim_layer_v1");
            goto LABEL_21;
          }
          v7 = LODWORD(v30[0]);
          if ( LODWORD(v30[0]) >= 8 )
          {
            result = printk(&unk_279F33, "_sde_crtc_set_dim_layer_v1");
            goto LABEL_21;
          }
          *(_DWORD *)(a2 + 1808) = v30[0];
          if ( (_DWORD)v7 )
          {
            v8 = 0;
            v9 = (unsigned __int16 *)(a2 + 1850);
            v10 = (char *)&v30[2] + 4;
            do
            {
              v11 = *((_DWORD *)v10 - 4);
              *(_DWORD *)(v9 - 15) = v11;
              v12 = *(_QWORD *)(*(_QWORD *)(v5 + 152) + 22008LL);
              v13 = *((_WORD *)v10 + 4);
              v14 = *(_DWORD *)v10;
              v15 = *((_DWORD *)v10 + 1);
              *(_QWORD *)(v9 - 11) = *((_QWORD *)v10 - 1);
              v16 = *((_WORD *)v10 + 6);
              v17 = *((_WORD *)v10 + 5);
              *(v9 - 3) = v13;
              *(_DWORD *)(v9 - 7) = v14;
              v18 = *((_WORD *)v10 + 7);
              v19 = v16 - v13;
              v20 = *((_DWORD *)v10 - 3);
              *(v9 - 2) = v17;
              *(v9 - 1) = v19;
              if ( (v12 & 0x2000) != 0 )
                v21 = v20;
              else
                v21 = v20 + 1;
              *v9 = v18 - v17;
              *(_DWORD *)(v9 - 13) = v21;
              *(_DWORD *)(v9 - 5) = v15;
              if ( (_drm_debug & 4) != 0 )
              {
                result = _drm_dev_dbg(0, 0, 0, "dim_layer[%d] - flags:%d, stage:%d\n", v8, v11, v21);
                if ( (_drm_debug & 4) != 0 )
                  result = _drm_dev_dbg(
                             0,
                             0,
                             0,
                             " rect:{%d,%d,%d,%d}, color:{%d,%d,%d,%d}\n",
                             *(v9 - 3),
                             *(v9 - 2),
                             *(v9 - 1),
                             *v9,
                             *(_DWORD *)(v9 - 11),
                             *(_DWORD *)(v9 - 9),
                             *(_DWORD *)(v9 - 7),
                             *(_DWORD *)(v9 - 5));
              }
              ++v8;
              v10 += 32;
              v9 += 16;
            }
            while ( v7 != v8 );
          }
          goto LABEL_20;
        }
LABEL_25:
        result = printk(&unk_234896, "_sde_crtc_set_dim_layer_v1");
        goto LABEL_21;
      }
      v22 = &unk_234896;
    }
    else
    {
      v22 = &unk_25E167;
    }
    printk(v22, "_sde_crtc_get_kms");
    goto LABEL_25;
  }
  result = ((__int64 (__fastcall *)(__int64))sde_crtc_clear_dim_layers_v1)(a2);
  if ( (_drm_debug & 4) != 0 )
    result = _drm_dev_dbg(0, 0, 0, "dim_layer data removed\n");
LABEL_20:
  _X8 = (unsigned __int64 *)(a2 + 1792);
  __asm { PRFM            #0x11, [X8] }
  do
    v29 = __ldxr(_X8);
  while ( __stxr(v29 | 2, _X8) );
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
