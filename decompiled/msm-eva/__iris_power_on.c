__int64 __fastcall _iris_power_on(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  int v5; // w21
  __int64 v7; // x0
  __int64 v8; // x20
  unsigned int v9; // w20
  void *v10; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  unsigned __int64 v13; // x20
  unsigned __int64 v14; // x26
  unsigned int v15; // w28
  __int64 v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x9
  unsigned int v18; // w20
  __int64 (__fastcall *v19)(_QWORD); // x8
  int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x3
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned int tcsr_register; // w0
  __int64 v26; // x2
  __int64 v27; // x3
  __int64 v28; // x23
  __int64 v29; // x8
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 v31; // x8
  unsigned int (__fastcall *v32)(_QWORD); // x9
  unsigned __int64 v33; // x8
  __int64 v34; // x1
  __int64 v35; // x2
  void *v36; // x0
  unsigned int (__fastcall *v37)(_QWORD); // x9
  unsigned __int64 v38; // x8
  __int64 v39; // x8
  void (__fastcall *v40)(_QWORD); // x8
  void (__fastcall *v41)(_QWORD); // x8
  unsigned int *v42; // x8
  int v43; // w8
  unsigned __int64 v44; // x8

  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
    return 0;
  v5 = *(_DWORD *)(a1 + 64);
  if ( v5 )
  {
    v7 = *(_QWORD *)(a1 + 56);
    if ( !v7 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_39;
      v9 = -22;
      v10 = &unk_824E5;
      StatusReg = _ReadStatusReg(SP_EL0);
LABEL_93:
      printk(v10, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v9;
LABEL_39:
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_80;
      v24 = _ReadStatusReg(SP_EL0);
      v18 = result;
      printk(&unk_8BAC1, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), &unk_8E7CE);
LABEL_79:
      result = v18;
LABEL_80:
      *(_BYTE *)(a1 + 72) = 0;
      return result;
    }
    v8 = kmemdup_noprof(v7, 20LL * v5, 3264);
    if ( !v8 )
    {
      result = 4294967284LL;
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_39;
      v9 = -12;
      v10 = &unk_8BB26;
      StatusReg = _ReadStatusReg(SP_EL0);
      goto LABEL_93;
    }
  }
  else
  {
    v8 = 0;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_94D84, &unk_8DA84, a3, a4);
      v8 = 0;
    }
  }
  kfree(*(_QWORD *)(a1 + 56));
  v12 = *(_QWORD *)(a1 + 2208);
  *(_QWORD *)(a1 + 56) = v8;
  *(_DWORD *)(a1 + 64) = v5;
  v13 = *(_QWORD *)(v12 + 296);
  if ( v13 >= v13 + 120LL * *(unsigned int *)(v12 + 304) )
    goto LABEL_23;
  result = 0;
  v14 = _ReadStatusReg(SP_EL0);
  do
  {
    while ( 1 )
    {
      if ( !v13 )
        goto LABEL_14;
      result = cvp_set_bw(v13, *(unsigned int *)(v13 + 12));
      if ( (_DWORD)result )
        break;
      v13 += 120LL;
      if ( v13 >= *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 296LL)
                + 120 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 304LL) )
        goto LABEL_23;
    }
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v15 = result;
      printk(&unk_84DBF, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
      result = v15;
    }
LABEL_14:
    v13 += 120LL;
  }
  while ( v13 < *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 296LL)
              + 120 * (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 2208) + 304LL) );
  if ( (_DWORD)result )
    goto LABEL_39;
LABEL_23:
  v16 = *(_QWORD *)(a1 + 2512);
  if ( !v16 )
    goto LABEL_33;
  v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 32);
  if ( !v17 )
  {
LABEL_29:
    v19 = *(__int64 (__fastcall **)(_QWORD))(v16 + 40);
    if ( !v19 )
      goto LABEL_33;
    if ( *((_DWORD *)v19 - 1) != -1303076162 )
      __break(0x8228u);
    v20 = v19(a1);
    if ( !v20 )
      goto LABEL_33;
    goto LABEL_72;
  }
  if ( *((_DWORD *)v17 - 1) != -1303076162 )
    __break(0x8229u);
  v18 = v17(a1);
  if ( v18 )
    goto LABEL_78;
  v16 = *(_QWORD *)(a1 + 2512);
  if ( v16 )
    goto LABEL_29;
