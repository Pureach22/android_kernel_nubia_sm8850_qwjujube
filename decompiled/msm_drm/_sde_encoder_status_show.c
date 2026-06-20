__int64 __fastcall sde_encoder_status_show(__int64 a1)
{
  _DWORD *v1; // x19
  __int64 v3; // x1
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 disp_op; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  _DWORD *v9; // x8
  unsigned int v10; // w20
  __int64 v11; // x28
  __int64 v12; // x0
  const char *v13; // x1
  __int64 v14; // x2
  _DWORD *v15; // x23
  int v16; // w8
  void *v18; // x0

  if ( !a1 )
    return (unsigned int)-22;
  v1 = *(_DWORD **)(a1 + 128);
  if ( !v1 )
    return (unsigned int)-22;
  mutex_lock(v1 + 132);
  if ( !*(_QWORD *)v1 )
  {
    v18 = &unk_26FCAB;
    goto LABEL_38;
  }
  v4 = *(_QWORD *)(*(_QWORD *)v1 + 56LL);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 8)) == 0 )
  {
    v18 = &unk_234896;
LABEL_38:
    printk(v18, "sde_encoder_get_kms");
    disp_op = 0;
    goto LABEL_7;
  }
  disp_op = sde_kms_get_disp_op(v5, v3);
  if ( (unsigned int)disp_op < 3 )
  {
LABEL_7:
    v9 = *(_DWORD **)&v1[2 * (unsigned int)disp_op + 1336];
    if ( v9 )
    {
      if ( *(v9 - 1) != -864029733 )
        __break(0x8228u);
      v10 = ((__int64 (__fastcall *)(_DWORD *, __int64))v9)(v1, a1);
      if ( v10 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "enc%d failed to dump debugfs status with error:%d\n", v1[6], v10);
      }
      goto LABEL_34;
    }
    if ( !v1[49] )
    {
LABEL_33:
      v10 = 0;
LABEL_34:
      mutex_unlock(v1 + 132);
      return v10;
    }
    v11 = 0;
    while ( 1 )
    {
      if ( v11 == 4 )
        goto LABEL_39;
      v15 = *(_DWORD **)&v1[2 * v11 + 50];
      if ( v15 )
        break;
LABEL_18:
      if ( ++v11 >= (unsigned __int64)(unsigned int)v1[49] )
        goto LABEL_33;
    }
    seq_printf(a1, "intf:%d    vsync:%8d     underrun:%8d    ", v15[168] - 1, v15[215], v15[218]);
    v16 = v15[167];
    if ( v16 <= 1 )
    {
      if ( !v16 )
      {
        v12 = a1;
        v13 = "mode: none\n";
        v14 = 11;
        goto LABEL_17;
      }
      if ( v16 != 1 )
        goto LABEL_32;
      v12 = a1;
      v13 = "mode: command\n";
    }
    else
    {
      if ( v16 != 4 )
      {
        if ( v16 == 3 )
        {
          v12 = a1;
          v13 = "mode: wb block\n";
          v14 = 15;
LABEL_17:
          disp_op = seq_write(v12, v13, v14);
          goto LABEL_18;
        }
        if ( v16 == 2 )
        {
          v12 = a1;
          v13 = "mode: video\n";
          v14 = 12;
          goto LABEL_17;
        }
LABEL_32:
        v12 = a1;
        v13 = "mode: ???\n";
        v14 = 10;
        goto LABEL_17;
      }
      v12 = a1;
      v13 = "mode: wb line\n";
    }
    v14 = 14;
    goto LABEL_17;
  }
LABEL_39:
  __break(0x5512u);
  return inline_copy_to_user_2(disp_op, v7, v8);
}
