__int64 __fastcall dsi_ctrl_cmd_tx_trigger(__int64 a1, int a2)
{
  char v4; // w23
  int v5; // w8
  int v6; // w9
  int v7; // w12
  __int64 result; // x0
  unsigned int v9; // w20
  int v10; // w25
  int v11; // w9
  __int64 v12; // x8
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x8
  unsigned int v20; // w20
  unsigned int v21; // w25
  __int64 (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1
  unsigned int v24; // w0
  __int64 v26; // x8
  void (__fastcall *v27)(_QWORD); // x8
  __int64 v28; // x8
  __int64 (__fastcall *v29)(__int64, __int64); // x8
  __int64 v30; // x1
  unsigned int v31; // w0
  void (__fastcall *v32)(_QWORD); // x8
  int v33; // w6
  int v34; // w7
  size_t v35; // x0
  int v36; // w4
  __int64 v37; // x8
  void (__fastcall *v38)(_QWORD); // x8
  __int64 v39; // x8
  __int64 (__fastcall *v40)(__int64, __int64); // x8
  __int64 v41; // x1
  unsigned int v42; // w0
  int v43; // w6
  int v44; // w7
  size_t v45; // x0
  int v46; // w4
  __int64 v47; // x8
  void (__fastcall *v48)(_QWORD); // x8
  char v49; // [xsp+0h] [xbp-5A0h]
  _QWORD s[178]; // [xsp+10h] [xbp-590h] BYREF

  s[177] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x588u);
  if ( a1 )
  {
    memcpy(s, (const void *)(a1 + 168), 0x588u);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_ctrl_cmd_tx_trigger",
      3815,
      -1,
      *(_DWORD *)(a1 + 8),
      4369,
      a2,
      -1059143953,
      v49);
    v4 = a2;
    if ( (a2 & 0x40) == 0 )
    {
LABEL_62:
      result = 0;
      goto LABEL_63;
    }
    mutex_lock(a1 + 32);
    if ( *(_DWORD *)(a1 + 2440) == 1 )
    {
      v5 = *(_DWORD *)(a1 + 2616);
      v6 = *(_DWORD *)(a1 + 2620) + *(_DWORD *)(a1 + 2624);
      if ( (a2 & 0x100) != 0 )
        v7 = *(_DWORD *)(a1 + 2524);
      else
        v7 = 1;
      v10 = v6 + v5 + v7;
      v9 = (0xF4240u / *(_DWORD *)(a1 + 2636) / (v6 + *(_DWORD *)(a1 + 2628) + v5) + 99)
         / (0xF4240u
          / *(_DWORD *)(a1 + 2636)
          / (v6 + *(_DWORD *)(a1 + 2628) + v5));
      if ( (v4 & 4) == 0 )
        goto LABEL_23;
    }
    else
    {
      v9 = 0;
      v10 = 1;
      if ( (v4 & 4) == 0 )
      {
LABEL_23:
        v26 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v26 < 3 )
        {
          v27 = (void (__fastcall *)(_QWORD))s[v26 + 51];
          if ( v27 )
          {
            if ( *((_DWORD *)v27 - 1) != 1133867105 )
              __break(0x8228u);
            v27(a1 + 96);
          }
          if ( *(_BYTE *)(a1 + 2896) != 1 )
            goto LABEL_61;
          v28 = *(unsigned int *)(a1 + 1608);
          if ( (unsigned int)v28 <= 2 )
          {
            v29 = (__int64 (__fastcall *)(__int64, __int64))s[v28 + 171];
            if ( v29 )
            {
              v30 = *(unsigned __int8 *)(a1 + 2897);
              if ( *((_DWORD *)v29 - 1) != 1825771015 )
                __break(0x8228u);
              v31 = v29(a1 + 96, v30);
            }
            else
            {
              v31 = 0;
            }
            v33 = (unsigned __int16)v31;
            v34 = HIWORD(v31);
            v35 = sde_dbg_base_evtlog;
            v36 = *(_DWORD *)(a1 + 8);
            *(_DWORD *)(a1 + 2900) = v33;
            *(_DWORD *)(a1 + 2904) = v34;
            sde_evtlog_log(v35, "dsi_ctrl_cmd_tx_trigger", 3847, -1, v36, 13107, v33, v34, 239);
            goto LABEL_61;
          }
        }
LABEL_64:
        __break(0x5512u);
        __break(1u);
        JUMPOUT(0x1D56F4);
      }
    }
    if ( (~v4 & 6) != 0 )
    {
LABEL_61:
      mutex_unlock(a1 + 32);
      goto LABEL_62;
    }
    *(_DWORD *)(a1 + 2852) = 0;
    dsi_ctrl_enable_status_interrupt((int *)a1, 0, nullptr);
    v11 = *(_DWORD *)(a1 + 2440);
    v12 = *(unsigned int *)(a1 + 1608);
    *(_DWORD *)(a1 + 2000) = 0;
    if ( v11 == 1 )
    {
      if ( (unsigned int)v12 > 2 )
        goto LABEL_64;
      if ( s[v12 + 129] && *(_DWORD *)(a1 + 1620) == 1 )
      {
        StatusReg = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v19 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v19 > 2 )
          goto LABEL_64;
        v20 = v10 - v9;
        v21 = v10 + 1;
        while ( 1 )
        {
          v22 = (__int64 (__fastcall *)(__int64, __int64))s[v19 + 171];
          v23 = *(unsigned __int8 *)(a1 + 2897);
          if ( *((_DWORD *)v22 - 1) != 1825771015 )
            __break(0x8228u);
          v24 = v22(a1 + 96, v23);
          if ( v24 < v20 || v24 > v21 )
            break;
          _WriteStatusReg(DAIF, StatusReg);
          _const_udelay(4295000);
          StatusReg = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v19 = *(unsigned int *)(a1 + 1608);
          if ( (unsigned int)v19 >= 3 )
            goto LABEL_64;
        }
        v37 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v37 > 2 )
          goto LABEL_64;
        v38 = (void (__fastcall *)(_QWORD))s[v37 + 51];
        if ( *((_DWORD *)v38 - 1) != 1133867105 )
          __break(0x8228u);
        v38(a1 + 96);
        _WriteStatusReg(DAIF, StatusReg);
        goto LABEL_45;
      }
    }
    else if ( (unsigned int)v12 > 2 )
    {
      goto LABEL_64;
    }
    v32 = (void (__fastcall *)(_QWORD))s[v12 + 51];
    if ( v32 )
    {
      if ( *((_DWORD *)v32 - 1) != 1133867105 )
        __break(0x8228u);
      v32(a1 + 96);
    }
