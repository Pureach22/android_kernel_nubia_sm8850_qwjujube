__int64 __fastcall mlo_link_recfg_find_link_status(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w9
  __int64 v13; // x9

  v12 = a2[2];
  if ( !a2[2] )
    goto LABEL_6;
  if ( a2[4] == (unsigned __int8)a1 )
  {
    v13 = 0;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 1 )
    goto LABEL_6;
  if ( a2[12] == (unsigned __int8)a1 )
  {
    v13 = 1;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 2 )
    goto LABEL_6;
  if ( a2[20] == (unsigned __int8)a1 )
  {
    v13 = 2;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 3 )
    goto LABEL_6;
  if ( a2[28] == (unsigned __int8)a1 )
  {
    v13 = 3;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 4 )
    goto LABEL_6;
  if ( a2[36] == (unsigned __int8)a1 )
  {
    v13 = 4;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 5 )
    goto LABEL_6;
  if ( a2[44] == (unsigned __int8)a1 )
  {
    v13 = 5;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 6 )
    goto LABEL_6;
  if ( a2[52] == (unsigned __int8)a1 )
  {
    v13 = 6;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 7 )
    goto LABEL_6;
  if ( a2[60] == (unsigned __int8)a1 )
  {
    v13 = 7;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 8 )
    goto LABEL_6;
  if ( a2[68] == (unsigned __int8)a1 )
  {
    v13 = 8;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 9 )
    goto LABEL_6;
  if ( a2[76] == (unsigned __int8)a1 )
  {
    v13 = 9;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 10 )
    goto LABEL_6;
  if ( a2[84] == (unsigned __int8)a1 )
  {
    v13 = 10;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 11 )
    goto LABEL_6;
  if ( a2[92] == (unsigned __int8)a1 )
  {
    v13 = 11;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 12 )
    goto LABEL_6;
  if ( a2[100] == (unsigned __int8)a1 )
  {
    v13 = 12;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 13 )
    goto LABEL_6;
  if ( a2[108] == (unsigned __int8)a1 )
  {
    v13 = 13;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 14 )
    goto LABEL_6;
  if ( a2[116] == (unsigned __int8)a1 )
  {
    v13 = 14;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 15 )
    goto LABEL_6;
  if ( a2[124] == (unsigned __int8)a1 )
  {
    v13 = 15;
    return *(unsigned int *)&a2[8 * v13 + 8];
  }
  if ( v12 == 16 )
  {
LABEL_6:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: link id not found",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "mlo_link_recfg_find_link_status",
      v10,
      v11);
    return 1;
  }
  else
  {
    __break(0x5512u);
    return mlo_link_recfg_update_added_link_in_mlo_mgr(a1, a2);
  }
}
