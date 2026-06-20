__int64 __fastcall cam_cpas_util_validate_stop_bw(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned __int64 v3; // x10
  __int64 *v4; // x8
  int v5; // w12
  __int64 v6; // x7
  __int64 v7; // x12
  __int64 v8; // x6
  const char *v9; // x5
  __int64 v10; // x4
  __int64 v12; // [xsp+8h] [xbp-18h]
  __int64 v13; // [xsp+10h] [xbp-10h]

  v2 = *(unsigned int *)(a2 + 2780);
  if ( !(_DWORD)v2 )
    return 0;
  v3 = 0;
  v4 = (__int64 *)(a2 + 3096);
  while ( *(_BYTE *)(a1 + 1609) )
  {
    if ( v3 >= 6 )
      goto LABEL_21;
    v5 = *((unsigned __int8 *)v4 + 88);
    if ( v5 == 1 )
    {
      v6 = v4[45];
      v7 = v4[46];
      if ( *(_OWORD *)(v4 + 45) != 0 )
        goto LABEL_18;
      if ( v4[48] || v4[49] )
      {
        v7 = 0;
LABEL_18:
        v8 = *v4;
        v9 = "port:%s Non zero DRV applied BW high[%llu %llu] low[%llu %llu]";
        v12 = v4[48];
        v13 = v4[49];
        v10 = 3055;
LABEL_19:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_util_validate_stop_bw",
          v10,
          v9,
          v8,
          v6,
          v7,
          v12,
          v13);
        return 4294967274LL;
      }
      goto LABEL_3;
    }
LABEL_13:
    if ( (v5 & 1) == 0 )
    {
      v6 = v4[45];
      v7 = v4[46];
      if ( *(_OWORD *)(v4 + 45) != 0 )
      {
        v8 = *v4;
        v9 = "port:%s Non zero HLOS applied BW [%llu %llu]";
        v10 = 3068;
        goto LABEL_19;
      }
    }
LABEL_3:
    ++v3;
    v4 += 51;
    if ( v2 == v3 )
      return 0;
  }
  if ( v3 <= 5 )
  {
    LOBYTE(v5) = *((_BYTE *)v4 + 88);
    goto LABEL_13;
  }
LABEL_21:
  __break(0x5512u);
  return cam_cpas_hw_register_client(a1, (char *)a2);
}
