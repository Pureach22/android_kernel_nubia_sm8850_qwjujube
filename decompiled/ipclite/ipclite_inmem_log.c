__int64 __fastcall ipclite_inmem_log(
        const char *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  __int16 v10; // w0
  __int64 result; // x0
  _QWORD arg[4]; // [xsp+38h] [xbp-48h] BYREF
  char *v13; // [xsp+58h] [xbp-28h]
  _QWORD *v14; // [xsp+60h] [xbp-20h]
  __int64 v15; // [xsp+68h] [xbp-18h]
  __int64 v16; // [xsp+70h] [xbp-10h]
  __int64 v17; // [xsp+78h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = nullptr;
  v14 = nullptr;
  if ( (debug_status & 1) != 0 )
  {
    v16 = 4294967240LL;
    v13 = &a9;
    v14 = arg;
    v10 = ipclite_global_atomic_inc(ipclite_dbg_info + 16);
    arg[0] = v13;
    arg[1] = v14;
    arg[2] = v15;
    arg[3] = v16;
    result = vsnprintf((char *)(ipclite_dbg_inmem + 100LL * (v10 & 0x1FF)), 0x64u, a1, arg);
  }
  else
  {
    result = printk(&unk_EEDB, "ipclite", "ipclite_inmem_log");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
