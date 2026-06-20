__int64 __fastcall sde_encoder_perf_uidle_status(__int64 result, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x20
  unsigned int disp_op; // w0
  _DWORD *v6; // x8
  unsigned int v7; // w0
  _DWORD *v8; // x8
  unsigned int v9; // w0
  _DWORD *v10; // x8
  _QWORD v11[9]; // [xsp+20h] [xbp-70h] BYREF
  _QWORD v12[3]; // [xsp+68h] [xbp-28h] BYREF
  int v13; // [xsp+80h] [xbp-10h]
  __int64 v14; // [xsp+88h] [xbp-8h]

  v3 = result;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  memset(v12, 0, sizeof(v12));
  memset(v11, 0, sizeof(v11));
  if ( !result || !a2 || (v4 = *(_QWORD *)(result + 3536)) == 0 )
  {
    result = printk(&unk_27D639, "sde_encoder_perf_uidle_status");
    goto LABEL_27;
  }
  if ( *(_BYTE *)(*(_QWORD *)(result + 152) + 21985LL) == 1 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(result + 152) + 21980LL) & 2) != 0 )
    {
      result = sde_crtc_get_disp_op(a2);
      if ( (unsigned int)result >= 3 )
        goto LABEL_28;
      if ( *(_QWORD *)(v4 + 136 + 8LL * (unsigned int)result) )
      {
        disp_op = sde_crtc_get_disp_op(a2);
        if ( disp_op > 2 )
          goto LABEL_28;
        v6 = *(_DWORD **)(v4 + 136 + 8LL * disp_op);
        if ( *(v6 - 1) != -1924637416 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD *))v6)(v4, v11);
      }
    }
    if ( (*(_BYTE *)(*(_QWORD *)(v3 + 152) + 21980LL) & 2) != 0 )
    {
      result = sde_crtc_get_disp_op(a2);
      if ( (unsigned int)result > 2 )
        goto LABEL_28;
      if ( *(_QWORD *)(v4 + 160 + 8LL * (unsigned int)result) )
      {
        v7 = sde_crtc_get_disp_op(a2);
        if ( v7 > 2 )
          goto LABEL_28;
        v8 = *(_DWORD **)(v4 + 160 + 8LL * v7);
        if ( *(v8 - 1) != -1924637416 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD *))v8)(v4, v11);
      }
    }
    if ( (*(_BYTE *)(*(_QWORD *)(v3 + 152) + 21980LL) & 1) == 0 )
      goto LABEL_27;
    result = sde_crtc_get_disp_op(a2);
    if ( (unsigned int)result <= 2 )
    {
      if ( !*(_QWORD *)(v4 + 112 + 8LL * (unsigned int)result) )
        goto LABEL_27;
      v9 = sde_crtc_get_disp_op(a2);
      if ( v9 <= 2 )
      {
        v10 = *(_DWORD **)(v4 + 112 + 8LL * v9);
        if ( *(v10 - 1) != 945428605 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, _QWORD *))v10)(v4, v12);
        goto LABEL_27;
      }
    }
LABEL_28:
    __break(0x5512u);
  }
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
