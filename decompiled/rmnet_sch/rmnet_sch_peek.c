__int64 __fastcall rmnet_sch_peek(_DWORD *a1)
{
  int v1; // w9
  unsigned int v2; // w8

  v1 = a1[100];
  if ( v1 )
  {
    if ( (int)a1[102] >= 1 )
    {
      v2 = 0;
      if ( (int)a1[103] > 0 )
        return *(_QWORD *)&a1[10 * v2 + 96];
    }
    v2 = 0;
    if ( !a1[110] )
    {
LABEL_5:
      if ( !a1[120] )
        goto LABEL_6;
      goto LABEL_13;
    }
  }
  else
  {
    v2 = 4;
    if ( !a1[110] )
      goto LABEL_5;
  }
  if ( (int)a1[112] >= 1 && (int)a1[113] > 0 )
  {
    v2 = 1;
    return *(_QWORD *)&a1[10 * v2 + 96];
  }
  v2 = v1 == 0;
  if ( a1[120] )
  {
LABEL_13:
    if ( (int)a1[122] < 1 || (int)a1[123] <= 0 )
    {
      if ( v2 >= 2 )
        v2 = 2;
      if ( !a1[130] )
        goto LABEL_24;
      goto LABEL_19;
    }
    v2 = 2;
    return *(_QWORD *)&a1[10 * v2 + 96];
  }
LABEL_6:
  if ( !a1[130] )
    goto LABEL_24;
LABEL_19:
  if ( (int)a1[132] >= 1 && (int)a1[133] > 0 )
  {
    v2 = 3;
    return *(_QWORD *)&a1[10 * v2 + 96];
  }
  if ( v2 >= 3 )
    v2 = 3;
LABEL_24:
  *((_QWORD *)a1 + 51) = 0x4000000000008LL;
  *((_QWORD *)a1 + 56) = 0x2000000000006LL;
  *((_QWORD *)a1 + 61) = 0x1000000000004LL;
  *((_QWORD *)a1 + 66) = 0x800000000002LL;
  if ( v2 <= 3 )
    return *(_QWORD *)&a1[10 * v2 + 96];
  return 0;
}
