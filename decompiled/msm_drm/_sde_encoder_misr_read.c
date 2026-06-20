__int64 __fastcall sde_encoder_misr_read(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v8; // x1
  __int64 result; // x0
  _DWORD *v10; // x19
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x23
  unsigned int v14; // w8
  unsigned int v15; // w8
  void *v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned int disp_op; // w26
  __int64 v20; // x25
  int v21; // w0
  unsigned int (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w0
  unsigned int v24; // w24
  unsigned int v25; // w23
  unsigned int v26; // w23
  unsigned int v27; // w23
  unsigned int v28; // w0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x28
  __int64 v33; // x25
  _DWORD *v34; // x8
  unsigned int v35; // w24
  void *v36; // x0
  __int64 v37; // x0
  __int64 v38; // x22
  __int64 v39; // x8
  __int64 v40; // x19
  unsigned int v41; // w8
  int v42; // w24
  unsigned int v49; // w10
  int v50; // w7
  char v51; // [xsp+0h] [xbp-120h]
  int v52; // [xsp+4h] [xbp-11Ch]
  int v53; // [xsp+8h] [xbp-118h] BYREF
  _BYTE s[257]; // [xsp+Fh] [xbp-111h] BYREF
  __int64 v55; // [xsp+110h] [xbp-10h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( *a4 )
  {
    result = 0;
    goto LABEL_19;
  }
  if ( !a1 || (v10 = *(_DWORD **)(a1 + 32)) == nullptr )
  {
    result = -22;
    goto LABEL_19;
  }
  v11 = *(_QWORD *)v10;
  if ( !*(_QWORD *)v10 )
  {
    v16 = &unk_26FCAB;
    goto LABEL_71;
  }
  v12 = *(_QWORD *)(v11 + 56);
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 8)) == 0 )
  {
    v16 = &unk_234896;
LABEL_71:
    printk(v16, "sde_encoder_get_kms");
    result = -22;
    goto LABEL_19;
  }
  if ( !*(_QWORD *)(v13 + 152) )
    goto LABEL_22;
  mutex_lock(v13 + 3696);
  if ( (*(_QWORD *)(*(_QWORD *)(v13 + 152) + 22008LL) & 0x400000000LL) != 0
    && *(_DWORD *)(v13 + 3664) == 1
    && (v14 = *(_DWORD *)(v13 + 3656), v14 <= 6)
    && ((1 << v14) & 0x64) != 0
    || (v15 = *(_DWORD *)(v13 + 3656), v15 <= 4) && ((1 << v15) & 0x1A) != 0 )
  {
    mutex_unlock(v13 + 3696);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d misr read not allowed\n", v10[6]);
    result = -524;
    goto LABEL_19;
  }
  mutex_unlock(v13 + 3696);
  v11 = *(_QWORD *)v10;
  if ( !*(_QWORD *)v10 )
  {
    v36 = &unk_26FCAB;
  }
  else
  {
LABEL_22:
    v17 = *(_QWORD *)(v11 + 56);
    if ( v17 )
    {
      v18 = *(_QWORD *)(v17 + 8);
      if ( v18 )
      {
        disp_op = sde_kms_get_disp_op(v18, v8);
        goto LABEL_25;
      }
    }
    v36 = &unk_234896;
  }
  printk(v36, "sde_encoder_get_kms");
  disp_op = 0;
