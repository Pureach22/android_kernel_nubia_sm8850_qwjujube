__int64 __fastcall sched_busy_hyst_handler(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 result; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  _QWORD v21[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v26 = a1[6];
  v24 = v9;
  v25 = v10;
  v11 = a1[1];
  v21[0] = *a1;
  v21[1] = v11;
  v12 = a1[3];
  v22 = a1[2];
  v23 = v12;
  if ( 4 * (unsigned __int64)(unsigned int)_sw_hweight64(_cpu_possible_mask) < (int)v22 )
    LODWORD(v22) = 4 * _sw_hweight64(_cpu_possible_mask);
  result = proc_dointvec_minmax(v21, a2, a3, a4, a5);
  if ( a2 && !(_DWORD)result )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, __int64, __int64))sched_update_hyst_times)(
      result,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
