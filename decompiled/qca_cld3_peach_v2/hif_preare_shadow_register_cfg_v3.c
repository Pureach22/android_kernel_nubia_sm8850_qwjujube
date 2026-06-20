__int64 __fastcall hif_preare_shadow_register_cfg_v3(__int64 result)
{
  int v1; // w9
  __int64 v2; // x8
  int v3; // w11
  __int64 v4; // x10
  int v5; // w9
  __int64 v6; // x11
  int v7; // w10
  int v8; // w13
  __int64 v9; // x10
  __int64 v10; // x0

  v1 = *(_DWORD *)(result + 656);
  v2 = *(unsigned int *)(result + 4192);
  if ( v1 )
  {
    if ( (unsigned int)v2 >= 0x28 )
      v3 = 40;
    else
      v3 = *(_DWORD *)(result + 4192);
    v4 = 0;
    while ( 40 - v3 != (_DWORD)v4 )
    {
      *(_DWORD *)(result + 4 * v2 + 4032 + 4 * v4) = *(_DWORD *)(*(_QWORD *)(result + 624) + 256LL)
                                                   + (*(_DWORD *)(*(_QWORD *)(result + 624) + 260LL)
                                                    - *(_DWORD *)(*(_QWORD *)(result + 624) + 256LL))
                                                   * v4
                                                   + *(_DWORD *)(*(_QWORD *)(result + 616) + 352LL);
      if ( v1 == (_DWORD)++v4 )
      {
        v5 = *(_DWORD *)(result + 656);
        if ( !v5 )
        {
          *(_DWORD *)(result + 4192) = v2 + v4;
          return result;
        }
        LODWORD(v2) = v2 + v4;
        v6 = 0;
        if ( (unsigned int)v2 >= 0x28 )
          v7 = 40;
        else
          v7 = v2;
        v8 = -v7;
        v9 = result + 4LL * (unsigned int)v2 + 4032;
        while ( v8 + 40 != (_DWORD)v6 )
        {
          LODWORD(v2) = v2 + 1;
          *(_DWORD *)(v9 + 4 * v6) = **(_DWORD **)(result + 624)
                                   + *(_DWORD *)(*(_QWORD *)(result + 624) + 256LL)
                                   + (*(_DWORD *)(*(_QWORD *)(result + 624) + 260LL)
                                    - *(_DWORD *)(*(_QWORD *)(result + 624) + 256LL))
                                   * v6;
          if ( v5 == (_DWORD)++v6 )
            goto LABEL_15;
        }
        break;
      }
    }
    __break(0x5512u);
    v10 = MEMORY[0xFFFFFFFFF89DCCF8]();
    return hif_get_shadow_reg_config_v3(v10);
  }
  else
  {
LABEL_15:
    *(_DWORD *)(result + 4192) = v2;
  }
  return result;
}