LABEL_33:
  if ( (unsigned int)msm_cvp_scale_clocks(a1) )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v23 = _ReadStatusReg(SP_EL0);
      printk(&unk_84D7D, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), "warn");
    }
  }
  else if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_92148, &unk_8DA84, v21, v22);
  }
  *(_BYTE *)(a1 + 72) = 1;
  _write_register(a1, 0xD0240u, 1u);
  _write_register(a1, 0xD0008u, 3u);
  tcsr_register = _read_tcsr_register(a1, 0x88000u);
  _write_register(a1, 0xA006Cu, tcsr_register);
  v28 = *(_QWORD *)(cvp_driver + 48);
  if ( v28 )
  {
    _write_register(a1, 0xB0078u, *(_DWORD *)(v28 + 1244));
    if ( *(_DWORD *)(v28 + 1244) == 0x20000 )
      _write_register(a1, 0xF9F24u, 1u);
  }
  v29 = *(_QWORD *)(a1 + 2512);
  if ( v29 )
  {
    v30 = *(__int64 (__fastcall **)(_QWORD))(v29 + 80);
    if ( v30 )
    {
      if ( *((_DWORD *)v30 - 1) != -1303076162 )
        __break(0x8228u);
      v20 = v30(a1);
      if ( v20 )
        goto LABEL_72;
    }
  }
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_8DAC8, "core", v26, v27);
    v31 = *(_QWORD *)(a1 + 2512);
    if ( !v31 )
      goto LABEL_87;
LABEL_56:
    v32 = *(unsigned int (__fastcall **)(_QWORD))(v31 + 64);
    if ( v32 )
    {
      if ( *((_DWORD *)v32 - 1) != -1303076162 )
        __break(0x8229u);
      if ( v32(a1) )
      {
        v20 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v33 = _ReadStatusReg(SP_EL0);
          v34 = *(unsigned int *)(v33 + 1800);
          v35 = *(unsigned int *)(v33 + 1804);
          v36 = &unk_96E09;
LABEL_71:
          printk(v36, v34, v35, &unk_8E7CE);
          v20 = -22;
          goto LABEL_72;
        }
        goto LABEL_72;
      }
      v31 = *(_QWORD *)(a1 + 2512);
      if ( !v31 )
        goto LABEL_87;
    }
    v37 = *(unsigned int (__fastcall **)(_QWORD))(v31 + 56);
    if ( v37 )
    {
      if ( *((_DWORD *)v37 - 1) != -1303076162 )
        __break(0x8229u);
      if ( v37(a1) )
      {
        v20 = -22;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v38 = _ReadStatusReg(SP_EL0);
          v34 = *(unsigned int *)(v38 + 1800);
          v35 = *(unsigned int *)(v38 + 1804);
          v36 = &unk_8A666;
          goto LABEL_71;
        }
LABEL_72:
        v39 = *(_QWORD *)(a1 + 2512);
        if ( v39 )
        {
          v40 = *(void (__fastcall **)(_QWORD))(v39 + 16);
          v18 = v20;
          if ( v40 )
          {
            if ( *((_DWORD *)v40 - 1) != -1303076162 )
              __break(0x8228u);
            v40(a1);
          }
        }
        else
        {
          v18 = v20;
        }
LABEL_78:
        _unvote_buses(a1);
        goto LABEL_79;
      }
      v31 = *(_QWORD *)(a1 + 2512);
      if ( !v31 )
        goto LABEL_87;
    }
    v41 = *(void (__fastcall **)(_QWORD))v31;
    if ( v41 )
    {
      if ( *((_DWORD *)v41 - 1) != -639316779 )
        __break(0x8228u);
      v41(a1);
    }
    goto LABEL_87;
  }
  v31 = *(_QWORD *)(a1 + 2512);
  if ( v31 )
    goto LABEL_56;
LABEL_87:
  if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    printk(&unk_8BAF8, "core", v26, v27);
  v42 = *(unsigned int **)(a1 + 2168);
  *(_DWORD *)(a1 + 20) = 0;
  enable_irq(*v42);
  _write_register(a1, 0xB0054u, 7u);
  v43 = __ratelimit(&_iris_power_on__rs, "__iris_power_on");
  result = 0;
  if ( v43 )
  {
    v44 = _ReadStatusReg(SP_EL0);
    printk(&unk_8C51B, *(unsigned int *)(v44 + 1800), *(unsigned int *)(v44 + 1804), &unk_8DA84);
    return 0;
  }
  return result;
}
