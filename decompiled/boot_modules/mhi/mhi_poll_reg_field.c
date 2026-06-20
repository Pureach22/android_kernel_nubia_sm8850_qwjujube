__int64 __fastcall mhi_poll_reg_field(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        unsigned int a6,
        int a7)
{
  __int64 result; // x0
  unsigned int v8; // w27
  __int64 v9; // x23
  __int64 v11; // x25
  __int64 v12; // x26
  __int64 v15; // x24
  char v17; // w28
  __int64 (__fastcall *v18)(__int64, __int64, int *); // x8
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( 1000 * a7 >= a6 )
  {
    v8 = 1000 * a7 / a6;
    v9 = a6;
    v11 = a2 + a3;
    v12 = 2LL * a6;
    v15 = (((unsigned __int64)a6 + 999) * (unsigned __int128)0x4189374BC6A7F0uLL) >> 64;
    v17 = __clz(__rbit64(a4));
    while ( 1 )
    {
      v18 = *(__int64 (__fastcall **)(__int64, __int64, int *))(a1 + 568);
      v19 = 0;
      if ( *((_DWORD *)v18 - 1) != -748163823 )
        __break(0x8228u);
      result = v18(a1, v11, &v19);
      if ( (_DWORD)result )
        break;
      if ( (v19 & a4) >> v17 == a5 )
      {
        result = 0;
        break;
      }
      if ( a6 <= 0xA )
      {
        _udelay(v9);
      }
      else if ( a6 > 0x4E20 )
      {
        msleep((unsigned int)v15);
      }
      else
      {
        usleep_range_state(v9, v12, 2);
      }
      if ( !--v8 )
        goto LABEL_2;
    }
  }
  else
  {
LABEL_2:
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
