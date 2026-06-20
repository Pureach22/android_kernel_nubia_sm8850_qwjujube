__int64 __fastcall kgsl_memfree_find_entry(int a1, unsigned __int64 *a2, _QWORD *a3, _QWORD *a4, _DWORD *a5)
{
  int v10; // w10
  unsigned int v11; // w19
  unsigned __int64 v13; // x12
  __int64 v14; // x14
  __int64 v15; // x16
  unsigned __int64 v16; // x15

  if ( memfree )
  {
    raw_spin_lock(&memfree_lock);
    v10 = qword_17D100 - 1;
    if ( (int)qword_17D100 - 1 < 0 )
      v10 = 511;
    if ( v10 == HIDWORD(qword_17D100) )
    {
LABEL_5:
      v11 = 0;
    }
    else
    {
      v13 = *a2;
      while ( 1 )
      {
        v14 = memfree + 40LL * v10;
        if ( *(_DWORD *)v14 == a1 )
        {
          v15 = *(_QWORD *)(v14 + 16);
          if ( v15 )
          {
            v16 = *(_QWORD *)(v14 + 8);
            if ( v16 <= v13 && v16 + v15 > v13 )
              break;
          }
        }
        if ( --v10 < 0 )
          v10 = 511;
        if ( v10 == HIDWORD(qword_17D100) )
          goto LABEL_5;
      }
      *a2 = v16;
      *a4 = *(_QWORD *)(v14 + 32);
      *a3 = *(_QWORD *)(v14 + 16);
      *a5 = *(_DWORD *)(v14 + 24);
      v11 = 1;
    }
    raw_spin_unlock(&memfree_lock);
  }
  else
  {
    return 0;
  }
  return v11;
}
