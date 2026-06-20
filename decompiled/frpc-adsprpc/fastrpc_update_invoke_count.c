__int64 __fastcall fastrpc_update_invoke_count(__int64 result, __int64 *a2)
{
  _QWORD *v2; // x19
  _QWORD *v3; // x21
  __int64 v5; // x10
  __int64 v6; // x11
  unsigned __int64 v7; // x8
  __int64 v8; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+10h] [xbp-20h]
  __int64 v10; // [xsp+18h] [xbp-18h] BYREF
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v2 = (_QWORD *)result;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result || (v3 = (_QWORD *)(result + 64), result == -64) )
  {
    if ( !result )
      goto LABEL_12;
  }
  else
  {
    v8 = 0;
    v9 = 0;
    ktime_get_real_ts64(&v8);
    v5 = *a2;
    v6 = a2[1];
    v10 = 0;
    v11 = 0;
    result = set_normalized_timespec64(&v10, v8 - v5, v9 - v6);
    if ( v10 <= 0x225C17D03LL )
    {
      if ( v10 >= (__int64)0xFFFFFFFDDA3E82FDLL )
        v7 = v11 + 1000000000 * v10;
      else
        v7 = 0x8000000000000000LL;
    }
    else
    {
      v7 = 0x7FFFFFFFFFFFFFFFLL;
    }
    *v3 += v7;
  }
  ++*v2;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
