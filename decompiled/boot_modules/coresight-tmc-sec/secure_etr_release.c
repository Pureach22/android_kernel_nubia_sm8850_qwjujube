__int64 __fastcall secure_etr_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x1
  unsigned int v6; // w20
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v13[2]; // [xsp+10h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 32);
  mutex_lock(v2 + 192);
  v3 = *(_QWORD *)(v2 + 248);
  v4 = *(_QWORD *)(v3 + 8);
  v5 = *(_QWORD *)(v3 + 16);
  v13[0] = 0x60000000FLL;
  v12 = 8;
  qcom_scm_assign_mem(v4, v5, &v12, v13, 1);
  v6 = secure_etr_assign_to_mpss(v2);
  if ( !v6 )
  {
    v7 = **(_QWORD **)(v2 + 8);
    v8 = *(unsigned int *)(v7 + 4);
    if ( (int)v8 < 1 )
      goto LABEL_8;
    v9 = *(_QWORD *)(v7 + 8);
    while ( 1 )
    {
      v10 = *(_QWORD *)(*(_QWORD *)v9 + 16LL);
      if ( v10 )
      {
        if ( *(_DWORD *)(v10 + 8) == 4 )
          break;
      }
      --v8;
      v9 += 8;
      if ( !v8 )
        goto LABEL_8;
    }
    v6 = coresight_qmi_remote_etm_enable();
    if ( !v6 )
    {
LABEL_8:
      v6 = 0;
      *(_BYTE *)(v2 + 244) = 0;
    }
  }
  mutex_unlock(v2 + 192);
  _ReadStatusReg(SP_EL0);
  return v6;
}
