__int64 __fastcall ad4_mode_setup(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w20
  unsigned int v4; // w8
  unsigned int v5; // w8
  int *v6; // x8
  int v7; // w9
  __int64 v8; // x8
  _DWORD *v9; // x8

  v2 = result;
  if ( !(_DWORD)a2 )
  {
    result = sde_reg_write(
               result,
               (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 344LL) + 4),
               257,
               "dspp->cap->sblk->ad.base + blk_offset");
    v8 = *(unsigned int *)(v2 + 64);
    if ( (unsigned int)v8 < 5 )
    {
      info[36 * v8] = 0;
      if ( ((16 * ((9 * v8) & 0xFFFFFFFFFLL)) | 4uLL) <= 0x2D0 )
      {
        v9 = &info[36 * (unsigned int)v8];
        *(_QWORD *)(v9 + 5) = 0xFF00000080LL;
        *((_QWORD *)v9 + 7) = 0xFFFF;
        *((_QWORD *)v9 + 8) = -1;
        *(_QWORD *)(v9 + 23) = 0xFFFF00000000LL;
        *(_QWORD *)(v9 + 25) = 0xFFFF00000000LL;
        v9[1] = 0;
        *((_QWORD *)v9 + 5) = 0;
        *((_QWORD *)v9 + 6) = -1;
        *(_QWORD *)(v9 + 27) = 0x40000000400LL;
        *(_QWORD *)(v9 + 29) = -1;
        *(_QWORD *)(v9 + 31) = -1;
        *(_QWORD *)(v9 + 33) = -1;
        return result;
      }
      goto LABEL_17;
    }
    goto LABEL_16;
  }
  v3 = a2;
  if ( (_DWORD)a2 != 3 )
    goto LABEL_5;
  result = sde_reg_write(
             result,
             (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 72) + 48LL) + 344LL) + 312),
             0,
             "dspp->cap->sblk->ad.base + blk_offset");
  v4 = *(_DWORD *)(v2 + 64);
  if ( v4 > 4 )
  {
LABEL_16:
    __break(0x5512u);
LABEL_17:
    __break(1u);
    return ad4_roi_coordinate_offset(result, a2);
  }
  result = sde_reg_write(
             v2,
             (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 48LL) + 344LL) + 316),
             (unsigned int)info[36 * v4 + 20],
             "dspp->cap->sblk->ad.base + blk_offset");
LABEL_5:
  v5 = *(_DWORD *)(v2 + 64);
  if ( v5 > 4 )
    goto LABEL_16;
  v6 = &info[36 * v5];
  if ( !*v6 )
  {
    if ( v3 == 3 )
    {
      v7 = 5;
    }
    else
    {
      v7 = 1;
      v6[18] = 0;
    }
    *v6 = v7;
  }
  return sde_reg_write(
           v2,
           (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 48LL) + 344LL) + 4),
           256,
           "dspp->cap->sblk->ad.base + blk_offset");
}
