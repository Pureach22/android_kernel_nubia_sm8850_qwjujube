__int64 __fastcall _power_collapse(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int16 v7; // w22
  unsigned int v8; // w20
  unsigned int v9; // w21
  unsigned __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x2
  void *v13; // x0
  __int64 v14; // x3
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  int v18; // w23
  __int16 v19; // w22
  unsigned __int64 v20; // x8
  unsigned int v21; // w19
  char v22; // w22
  unsigned __int64 v23; // x8
  unsigned int v24; // w20
  unsigned __int64 v25; // x8

  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
  {
    if ( *(_DWORD *)(a1 + 2408) == 1 )
    {
      result = 4294967274LL;
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_86B58, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
        return 4294967274LL;
      }
      return result;
    }
    if ( (msm_cvp_dsp_disable & 1) == 0 )
    {
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
      {
        v22 = a2;
        printk(&unk_95776, "dsp", "__dsp_suspend", a4);
        a2 = v22;
      }
      result = cvp_dsp_suspend(a2 & 1);
      if ( (_DWORD)result == -16 )
        return result;
      if ( (_DWORD)result )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v23 = _ReadStatusReg(SP_EL0);
          v24 = result;
          printk(&unk_8B0E2, *(unsigned int *)(v23 + 1800), *(unsigned int *)(v23 + 1804), &unk_8E7CE);
          result = v24;
          if ( v24 == -22 )
            return result;
        }
        else if ( (_DWORD)result == -22 )
        {
          return result;
        }
        v9 = 0;
        v8 = 0;
        goto LABEL_51;
      }
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        printk(&unk_8C4F8, "dsp", "__dsp_suspend", v14);
    }
    _flush_debug_queue((_QWORD *)a1, *(unsigned int **)(a1 + 2440));
    v7 = _read_register(a1, 0xA004Cu);
    v8 = _read_register(a1, 0xC0010u);
    if ( (v7 & 0x100) != 0 )
    {
      if ( (v8 & 1) == 0 )
      {
        v9 = 0;
        if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
        {
          v15 = _ReadStatusReg(SP_EL0);
          printk(&unk_94C70, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), "warn");
          v9 = 0;
        }
        goto LABEL_51;
      }
    }
    else
    {
      v9 = _read_register(a1, 0xA004Cu);
      if ( (v8 & 1) == 0 )
      {
        if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
          goto LABEL_51;
        v10 = _ReadStatusReg(SP_EL0);
        v11 = *(unsigned int *)(v10 + 1800);
        v12 = *(unsigned int *)(v10 + 1804);
        v13 = &unk_8B09D;
LABEL_39:
        printk(v13, v11, v12, "warn");
LABEL_51:
        if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
          printk(&unk_9574E, &unk_8DA84, v8, v9);
        _flush_debug_queue((_QWORD *)a1, *(unsigned int **)(a1 + 2440));
        return 4294967285LL;
      }
      if ( (v9 & 0x40000000) == 0 )
      {
        if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
          goto LABEL_51;
        v16 = _ReadStatusReg(SP_EL0);
        v11 = *(unsigned int *)(v16 + 1800);
        v12 = *(unsigned int *)(v16 + 1804);
        v13 = &unk_874F4;
        goto LABEL_39;
      }
      if ( (unsigned int)_prepare_pc(a1) )
      {
        if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
          goto LABEL_51;
        v17 = _ReadStatusReg(SP_EL0);
        v11 = *(unsigned int *)(v17 + 1800);
        v12 = *(unsigned int *)(v17 + 1804);
        v13 = &unk_93976;
        goto LABEL_39;
      }
      v18 = 150;
      while ( 1 )
      {
        v8 = _read_register(a1, 0xC0010u);
        v19 = _read_register(a1, 0xA004Cu);
        if ( (v8 & 1) != 0 && (v19 & 0x100) != 0 )
          break;
        usleep_range_state(150, 250, 2);
        if ( !--v18 )
        {
          if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v25 = _ReadStatusReg(SP_EL0);
            printk(&unk_82480, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
          }
          goto LABEL_51;
        }
      }
    }
    result = _suspend(a1);
    if ( (_DWORD)result && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      v21 = result;
      printk(&unk_82D62, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
      return v21;
    }
  }
  else
  {
    result = 0;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_82454, &unk_8DA84, "__power_collapse", a4);
      return 0;
    }
  }
  return result;
}
