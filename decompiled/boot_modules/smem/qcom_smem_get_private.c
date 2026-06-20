unsigned __int64 __fastcall qcom_smem_get_private(_QWORD *a1, unsigned __int64 *a2, int a3, _QWORD *a4)
{
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x10
  __int64 v6; // x14
  unsigned __int64 v7; // x12
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x8
  bool v10; // cc
  unsigned __int16 *v12; // x13
  unsigned __int16 *v13; // x15
  unsigned __int16 *v14; // x15
  unsigned __int64 result; // x0
  unsigned __int64 v16; // x8
  unsigned int v17; // w9
  bool v18; // cf
  __int64 v19; // x8
  __int64 v20; // x13
  unsigned __int16 *v21; // x11
  unsigned __int64 v22; // x14
  unsigned __int16 *v23; // x14
  unsigned int v24; // w9

  v4 = *a2;
  v5 = a2[3];
  v6 = *(unsigned int *)(*a2 + 16);
  v7 = *a2 + v5;
  v8 = *a2 + *(unsigned int *)(*a2 + 12);
  v9 = *a2 + v6;
  v10 = v8 < *a2 || v8 > v9;
  if ( !v10 && v9 <= v7 )
  {
    v12 = (unsigned __int16 *)(v4 + 32);
    while ( 1 )
    {
      if ( (unsigned __int64)v12 >= v8 || (v13 = v12 + 8, (unsigned __int64)(v12 + 8) >= v8) )
      {
        if ( (unsigned __int64)v12 > v8 )
          goto LABEL_42;
        if ( v5 == v6 )
          return -2;
        v20 = (a2[2] + 15) & -(__int64)a2[2];
        v21 = (unsigned __int16 *)(v4 + *(unsigned int *)(v4 + 8) - v20);
        if ( (unsigned __int64)v21 >= v9 && v21 + 8 >= v21 && (unsigned __int64)(v21 + 8) <= v7 )
        {
          while ( 1 )
          {
            if ( (unsigned __int64)v21 <= v9 )
            {
              if ( (unsigned __int64)v21 >= v4 )
                return -2;
              goto LABEL_42;
            }
            if ( *v21 != 42405 )
              goto LABEL_43;
            v22 = *((unsigned int *)v21 + 1);
            if ( v21[1] == a3 )
              break;
            v23 = (unsigned __int16 *)((char *)v21 - v22 - v20);
            v18 = v23 >= v21;
            v21 = v23;
            if ( v18 )
              goto LABEL_42;
          }
          result = -22;
          if ( v5 <= v22 )
            return result;
          v24 = v21[4];
          if ( (unsigned int)v22 <= v24 )
            return result;
          result = (unsigned __int64)v21 - v22;
          if ( (unsigned __int64)v21 - v22 >= v9 )
          {
            v19 = (unsigned int)v22 - v24;
            if ( result + v19 >= result && result + v19 <= (unsigned __int64)v21 )
              goto LABEL_35;
          }
        }
        goto LABEL_42;
      }
      if ( *v12 != 42405 )
      {
LABEL_43:
        dev_err(
          *a1,
          "Found invalid canary in hosts %hu:%hu partition\n",
          *(unsigned __int16 *)(v4 + 4),
          *(unsigned __int16 *)(v4 + 6));
        return -22;
      }
      if ( v12[1] == a3 )
        break;
      v14 = (unsigned __int16 *)((char *)v13 + v12[5] + *((unsigned int *)v12 + 1));
      v10 = v14 > v12;
      v12 = v14;
      if ( !v10 )
        goto LABEL_42;
    }
    v16 = *((unsigned int *)v12 + 1);
    result = -22;
    if ( v5 <= v16 )
      return result;
    v17 = v12[4];
    v18 = (unsigned int)v16 >= v17;
    v19 = (unsigned int)v16 - v17;
    if ( (_DWORD)v19 == 0 || !v18 )
      return result;
    result = (unsigned __int64)v13 + v12[5];
    if ( result >= (unsigned __int64)v12 && result + v19 >= result && result + v19 <= v8 )
    {
LABEL_35:
      if ( a4 )
        *a4 = v19;
      return result;
    }
  }
LABEL_42:
  __break(0x800u);
  return -22;
}
