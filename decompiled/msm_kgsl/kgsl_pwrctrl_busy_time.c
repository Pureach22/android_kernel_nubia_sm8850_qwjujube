__int64 __fastcall kgsl_pwrctrl_busy_time(__int64 result, int a2, int a3)
{
  unsigned int v3; // w9
  int v4; // w10
  _DWORD *v5; // x20
  int v6; // w8
  int v7; // w9

  v3 = *(_DWORD *)(result + 10356) + a2;
  v4 = *(_DWORD *)(result + 10352) + a3;
  *(_DWORD *)(result + 10356) = v3;
  *(_DWORD *)(result + 10352) = v4;
  if ( v3 >= 0xF4240 )
  {
    v5 = (_DWORD *)result;
    mutex_lock(result + 11016);
    v6 = v5[2589];
    v7 = v5[2588];
    *((_QWORD *)v5 + 1294) = 0;
    v5[2591] = v6;
    v5[2590] = v7;
    return mutex_unlock(v5 + 2754);
  }
  return result;
}
