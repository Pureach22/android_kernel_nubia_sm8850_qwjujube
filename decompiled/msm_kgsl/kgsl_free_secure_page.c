__int64 __fastcall kgsl_free_secure_page(__int64 result)
{
  __int64 v1; // x19
  __int64 inited; // x0
  __int64 v3; // [xsp+8h] [xbp-48h] BYREF
  __int64 v4; // [xsp+10h] [xbp-40h]
  __int64 v5; // [xsp+18h] [xbp-38h]
  __int64 v6; // [xsp+20h] [xbp-30h]
  _QWORD v7[2]; // [xsp+28h] [xbp-28h] BYREF
  int v8; // [xsp+3Ch] [xbp-14h] BYREF
  int v9; // [xsp+40h] [xbp-10h] BYREF
  int v10; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+48h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_6;
  v1 = result;
  v5 = 0;
  v6 = 0;
  v3 = 0;
  v4 = 0;
  v7[0] = &v3;
  v7[1] = 0x100000001LL;
  inited = sg_init_table(&v3, 1);
  if ( (v1 & 3) == 0 )
  {
    v9 = 10;
    v10 = 7;
    v3 = v3 & 3 | v1;
    v4 = 0x100000000000LL;
    v8 = 3;
    while ( (unsigned int)hyp_assign_table(v7, &v9, 1, &v8, &v10, 1) == -11 )
      ;
    result = _free_pages(v1, 0);
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x800u);
  return kgsl_alloc_secure_page(inited);
}
