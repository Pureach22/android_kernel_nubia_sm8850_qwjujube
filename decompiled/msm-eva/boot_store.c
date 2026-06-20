__int64 __fastcall boot_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 v5; // x20
  __int64 v6; // x0
  int v7; // w0
  int v8; // w21
  __int64 v9; // x1
  __int64 v10; // x2
  void *v11; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x21
  int v16; // w0
  __int64 v18; // x1
  __int64 v19; // x2
  void *v20; // x0
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v21) || v21 < 0 )
  {
    a4 = -22;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_961A4, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
  }
  else if ( v21 != 1 || (boot_store_booted & 1) != 0 )
  {
    if ( v21 != 2 )
      goto LABEL_25;
    v13 = _ReadStatusReg(SP_EL0);
    v14 = msm_cvp_open(1, v13);
    if ( v14 )
    {
      v15 = v14;
      if ( (unsigned int)msm_cvp_session_create() && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8E7F1, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
      v16 = msm_cvp_close(v15);
      if ( v16 )
      {
        v8 = v16;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_24;
        v9 = *(unsigned int *)(v13 + 1800);
        v10 = *(unsigned int *)(v13 + 1804);
        v11 = &unk_85674;
        goto LABEL_23;
      }
LABEL_25:
      boot_store_booted = 1;
      goto LABEL_26;
    }
    a4 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v18 = *(unsigned int *)(v13 + 1800);
      v19 = *(unsigned int *)(v13 + 1804);
      v20 = &unk_92D04;
      goto LABEL_33;
    }
  }
  else
  {
    v5 = _ReadStatusReg(SP_EL0);
    v6 = msm_cvp_open(3, v5);
    if ( v6 )
    {
      v7 = msm_cvp_close(v6);
      if ( v7 )
      {
        v8 = v7;
        if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
          goto LABEL_24;
        v9 = *(unsigned int *)(v5 + 1800);
        v10 = *(unsigned int *)(v5 + 1804);
        v11 = &unk_84C16;
LABEL_23:
        printk(v11, v9, v10, &unk_8E7CE);
LABEL_24:
        a4 = v8;
        goto LABEL_26;
      }
      goto LABEL_25;
    }
    a4 = -12;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v18 = *(unsigned int *)(v5 + 1800);
      v19 = *(unsigned int *)(v5 + 1804);
      v20 = &unk_87441;
LABEL_33:
      printk(v20, v18, v19, &unk_8E7CE);
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return a4;
}
