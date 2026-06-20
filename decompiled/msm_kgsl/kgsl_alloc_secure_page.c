__int64 kgsl_alloc_secure_page()
{
  __int64 v0; // x19
  __int64 inited; // x0
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x4
  int v6; // w0
  __int64 v8; // [xsp+8h] [xbp-48h] BYREF
  __int64 v9; // [xsp+10h] [xbp-40h]
  __int64 v10; // [xsp+18h] [xbp-38h]
  __int64 v11; // [xsp+20h] [xbp-30h]
  __int64 *v12; // [xsp+28h] [xbp-28h] BYREF
  __int64 v13; // [xsp+30h] [xbp-20h]
  int v14; // [xsp+3Ch] [xbp-14h] BYREF
  int v15; // [xsp+40h] [xbp-10h] BYREF
  int v16; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+48h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = nullptr;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  v0 = _alloc_pages_noprof(69058, 0, 0, 0);
  if ( !v0 )
    goto LABEL_9;
  v12 = &v8;
  v13 = 0x100000001LL;
  inited = sg_init_table(&v8, 1);
  if ( (v0 & 3) == 0 )
  {
    v15 = 3;
    v16 = 6;
    v8 = v8 & 3 | v0;
    v9 = 0x100000000000LL;
    v14 = 10;
    do
      v6 = hyp_assign_table(&v12, &v15, 1, &v14, &v16, 1);
    while ( v6 == -11 );
    if ( v6 == -99 )
    {
      printk(&unk_13A8CD);
    }
    else
    {
      if ( !v6 )
      {
LABEL_9:
        _ReadStatusReg(SP_EL0);
        return v0;
      }
      _free_pages(v0, 0);
    }
    v0 = 0;
    goto LABEL_9;
  }
  __break(0x800u);
  return kgsl_allocate_user(inited, v2, v3, v4, v5);
}
