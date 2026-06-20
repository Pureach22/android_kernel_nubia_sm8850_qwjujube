void __fastcall iris_hfi_pm_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  _DWORD *v6; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x1
  __int64 v9; // x2
  void *v10; // x0
  int v11; // w20
  __int64 v12; // x3
  __int64 v13; // x3
  char v14; // w9
  unsigned __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x19
  __int64 v18; // x0
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  _BYTE v21[760]; // [xsp+0h] [xbp-300h] BYREF
  __int64 v22; // [xsp+2F8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(cvp_driver + 48);
  if ( !v4 )
    goto LABEL_30;
  v5 = **(_QWORD **)(v4 + 256);
  if ( !v5 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_30;
    StatusReg = _ReadStatusReg(SP_EL0);
    v8 = *(unsigned int *)(StatusReg + 1800);
    v9 = *(unsigned int *)(StatusReg + 1804);
    v10 = &unk_89BB3;
LABEL_16:
    printk(v10, v8, v9, &unk_8E7CE);
    goto LABEL_30;
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_881DF, &unk_8DA84, "iris_hfi_pm_handler", a4);
  if ( *(_DWORD *)(v5 + 2496) >= 0xAu )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v20 = _ReadStatusReg(SP_EL0);
      printk(&unk_8C4C5, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), "warn");
    }
    *(_DWORD *)(v5 + 2496) = 0;
    memset(v21, 0, sizeof(v21));
    v6 = *(_DWORD **)(v5 + 128);
    if ( *(v6 - 1) != -312014295 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _BYTE *))v6)(9, v21);
    goto LABEL_30;
  }
  mutex_lock(v5 + 80);
  v11 = _power_collapse(v5, dword_6C668 == 4);
  mutex_unlock(v5 + 80);
  if ( v11 == -16 )
  {
    *(_DWORD *)(v5 + 2496) = 0;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
      printk(&unk_842C6, &unk_8DA84, "iris_hfi_pm_handler", v12);
    goto LABEL_29;
  }
  if ( v11 == -11 )
  {
    v14 = msm_cvp_debug;
    ++*(_DWORD *)(v5 + 2496);
    if ( (v14 & 2) != 0 && !msm_cvp_debug_out )
    {
      v15 = _ReadStatusReg(SP_EL0);
      printk(&unk_82417, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), "warn");
    }
LABEL_29:
    v16 = *(_QWORD *)(v5 + 2208);
    v17 = *(_QWORD *)(v5 + 2184);
    v18 = _msecs_to_jiffies(*(unsigned int *)(v16 + 432));
    queue_delayed_work_on(32, v17, &iris_hfi_pm_work, v18);
    goto LABEL_30;
  }
  if ( v11 )
  {
    if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
      goto LABEL_30;
    v19 = _ReadStatusReg(SP_EL0);
    v8 = *(unsigned int *)(v19 + 1800);
    v9 = *(unsigned int *)(v19 + 1804);
    v10 = &unk_96D77;
    goto LABEL_16;
  }
  *(_DWORD *)(v5 + 2496) = 0;
  cancel_delayed_work(&iris_hfi_pm_work);
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_85F1D, &unk_8DA84, "iris_hfi_pm_handler", v13);
LABEL_30:
  _ReadStatusReg(SP_EL0);
}
