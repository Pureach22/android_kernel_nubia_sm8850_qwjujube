__int64 __fastcall gen7_hwsched_warmboot_init_gmu(__int64 a1)
{
  __int64 v2; // x20
  char v3; // w9
  __int64 v4; // x8
  int v5; // w9
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w8
  unsigned int v9; // w22
  __int64 v10; // x20
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v26; // x9
  int v27[5]; // [xsp+4h] [xbp-9Ch] BYREF
  _QWORD v28[17]; // [xsp+18h] [xbp-88h] BYREF

  v28[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = to_gen7_gmu(a1);
  v3 = *(_BYTE *)(a1 + 8284);
  v4 = *(_QWORD *)(v2 + 24);
  memset(v28, 0, 128);
  v27[1] = 0;
  if ( (v3 & 1) != 0 )
  {
    v5 = *(_DWORD *)(v4 + 184);
    v6 = *(_QWORD *)(v4 + 40);
    v27[3] = v5;
    v27[4] = v6;
    v27[2] = 1;
    v27[0] = 154;
    LODWORD(result) = gen7_hfi_send_generic_req_v5(a1, v27, (int *)v28, 0x14u);
    if ( (_DWORD)result )
      goto LABEL_5;
  }
  v8 = *(_DWORD *)(a1 + 24552) | 1;
  *(_DWORD *)(a1 + 24552) = v8;
  gmu_core_regwrite(a1, 129427, (unsigned int)~v8);
  _X8 = (unsigned __int64 *)(v2 + 1096);
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 | 4, _X8) );
  result = kgsl_pwrctrl_setup_default_votes(a1);
  if ( (_DWORD)result )
  {
LABEL_5:
    _X8 = (unsigned __int64 *)(v2 + 1096);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
    _X8 = (unsigned __int64 *)(v2 + 1096);
    __asm { PRFM            #0x11, [X8] }
    do
      v16 = __ldxr(_X8);
    while ( __stxr(v16 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
    v9 = result;
    v10 = to_gen7_gmu(a1);
    *(_DWORD *)(a1 + 24552) &= ~1u;
    gen7_hwsched_process_msgq(a1);
    gen7_hwsched_process_dbgq(a1, 0);
    kgsl_pwrctrl_axi(a1, 0);
    _X8 = (unsigned __int64 *)(v10 + 1096);
    __asm { PRFM            #0x11, [X8] }
    do
      v19 = __ldxr(_X8);
    while ( __stxr(v19 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    result = v9;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
