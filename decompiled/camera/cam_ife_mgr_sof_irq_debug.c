__int64 __fastcall cam_ife_mgr_sof_irq_debug(__int64 result, int a2)
{
  __int64 v2; // x19
  int v3; // w8
  unsigned __int64 v4; // x26
  int v5; // w20
  __int64 v6; // x27
  _DWORD *v7; // x28
  __int64 v8; // x23
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64, int *, __int64); // x9
  __int64 v11; // x0
  _QWORD *v12; // x19
  _QWORD *v13; // x26
  _QWORD *v14; // t1
  __int64 v15; // x23
  int v16; // w8
  __int64 (__fastcall *v17)(__int64, __int64, __int64 *, __int64); // x8
  __int64 *v18; // x2
  __int64 v19; // x0
  __int64 v20; // x3
  __int64 v21; // x9
  __int64 v22; // x23
  int v23; // w8
  __int64 (__fastcall *v24)(__int64, __int64, __int64 *, __int64); // x8
  __int64 *v25; // x2
  __int64 v26; // x0
  __int64 v27; // x3
  __int64 v28; // x9
  __int64 v29; // [xsp+0h] [xbp-20h] BYREF
  __int64 v30; // [xsp+8h] [xbp-18h]
  int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v2 = result;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(result + 8716);
  v31 = a2;
  if ( v3 )
  {
    v4 = 0;
    v5 = 0;
    v6 = *(_QWORD *)(result + 72) + 96LL;
    v7 = (_DWORD *)(result + 8592);
    while ( v4 != 11 )
    {
      if ( !*v7 )
      {
        v8 = (unsigned int)*(v7 - 2);
        if ( (unsigned int)v8 > 7 )
          break;
        v9 = *(_QWORD *)(v6 + 8 * v8);
        if ( v9 )
        {
          v10 = *(__int64 (__fastcall **)(__int64, __int64, int *, __int64))(v9 + 88);
          v11 = *(_QWORD *)(v9 + 112);
          if ( *((_DWORD *)v10 - 1) != -1055839300 )
            __break(0x8229u);
          result = v10(v11, 47, &v31, 4);
          v5 |= result;
          if ( v5 && (debug_mdl & 8) != 0 && !debug_priority )
            result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       debug_mdl & 8,
                       4,
                       "cam_ife_mgr_sof_irq_debug",
                       15776,
                       "Failed to set CSID_%u sof irq debug cfg rc: %d",
                       v8,
                       v5);
        }
      }
      ++v4;
      v7 += 3;
      if ( v4 >= *(unsigned int *)(v2 + 8716) )
        goto LABEL_15;
    }
    __break(0x5512u);
  }
  v5 = 0;
LABEL_15:
  v14 = *(_QWORD **)(v2 + 224);
  v12 = (_QWORD *)(v2 + 224);
  v13 = v14;
  if ( v14 != v12 )
  {
    while ( 1 )
    {
      v15 = v13[4];
      if ( !v15 || (v16 = *(_DWORD *)(v15 + 4), v16 != 3) && v16 )
      {
LABEL_32:
        v22 = v13[5];
        if ( !v22 )
          goto LABEL_17;
        goto LABEL_33;
      }
      v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v15 + 104);
      if ( v17 )
        break;
      v21 = *(_QWORD *)(v15 + 16);
      v17 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v21 + 88);
      if ( v17 )
      {
        v19 = *(_QWORD *)(v21 + 112);
        v18 = &v29;
        v20 = 16;
        v29 = v13[4];
        v30 = 1;
        if ( *((_DWORD *)v17 - 1) != -1055839300 )
          __break(0x8228u);
        goto LABEL_28;
      }
LABEL_29:
      if ( !v5 || (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_32;
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_mgr_sof_irq_debug",
                 15807,
                 "Failed to set VFE:%u sof irq debug, rc: %d",
                 *(_DWORD *)(*(_QWORD *)(v15 + 16) + 4LL),
                 v5);
      v22 = v13[5];
      if ( !v22 )
        goto LABEL_17;
LABEL_33:
      v23 = *(_DWORD *)(v22 + 4);
      if ( v23 == 3 || !v23 )
      {
        v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v22 + 104);
        if ( v24 )
        {
          v25 = (__int64 *)&v31;
          v26 = v22;
          v27 = 4;
          if ( *((_DWORD *)v24 - 1) != -1380041226 )
            __break(0x8228u);
          goto LABEL_42;
        }
        v28 = *(_QWORD *)(v22 + 16);
        v24 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *, __int64))(v28 + 88);
        if ( v24 )
        {
          v26 = *(_QWORD *)(v28 + 112);
          v25 = &v29;
          v27 = 16;
          v29 = v22;
          v30 = 1;
          if ( *((_DWORD *)v24 - 1) != -1055839300 )
            __break(0x8228u);
LABEL_42:
          result = v24(v26, 18, v25, v27);
          v5 |= result;
        }
        if ( v5 && (debug_mdl & 8) != 0 && !debug_priority )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 8,
                     4,
                     "cam_ife_mgr_sof_irq_debug",
                     15807,
                     "Failed to set VFE:%u sof irq debug, rc: %d",
                     *(_DWORD *)(*(_QWORD *)(v22 + 16) + 4LL),
                     v5);
      }
LABEL_17:
      v13 = (_QWORD *)*v13;
      if ( v13 == v12 )
        goto LABEL_49;
    }
    v18 = (__int64 *)&v31;
    v19 = v13[4];
    v20 = 4;
    if ( *((_DWORD *)v17 - 1) != -1380041226 )
      __break(0x8228u);
LABEL_28:
    result = v17(v19, 18, v18, v20);
    v5 |= result;
    goto LABEL_29;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
