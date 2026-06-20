__int64 __fastcall scmi_clk_get_parent(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 (__fastcall *v4)(__int64, __int64, int *); // x8
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x9
  int *v9; // x11
  int v10; // t1
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[4];
  v3 = *((unsigned int *)a1 - 4);
  v11 = 0;
  v4 = *(__int64 (__fastcall **)(__int64, __int64, int *))(scmi_proto_clk_ops + 72);
  if ( *((_DWORD *)v4 - 1) != -1920770657 )
    __break(0x8228u);
  v5 = v4(v2, v3, &v11);
  result = 0;
  if ( !v5 )
  {
    v7 = *(unsigned int *)(a1[3] + 216LL);
    if ( (_DWORD)v7 )
    {
      v8 = 0;
      v9 = (int *)(a1[5] + 24LL);
      while ( 1 )
      {
        v10 = *v9;
        v9 += 8;
        if ( v10 == v11 )
          break;
        if ( v7 == ++v8 )
        {
          LODWORD(v8) = *(_DWORD *)(a1[3] + 216LL);
          break;
        }
      }
    }
    else
    {
      LODWORD(v8) = 0;
    }
    if ( (_DWORD)v8 == (_DWORD)v7 )
      result = 0;
    else
      result = (unsigned int)v8;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
