__int64 __fastcall set_task_boost(__int64 result, __int64 a2)
{
  char *StatusReg; // x10
  void *v3; // x19
  __int64 v4; // x9
  bool v5; // zf
  __int64 v6; // x0
  __int64 v7; // x8

  StatusReg = (char *)_ReadStatusReg(SP_EL0);
  if ( StatusReg == (char *)&init_task )
    v3 = &vendor_data_pad;
  else
    v3 = StatusReg + 5184;
  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  if ( (unsigned int)result > 3 )
    return 4294967274LL;
  if ( (_DWORD)result )
  {
    *((_DWORD *)v3 + 46) = result;
    v4 = 1000000 * a2;
    v5 = walt_clock_suspended == 1;
    *((_QWORD *)v3 + 24) = 1000000 * a2;
    if ( v5 )
    {
      v7 = sched_clock_last;
    }
    else
    {
      v6 = sched_clock(result, a2);
      v4 = *((_QWORD *)v3 + 24);
      v7 = v6;
    }
    *((_QWORD *)v3 + 25) = v4 + v7;
    return 0;
  }
  else
  {
    *((_DWORD *)v3 + 46) = 0;
    *((_QWORD *)v3 + 24) = 0;
    *((_QWORD *)v3 + 25) = 0;
  }
  return result;
}
