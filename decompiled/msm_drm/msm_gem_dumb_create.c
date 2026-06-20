__int64 __fastcall msm_gem_dumb_create(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w9
  int v4; // w10
  int v5; // w9
  unsigned int v6; // w9
  int v7; // w10
  __int64 v8; // x9

  v3 = *(_DWORD *)(a3 + 8);
  v4 = v3 + 7;
  v5 = v3 + 14;
  if ( v4 >= 0 )
    v5 = v4;
  v6 = (v5 >> 3) * ((*(_DWORD *)(a3 + 4) + 31) & 0xFFFFFFE0);
  v7 = v6 * *(_DWORD *)a3 + 4095;
  *(_DWORD *)(a3 + 20) = v6;
  v8 = v7 & 0xFFFFF000;
  *(_QWORD *)(a3 + 24) = v8;
  return msm_gem_new_handle(a2, a1, (unsigned int)v8, 65537, a3 + 16, "dumb");
}
