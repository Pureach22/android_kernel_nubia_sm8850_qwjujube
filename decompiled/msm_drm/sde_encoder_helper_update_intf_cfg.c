__int64 __fastcall sde_encoder_helper_update_intf_cfg(
        __int64 **a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int16 *a5)
{
  unsigned __int16 v5; // w12
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned int disp_op; // w20
  __int64 *v10; // x8
  __int64 v11; // x21
  __int64 v12; // x22
  __int64 v13; // x23
  int v14; // w4
  __int64 v15; // x3
  int v16; // w8
  void (*v17)(void); // x8
  __int64 *v18; // x8
  __int64 v19; // x9
  __int64 *v20; // x10
  unsigned int v21; // w8
  unsigned int v22; // w9
  __int64 result; // x0
  __int64 (*v24)(void); // x8
  __int64 *v25; // x10
  void *v26; // x0
  __int64 v27; // x9
  __int64 v28; // x8
  int v29; // w9

  if ( !a1 || !a1[62] )
    return printk(&unk_265831, "sde_encoder_helper_update_intf_cfg");
  if ( !*a1 )
  {
    v12 = 328;
    disp_op = 0;
    v11 = 0x29EC4C0029EDA3LL;
    v13 = 0x29EC4C0029F05BLL;
    if ( (_drm_debug & 4) == 0 )
      goto LABEL_14;
    goto LABEL_12;
  }
  v7 = **a1;
  if ( v7 )
  {
    v8 = *(_QWORD *)(v7 + 56);
    if ( v8 && *(_QWORD *)(v8 + 8) )
    {
      disp_op = sde_kms_get_disp_op();
      goto LABEL_8;
    }
    v26 = &unk_234896;
  }
  else
  {
    v26 = &unk_26FCAB;
  }
  printk(v26, "sde_encoder_get_kms");
  disp_op = 0;
LABEL_8:
  v10 = *a1;
  v11 = (*a1)[41];
  v12 = (__int64)(*a1 + 41);
  v13 = v11 + 696;
  if ( (_drm_debug & 4) == 0 )
    goto LABEL_14;
  if ( !v10 )
  {
LABEL_12:
    v14 = -1;
    goto LABEL_13;
  }
  v14 = *((_DWORD *)v10 + 6);
LABEL_13:
  _drm_dev_dbg(0, 0, 0, "enc%d intf_cfg updated for %d at idx %d\n", v14, *((_DWORD *)a1 + 168), *(_DWORD *)(v11 + 696));
LABEL_14:
  v15 = *(unsigned int *)(v11 + 696);
  if ( (unsigned int)v15 >= 2 )
    return printk(&unk_22407E, "sde_encoder_helper_update_intf_cfg");
  v16 = *((_DWORD *)a1 + 168);
  *(_DWORD *)v13 = v15 + 1;
  *(_DWORD *)(v11 + 4 * v15 + 700) = v16;
  if ( *(__int64 ***)v12 == a1 )
    *(_DWORD *)(v11 + 708) = *(_DWORD *)(*(_QWORD *)v12 + 668LL) == 1;
  if ( (unsigned int)(*((_DWORD *)a1 + 166) - 1) <= 1 )
    *(_DWORD *)(v11 + 712) = *((_DWORD *)a1[53] + 8);
  if ( disp_op > 2 )
  {
    __break(0x5512u);
    __stlxr(v5, a5);
    return sde_encoder_helper_split_config();
  }
  v17 = (void (*)(void))a1[53][disp_op + 52];
  if ( v17 )
  {
    if ( *((_DWORD *)v17 - 1) != 530145669 )
      __break(0x8228u);
    v17();
  }
  if ( *((_DWORD *)a1 + 208) )
  {
    v18 = a1[1];
    if ( v18 )
    {
      v19 = v18[314];
      if ( v19 )
      {
        v20 = a1[53];
        v21 = *(_DWORD *)(v19 + 2244);
        v22 = *(_DWORD *)(v19 + 2248);
        if ( !v20 || (*((_BYTE *)v20 + 77) & 1) == 0 )
        {
          if ( *((_DWORD *)a1 + 166) )
          {
            v25 = *a1;
            if ( *a1 )
            {
              if ( *((_DWORD *)v25 + 49) == 1 )
              {
                LODWORD(v25) = *((unsigned __int8 *)v25 + 4936);
                if ( (_DWORD)v25 == 1 && v21 == 2 && v22 < 2 )
                  goto LABEL_52;
              }
              else
              {
                LOBYTE(v25) = 0;
              }
            }
            if ( ((unsigned __int8)v25 & 1) != 0 || v21 != 4 )
              goto LABEL_29;
          }
          else if ( v21 != 2 )
          {
            goto LABEL_29;
          }
          if ( v21 <= v22 )
            goto LABEL_29;
LABEL_52:
          v27 = a1[62][7];
          if ( v27 )
          {
            v28 = *(unsigned int *)(v11 + 724);
            if ( (unsigned int)v28 <= 1 )
            {
              v29 = *(_DWORD *)(v27 + 32);
              *(_DWORD *)(v11 + 724) = v28 + 1;
              *(_DWORD *)(v11 + 4 * v28 + 728) = v29;
            }
          }
        }
      }
    }
  }
LABEL_29:
  result = (__int64)a1[62];
  v24 = *(__int64 (**)(void))(result + 8LL * disp_op + 376);
  if ( v24 )
  {
    if ( *((_DWORD *)v24 - 1) != -671500202 )
      __break(0x8228u);
    return v24();
  }
  return result;
}
