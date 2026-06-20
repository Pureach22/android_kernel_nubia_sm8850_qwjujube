__int64 __fastcall si_core_client_env_open(char *a1, unsigned __int64 a2, int a3, _QWORD *a4)
{
  int v5; // w0
  __int64 result; // x0
  int v7; // [xsp+8h] [xbp-58h] BYREF
  int v8; // [xsp+Ch] [xbp-54h] BYREF
  _QWORD v9[4]; // [xsp+10h] [xbp-50h] BYREF
  __int64 v10; // [xsp+30h] [xbp-30h]
  __int64 v11; // [xsp+38h] [xbp-28h]
  __int64 v12; // [xsp+40h] [xbp-20h]
  __int64 v13; // [xsp+48h] [xbp-18h]
  __int64 v14; // [xsp+50h] [xbp-10h]
  __int64 v15; // [xsp+58h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v8 = a3;
  v9[1] = &v8;
  v13 = 0;
  v14 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  v9[2] = 4;
  v9[0] = 1;
  v9[3] = 4;
  v5 = si_object_do_invoke(a1, a2, 0, (__int64)v9, &v7);
  if ( v5 | v7 )
  {
    printk(&unk_B4BB, "si_core_client_env_open");
    result = 4294967274LL;
  }
  else
  {
    result = 0;
    *a4 = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
