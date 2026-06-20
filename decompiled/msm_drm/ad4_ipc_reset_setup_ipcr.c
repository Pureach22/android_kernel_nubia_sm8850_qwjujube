// positive sp value has been detected, the output may be wrong!
__int64 __fastcall ad4_ipc_reset_setup_ipcr(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x8
  int v5; // w0
  int v6; // w20
  unsigned int v7; // w8
  _DWORD *v8; // x9
  int v9; // w10
  _DWORD *v10; // x8
  unsigned int v11; // w8
  unsigned int v12; // w8
  __int64 v13; // x2
  _DWORD *v14; // x9
  __int64 v15; // x2
  _DWORD *v16; // x9
  __int64 v17; // x2
  _DWORD *v18; // x9
  _DWORD *v19; // x9
  int v20; // w8
  unsigned int v21; // w8

  v2 = *(_QWORD *)(a2 + 8);
  if ( *(_DWORD *)(v2 + 28) == 2 && *(_BYTE *)(*(_QWORD *)(v2 + 32) + 384LL) == 1 )
  {
    v4 = &unk_99D0;
    if ( (byte_99E0 & 1) != 0
      || (v4 = &unk_9A60, (byte_9A70 & 1) != 0)
      || (v4 = &unk_9AF0, (byte_9B00 & 1) != 0)
      || (v4 = &unk_9B80, (byte_9B90 & 1) != 0) )
    {
      v6 = v4[7];
      v5 = v4[8];
    }
    else
    {
      v6 = 0;
      v5 = 0;
    }
  }
  else
  {
    v6 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 76));
    v5 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 80));
  }
  v7 = *(_DWORD *)(a1 + 64);
  if ( v7 > 4 )
  {
LABEL_29:
    __break(0x5512u);
    __break(1u);
    JUMPOUT(0x167064);
  }
  v8 = &info[36 * v7];
  v9 = v8[18];
  if ( v9 == 2 )
  {
    v10 = &info[36 * v7];
    *v8 = 2;
    v10[7] = v6;
    v10[8] = v5;
    sde_reg_write(
      a1,
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 52),
      (unsigned int)v10[21],
      "dspp->cap->sblk->ad.base + blk_offset");
    v11 = *(_DWORD *)(a1 + 64);
    if ( v11 > 4 )
      goto LABEL_29;
    sde_reg_write(
      a1,
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 312),
      (unsigned int)info[36 * v11 + 22],
      "dspp->cap->sblk->ad.base + blk_offset");
    v12 = *(_DWORD *)(a1 + 64);
    if ( v12 > 4 )
      goto LABEL_29;
    v13 = *(_QWORD *)&info[36 * v12 + 12];
    if ( v13 != -1 )
    {
      sde_reg_write(
        a1,
        (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 40),
        v13,
        "dspp->cap->sblk->ad.base + 0x28");
      v12 = *(_DWORD *)(a1 + 64);
      if ( v12 > 4 )
        goto LABEL_29;
      v14 = &info[36 * v12];
      *((_QWORD *)v14 + 5) = *((_QWORD *)v14 + 6);
      *((_QWORD *)v14 + 6) = -1;
    }
    v15 = *(_QWORD *)&info[36 * v12 + 16];
    if ( v15 != -1 )
    {
      sde_reg_write(
        a1,
        (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 44),
        v15,
        "dspp->cap->sblk->ad.base + 0x2c");
      v12 = *(_DWORD *)(a1 + 64);
      if ( v12 > 4 )
        goto LABEL_29;
      v16 = &info[36 * v12];
      *((_QWORD *)v16 + 7) = *((_QWORD *)v16 + 8);
      *((_QWORD *)v16 + 8) = -1;
    }
    v17 = (unsigned int)info[36 * v12 + 6];
    if ( (_DWORD)v17 != 255 )
    {
      sde_reg_write(
        a1,
        (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 48),
        v17,
        "dspp->cap->sblk->ad.base + 0x30");
      v12 = *(_DWORD *)(a1 + 64);
      if ( v12 > 4 )
        goto LABEL_29;
      v18 = &info[36 * v12];
      v18[5] = v18[6];
      v18[6] = 255;
    }
    v19 = &info[36 * v12];
    v20 = v19[29];
    if ( v20 != -1 )
    {
      sde_reg_write(
        a1,
        (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 24),
        *((unsigned __int16 *)v19 + 60) | (unsigned int)(v20 << 16),
        "dspp->cap->sblk->ad.base + blk_offset");
      v21 = *(_DWORD *)(a1 + 64);
      if ( v21 <= 4 )
      {
        sde_reg_write(
          a1,
          (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 28),
          (unsigned int)LOWORD(info[36 * v21 + 32]) | (info[36 * v21 + 31] << 16),
          "dspp->cap->sblk->ad.base + blk_offset");
        if ( *(_DWORD *)(a1 + 64) <= 4u )
          JUMPOUT(0x166FEC);
      }
      goto LABEL_29;
    }
  }
  else
  {
    v8[18] = v9 + 1;
  }
  return 0;
}
