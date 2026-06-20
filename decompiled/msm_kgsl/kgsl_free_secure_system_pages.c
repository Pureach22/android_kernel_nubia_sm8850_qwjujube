__int64 __fastcall kgsl_free_secure_system_pages(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x8
  _QWORD *v6; // x20
  unsigned int v7; // w21
  __int64 v8; // x0
  unsigned __int64 v15; // x10
  int v16; // [xsp+Ch] [xbp-14h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  int v18; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(result + 48) & 8) == 0 )
  {
    v1 = *(_QWORD *)(result + 56);
    v2 = result;
    v18 = 7;
    v16 = 3;
    v17 = 10;
    do
      v3 = hyp_assign_table(v1, &v17, 1, &v16, &v18, 1);
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
        v15 = __ldxr((unsigned __int64 *)&qword_3A8D8);
      while ( __stxr(v15 - v4, (unsigned __int64 *)&qword_3A8D8) );
      v5 = *(_QWORD *)(v2 + 56);
      if ( *(_DWORD *)(v5 + 8) )
      {
        v6 = *(_QWORD **)v5;
        v7 = 0;
        do
        {
          _free_pages(*v6 & 0xFFFFFFFFFFFFFFFCLL, 0);
          ++v7;
          v8 = sg_next(v6);
          v5 = *(_QWORD *)(v2 + 56);
          v6 = (_QWORD *)v8;
        }
        while ( v7 < *(_DWORD *)(v5 + 8) );
      }
      sg_free_table(v5);
      result = kfree(*(_QWORD *)(v2 + 56));
      *(_QWORD *)(v2 + 56) = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
