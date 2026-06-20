__int64 __fastcall hdd_get_stainfo(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  int v5; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch]
  __int64 v7; // [xsp+8h] [xbp-8h]

  v3 = 35;
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2;
  v6 = WORD2(a2);
  while ( (unsigned int)qdf_mem_cmp((const void *)(a1 + 32), &v5, 6u) )
  {
    --v3;
    a1 += 512;
    if ( !v3 )
    {
      a1 = 0;
      break;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a1;
}
