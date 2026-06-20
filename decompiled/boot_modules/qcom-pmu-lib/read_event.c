__int64 __fastcall read_event(__int64 a1, char a2)
{
  int v4; // w1
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // [xsp+0h] [xbp-30h] BYREF
  __int64 v8; // [xsp+8h] [xbp-28h]
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a1 + 32);
  v11 = 0;
  v9 = 0;
  v10 = 0;
  v7 = 0;
  v8 = 0;
  if ( (unsigned int)v4 > 3 )
  {
    v6 = *(_QWORD *)(a1 + 8);
    if ( v6 )
    {
      if ( (a2 & 1) != 0 )
      {
        perf_event_read_local(v6);
        result = v9;
      }
      else
      {
        result = perf_event_read_value(v6);
      }
      goto LABEL_17;
    }
  }
  else
  {
    LODWORD(v7) = v4;
    if ( (a2 & 1) != 0 )
    {
      if ( v4 > 1 )
      {
        if ( v4 == 2 )
          result = _ReadStatusReg(AMEVCNTR02_EL0);
        else
          result = _ReadStatusReg(AMEVCNTR03_EL0);
      }
      else if ( v4 )
      {
        result = _ReadStatusReg(AMEVCNTR00_EL0);
      }
      else
      {
        result = _ReadStatusReg(AMEVCNTR01_EL0);
      }
      goto LABEL_17;
    }
    if ( (smp_call_function_single(*(unsigned int *)(a1 + 16), read_amu_reg, &v7, 1) & 0x80000000) == 0 )
    {
      result = v8;
LABEL_17:
      *(_QWORD *)(a1 + 24) = result;
      goto LABEL_18;
    }
  }
  result = *(_QWORD *)(a1 + 24);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
