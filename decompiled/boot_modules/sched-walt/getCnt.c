__int64 __fastcall getCnt(_DWORD *a1)
{
  int v1; // w8
  int v2; // w9
  bool v4; // vf
  int v5; // w8

  if ( a1 )
  {
    v1 = a1[7];
    v2 = a1[8];
    if ( v2 == v1 )
    {
      return 0;
    }
    else if ( v2 >= v1 )
    {
      v4 = __OFSUB__(v2, v1);
      v5 = v2 - v1;
      if ( (v5 < 0) ^ v4 | (v5 == 0) )
        return 0xFFFFFFFFLL;
      else
        return (unsigned int)v5;
    }
    else
    {
      return (unsigned int)(v2 - v1 + a1[6]);
    }
  }
  else
  {
    printk(&unk_61D9B);
    return 0xFFFFFFFFLL;
  }
}
