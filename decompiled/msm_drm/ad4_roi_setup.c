__int64 __fastcall ad4_roi_setup(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  unsigned int v5; // w8
  _DWORD *v6; // x8
  int v7; // w9
  __int64 v8; // x10
  __int64 v9; // x11
  unsigned int v10; // w8
  unsigned int v11; // w8
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 8);
  v13 = 0;
  v14 = 0;
  v12 = 0;
  if ( (unsigned int)ad4_roi_coordinate_offset(v3, &v12) )
  {
    _drm_err("params invalid\n");
    result = 4294967274LL;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 64);
    if ( v5 >= 5 )
      goto LABEL_8;
    v6 = &info[36 * v5];
    v7 = v12;
    v8 = v13;
    v9 = v14;
    *(_QWORD *)(v6 + 23) = v12;
    *(_QWORD *)(v6 + 25) = v8;
    *(_QWORD *)(v6 + 27) = v9;
    sde_reg_write(
      a1,
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 24),
      *((unsigned __int16 *)v6 + 48) | (unsigned int)(v7 << 16),
      "dspp->cap->sblk->ad.base + blk_offset");
    v10 = *(_DWORD *)(a1 + 64);
    if ( v10 > 4
      || (sde_reg_write(
            a1,
            (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 28),
            (unsigned int)LOWORD(info[36 * v10 + 26]) | (info[36 * v10 + 25] << 16),
            "dspp->cap->sblk->ad.base + blk_offset"),
          v11 = *(_DWORD *)(a1 + 64),
          v11 > 4) )
    {
LABEL_8:
      __break(0x5512u);
    }
    sde_reg_write(
      a1,
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 64),
      (unsigned int)LOWORD(info[36 * v11 + 28]) | (info[36 * v11 + 27] << 16),
      "dspp->cap->sblk->ad.base + blk_offset");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
