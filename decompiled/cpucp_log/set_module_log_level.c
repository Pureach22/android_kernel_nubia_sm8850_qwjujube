const char *__fastcall set_module_log_level(__int64 a1, __int64 a2, const char *a3)
{
  const char *v3; // x19
  const char *v4; // x0
  const char *v5; // x20
  int v6; // w0
  __int64 v7; // x0
  __int64 (__fastcall *v8)(__int64, _QWORD *, __int64, __int64, __int64); // x8
  int v9; // w0
  int v11; // w21
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a3;
  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = 0;
  v4 = (const char *)memdup_user(a2, a3);
  if ( (unsigned __int64)v4 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = v4;
    v6 = sscanf(v4, "%u %u", v12, (char *)v12 + 4);
    if ( v6 < 0 )
    {
      v3 = (const char *)v6;
    }
    else
    {
      v7 = ph;
      v8 = *(__int64 (__fastcall **)(__int64, _QWORD *, __int64, __int64, __int64))ops;
      if ( *(_DWORD *)(*(_QWORD *)ops - 4LL) != 1737159351 )
        __break(0x8228u);
      v9 = v8(v7, v12, 0x435055435043544CLL, 5, 8);
      if ( v9 < 0 )
      {
        v11 = v9;
        printk(&unk_87B6);
        kfree(v5);
        v3 = (const char *)v11;
      }
      else
      {
        kfree(v5);
      }
    }
  }
  else
  {
    v3 = v4;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
