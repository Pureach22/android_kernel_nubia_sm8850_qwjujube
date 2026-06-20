__int64 __fastcall secure_etr_open(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  unsigned int v5; // w22
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v11[2]; // [xsp+10h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 656);
  mutex_lock(v4 + 168);
  if ( (*(_BYTE *)(v4 + 220) & 1) != 0 )
  {
    v5 = -16;
    goto LABEL_7;
  }
  if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(v4 - 16) + 968LL) != 1 )
  {
    v5 = -22;
    goto LABEL_7;
  }
  v5 = secure_etr_assign_to_apss(v4 - 24);
  if ( v5 )
  {
LABEL_7:
    mutex_unlock(v4 + 168);
    goto LABEL_8;
  }
  v6 = *(_QWORD *)(v4 + 224);
  v7 = *(_QWORD *)(v6 + 8);
  v8 = *(_QWORD *)(v6 + 16);
  v11[0] = 0x700000003LL;
  v10 = 0x8000;
  qcom_scm_assign_mem(v7, v8, &v10, v11, 1);
  *(_BYTE *)(v4 + 220) = 1;
  *(_QWORD *)(a2 + 32) = v4 - 24;
  mutex_unlock(v4 + 168);
  nonseekable_open(a1, a2);
  v5 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v5;
}
