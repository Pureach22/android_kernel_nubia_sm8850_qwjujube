__int64 __fastcall kgsl_pwrctrl_set_constraint(__int64 result, int *a2, int a3, int a4)
{
  int v4; // w8
  int v5; // w10
  int v6; // w9
  __int64 v7; // x20
  __int64 v8; // x19
  __int64 v9; // x20
  int v11; // w8
  __int64 v12; // x21
  __int64 v13; // x0

  if ( !result || !a2 )
    return result;
  v4 = *a2;
  if ( *a2 == 1 && a2[1] == 1 )
  {
    v5 = *(_DWORD *)(result + 10416);
    if ( v5 )
      goto LABEL_6;
LABEL_12:
    *(_DWORD *)(result + 10416) = v4;
    v9 = result;
    v11 = a2[1];
    *(_DWORD *)(result + 10432) = a3;
    *(_DWORD *)(result + 10420) = v11;
    v12 = jiffies;
    v13 = _msecs_to_jiffies((unsigned int)*(_QWORD *)(result + 10080));
    *(_DWORD *)(v9 + 10436) = a4;
    *(_QWORD *)(v9 + 10424) = v13 + v12;
    return kgsl_pwrctrl_pwrlevel_change(v9);
  }
  v5 = *(_DWORD *)(result + 10416);
  if ( !v5 )
    goto LABEL_12;
LABEL_6:
  v6 = *(_DWORD *)(result + 10420);
  if ( !v6 && a2[1] == 1 )
    goto LABEL_12;
  if ( v5 == v4 && v6 == a2[1] )
  {
    *(_DWORD *)(result + 10432) = a3;
    v7 = result;
    *(_DWORD *)(result + 10436) = a4;
    v8 = jiffies;
    result = _msecs_to_jiffies((unsigned int)*(_QWORD *)(result + 10080));
    *(_QWORD *)(v7 + 10424) = result + v8;
  }
  return result;
}
