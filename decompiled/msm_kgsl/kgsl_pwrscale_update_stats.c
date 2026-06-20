__int64 __fastcall kgsl_pwrscale_update_stats(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  __int64 (__fastcall *v3)(__int64, __int64 *); // x8
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x9
  int v9; // w11
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h]
  __int64 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(result + 11112) )
  {
    __break(0x800u);
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_BYTE *)(result + 11880) != 1 || *(_DWORD *)(result + 11120) != 2 )
    goto LABEL_10;
  v11 = 0;
  v12 = 0;
  v1 = result;
  v10 = 0;
  v2 = ktime_get(result);
  v3 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v1 + 8752) + 80LL);
  if ( *((_DWORD *)v3 - 1) != -2100949828 )
    __break(0x8228u);
  result = v3(v1, &v10);
  v4 = v10;
  v5 = *(unsigned int *)(v1 + 10040);
  v6 = *(_QWORD *)(v1 + 11864) + v11;
  v7 = *(_QWORD *)(v1 + 11872) + v12;
  *(_QWORD *)(v1 + 11856) += v10;
  *(_QWORD *)(v1 + 11864) = v6;
  *(_QWORD *)(v1 + 11872) = v7;
  if ( (unsigned int)v5 < 0x20 )
  {
    v8 = v1 + 8 * v5;
    v9 = *(_DWORD *)(v1 + 10048);
    *(_QWORD *)(v8 + 10088) += v4;
    if ( v9 )
      *(_QWORD *)(v1 + 10344) += v4;
    *(_QWORD *)(v8 + 10648) += (v2 - *(_QWORD *)(v1 + 10904)) / 1000;
    *(_QWORD *)(v1 + 10904) = v2;
    goto LABEL_10;
  }
  __break(0x5512u);
  return kgsl_pwrscale_update(result);
}
