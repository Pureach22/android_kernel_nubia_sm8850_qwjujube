__int64 __fastcall si_core_get_client_env(char *a1, _QWORD *a2)
{
  int v3; // w0
  __int64 result; // x0
  int v5; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD v6[4]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v7; // [xsp+30h] [xbp-30h]
  __int64 v8; // [xsp+38h] [xbp-28h]
  __int64 v9; // [xsp+40h] [xbp-20h]
  __int64 v10; // [xsp+48h] [xbp-18h]
  __int64 v11; // [xsp+50h] [xbp-10h]
  __int64 v12; // [xsp+58h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  v6[0] = 3;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  v7 = 0;
  v6[1] = 0;
  v6[2] = 0;
  v6[3] = 4;
  v3 = si_object_do_invoke(a1, 1u, 5, (__int64)v6, &v5);
  if ( v3 | v5 )
  {
    printk(&unk_B4BB, "si_core_get_client_env");
    result = 4294967274LL;
  }
  else
  {
    result = 0;
    *a2 = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
