__int64 __fastcall gh_get_virt_time_offset(_QWORD *a1)
{
  __int64 v2; // x0
  unsigned __int64 v3; // x8
  int v4; // w10
  unsigned __int64 v5; // x12
  __int64 v6; // x9
  unsigned __int64 v7; // x12
  unsigned __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 result; // x0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  do
  {
    v2 = sched_clock_read_begin(&v12);
    v3 = *(_QWORD *)(v2 + 8);
    v4 = *(_DWORD *)(v2 + 36);
    v5 = (*(unsigned int *)(v2 + 32) * (unsigned __int128)v3) >> 64;
    v6 = 2 * v5;
    v7 = v5 >> v4;
    v8 = (v6 << ~(_BYTE)v4) | ((*(unsigned int *)(v2 + 32) * v3) >> v4);
    if ( (v4 & 0x40) != 0 )
      v8 = v7;
    *a1 = v8 - *(_QWORD *)v2;
    v9 = *(_QWORD *)v2;
    v10 = v12;
    a1[1] = v9;
    result = sched_clock_read_retry(v10);
  }
  while ( (_DWORD)result );
  _ReadStatusReg(SP_EL0);
  return result;
}