LABEL_45:
    if ( *(_BYTE *)(a1 + 2896) == 1 )
    {
      v39 = *(unsigned int *)(a1 + 1608);
      if ( (unsigned int)v39 > 2 )
        goto LABEL_64;
      v40 = (__int64 (__fastcall *)(__int64, __int64))s[v39 + 171];
      if ( v40 )
      {
        v41 = *(unsigned __int8 *)(a1 + 2897);
        if ( *((_DWORD *)v40 - 1) != 1825771015 )
          __break(0x8228u);
        v42 = v40(a1 + 96, v41);
      }
      else
      {
        v42 = 0;
      }
      v43 = (unsigned __int16)v42;
      v44 = HIWORD(v42);
      v45 = sde_dbg_base_evtlog;
      v46 = *(_DWORD *)(a1 + 8);
      *(_DWORD *)(a1 + 2900) = v43;
      *(_DWORD *)(a1 + 2904) = v44;
      sde_evtlog_log(v45, "dsi_ctrl_cmd_tx_trigger", 3900, -1, v46, 13107, v43, v44, 239);
    }
    if ( v4 < 0 )
    {
      if ( *(_DWORD *)(a1 + 88) <= 2u )
      {
        v47 = *(unsigned int *)(a1 + 1608);
        if ( (unsigned int)v47 > 2 )
          goto LABEL_64;
        v48 = (void (__fastcall *)(_QWORD))s[v47 + 33];
        if ( v48 )
        {
          if ( *((_DWORD *)v48 - 1) != 1133867105 )
            __break(0x8228u);
          v48(a1 + 96);
        }
      }
      *(_DWORD *)(a1 + 2784) = 0;
    }
    goto LABEL_61;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
  result = 4294967274LL;
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return result;
}
