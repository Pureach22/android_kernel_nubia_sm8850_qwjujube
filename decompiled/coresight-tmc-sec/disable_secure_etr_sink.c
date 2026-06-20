__int64 __fastcall disable_secure_etr_sink(__int64 a1)
{
  _QWORD *v2; // x19
  int v3; // w8
  unsigned int v4; // w20
  __int64 v5; // x21
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 152) + 152LL);
  mutex_lock(v2 + 24);
  if ( (*((_BYTE *)v2 + 244) & 1) != 0 || (v3 = *(_DWORD *)(a1 + 976) - 1, (*(_DWORD *)(a1 + 976) = v3) != 0) )
  {
    v4 = -16;
  }
  else
  {
    v4 = secure_etr_assign_to_apss(v2);
    if ( v4 )
      dev_err(*v2, "assign etr to apss fail\n");
    v7 = v2[31];
    v8 = *(_QWORD *)(v7 + 8);
    v9 = *(_QWORD *)(v7 + 16);
    v12[0] = 0x700000003LL;
    v11 = 0x8000;
    qcom_scm_assign_mem(v8, v9, &v11, v12, 1);
    dmam_free_coherent(*v2, *(_QWORD *)(v2[31] + 16LL), *(_QWORD *)v2[31], *(_QWORD *)(v2[31] + 8LL));
    dev_info(*v2, "disable modem etr\n");
    *(_QWORD *)(a1 + 968) = 0;
    v10 = v2[22];
    if ( v10 )
    {
      *(_QWORD *)(*(_QWORD *)(v10 + 16) + 968LL) = 0;
      v2[22] = 0;
    }
  }
  v5 = v2[35];
  clk_disable(v5);
  clk_unprepare(v5);
  mutex_unlock(v2 + 24);
  _ReadStatusReg(SP_EL0);
  return v4;
}
