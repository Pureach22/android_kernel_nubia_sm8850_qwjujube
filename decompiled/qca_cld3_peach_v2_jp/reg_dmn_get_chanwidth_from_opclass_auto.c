__int64 __fastcall reg_dmn_get_chanwidth_from_opclass_auto(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w19
  int v12; // w20
  char *class_from_country; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // t1
  __int64 v24; // x8
  __int64 result; // x0
  char *v26; // x0
  int v27; // w8
  int v28; // t1
  __int64 v29; // x8
  __int16 v30; // [xsp+4h] [xbp-Ch] BYREF
  char v31; // [xsp+6h] [xbp-Ah]
  __int64 v32; // [xsp+8h] [xbp-8h]

  v11 = a2;
  v12 = a3;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  class_from_country = reg_get_class_from_country(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  v22 = (unsigned __int8)*class_from_country;
  if ( *class_from_country )
  {
    do
    {
      if ( v22 == v12 )
      {
        v24 = 16;
        while ( class_from_country[v24] )
        {
          if ( (unsigned __int8)class_from_country[v24] == v11 )
          {
            result = *((unsigned __int16 *)class_from_country + 1);
            if ( (_DWORD)result )
              goto LABEL_21;
            goto LABEL_11;
          }
          if ( ++v24 == 86 )
            break;
        }
      }
      v23 = (unsigned __int8)class_from_country[96];
      class_from_country += 96;
      v22 = v23;
    }
    while ( v23 );
  }
LABEL_11:
  v31 = 4;
  v26 = reg_get_class_from_country((unsigned __int8 *)&v30, v14, v15, v16, v17, v18, v19, v20, v21);
  v27 = (unsigned __int8)*v26;
  if ( *v26 )
  {
    do
    {
      if ( v27 == v12 )
      {
        v29 = 16;
        while ( v26[v29] )
        {
          if ( (unsigned __int8)v26[v29] == v11 )
          {
            result = *((unsigned __int16 *)v26 + 1);
            goto LABEL_21;
          }
          if ( ++v29 == 86 )
            break;
        }
      }
      v28 = (unsigned __int8)v26[96];
      v26 += 96;
      v27 = v28;
    }
    while ( v28 );
  }
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
