__int64 __fastcall kgsl_free_secure_pages(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x8
  unsigned __int64 v11; // x10
  int v12; // [xsp+Ch] [xbp-14h] BYREF
  int v13; // [xsp+10h] [xbp-10h] BYREF
  int v14; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(result + 48) & 8) == 0 )
  {
    v1 = *(_QWORD *)(result + 56);
    v2 = result;
    v14 = 7;
    v12 = 3;
    v13 = 10;
    do
      v3 = hyp_assign_table(v1, &v13, 1, &v12, &v14, 1);
    while ( v3 == -11 );
    if ( v3 )
    {
      result = printk(&unk_13F638);
    }
    else
    {
      v4 = *(_QWORD *)(v2 + 40);
      _X9 = &qword_3A8D8;
      __asm { PRFM            #0x11, [X9] }
      do
        v11 = __ldxr((unsigned __int64 *)&qword_3A8D8);
      while ( __stxr(v11 - v4, (unsigned __int64 *)&qword_3A8D8) );
      kgsl_free_pages_from_sgt(v2);
      sg_free_table(*(_QWORD *)(v2 + 56));
      result = kfree(*(_QWORD *)(v2 + 56));
      *(_QWORD *)(v2 + 56) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
