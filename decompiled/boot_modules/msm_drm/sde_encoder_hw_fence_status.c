__int64 __fastcall sde_encoder_hw_fence_status(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v7; // x22
  unsigned int disp_op; // w0
  __int64 v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  unsigned int v12; // w0
  _DWORD *v13; // x8
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15[0] = 0;
  if ( !result || !a3 || (v4 = *(_QWORD *)(result + 3528), v5 = result, !v4) )
  {
    result = printk(&unk_23F31F, "sde_encoder_hw_fence_status");
    goto LABEL_19;
  }
  if ( (*(_BYTE *)(result + 6400) & 1) != 0 )
  {
    result = sde_crtc_get_disp_op(a2);
    if ( (unsigned int)result >= 3 )
      goto LABEL_20;
    if ( *(_QWORD *)(v4 + 8LL * (unsigned int)result + 392) )
    {
      v7 = *(_QWORD *)(v5 + 3528);
      disp_op = sde_crtc_get_disp_op(a2);
      if ( disp_op > 2 )
        goto LABEL_20;
      v9 = v7 + 8LL * disp_op;
      v10 = *(_QWORD *)(v5 + 3528);
      v11 = *(_DWORD **)(v9 + 392);
      if ( *(v11 - 1) != 1653040843 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))v11)(v10, v15, &v14);
    }
  }
  if ( (*(_BYTE *)(v5 + 6400) & 2) == 0 )
    goto LABEL_19;
  result = sde_crtc_get_disp_op(a2);
  if ( (unsigned int)result > 2 )
    goto LABEL_20;
  if ( !*(_QWORD *)(a3 + 400 + 8LL * (unsigned int)result) )
    goto LABEL_19;
  v12 = sde_crtc_get_disp_op(a2);
  if ( v12 > 2 )
LABEL_20:
    __break(0x5512u);
  v13 = *(_DWORD **)(a3 + 400 + 8LL * v12);
  if ( *(v13 - 1) != 752484672 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))v13)(a3, v15, &v14);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
