__int64 __fastcall sde_setup_dspp_ltm_hist_ctrlv1_2(__int64 a1, _DWORD *a2, char a3, __int64 a4)
{
  int v8; // w21
  unsigned int v9; // w8
  unsigned int v10; // w11
  bool v11; // cf
  unsigned int v12; // w11
  unsigned int v13; // w10
  unsigned int v14; // w12
  char v15; // w14
  unsigned int v16; // w10
  int v17; // w9
  __int64 result; // x0
  __int64 v19; // [xsp+0h] [xbp-30h] BYREF
  __int64 v20; // [xsp+8h] [xbp-28h]
  __int64 v21; // [xsp+10h] [xbp-20h]
  __int64 v22; // [xsp+18h] [xbp-18h]
  int v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( a1 )
  {
    if ( (a3 & 1) == 0 || a2 && a4 )
    {
      v8 = sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 4));
      if ( (a3 & 1) != 0 )
      {
        v10 = a2[10];
        v9 = a2[11];
        v23 = 0;
        v11 = v9 >= v10;
        v12 = v10 - 1;
        if ( v11 )
          v13 = 117440512;
        else
          v13 = 50331648;
        if ( v11 )
          v14 = 50331648;
        else
          v14 = 117440512;
        v15 = !v11;
        v16 = v13 / (v9 - 1);
        v17 = a2[7];
        LOBYTE(v23) = v15;
        BYTE1(v23) = v17 != 1;
        v19 = 0x80000000000000LL;
        v20 = 0x80000000800000LL;
        v21 = 0x80000000800000LL;
        LODWORD(v22) = v16;
        HIDWORD(v22) = v14 / v12;
        if ( v17 != 1 )
        {
          LODWORD(v20) = v16 * (v9 >> 1) + 0x800000;
          LODWORD(v21) = v20;
        }
        sde_reg_write(
          a1,
          (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 24),
          v17 != 1,
          "offset");
        result = sde_setup_dspp_ltm_hist_ctrl_common(a1, a4, v8, (__int64)&v19);
      }
      else
      {
        result = sde_reg_write(
                   a1,
                   (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 380LL) + 4),
                   v8 & (v8 << 30 >> 31) & 0x1FFFFFE,
                   "ctx->cap->sblk->ltm.base + 0x4");
      }
    }
    else
    {
      result = _drm_err("invalid addr 0x%llx cfg %pK\n", a4, a2);
    }
  }
  else
  {
    result = _drm_err("invalid parameters ctx %pK\n", nullptr);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
