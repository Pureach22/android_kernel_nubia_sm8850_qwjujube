__int64 __fastcall sde_encoder_helper_phys_reset(unsigned __int64 *a1)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8
  unsigned int disp_op; // w0
  _QWORD *v7; // x21
  void (__fastcall *v8)(_QWORD); // x8
  int v9; // w7
  void (__fastcall *v10)(unsigned __int64, int *); // x8
  int v11; // w4
  __int64 result; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 (__fastcall *v14)(_QWORD); // x8
  void *v15; // x0
  __int64 v16; // x0
  char v17; // [xsp+0h] [xbp-50h]
  int v18[2]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v19; // [xsp+10h] [xbp-40h]
  __int64 v20; // [xsp+18h] [xbp-38h]
  __int64 v21; // [xsp+20h] [xbp-30h]
  __int64 v22; // [xsp+28h] [xbp-28h]
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v3 = a1[52];
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  *(_QWORD *)v18 = 0;
  v19 = 0;
  if ( !v2 )
    goto LABEL_7;
  v4 = *(_QWORD *)v2;
  if ( !v4 )
  {
    v15 = &unk_26FCAB;
    goto LABEL_29;
  }
  v5 = *(_QWORD *)(v4 + 56);
  if ( !v5 || !*(_QWORD *)(v5 + 8) )
  {
    v15 = &unk_234896;
LABEL_29:
    printk(v15, "sde_encoder_get_kms");
    v2 = 0;
    goto LABEL_7;
  }
  disp_op = sde_kms_get_disp_op();
  if ( disp_op >= 3 )
  {
    __break(0x5512u);
    v16 = MEMORY[0x7C23A30]();
    return sde_encoder_hw_fence_status(v16);
  }
  v2 = disp_op;
LABEL_7:
  v7 = (_QWORD *)(v3 + 8 * v2);
  v8 = (void (__fastcall *)(_QWORD))v7[116];
  if ( v8 )
  {
    if ( *((_DWORD *)v8 - 1) != 1800103338 )
      __break(0x8228u);
    v8(v3);
  }
  ((void (__fastcall *)(unsigned __int64 *, _QWORD))sde_encoder_helper_reset_mixers)(a1, 0);
  v10 = (void (__fastcall *)(unsigned __int64, int *))v7[89];
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 1851168652 )
      __break(0x8228u);
    v10(v3, v18);
  }
  if ( *a1 )
    v11 = *(_DWORD *)(*a1 + 24);
  else
    v11 = -1;
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "sde_encoder_helper_phys_reset",
             4608,
             -1,
             v11,
             v18[0],
             -1059143953,
             v9,
             v17);
  v13 = (__int64 (__fastcall *)(_QWORD))v7[95];
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != 1800103338 )
      __break(0x8228u);
    result = v13(v3);
  }
  v14 = (__int64 (__fastcall *)(_QWORD))v7[71];
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 1800103338 )
      __break(0x8228u);
    result = v14(v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
