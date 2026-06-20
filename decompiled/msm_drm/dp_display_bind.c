__int64 __fastcall dp_display_bind(__int64 *a1, _QWORD *a2)
{
  __int64 *v3; // x20
  _QWORD *v4; // x21
  _QWORD *v5; // x20
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  _QWORD v9[5]; // [xsp+8h] [xbp-28h] BYREF

  v3 = a1 - 2;
  v9[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = dp_display_pre_hw_release;
  v9[1] = dp_display_post_hw_acquire;
  v9[2] = 0;
  v9[3] = 0;
  if ( a2 && a1 && a1 != &qword_10 )
  {
    v4 = (_QWORD *)a2[19];
    v5 = (_QWORD *)a1[19];
    if ( v4 && v5 )
    {
      v5[146] = v4;
      v5[189] = v4[7];
      msm_register_vm_event(a2, a1, v9, v5 + 146);
      result = 0;
    }
    else
    {
      if ( !g_dp_display || (v8 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v8 = 0;
      ipc_log_string(
        v8,
        "[e][%-4d]invalid param(s), drm %pK, dp %pK\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v4,
        v5);
      printk(&unk_264E45, "dp_display_bind");
      result = 4294967274LL;
    }
  }
  else
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    ipc_log_string(
      v7,
      "[e][%-4d]invalid param(s), dev %pK, pdev %pK, master %pK\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a1,
      v3,
      a2);
    printk(&unk_21FF39, "dp_display_bind");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
