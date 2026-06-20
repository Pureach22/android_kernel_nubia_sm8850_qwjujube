__int64 __fastcall sde_cesta_update_perf_config(__int64 result, __int64 *a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x10
  __int64 v4; // x11
  __int64 v5; // x12

  if ( !(_DWORD)result )
  {
    v2 = (_QWORD *)cesta_list_0;
    if ( cesta_list_0 )
    {
      if ( a2 )
      {
        v3 = a2[2];
        v4 = *a2;
        v5 = a2[1];
        *(_QWORD *)(cesta_list_0 + 1152) = a2[3];
        v2[143] = v3;
        v2[142] = v5;
        v2[141] = v4;
      }
      else
      {
        return printk(&unk_254BF7, "sde_cesta_update_perf_config");
      }
    }
  }
  return result;
}
