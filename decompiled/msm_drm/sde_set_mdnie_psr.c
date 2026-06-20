__int64 __fastcall sde_set_mdnie_psr(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  int v3; // w21
  __int64 v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 2216);
    if ( v1 )
    {
      v2 = *(unsigned int *)(v1 + 28);
      if ( (unsigned int)v2 > 2 )
      {
LABEL_11:
        __break(0x5512u);
        return dspp_ai_scaler_install_property();
      }
      if ( *(_QWORD *)(v1 + 1384 + 8 * v2) )
      {
        v3 = *(_DWORD *)(result + 2192);
        if ( v3 )
        {
          while ( 1 )
          {
            v4 = *(unsigned int *)(v1 + 28);
            if ( (unsigned int)v4 > 2 )
              break;
            v5 = *(__int64 (__fastcall **)(_QWORD))(v1 + 1384 + 8 * v4);
            if ( *((_DWORD *)v5 - 1) != 206991498 )
              __break(0x8228u);
            result = v5(v1);
            if ( !--v3 )
              return result;
          }
          goto LABEL_11;
        }
      }
    }
  }
  return result;
}
