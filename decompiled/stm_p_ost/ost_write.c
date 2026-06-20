__int64 __fastcall ost_write(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5)
{
  _DWORD *v8; // x25
  unsigned int v9; // w21
  int v10; // w24
  __int64 v12; // x2
  int v13; // w8
  __int64 (__fastcall *v14)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, int *); // x9
  __int64 result; // x0
  unsigned __int64 StatusReg; // x26
  int v17; // w9
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x2
  __int64 v21; // x20
  int v22; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v23[4]; // [xsp+Ch] [xbp-24h] BYREF
  _DWORD v24[2]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v25; // [xsp+18h] [xbp-18h]
  __int64 v26; // [xsp+20h] [xbp-10h]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_DWORD **)(a2 + 16);
  v23[0] = 0;
  v9 = *(_DWORD *)(a2 + 4);
  v10 = *(_DWORD *)(a2 + 8);
  v12 = (unsigned int)(v10 + a3);
  if ( *v8 == 1 )
    v13 = 69648;
  else
    v13 = 15601680;
  v14 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, __int64, __int64, int *))(a1 + 40);
  v22 = v13;
  result = v14(a1, v9, v12, 0, 1, 4, &v22);
  if ( result >= 1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v17 = *(_DWORD *)(StatusReg + 40);
    v24[0] = 1498611715;
    v24[1] = v17;
    v18 = sched_clock();
    v19 = *(int *)(StatusReg + 1804);
    v25 = v18;
    v26 = v19;
    if ( *v8 == 2 || (result = stm_data_write(a1, v9, (unsigned int)(v10 + a3), 0, v24, 24), result >= 1) )
    {
      result = stm_data_write(a1, v9, (unsigned int)(v10 + a3), 0, a4, a5);
      if ( result >= 1 )
      {
        v20 = (unsigned int)(v10 + a3);
        v21 = result;
        (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, __int64, _QWORD, _BYTE *))(a1 + 40))(
          a1,
          v9,
          v20,
          1,
          2,
          0,
          v23);
        result = v21;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
