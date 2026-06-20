__int64 __fastcall sde_hw_ds_setup_scaler3(__int64 result, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x22
  unsigned int v5; // w19
  unsigned int v6; // w21
  __int64 v8; // x20
  const char *sde_format_ext; // x0

  if ( result )
  {
    if ( a3 )
    {
      if ( a2 )
      {
        v3 = *(_QWORD *)(result + 40);
        if ( v3 )
        {
          if ( *(_BYTE *)a3 == 1 )
          {
            a2[24] = *(_QWORD *)(a3 + 8);
            a2[25] = *(_QWORD *)(a3 + 16);
            a2[26] = *(_QWORD *)(a3 + 24);
            a2[27] = *(_QWORD *)(a3 + 32);
            a2[28] = *(_QWORD *)(a3 + 40);
            a2[29] = *(_QWORD *)(a3 + 48);
            v3 = *(_QWORD *)(result + 40);
          }
          v4 = result;
          v5 = *(_DWORD *)(v3 + 48);
          v6 = *(_DWORD *)(v3 + 20);
          v8 = (*(_QWORD *)(v3 + 32) >> 1) & 1LL;
          sde_format_ext = sde_get_sde_format_ext(808665688, 0);
          return sde_hw_setup_scaler3(v4, (__int64)a2, v5, v6, (__int64)sde_format_ext, v8);
        }
      }
    }
  }
  return result;
}
