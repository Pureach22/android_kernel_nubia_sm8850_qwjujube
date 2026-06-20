__int64 __fastcall store_enable_trace(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  __int64 v6; // x0
  __int64 (__fastcall *v7)(__int64, int *, __int64, __int64, __int64); // x8
  int v8; // w0
  int v10; // w20
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ops )
  {
    v11 = 0;
    v5 = kstrtouint(a3, 10, &v11);
    if ( v5 < 0 )
    {
      a4 = v5;
    }
    else
    {
      v6 = ph;
      v7 = *(__int64 (__fastcall **)(__int64, int *, __int64, __int64, __int64))ops;
      if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
        __break(0x8228u);
      v8 = v7(v6, &v11, 0x504D554D4150LL, 12, 4);
      if ( v8 < 0 )
      {
        v10 = v8;
        printk(&unk_9053);
        a4 = v10;
      }
      else
      {
        pmu_enable_trace = v11;
      }
    }
  }
  else
  {
    a4 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
