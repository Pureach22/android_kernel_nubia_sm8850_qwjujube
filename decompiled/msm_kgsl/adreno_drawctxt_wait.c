__int64 __fastcall adreno_drawctxt_wait(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v6; // w19
  __int64 result; // x0
  unsigned int v9; // w23
  __int64 v10; // x22
  char v11; // w0
  __int64 v12; // x0
  unsigned __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  char v20; // w8
  __int64 v21; // x0
  __int64 v22; // x9
  unsigned int v23; // w8
  _QWORD v24[6]; // [xsp+0h] [xbp-30h] BYREF

  v24[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || (*(_QWORD *)(a2 + 32) & 2) != 0 )
  {
    result = 4294967294LL;
    goto LABEL_25;
  }
  if ( (*(_QWORD *)(a2 + 32) & 4) != 0 )
  {
    result = 4294967261LL;
    goto LABEL_25;
  }
  v6 = a3;
  result = kgsl_add_event(a1, a2 + 64, a3, wait_callback, a2);
  if ( (_DWORD)result )
    goto LABEL_25;
  if ( a4 )
    v9 = a4;
  else
    v9 = -1;
  v10 = _msecs_to_jiffies(v9);
  if ( (*(_QWORD *)(a2 + 32) & 2) != 0 || (*(_QWORD *)(a2 + 32) & 4) != 0 )
  {
    v12 = a1;
    if ( !v10 )
      goto LABEL_29;
    goto LABEL_28;
  }
  v11 = kgsl_check_timestamp(a1, a2, v6);
  if ( (v11 & 1 & (v10 == 0)) != 0 )
    v10 = 1;
  if ( (v11 & 1) != 0 )
    goto LABEL_40;
  v12 = a1;
  if ( !v10 )
  {
LABEL_28:
    if ( v10 <= 0 )
      goto LABEL_41;
    goto LABEL_29;
  }
  memset(v24, 0, 40);
  v13 = _msecs_to_jiffies(v9);
  init_wait_entry(v24, 0);
  while ( 1 )
  {
    v14 = prepare_to_wait_event(a2 + 1464, v24, 1);
    if ( (*(_QWORD *)(a2 + 32) & 2) != 0 || (*(_QWORD *)(a2 + 32) & 4) != 0 )
      break;
    v10 = v14;
    v20 = kgsl_check_timestamp(a1, a2, v6);
    if ( (v20 & 1 & (v13 == 0)) != 0 )
      v21 = 1;
    else
      v21 = v13;
    if ( (v20 & 1) != 0 || !v21 )
    {
      v10 = v21;
      goto LABEL_39;
    }
    if ( v10 )
      goto LABEL_40;
    v13 = schedule_timeout(v21, v15, v16, v17, v18, v19);
  }
  if ( v13 <= 1 )
    v10 = 1;
  else
    v10 = v13;
LABEL_39:
  finish_wait(a2 + 1464, v24);
LABEL_40:
  v12 = a1;
  if ( v10 <= 0 )
  {
LABEL_41:
    kgsl_cancel_event(v12, a2 + 64, v6, wait_callback, a2);
    if ( v10 )
      result = (unsigned int)v10;
    else
      result = 4294967186LL;
    goto LABEL_25;
  }
LABEL_29:
  v22 = *(_QWORD *)(a2 + 32);
  if ( (v22 & 4) != 0 )
    v23 = -35;
  else
    v23 = 0;
  if ( (v22 & 2) != 0 )
    result = 4294967294LL;
  else
    result = v23;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