LABEL_25:
  v52 = v10[200];
  if ( !v52 )
  {
LABEL_46:
    v28 = scnprintf(s, 256, "disabled\n");
LABEL_47:
    v24 = v28;
    goto LABEL_79;
  }
  v20 = *(_QWORD *)(*(_QWORD *)v10 + 8LL);
  v21 = _pm_runtime_resume(v20, 4);
  if ( (v21 & 0x80000000) == 0 )
  {
    if ( disp_op > 2 )
      goto LABEL_105;
    v22 = *(unsigned int (__fastcall **)(_QWORD))&v10[2 * disp_op + 1330];
    if ( v22 )
    {
      if ( *((_DWORD *)v22 - 1) != 17023570 )
        __break(0x8228u);
      if ( v22(v10) )
      {
        printk(&unk_25E465, "_sde_encoder_misr_read");
        v28 = scnprintf(s, 256, "invalid\n");
        goto LABEL_47;
      }
      if ( !v10[204] )
      {
        result = 0;
        if ( !a3 )
          goto LABEL_87;
        goto LABEL_81;
      }
      v23 = scnprintf(s, 256, "Intf idx:%d\n", 0);
      if ( v23 < 0x102 )
      {
        v24 = scnprintf(&s[v23], (int)(256 - v23), "0x%x\n", v10[205]) + v23;
        if ( v10[204] < 2u )
          goto LABEL_79;
        if ( v24 > 0x101 )
          goto LABEL_105;
        v25 = scnprintf(&s[v24], (int)(256 - v24), "Intf idx:%d\n", 1) + v24;
        if ( v25 > 0x101 )
          goto LABEL_105;
        v24 = scnprintf(&s[v25], (int)(256 - v25), "0x%x\n", v10[206]) + v25;
        if ( v10[204] < 3u )
          goto LABEL_79;
        if ( v24 > 0x101 )
          goto LABEL_105;
        v26 = scnprintf(&s[v24], (int)(256 - v24), "Intf idx:%d\n", 2) + v24;
        if ( v26 > 0x101 )
          goto LABEL_105;
        v24 = scnprintf(&s[v26], (int)(256 - v26), "0x%x\n", v10[207]) + v26;
        if ( v10[204] < 4u )
          goto LABEL_79;
        if ( v24 > 0x101 )
          goto LABEL_105;
        v27 = scnprintf(&s[v24], (int)(256 - v24), "Intf idx:%d\n", 3) + v24;
        if ( v27 > 0x101 )
          goto LABEL_105;
        v24 = scnprintf(&s[v27], (int)(256 - v27), "0x%x\n", v10[208]) + v27;
        if ( v10[204] < 5u )
        {
LABEL_79:
          result = (int)v24;
          if ( (int)v24 >= a3 )
          {
            result = 0;
            if ( !v52 )
              goto LABEL_19;
            goto LABEL_87;
          }
          if ( v24 >= 0x102 )
          {
            _copy_overflow(257, (int)v24);
LABEL_82:
            result = -14;
            if ( !v52 )
              goto LABEL_19;
            goto LABEL_87;
          }
LABEL_81:
          v38 = result;
          _check_object_size(s, result, 1);
          if ( inline_copy_to_user_2(a2, s, v38) )
            goto LABEL_82;
          result = v38;
          *a4 += v38;
          if ( !v52 )
            goto LABEL_19;
LABEL_87:
          v39 = *(_QWORD *)v10;
          v40 = result;
          _pm_runtime_idle(*(_QWORD *)(v39 + 8), 4);
          result = v40;
          goto LABEL_19;
        }
        if ( v24 <= 0x101 )
        {
          scnprintf(&s[v24], (int)(256 - v24), "Intf idx:%d\n", 4);
          __break(0x5512u);
          goto LABEL_46;
        }
      }
    }
    else
    {
      v29 = *(_QWORD *)(v13 + 6384);
      if ( v29 )
      {
        mutex_lock(v29);
        v30 = *(_QWORD *)(v13 + 6384);
        if ( v30 )
        {
          v31 = *(__int64 (__fastcall **)(_QWORD))(v30 + 88);
          if ( v31 )
          {
            if ( *((_DWORD *)v31 - 1) != 1370937740 )
              __break(0x8228u);
            if ( (v31(v13) & 1) == 0 )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "op not supported due to HW unavailablity\n");
              result = *(_QWORD *)(v13 + 6384);
              if ( result )
              {
                mutex_unlock(result);
                result = 0;
              }
              goto LABEL_87;
            }
          }
        }
      }
      if ( !v10[49] )
      {
        v24 = 0;
LABEL_77:
        v37 = *(_QWORD *)(v13 + 6384);
        if ( v37 )
          mutex_unlock(v37);
        goto LABEL_79;
      }
      v32 = 0;
      v24 = 0;
      while ( v32 != 4 )
      {
        v33 = *(_QWORD *)&v10[2 * v32 + 50];
        v53 = 0;
        if ( v33 && (v34 = *(_DWORD **)(v33 + 208)) != nullptr )
        {
          if ( *(v34 - 1) != 1336452942 )
            __break(0x8228u);
          if ( ((unsigned int (__fastcall *)(__int64, _QWORD, int *))v34)(v33, 0, &v53) )
          {
            if ( v24 > 0x101 )
              break;
            v24 += scnprintf(&s[v24], (int)(256 - v24), "invalid\n");
            printk(&unk_21D72E, "_sde_encoder_misr_read");
          }
          else
          {
            if ( v24 > 0x101 )
              break;
            v35 = scnprintf(&s[v24], (int)(256 - v24), "Intf idx:%d\n", *(_DWORD *)(v33 + 672) - 1) + v24;
            if ( v35 > 0x101 )
              break;
            v24 = scnprintf(&s[v35], (int)(256 - v35), "0x%x\n", v53) + v35;
          }
        }
        else
        {
          if ( v24 > 0x101 )
            break;
          v24 += scnprintf(&s[v24], (int)(256 - v24), "invalid\n");
          printk(&unk_27A219, "_sde_encoder_misr_read");
        }
        if ( ++v32 >= (unsigned __int64)(unsigned int)v10[49] )
          goto LABEL_77;
      }
    }
LABEL_105:
    __break(0x5512u);
  }
  v41 = *(_DWORD *)(v20 + 480);
  v42 = v21;
  do
  {
    if ( !v41 )
      break;
    _X12 = (unsigned int *)(v20 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v49 = __ldxr(_X12);
      if ( v49 != v41 )
        break;
      if ( !__stlxr(v41 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v49 == v41;
    v41 = v49;
  }
  while ( !_ZF );
  printk(&unk_24C43E, "_sde_encoder_misr_read");
  sde_evtlog_log(sde_dbg_base_evtlog, "_sde_encoder_misr_read", 7865, -1, v42, 60333, -1059143953, v50, v51);
  result = v42;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
