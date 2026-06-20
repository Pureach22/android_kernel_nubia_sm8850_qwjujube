__int64 __fastcall kgsl_add_event_group(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        char *format,
        int a7,
        int a8,
        char a9)
{
  _QWORD *v11; // x0
  _QWORD *v12; // x1
  __int64 v13; // x2
  __int64 result; // x0
  _QWORD arg[4]; // [xsp+18h] [xbp-48h] BYREF
  char *v16; // [xsp+38h] [xbp-28h]
  _QWORD *v17; // [xsp+40h] [xbp-20h]
  __int64 v18; // [xsp+48h] [xbp-18h]
  __int64 v19; // [xsp+50h] [xbp-10h]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = nullptr;
  v17 = nullptr;
  if ( !a4 )
    __break(0x800u);
  *(_DWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = a2 + 16;
  *(_QWORD *)(a2 + 24) = a2 + 16;
  *(_QWORD *)a2 = a3;
  *(_QWORD *)(a2 + 120) = a4;
  *(_QWORD *)(a2 + 128) = a5;
  if ( format )
  {
    v19 = 4294967280LL;
    v16 = &a9;
    v17 = arg;
    arg[0] = &a9;
    arg[1] = arg;
    arg[2] = v18;
    arg[3] = 4294967280LL;
    vsnprintf((char *)(a2 + 52), 0x40u, format, arg);
  }
  raw_write_lock(a1 + 13168);
  v11 = (_QWORD *)(a2 + 32);
  v12 = *(_QWORD **)(a1 + 13160);
  v13 = a1 + 13152;
  if ( a2 + 32 == a1 + 13152 || v12 == v11 || *v12 != v13 )
  {
    _list_add_valid_or_report(v11, v12);
  }
  else
  {
    *(_QWORD *)(a1 + 13160) = v11;
    *(_QWORD *)(a2 + 32) = v13;
    *(_QWORD *)(a2 + 40) = v12;
    *v12 = v11;
  }
  result = raw_write_unlock(a1 + 13168);
  _ReadStatusReg(SP_EL0);
  return result;
}
