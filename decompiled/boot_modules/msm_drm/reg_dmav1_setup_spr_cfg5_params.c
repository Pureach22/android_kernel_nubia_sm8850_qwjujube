__int64 __fastcall reg_dmav1_setup_spr_cfg5_params(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w23
  int v9; // w24
  unsigned int v10; // w25
  char v11; // w8
  int v12; // w1
  unsigned int v13; // w25
  __int64 result; // x0
  int v15; // w8
  int v16; // w25
  int v17; // w9
  int v18; // w25
  int v19; // w1
  int v20; // w22
  int v21; // w8
  unsigned int v22; // w22
  __int64 (__fastcall *v23)(_QWORD); // x8
  int v24; // w0
  unsigned int v25; // w19
  unsigned int v26; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_WORD *)(a2 + 292) )
  {
    v6 = *(_DWORD *)(a1 + 8);
    v9 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 416LL);
    v10 = ((*(_BYTE *)(a2 + 294) & 7) << 16) & 0xFF8FFFFF | ((*(_BYTE *)(a2 + 295) & 7) << 20);
    v11 = *(_BYTE *)(a2 + 296);
    v12 = *(unsigned __int8 *)(a2 + 297);
    v13 = v10 & 0xF8FFFFFF | ((v11 & 7) << 24);
    if ( v12 )
    {
      if ( v12 == 4 )
      {
        v12 = 2;
      }
      else if ( v12 == 2 )
      {
        v12 = 1;
      }
      else
      {
        _drm_err("Invalid payload for cfg18. Val %u\n", v12);
        v12 = 0;
      }
    }
    v15 = *(unsigned __int8 *)(a2 + 298);
    v16 = v13 | v12;
    if ( *(_BYTE *)(a2 + 298) )
    {
      if ( v15 == 2 )
      {
        v15 = 16;
      }
      else if ( v15 == 4 )
      {
        v15 = 32;
      }
      else
      {
        _drm_err("Invalid payload for cfg18. Val %u\n", *(unsigned __int8 *)(a2 + 298));
        v15 = 0;
      }
    }
    v17 = *(unsigned __int8 *)(a2 + 299);
    v18 = v16 | v15;
    if ( *(_BYTE *)(a2 + 299) )
    {
      if ( v17 == 2 )
      {
        v17 = 256;
      }
      else if ( v17 == 4 )
      {
        v17 = 512;
      }
      else
      {
        _drm_err("Invalid payload for cfg18. Val %u\n", v17);
        v17 = 0;
      }
    }
    v19 = *(unsigned __int8 *)(a2 + 300);
    v20 = v18 | v17;
    if ( v19 )
    {
      if ( v19 == 2 )
      {
        v19 = 4096;
      }
      else if ( v19 == 4 )
      {
        v19 = 0x2000;
      }
      else
      {
        _drm_err("Invalid payload for cfg18. Val %u\n", v19);
        v19 = 0;
      }
    }
    v21 = *(_DWORD *)(a1 + 28);
    v22 = v20 | v19;
    v26 = v22;
    if ( v21 )
    {
      *(_QWORD *)(a3 + 12) = 0;
      *(_DWORD *)a3 = 1;
      *(_DWORD *)(a3 + 20) = v6 + v9 + 124;
      *(_QWORD *)(a3 + 32) = &v26;
      *(_QWORD *)(a3 + 40) = 0x400000000LL;
      v23 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
      if ( *((_DWORD *)v23 - 1) != -1839634494 )
        __break(0x8228u);
      v24 = v23(a3);
      if ( v24 )
      {
        v25 = v24;
        _drm_err("spr write cfg_18 failed ret %d\n", v24);
        result = v25;
        goto LABEL_35;
      }
      v22 = v26;
    }
    else
    {
      sde_reg_write(
        a1,
        (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 416LL) + 124),
        v22,
        "ctx->cap->sblk->spr.base + 0x7C");
    }
    result = 0;
    *(_DWORD *)(a1 + 84) = v22;
    goto LABEL_35;
  }
  result = 0;
  *(_DWORD *)(a1 + 84) = 0;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
