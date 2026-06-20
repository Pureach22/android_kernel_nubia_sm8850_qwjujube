__int64 __fastcall kgsl_pwrscale_wake(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  _QWORD *v5; // x19
  _DWORD *v6; // x9
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  _QWORD v10[4]; // [xsp+0h] [xbp-20h] BYREF

  v10[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(result + 11880) == 1 )
  {
    v4 = *(_QWORD *)(result + 8752);
    *(_QWORD *)(result + 11856) = 0;
    *(_QWORD *)(result + 11864) = 0;
    *(_QWORD *)(result + 11872) = 0;
    v5 = (_QWORD *)result;
    v6 = *(_DWORD **)(v4 + 80);
    memset(v10, 0, 24);
    last_xstats = 0;
    qword_17D170 = 0;
    qword_17D178 = 0;
    qword_17D180 = 0;
    if ( *(v6 - 1) != -2100949828 )
      __break(0x8229u);
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64))v6)(result, v10, a3, a4);
    v8 = ktime_get(v7);
    v9 = v5[1487];
    v5[1486] = v8;
    v5[1502] = v8 + 10000000;
    result = queue_work_on(32, v9, v5 + 1492);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
